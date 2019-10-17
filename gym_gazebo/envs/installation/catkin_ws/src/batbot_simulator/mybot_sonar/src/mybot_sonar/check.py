#!/usr/bin/env python3
import rospy
import sys
from geometry_msgs.msg import Pose
from geometry_msgs.msg import PoseStamped
from tf2_msgs.msg import TFMessage as tf2
import tf.transformations as tran 
from nav_msgs.msg import Odometry as odom
import numpy as np
import math

import library

import sonar_gen

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
List_of_points = [[0,-5.00],[0.58, -4.966],[1.153, -4.865],[1.71,-4.698],[2.244,-4.468],[2.748,-4.177],[3.214,-3.83],[3.637,-3.431],[4.011,-2.986],[4.33,-2.5],[4.591,-1.98],[4.79,-1.434],[4.924,-0.868],[4.992,-0.291],[5.00,0],[0,5.00],[0.58, 4.966],[1.153, 4.865],[1.71,4.698],[2.244,4.468],[2.748,4.177],[3.214,3.83],[3.637,3.431],[4.011,2.986],[4.33,2.5],[4.591,1.98],[4.79,1.434],[4.924,0.868],[4.992,0.291]]

DirectionalityPoints = {}
OdomVariations ={}

i=0
total_energy_list=[]
rpy_list=np.array([[]])
cumulative_variations= np.array([])

# call back for the function 
# this call back tries to calulate the angle between the object and the robot
# then saves the corresponding echo sequence in the dictionary 
# this will stored / recorded for later analysis
# this  callback function handles three topics 
# @pos-data which is position of the testing object
# @odom_data which is postion and orientation of the robot
# @polor-cloud which point cloud data from ray sensor in polor co-ordinates format
# this data is used to simulate echo-pulse



def track_energy_variations_withPOSNROS(euler_current , points_varx , energy_current , count):
    # calulating the energy of the echo pulse
    global rpy_list
    if count ==1:
        rpy_list = np.array([euler_current])
    else :
        rpy_list = numpy.append(rpy_list, np.array([euler_current]), axis=0)
    
    global cumulative_variations
    print("value",points_varx)
    

    if count ==1 :
        cumulative_variations = np.array([points_varx])
    else:
        cumulative_variations = np.append(cumulative_variations,np.array([points_varx]),axis=0)

    
    
    total_energy_list.append(energy_current)
    live_plot1D(np.arange(i) , [total_energy_list, rpy_list], row =1 , col =2 , shape = [1,3])
    
    live_plot1D(np.arange(i) , cumulative_variations , fig_num=3 , shape=[1])
    clear_plot(num=3)

def call_back2(pos_data, odom_data , polorcloud_data):
    global i 
    i += 1
    print("the current i ", i)
    odomP = odom_data.pose.pose.position
    odomRot = odom_data.pose.pose.orientation
    q = (odomRot.x , odomRot.y , odomRot.z , odomRot.w)
    euler = tran.euler_from_quaternion(q)
    

    yaw = math.degrees(euler[2])
    # print("rpy shape", np.shape(rpy_list))
    odomVe = np.array([odomP.x , odomP.y])
    stdVe = np.array([1,0])
    poseP = pos_data.pose.position
    poseVe = np.array([poseP.x, poseP.y])
    # for angle calulation using std_ve which denotes the desired direction the robot supposed to be facing
    # so that vector [1,0] gives zero degree and left is positve and right is negative
    print("angle", angle_between(stdVe , poseVe),"vs another", give_angle_between(stdVe,poseVe))
    angle = angle_between(stdVe , poseVe) - yaw 
    # for calulating the distance using the actual position of the robot
    dist = np.linalg.norm(odomVe-poseVe)
    print("angle in between is odom" , odomVe ,"yaw of the robot :", yaw,"and pose of the object",poseVe,"is:", angle , "distance is given by :", dist)
    
    echo_sequence , impulse_time , variations = sonar_gen.echo_genration(polorcloud_data.points)
    #if checking == None:
    total_energy = sonar_gen.echo_total_energycalulation(echo_sequence)
    # calulating the energy variation with time using a time window of 2ms @time_window= 2e-3
    energy_variation = sonar_gen.echo_time_window_energycalulation(echo_sequence , time_window= 2e-3)
    # storing various echoes_based on it's angle with testing objects 
    #
    variations = np.mean(variations , axis=0)
    print("the echo sequence structure :", np.shape(echo_sequence) , "energy", total_energy)
    variations = numpy.where(variations>0 , variations , -1)
    checking = np.mean(variations[variations>-1])
    print("checking", checking , "shape", np.shape(checking))
    #live_plot1D(impulse_time , echo_sequence , fig_num=2)
    #clear_plot(num =1)
    #track_energy_variations_withPOSNROS(euler , checking , total_energy , i)
    if angle in DirectionalityPoints:
        DirectionalityPoints[angle].append([total_energy, energy_variation])
    else:
        DirectionalityPoints[angle] = [[total_energy, energy_variation]]
    

def call_back3(data):
    print("hello")
    print(data)   
