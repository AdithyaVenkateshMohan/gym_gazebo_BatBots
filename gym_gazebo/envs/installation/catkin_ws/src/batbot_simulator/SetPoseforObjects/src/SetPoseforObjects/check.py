#!/usr/bin/env python3
import rospy
import sys
from geometry_msgs.msg import Pose
from geometry_msgs.msg import PoseStamped
from tf2_msgs.msg import TFMessage as tf
from nav_msgs.msg import Odometry as odom
import numpy as np

from mybot_sonar.src import library
from mybot_sonar.src import sonar_gen

from sensor_msgs.msg import PointCloud 
from geometry_msgs.msg import Point 

import sensor_msgs.point_cloud2 as pc2


import numpy
from matplotlib import pyplot
from scipy.interpolate import interp1d

from SetPoseforObjects.srv import *
# not required avoiding ros python3 errors by just using python2 for now

# _Python3path = r"/usr/local/lib/python3.5/dist-packages"
# _Python2path = r"/opt/ros/kinetic/lib/python2.7/dist-packages"
# print(sys.path)
# sys.path.append(_Python3path)
# sys.path.remove(_Python2path)
# print(sys.path)
import message_filters as mf
# these are the list of points to check the directionality
List_of_points = [[0,-5],[1.71,-4.678],[3.214,-3.83],[4.33,2.5],[4.924,-0.868],[0,0],[0,5],[1.71,4.678],[3.214,3.83],[4.33,2.5],[4.924,0.868]]

def call_back2(pos_data, odom_data):
    odomP = odom_data.pose.pose.position
    odomVe = np.array([odomP.x , odomP.y])
    poseP = pos_data.pose.position
    poseVe = np.array([poseP.x, poseP.y])
    angle = angle_between(odomVe , poseVe)
    print("angle in between is" , angle)

def call_back3(data):
    print("hello")
    print(data)   

def unit_vector(vector):
    """ Returns the unit vector of the vector.  """
    return vector / np.linalg.norm(vector)

def angle_between(v1, v2):
    """ Returns the angle in radians between vectors 'v1' and 'v2'::

            >>> angle_between((1, 0, 0), (0, 1, 0))
            1.5707963267948966
            >>> angle_between((1, 0, 0), (1, 0, 0))
            0.0
            >>> angle_between((1, 0, 0), (-1, 0, 0))
            3.141592653589793
    """
    v1_u = unit_vector(v1)
    v2_u = unit_vector(v2)
    return np.arccos(np.clip(np.dot(v1_u, v2_u), -1.0, 1.0))

def listener(topic , node_name, call_back ,msg_type ,anom = False):
    rospy.init_node(node_name,anonymous=anom)
    print(topic,node_name , msg_type ,call_back)
    p = rospy.Subscriber(topic ,msg_type, call_back)
    print(p)
    rospy.spin()

def sync_listener(topic , node_name, call_back ,msg_type ,anom = False):
    print("no. of topics", len(topic))
    assert(len(topic)==len(msg_type))
    rospy.init_node(node_name,anonymous=anom)
    print(topic,"--in--",node_name, "--of type--",msg_type , "---calling---",call_back)
    message_queue =[]
    # creating subscriber for all the topics given with message filters 
    for i in range(len(topic)):
        message_queue.append(mf.Subscriber(topic[i], msg_type[i]))
    #print(p , q)
    # defining the time sync with @param queue size = 30
    tsync = mf.TimeSynchronizer(message_queue, 30)
    #registering the call_back to handle messages
    tsync.registerCallback(call_back)
    rospy.spin()

def postion_the_object(x,y,z,rx,ry,rz,rw):
    rospy.wait_for_service('Calibration_Directionality/MoveToPtr' , 15.0)
    try:
        position_the_obj = rospy.ServiceProxy('Calibration_Directionality/MoveToPtr', MoveToPtr)
        pose_ = geometry_msgs.msg.Pose()
        pose_.position.x = x
        pose_.position.y = y
        pose_.position.z = z
        pose_.orientation.x = rx
        pose_.orientation.y = ry
        pose_.orientation.z = rz
        pose_.orientation.w = rw
        print(pose_)
        resp = position_the_obj(pose_)
        return resp.done
    except rospy.ServiceException :
        print("service call failed")
        return False
    
   

#     import message_filters
#     2 from sensor_msgs.msg import Image, CameraInfo
#     3 
#     4 def callback(image, camera_info):
#     5   # Solve all of perception here...
#     6 
#     7 image_sub = message_filters.Subscriber('image', Image)
#     8 info_sub = message_filters.Subscriber('camera_info', CameraInfo)
#     9 
#    10 ts = message_filters.TimeSynchronizer([image_sub, info_sub], 10)
#    11 ts.registerCallback(callback)
#    12 rospy.spin()

if __name__ == "__main__":
    print("came to main first")
    _Topic = [r'/test/sphere/pose', r'/odom']
    _nodeName = "eagleEye"
    _MsgType = [PoseStamped , odom]
    sync_listener(_Topic,_nodeName , call_back2, _MsgType)
    test_directionalityDrill(list_points)