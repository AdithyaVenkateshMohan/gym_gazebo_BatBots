#ifndef SETPOSETOOBJECTS_HH
#define SETPOSETOOBJECTS_HH

#include <gazebo/common/Plugin.hh>
#include "SetPoseforObjects/MoveToPtr.h"
#include <ros/ros.h>


namespace gazebo
{
class setPosetoObjects : public ModelPlugin
{
    public: 
        setPosetoObjects();
    public:
        ~setPosetoObjects();
    // init for the gazebo plugin which loads the model and sdf description file
    public :  void Load(physics::ModelPtr _model, sdf::ElementPtr _sdf);

    // called each time on update
    public : void OnUpdate();

    // this is the function that moves the calibration object to the point

    public : bool moveToPt(SetPoseforObjects::MoveToPtr::Request & req , SetPoseforObjects::MoveToPtr::Response & res );

    // all the event connections
    private : std::vector<event::ConnectionPtr> connections;

    // pointer to the model
    private : physics:: ModelPtr model; 

    private : sdf::ElementPtr sdf;

    private : ros::NodeHandle * rosnode_;

    private : ros::ServiceServer service;  
    

};

}

#endif