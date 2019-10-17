#ifndef GAZEBO_3D_LASER_HH
#define GAZEBO_3D_LASER_HH

// Custom Callback Queue
#include <ros/ros.h>
#include <ros/callback_queue.h>
#include <ros/advertise_options.h>

#include <sdf/Param.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/transport/TransportTypes.hh>
#include <gazebo/msgs/MessageTypes.hh>
#include <gazebo/common/Time.hh>
#include <gazebo/common/Plugin.hh>
#include <gazebo/sensors/SensorTypes.hh>
#include <gazebo/plugins/RayPlugin.hh>

#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>

#include <sensor_msgs/PointCloud.h>

namespace gazebo
{

  class Gazebo3DLaser : public RayPlugin
  {
    /// \brief Constructor
    /// \param parent The parent entity, must be a Model or a Sensor
    public: Gazebo3DLaser();
    public: ~Gazebo3DLaser();
    /// \brief Destructor
    /// \brief Load the plugin
    /// \param take in SDF root element
    public: void Load(sensors::SensorPtr _parent, sdf::ElementPtr _sdf);

    /// \brief Update the controller
    protected: virtual void OnNewLaserScans();

    /// \brief Put laser data to the ROS topic
    private: void PutLaserData(common::Time &_updateTime);

    private: common::Time last_update_time_;

    /// \brief Keep track of number of connctions
    private: int laser_connect_count_;
    private: void LaserConnect();
    private: void LaserDisconnect();

    // Pointer to the model
    private: physics::WorldPtr world_;
    /// \brief The parent sensor
    private: sensors::SensorPtr parent_sensor_;
    private: sensors::RaySensorPtr parent_ray_sensor_;

    /// \brief pointer to ros node
    private: ros::NodeHandle* rosnode_;
    private: ros::Publisher pub_;

    private: ros::Publisher pub2_;

  

    /// \brief ros message
    private: sensor_msgs::PointCloud cloud_msg_;

    private: sensor_msgs::PointCloud polar_cloud_msg_;
    /// \brief topic name
    private: std::string topic_name_;

    /// \brief frame transform name, should match link name
    private: std::string frame_name_;

    /// \brief Gaussian noise
    private: double gaussian_noise_;

    /// \brief Gaussian noise generator
    private: double GaussianKernel(double mu,double sigma);

    /// \brief A mutex to lock access to fields that are used in message callbacks
    private: boost::mutex lock;

    /// \brief hack to mimic hokuyo intensity cutoff of 100
    //private: ParamT<double> *hokuyoMinIntensityP;
    private: double hokuyo_min_intensity_;

    /// update rate of this sensor
    private: double update_rate_;

    /// \brief for setting ROS name space
    private: std::string robot_namespace_;

    // Custom Callback Queue
    private: ros::CallbackQueue laser_queue_;

    private: void LaserQueueThread();
    private: boost::thread callback_laser_queue_thread_;

    // subscribe to world stats
    private: transport::NodePtr node_;
    private: common::Time sim_time_;
    public: void OnStats( const boost::shared_ptr<msgs::WorldStatistics const> &_msg);

  };

}

#endif
