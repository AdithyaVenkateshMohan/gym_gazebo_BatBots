#include <algorithm>
#include <assert.h>

#include <gazebo_3d_laser_plugin/gazebo_3d_laser.h>
#include <gazebo_3d_laser_plugin/gazebo_ros_utils.h>

#include <gazebo/physics/World.hh>
#include <gazebo/physics/HingeJoint.hh>
#include <gazebo/sensors/Sensor.hh>
#include <sdf/sdf.hh>
#include <sdf/Param.hh>
#include <gazebo/common/Exception.hh>
#include <gazebo/sensors/RaySensor.hh>
#include <gazebo/sensors/SensorTypes.hh>
#include <gazebo/transport/Node.hh>

#include <geometry_msgs/Point32.h>
#include <sensor_msgs/ChannelFloat32.h>

#include <tf/tf.h>

#define EPSILON_DIFF 0.000001

namespace gazebo
{
// Register this plugin with the simulator
GZ_REGISTER_SENSOR_PLUGIN(Gazebo3DLaser)

////////////////////////////////////////////////////////////////////////////////
// Constructor
Gazebo3DLaser::Gazebo3DLaser()
{
}

////////////////////////////////////////////////////////////////////////////////
// Destructor
Gazebo3DLaser::~Gazebo3DLaser()
{
  ////////////////////////////////////////////////////////////////////////////////
  // Finalize the controller / Custom Callback Queue
  this->laser_queue_.clear();
  this->laser_queue_.disable();
  this->rosnode_->shutdown();
  this->callback_laser_queue_thread_.join();

  delete this->rosnode_;
}

////////////////////////////////////////////////////////////////////////////////
// Load the controller
void Gazebo3DLaser::Load(sensors::SensorPtr _parent, sdf::ElementPtr _sdf)
{
  // load plugin
  RayPlugin::Load(_parent, _sdf);

  // Get then name of the parent sensor
  this->parent_sensor_ = _parent;

  // Get the world name.
  std::string worldName = _parent->WorldName();
  this->world_ = physics::get_world(worldName);

#if GAZEBO_MAJOR_VERSION >= 8
  last_update_time_ = this->world_->SimTime();
#else
  last_update_time_ = this->world_->GetSimTime();
#endif

  this->node_ = transport::NodePtr(new transport::Node());
  this->node_->Init(worldName);

  GAZEBO_SENSORS_USING_DYNAMIC_POINTER_CAST;
  this->parent_ray_sensor_ = dynamic_pointer_cast<sensors::RaySensor>(this->parent_sensor_);

  if (!this->parent_ray_sensor_)
    gzthrow("GazeboRosBlockLaser controller requires a Ray Sensor as its parent");

  this->robot_namespace_ = "";
  if (_sdf->HasElement("robotNamespace"))
    this->robot_namespace_ = _sdf->GetElement("robotNamespace")->Get<std::string>() + "/";

  if (!_sdf->HasElement("frameName"))
  {
    ROS_INFO_NAMED("block_laser", "Block laser plugin missing <frameName>, defaults to /world");
    this->frame_name_ = "/world";
  }
  else
    this->frame_name_ = _sdf->GetElement("frameName")->Get<std::string>();

  if (!_sdf->HasElement("topicName"))
  {
    ROS_INFO_NAMED("block_laser", "Block laser plugin missing <topicName>, defaults to /world");
    this->topic_name_ = "/world";
  }
  else
    this->topic_name_ = _sdf->GetElement("topicName")->Get<std::string>();

  if (!_sdf->HasElement("gaussianNoise"))
  {
    ROS_INFO_NAMED("block_laser", "Block laser plugin missing <gaussianNoise>, defaults to 0.0");
    this->gaussian_noise_ = 0;
  }
  else
    this->gaussian_noise_ = _sdf->GetElement("gaussianNoise")->Get<double>();

  if (!_sdf->HasElement("hokuyoMinIntensity"))
  {
    ROS_INFO_NAMED("block_laser", "Block laser plugin missing <hokuyoMinIntensity>, defaults to 101");
    this->hokuyo_min_intensity_ = 101;
  }
  else
    this->hokuyo_min_intensity_ = _sdf->GetElement("hokuyoMinIntensity")->Get<double>();

  ROS_DEBUG_NAMED("block_laser", "gazebo_ros_laser plugin should set minimum intensity to %f due to cutoff in hokuyo filters." , this->hokuyo_min_intensity_);

  if (!_sdf->HasElement("updateRate"))
  {
    ROS_INFO_NAMED("block_laser", "Block laser plugin missing <updateRate>, defaults to 0");
    this->update_rate_ = 0;
  }
  else
    this->update_rate_ = _sdf->GetElement("updateRate")->Get<double>();
  // FIXME:  update the update_rate_


  this->laser_connect_count_ = 0;

  // Make sure the ROS node for Gazebo has already been initialized
  if (!ros::isInitialized())
  {
    ROS_FATAL_STREAM_NAMED("block_laser", "A ROS node for Gazebo has not been initialized, unable to load plugin. "
      << "Load the Gazebo system plugin 'libgazebo_ros_api_plugin.so' in the gazebo_ros package)");
    return;
  }

  this->rosnode_ = new ros::NodeHandle(this->robot_namespace_);

  // resolve tf prefix
  std::string prefix;
  this->rosnode_->getParam(std::string("tf_prefix"), prefix);
  this->frame_name_ = tf::resolve(prefix, this->frame_name_);

  // set size of cloud message, starts at 0!! FIXME: not necessary
  this->cloud_msg_.points.clear();
  this->cloud_msg_.channels.clear();
  this->cloud_msg_.channels.push_back(sensor_msgs::ChannelFloat32());

  this->polar_cloud_msg_.points.clear();
  this->polar_cloud_msg_.channels.clear();
  this->polar_cloud_msg_.channels.push_back(sensor_msgs::ChannelFloat32());

  if (this->topic_name_ != "")
  {
    // Custom Callback Queue
    ros::AdvertiseOptions ao = ros::AdvertiseOptions::create<sensor_msgs::PointCloud>(
      this->topic_name_ + "/pointcloud",1,
      boost::bind( &Gazebo3DLaser::LaserConnect,this),
      boost::bind( &Gazebo3DLaser::LaserDisconnect,this), ros::VoidPtr(), &this->laser_queue_);
  
    this->pub_ = this->rosnode_->advertise(ao);

    // adding one more publisher here to publish the polar co-ordinates

    ros::AdvertiseOptions aopo = ros::AdvertiseOptions::create<sensor_msgs::PointCloud>(
      this->topic_name_ + "/polorcloud",1,
      boost::bind( &Gazebo3DLaser::LaserConnect,this),
      boost::bind( &Gazebo3DLaser::LaserDisconnect,this), ros::VoidPtr(), &this->laser_queue_);

      this->pub2_ = this->rosnode_-> advertise(aopo);

  }


  // Initialize the controller

  // sensor generation off by default
  this->parent_ray_sensor_->SetActive(false);
  // start custom queue for laser
  this->callback_laser_queue_thread_ = boost::thread( boost::bind( &Gazebo3DLaser::LaserQueueThread,this ) );

}

////////////////////////////////////////////////////////////////////////////////
// Increment count
void Gazebo3DLaser::LaserConnect()
{
  this->laser_connect_count_++;
  this->parent_ray_sensor_->SetActive(true);
}
////////////////////////////////////////////////////////////////////////////////
// Decrement count
void Gazebo3DLaser::LaserDisconnect()
{
  this->laser_connect_count_--;

  if (this->laser_connect_count_ == 0)
    this->parent_ray_sensor_->SetActive(false);
}

////////////////////////////////////////////////////////////////////////////////
// Update the controller
void Gazebo3DLaser::OnNewLaserScans()
{
  if (this->topic_name_ != "")
  {
    common::Time sensor_update_time = this->parent_sensor_->LastUpdateTime();
    if (sensor_update_time < last_update_time_)
    {
        ROS_WARN_NAMED("block_laser", "Negative sensor update time difference detected.");
        last_update_time_ = sensor_update_time;
    }

    if (last_update_time_ < sensor_update_time)
    {
      this->PutLaserData(sensor_update_time);
      last_update_time_ = sensor_update_time;
    }
  }
  else
  {
    ROS_INFO_NAMED("block_laser", "gazebo_ros_block_laser topic name not set");
  }
}

////////////////////////////////////////////////////////////////////////////////
// Put laser data to the interface
void Gazebo3DLaser::PutLaserData(common::Time &_updateTime)
{
  int i, hja, hjb;
  int j, vja, vjb;
  double vb, hb;
  int    j1, j2, j3, j4; // four corners indices
  double r1, r2, r3, r4, r; // four corner values + interpolated range
  double intensity , intensity1;

  this->parent_ray_sensor_->SetActive(false);

  auto maxAngle = this->parent_ray_sensor_->AngleMax();
  auto minAngle = this->parent_ray_sensor_->AngleMin();

  double maxRange = this->parent_ray_sensor_->RangeMax();
  double minRange = this->parent_ray_sensor_->RangeMin();
  int rayCount = this->parent_ray_sensor_->RayCount();
  int rangeCount = this->parent_ray_sensor_->RangeCount();

  int verticalRayCount = this->parent_ray_sensor_->VerticalRayCount();
  int verticalRangeCount = this->parent_ray_sensor_->VerticalRangeCount();
  auto verticalMaxAngle = this->parent_ray_sensor_->VerticalAngleMax();
  auto verticalMinAngle = this->parent_ray_sensor_->VerticalAngleMin();

  double yDiff = maxAngle.Radian() - minAngle.Radian();
  double pDiff = verticalMaxAngle.Radian() - verticalMinAngle.Radian();


  // set size of cloud message everytime!
  //int r_size = rangeCount * verticalRangeCount;
  this->cloud_msg_.points.clear();
  this->cloud_msg_.channels.clear();
  this->cloud_msg_.channels.push_back(sensor_msgs::ChannelFloat32());

  this->polar_cloud_msg_.points.clear();
  this->polar_cloud_msg_.channels.clear();
  this->polar_cloud_msg_.channels.push_back(sensor_msgs::ChannelFloat32());

  /***************************************************************/
  /*                                                             */
  /*  point scan from laser                                      */
  /*                                                             */
  /***************************************************************/
  boost::mutex::scoped_lock sclock(this->lock);
  // Add Frame Name
  this->cloud_msg_.header.frame_id = this->frame_name_;
  this->cloud_msg_.header.stamp.sec = _updateTime.sec;
  this->cloud_msg_.header.stamp.nsec = _updateTime.nsec;

  this->polar_cloud_msg_.header.frame_id = this->frame_name_;
  this->polar_cloud_msg_.header.stamp.sec = _updateTime.sec;
  this->polar_cloud_msg_.header.stamp.nsec = _updateTime.nsec;


  for (j = 0; j<verticalRangeCount; j++)
  {
    // interpolating in vertical direction
    vb = (verticalRangeCount == 1) ? 0 : (double) j * (verticalRayCount - 1) / (verticalRangeCount - 1);
    vja = (int) floor(vb);
    vjb = std::min(vja + 1, verticalRayCount - 1);
    vb = vb - floor(vb); // fraction from min

    assert(vja >= 0 && vja < verticalRayCount);
    assert(vjb >= 0 && vjb < verticalRayCount);

    for (i = 0; i<rangeCount; i++)
    {
      // Interpolate the range readings from the rays in horizontal direction
      hb = (rangeCount == 1)? 0 : (double) i * (rayCount - 1) / (rangeCount - 1);
      hja = (int) floor(hb);
      hjb = std::min(hja + 1, rayCount - 1);
      hb = hb - floor(hb); // fraction from min

      assert(hja >= 0 && hja < rayCount);
      assert(hjb >= 0 && hjb < rayCount);

      // indices of 4 corners
      j1 = hja + vja * rayCount;
      j2 = hjb + vja * rayCount;
      j3 = hja + vjb * rayCount;
      j4 = hjb + vjb * rayCount;
      // range readings of 4 corners
      r1 = std::min(this->parent_ray_sensor_->LaserShape()->GetRange(j1) , maxRange-minRange);
      r2 = std::min(this->parent_ray_sensor_->LaserShape()->GetRange(j2) , maxRange-minRange);
      r3 = std::min(this->parent_ray_sensor_->LaserShape()->GetRange(j3) , maxRange-minRange);
      r4 = std::min(this->parent_ray_sensor_->LaserShape()->GetRange(j4) , maxRange-minRange);

      // Range is linear interpolation if values are close,
      // and min if they are very different
      r = (1-vb)*((1 - hb) * r1 + hb * r2)
         +   vb *((1 - hb) * r3 + hb * r4);

      // Intensity is averaged

      intensity1 = this->parent_ray_sensor_->LaserShape()->GetRetro(j1);

      intensity = 0.25*(this->parent_ray_sensor_->LaserShape()->GetRetro(j1) +
                        this->parent_ray_sensor_->LaserShape()->GetRetro(j2) +
                        this->parent_ray_sensor_->LaserShape()->GetRetro(j3) +
                        this->parent_ray_sensor_->LaserShape()->GetRetro(j4));



      // if (intensity <= 50)
      // {
      //   continue;
      // }

      //std::cout << "debug intensity" << intensity << "minor j1"<< intensity1 <<std::endl;

      // std::cout << " block debug "
      //           << "  ij("<<i<<","<<j<<")"
      //           << "  j1234("<<j1<<","<<j2<<","<<j3<<","<<j4<<")"
      //           << "  r1234("<<r1<<","<<r2<<","<<r3<<","<<r4<<")"
      //           << std::endl;

      // get angles of ray to get xyz for point
      double yAngle = 0.5*(hja+hjb) * yDiff / (rayCount -1) + minAngle.Radian();
      double pAngle = 0.5*(vja+vjb) * pDiff / (verticalRayCount -1) + verticalMinAngle.Radian();

      /***************************************************************/
      /*                                                             */
      /*  point scan from laser                                      */
      /*                                                             */
      /***************************************************************/
      //compare 2 doubles
      double diffRange = maxRange - minRange;
      double diff  = diffRange - r;
      if (fabs(diff) < EPSILON_DIFF)
      {
        // no noise if at max range
        geometry_msgs::Point32 point;

        geometry_msgs::Point32 polar;
        //pAngle is rotated by yAngle:
        point.x = r * cos(pAngle) * cos(yAngle);
        point.y = r * cos(pAngle) * sin(yAngle);
        point.z = r * sin(pAngle);

        polar.x = r ;
        polar.y = yAngle;
        polar.z = pAngle;

        this->cloud_msg_.points.push_back(point);
        this->polar_cloud_msg_.points.push_back(polar);
      }
      else
      {
        geometry_msgs::Point32 point;
        geometry_msgs::Point32 polar;
        //pAngle is rotated by yAngle:
        // try to directly pack the polar co-ordinates values over here
        point.x = r * cos(pAngle) * cos(yAngle) + this->GaussianKernel(0,this->gaussian_noise_);
        point.y = r * cos(pAngle) * sin(yAngle) + this->GaussianKernel(0,this->gaussian_noise_);
        point.z = r * sin(pAngle) + this->GaussianKernel(0,this->gaussian_noise_);
        
        polar.x = r ;
        polar.y = yAngle;
        polar.z = pAngle;

        this->cloud_msg_.points.push_back(point);
        this->polar_cloud_msg_.points.push_back(polar);
      } // only 1 channel
      // this->cloud_msg_.channels[0]. push the name here
      // removing the noise
      // this->cloud_msg_.channels[0].values.push_back(intensity + this->GaussianKernel(0,this->gaussian_noise_)) ;
      this->cloud_msg_.channels[0].values.push_back(intensity);
      this->polar_cloud_msg_.channels[0].values.push_back(intensity);
    }
  }
  this->parent_ray_sensor_->SetActive(true);
  // may be try to just send the polar co-ord as addtional topic to avoid confusion
  // send data out via ros message
  this->pub_.publish(this->cloud_msg_);
  this->pub2_.publish(this->polar_cloud_msg_);


}


//////////////////////////////////////////////////////////////////////////////
// Utility for adding noise
double Gazebo3DLaser::GaussianKernel(double mu,double sigma)
{
  // using Box-Muller transform to generate two independent standard normally disbributed normal variables
  // see wikipedia
  double U = (double)rand()/(double)RAND_MAX; // normalized uniform random variable
  double V = (double)rand()/(double)RAND_MAX; // normalized uniform random variable
  double X = sqrt(-2.0 * ::log(U)) * cos( 2.0*M_PI * V);
  //double Y = sqrt(-2.0 * ::log(U)) * sin( 2.0*M_PI * V); // the other indep. normal variable
  // we'll just use X
  // scale to our mu and sigma
  X = sigma * X + mu;
  return X;
}

// Custom Callback Queue
////////////////////////////////////////////////////////////////////////////////
// custom callback queue thread
void Gazebo3DLaser::LaserQueueThread()
{
  static const double timeout = 0.01;

  while (this->rosnode_->ok())
  {
    this->laser_queue_.callAvailable(ros::WallDuration(timeout));
  }
}

void Gazebo3DLaser::OnStats( const boost::shared_ptr<msgs::WorldStatistics const> &_msg)
{
  this->sim_time_  = msgs::Convert( _msg->sim_time() );

  ignition::math::Pose3d pose;
  pose.Pos().X() = 0.5*sin(0.01*this->sim_time_.Double());
  gzdbg << "plugin simTime [" << this->sim_time_.Double() << "] update pose [" << pose.Pos().X() << "]\n";
}


}