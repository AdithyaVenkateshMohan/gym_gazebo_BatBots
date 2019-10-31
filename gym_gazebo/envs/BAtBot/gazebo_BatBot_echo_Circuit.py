import gym
import rospy
import roslaunch
import time
import numpy as np

from gym import utils, spaces
from gym_gazebo.envs import gazebo_env
from geometry_msgs.msg import Pose, Twist
from std_msgs.msg import Empty , String
from std_srvs.srv import Empty
# this the echogenration lib which will be used to convert the point cloud data to 
from mybot_sonar import sonar_gen 
from ..gazeboconnection import GazeboConnection


from sensor_msgs.msg import LaserScan
from sensor_msgs.msg import PointCloud

from gym.utils import seeding
import copy

class Gazebo_BatBot_echo_Circuit_Env(gazebo_env.GazeboEnv):
    def __init__(self):
        
        gazebo_env.GazeboEnv.__init__(self, "GazeboBATBoT_Sonar_v0.launch")
        # action velocity that needs to published for sending the velocity info to the sim
        self.action_topic = '/cmd_vel' # switch the topic if the controller is subscribing to a different topic
        # action velocity pub
        self.vel_pub = rospy.Publisher(self.action_topic , Twist, queue_size = 10)
        
        # defining the default velocity here it is the zero velocity
        # at rest or bring the robot to rest this velocity will be published 

        self.default_velocity = Twist()

        self.default_velocity.linear.x =0
        self.default_velocity.linear.y =0
        self.default_velocity.linear.z =0
        self.default_velocity.angular.x =0
        self.default_velocity.angular.y =0
        self.default_velocity.angular.z =0

        # actions timestep which the time for which the action selected is excuted
        self.action_timeStep = 0.5
        # actions velocity is the velocity at which selected action is excuted
        self.action_velocity = 0.05

        #common timeout constant that we wait for the data 
        self.timeout = 5
        
        #encoded actions
        self.straight = 0
        self.back = 1
        self.right = 2
        self.left = 3
        #param for calulating rewards
        # so it's good for the robot to stay from 4 to 6 units away from the wall
        # for the wall following behav not more not less 

        self.distance_fromWall = 0.7
        self.deltaDistance = 1
        # defining the the reward range
        self.reward_range = (-np.Inf , np.Inf)
        # defining the action_space
        self.action_space = spaces.Discrete(4)
        # storing the function pointer for the echo_genration
        self.echoes_genration = sonar_gen.echo_genration_for_observation 
        # observation space is defined here
        self.observation_space = spaces.Box(low = -np.Inf , high = np.Inf , shape = (1,28000))

        # gazebo connection is established
        self.gazebo_pipe = GazeboConnection() 

        #storing the topic for the observation and reward signals
        # which is to be subscribed and read for getting the data from the sim
        self.observation_topic = '/mybot/laser/polorcloud'
        self.rewardsignal_topic = '/scan'
        self.collision_topic = '/mybot/collision'
        
        self.seed = self._seed()
    
    def _seed(self, seed=None):
        self.np_random , seed = seeding.np_random(seed)
        return [seed]
    
    def step(self, action):
        # unpause the sim 
        self.gazebo_pipe.resumeSim()
        # velocity to be is selected according to the action variable
        self.velocity_toBe = copy.deepcopy(self.default_velocity)
        if (action == self.straight):
            self.velocity_toBe.linear.x = self.action_velocity
        else:
            if(action == self.back):
                self.velocity_toBe.linear.x = -self.action_velocity
            else:
                if(action == self.right):
                    self.velocity_toBe.angular.z = -self.action_velocity
                else:
                    if(action == self.left):
                        self.velocity_toBe.angular.z = self.action_velocity
        # publishing the selected velocity
        self.vel_pub.publish(self.velocity_toBe)
        # sleep for action time step
        rospy.sleep(self.action_timeStep)
        self.vel_pub.publish(self.default_velocity)
        
        echo , time  = self.get_observationEnv()

        reward = self.get_reward()
        # pause the sim 
        self.gazebo_pipe.pauseSim()

        # do somethng abt done
        done = False

        return echo , reward , done , {}
    
    def reset(self):
        #resets the simulator to the default starting case
        self.gazebo_pipe.resetSim()
        #unpause the sim 
        self.gazebo_pipe.resumeSim()
        #checks all the connections of the pub
        self.checkalltopics_pubConnections()
        #resetting velocities just in case
        self.reset_velocities()
        # getting the first observation
        observation = self.get_observationEnv()
        # the gazebo engine is paused 
        self.gazebo_pipe.pauseSim()
        
        return observation
    
    def checkalltopics_pubConnections(self):
        rate = rospy.Rate(10)

        while self.vel_pub.get_num_connections() == 0:
            rospy.loginfo("the vel_pub has zero connections so wait")
            rate.sleep(10)

        rospy.loginfo("velocity vel_pub connection with the gazebo sim is connected succesfully")

    def reset_velocities(self):
        self.vel_pub.publish(self.default_velocity)
        rospy.sleep(self.action_timeStep)
    
    def get_observationEnv(self):
        Cloudobservation = None
        while Cloudobservation is None:
            try:
                Cloudobservation  = rospy.wait_for_message(self.observation_topic , PointCloud , timeout= self.timeout)
            except:
                rospy.loginfo("exception raised at getting observation of the polar cloud from topic", self.observation_topic)
        print("cloud points used for observation ", Cloudobservation.points)
        echo_pulse,echo_time = self.echoes_genration(Cloudobservation.points)

        return echo_pulse, echo_time

    # this is where reward the agent should get is calulated 
    def get_reward(self):
        #this is not yet done have to work on reward function
        AVOIDANCE_DISTANCE = self.distance_fromWall
        LaserscanRange = None
        while LaserscanRange is None:
            try:
                LaserscanRange  = rospy.wait_for_message(self.rewardsignal_topic , LaserScan , timeout= self.timeout)
            except:
                rospy.loginfo("exception raised at getting laser scan from topic", self.observation_topic)
            
        ranges = LaserscanRange.ranges
        print("the ranges of the bat", ranges)
        minRange = -1
        for r in ranges:
            if minRange == -1:
                minRange = r
            elif minRange > r:
                minRange = r
        print("the nearest obstacle is at ", minRange)
        if minRange < AVOIDANCE_DISTANCE:
            reward = 1
        else:
            reward =-10

        
        #reward = 1
        return reward
    
         