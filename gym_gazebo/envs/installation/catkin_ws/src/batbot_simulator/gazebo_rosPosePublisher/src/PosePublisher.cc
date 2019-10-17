
#include <ignition/math/Pose3.hh>
#include <ignition/math/Rand.hh>
#include <gazebo/physics/physics.hh>

#include <geometry_msgs/Point.h>
#include <geometry_msgs/Quaternion.h>

// include files for ros
#include <ros/ros.h>
#include "geometry_msgs/Pose.h"
#include <geometry_msgs/PoseStamped.h>
#include <std_msgs/Header.h>
#include "gazebo_rosPosePublisher/PosePublisher.hh"

using namespace gazebo;

GZ_REGISTER_MODEL_PLUGIN(PosePub)

PosePub::PosePub()
{

    ROS_INFO("Pose publisher  is  about to be switched on");

}


PosePub::~PosePub()
{
  this->pose_queue_.clear();
  this->pose_queue_.disable();
  this->rosnode->shutdown();
  this->callback_pose_queue_thread_.join();
  delete this->rosnode;
}


void PosePub::Load(physics::ModelPtr _model , sdf::ElementPtr _sdf)
{
  ROS_INFO("Loading");
    this-> model = _model;
    this->sdf = _sdf;

    this->world_ = _model->GetWorld();

    this->last_update_time_ = this->world_->GetSimTime();

ROS_INFO(".");
    if (!_sdf->HasElement("frameName"))
  {
    ROS_INFO_NAMED("block_laser", "Block laser plugin missing <frameName>, defaults to /world");
    this->frame_name_ = "/world";
  }
  else
    this->frame_name_ = _sdf->GetElement("frameName")->Get<std::string>();

  if (!_sdf->HasElement("topicName"))
  {
    ROS_INFO_NAMED("block_laser", "Block laser plugin missing <topicName>, defaults to /worldd");
    this->topic_name_ = "/world";
  }
  else
    this->topic_name_ = _sdf->GetElement("topicName")->Get<std::string>();


 this->connections.push_back(event::Events::ConnectWorldUpdateBegin(std::bind(&PosePub::onUpdate, this)));

 ROS_INFO(".");

 if (!ros::isInitialized())
  {
    ROS_FATAL_STREAM_NAMED("block_laser", "A ROS node for Gazebo has not been initialized, unable to load plugin. "
      << "Load the Gazebo system plugin 'libgazebo_ros_api_plugin.so' in the gazebo_ros package)");
    return;
  }

    //// ros side of the functions

    this->rosnode = new ros::NodeHandle("PosePub");
    std::cout<< this->frame_name_<<std::endl;
    ros::AdvertiseOptions ao = ros::AdvertiseOptions::create<geometry_msgs::PoseStamped>(
                                this->topic_name_ ,100 ,boost::bind(&PosePub::PoseConnect, this),boost::bind(&PosePub::PoseDisconnect, this),ros::VoidPtr(), &this->pose_queue_ );
  ROS_INFO(".");
    this->pub_ = this->rosnode->advertise(ao);

    this->callback_pose_queue_thread_ = boost::thread( boost::bind( &PosePub::PoseQueueThread,this ) );

    ROS_INFO("Done loading");
}

void PosePub::onUpdate()
{

/// gets the prev animation time according to the model
    common::Time model_update_time = this->world_->GetSimTime();

    // this block is to omit the negative update time
    if(model_update_time <  this->last_update_time_)
    {
      ROS_WARN_NAMED("posepub", "negative model update time");
      this->last_update_time_ = model_update_time ;
      
    }

    if (this->last_update_time_ < model_update_time)
    {
        
      ignition::math::Pose3d pose = this->model->GetWorldPose().Ign();

      

      /// updating the time stamp info with the current time
      this->poseStamp_.header.frame_id = this->frame_name_;
      this->poseStamp_.header.stamp.sec = model_update_time.sec;
      this->poseStamp_.header.stamp.nsec = model_update_time.nsec;
      /// getting the pose info from the gazebo engine
      pose_.position.x = pose.Pos().X();
      pose_.position.y = pose.Pos().Y();
      pose_.position.z = pose.Pos().Z();

      pose_.orientation.x = pose.Rot().X();
      pose_.orientation.y = pose.Rot().Y();
      pose_.orientation.z = pose.Rot().Z();
      pose_.orientation.w = pose.Rot().W();

      this->poseStamp_.pose = this->pose_;

      /// publishing the pose of the model in the given topic in ros
      this->pub_. publish(this->poseStamp_);

  //     this->cloud_msg_.header.frame_id = this->frame_name_;
  // this->cloud_msg_.header.stamp.sec = _updateTime.sec;
  // this->cloud_msg_.header.stamp.nsec = _updateTime.nsec;



      // updating the last update time 
      this->last_update_time_ = model_update_time;
    }

  

}

void PosePub::PoseConnect()
{
  ROS_INFO("pose publisher under topic name " );

}


void PosePub::PoseDisconnect()
{
    ROS_INFO("pose publisher stopped" );
}

void PosePub::PoseQueueThread()
{
  static const double timeout = 0.01;

  while (this->rosnode->ok())
  {
    this->pose_queue_.callAvailable(ros::WallDuration(timeout));
  }
}