# return a unit vector
def unit_vector(vector):
    """ Returns the unit vector of the vector.  """
    return vector / np.linalg.norm(vector)

def norm(vector):
    return np.linalg.norm(vector)

def get_listofpoints_with_var_angle(angleRange , sigma , radius =1, type='deg'):
    print("genrating points between:", angleRange)
    start = angleRange[0]
    end = angleRange[1]
    List_points =[]
    for a in np.arange(start,end,sigma):
        p = get_point_alpha_r(a,radius)
        List_points.append(p)
    return List_points


def get_point_alpha_r(alpha, radius , type='deg'):
    "returns a point with alpha and radius using formula {rcosa , rsina}"
    if type == 'deg':
        alpha = np.radians(alpha)
    return np.array([radius*np.cos(alpha), radius*np.sin(alpha)])

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
    sign = 1 if v2[1] > 0 else -1
    a_rad = np.arccos(np.clip(np.dot(v1_u, v2_u), -1.0, 1.0)) * sign


    return math.degrees(a_rad)

def give_angle_between(ref , vec):
    sign = 1 if vec[1] > 0 else -1
    dot_p = np.dot(ref,vec)
    value = dot_p/(norm(ref)*norm(vec))
    a_rad = np.arccos(value) *sign
    return math.degrees(a_rad)

# used for live plot the data eith time_axis

#  pyplot.figure(fig_num)
#         pyplot.subplot(121)
#         pyplot.plot(t,x[0])
#         pyplot.draw()
#         for o in range(3):
#             pyplot.subplot(122)
#             pyplot.plot(t,x[1][:,o])
#             pyplot.draw()
t_fig = 0

def live_plot1D(t , x , fig_num =1, row = 1 , col =1 , shape =[1]):
    print ('ploting the data' , x)
    if row ==1 and col ==1:
        assert(len(shape)==1)
        pyplot.figure(fig_num)
        if shape[0] >1:
            for o in range(shape[0]):
                pyplot.plot(t,x[:,o])
                pyplot.draw()
        else:
            pyplot.plot(t,x)
            pyplot.draw()
       
    else:
        pyplot.figure(fig_num)
        plot_no = row*100+col*10
        for n in range(row*col):
            pyplot.subplot(plot_no+n+1)
            if shape[n] > 1:
                for o in range(shape[n]):
                    pyplot.plot(t,x[n][:,o])
                    pyplot.draw()
            else:
                pyplot.plot(t,x[n])
                pyplot.draw()

    global t_fig
    t_fig+=1  
    pyplot.pause(0.000000000000002)

# clearing the plot for the new one
def clear_plot(num = t_fig):
    for i in range(num):
        pyplot.figure(i+1)
        pyplot.clf()
        pyplot.cla()
# normal listener
def listener(topic , node_name, call_back ,msg_type ,anom = False):
    rospy.init_node(node_name,anonymous=anom)
    print(topic,node_name , msg_type ,call_back)
    p = rospy.Subscriber(topic ,msg_type, call_back)
    print(p)
    rospy.spin()
# listener which syncs the listener according to the time stamp

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
    
# changes the position of the linked object to the given co-ords in gazebo
def postion_the_object(x,y,z,rx,ry,rz,rw):
    rospy.wait_for_service('Calibration_Directionality/MoveToPtr' , 15.0)
    try:
        position_the_obj = rospy.ServiceProxy('Calibration_Directionality/MoveToPtr', MoveToPtr)
        pose_ = Pose()
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
    
def plot_directionalitygraph(directionalitygraph):
    angles = []
    total_energyies =[]
    energy_time_variations=[]
    print(directionalitygraph)
    angles_key = np.sort(directionalitygraph.keys())
    for k in angles_key:
        v = np.array(directionalitygraph[k])
        print("the energ tructure", np.shape(v))
        angles.append(k)
        total_energyies.append(v[0,0])
        # if len(v) == 1:
        #     total_energyies.append(v[0,0])
        # else:
        #     total_energyies.append(np.mean(v[:,0]))

    pyplot.figure(1)
    pyplot.title("the directionality graph")
    pyplot.xlabel("the angles ---->")
    pyplot.ylabel("energies --->")
    pyplot.plot(angles,total_energyies)
    pyplot.draw()
    pyplot.pause(0.000000000000002)
# not yet done
def plot_odomVar():
    global OdomVariations
    pass


def test_directionalityDrill(list_points):
    print("drill has started")
    for p in list_points:
        postion_the_object(p[0], p[1], 0.4 , 0 ,0 , 0 , 0)
        rospy.sleep(10)
    print("drill is done", DirectionalityPoints)
    plot_directionalitygraph(DirectionalityPoints)



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
    angle_range= [-45,45]
    list_of_points = get_listofpoints_with_var_angle(angle_range,1,radius=2)
    _Topic = [r'/test/sphere/pose', r'/odom', r'/mybot/laser/polorcloud']
    _nodeName = "eaglesEye"
    _MsgType = [PoseStamped , odom,PointCloud]
    sync_listener(_Topic,_nodeName , call_back2, _MsgType)
    test_directionalityDrill(list_of_points)
    rospy.spin()