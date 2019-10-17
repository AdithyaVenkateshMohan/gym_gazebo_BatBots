#ifndef POSEPUBLISHER_HH
#define POSEPUBLISHER_HH


#include <gazebo/common/Plugin.hh>
#include <ros/ros.h>
#include "geometry_msgs/Pose.h"
#include <geometry_msgs/PoseStamped.h>

#include <ros/callback_queue.h>
#include <ros/advertise_options.h>

namespace gazebo
{
    class PosePub: public ModelPlugin
    {

        public :
                PosePub();
                
                ~PosePub();
                
                void Load(physics::ModelPtr _model , sdf::ElementPtr _sdf);

                void onUpdate();

        private : 

                physics::WorldPtr world_;

                common::Time last_update_time_;

                std::vector<event::ConnectionPtr> connections;

                physics::ModelPtr model;

                sdf::ElementPtr sdf;

                ros::NodeHandle * rosnode;

                ros::Publisher pub_;

                std::string topic_name_;

                std::string frame_name_;

                geometry_msgs::Pose pose_;

                geometry_msgs::PoseStamped poseStamp_;

                ros::CallbackQueue pose_queue_;

                void PoseQueueThread();
                
                boost::thread callback_pose_queue_thread_;

                void PoseConnect();

                void PoseDisconnect();



    };
}



#endif