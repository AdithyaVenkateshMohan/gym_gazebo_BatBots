// include files for gazebo

#include <ignition/math/Pose3.hh>
#include <ignition/math/Rand.hh>
#include <gazebo/physics/physics.hh>

// include files for ros lib
#include <ros/ros.h>


#include "SetPoseforObjects/SetPoseforObjects.h"

 namespace gazebo
 {

GZ_REGISTER_MODEL_PLUGIN(setPosetoObjects)

 setPosetoObjects::setPosetoObjects()
 {

 }

  setPosetoObjects::~setPosetoObjects()
 {
    
 }


bool setPosetoObjects::moveToPt(SetPoseforObjects::MoveToPtr::Request & req , SetPoseforObjects::MoveToPtr::Response & res )
{
    ignition::math::Pose3d pose = this->model->GetWorldPose().Ign();

    std::cout<<"the point send here is"<< "\t"<<req.px.position.x <<"\t" <<req.px.position.y << req.px.position.z << std::endl;

    pose =  ignition::math::Pose3d(req.px.position.x ,
                                    req.px.position.y ,
                                    req.px.position.z ,
                                    req.px.orientation.x,
                                    req.px.orientation.y,
                                    req.px.orientation.z,
                                    req.px.orientation.w);

    this->model->SetWorldPose(pose);

    res.done = true;

    return true;
}



void setPosetoObjects::Load(physics::ModelPtr _model , sdf::ElementPtr _sdf )
{
  ROS_INFO("the load of the  setPoseobjects is started");
    //ModelPlugin::Load(_model, _sdf);
    this->model = _model;
    this->sdf = _sdf;
    //ModelPlugin(_model , _sdf);
    //this->connections.push_back(event::Events::ConnectWorldUpdateEnd(std::bind(&SetPoseforObjects:: OnUpdate , this)));
    
    if (!ros::isInitialized())
  {

    ROS_INFO("error...in set pose");
    ROS_FATAL_STREAM_NAMED("block_laser", "A ROS node for Gazebo has not been initialized, unable to load plugin. "
      << "Load the Gazebo system plugin 'libgazebo_ros_api_plugin.so' in the gazebo_ros package)");
    return;
  }


  try
  {
    this->rosnode_ = new ros::NodeHandle("Calibration_Directionality");
    this->service =  rosnode_->advertiseService("MoveToPtr", &setPosetoObjects::moveToPt , this);
  }
  catch(ros::Exception &e)
  {
    ROS_INFO("the error is in ros part %s", e.what());
  }
  catch(const std::exception& e)
  {
    ROS_INFO("exception in ros part");
    std::cerr << e.what() << '\n';
  }

  
 ROS_INFO("the load of the  setPoseobjects is done");

}

void setPosetoObjects::OnUpdate()
{

    ignition::math::Pose3d pose = this->model->GetWorldPose().Ign();

    pose += ignition::math::Pose3d(ignition::math::Rand::DblUniform(-0.01,0.1) ,
                                    ignition::math::Rand::DblUniform(-0.01,0.1) ,
                                    ignition::math::Rand::DblUniform(-0.01,0.1) ,
                                    ignition::math::Rand::DblUniform(-0.01,0.01),
                                    ignition::math::Rand::DblUniform(-0.01,0.01),
                                    ignition::math::Rand::DblUniform(-0.01,0.01));

    pose.Pos().Z() = pose.Pos().Z() < 0.5 ? 0.5 : pose.Pos().Z();

    this->model->SetWorldPose(pose);

}


 }