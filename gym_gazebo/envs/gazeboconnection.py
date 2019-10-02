import rospy
from std_srvs.srv import Empty

class GazeboConnection():
    
    def __init__(self):
        self.pause_srv = '/gazebo/pause_physics'
        self.pause_sim = rospy.ServiceProxy(self.pause_srv, Empty)
        self.resume_srv = '/gazebo/unpause_physics'
        self.resume_sim = rospy.ServiceProxy(self.resume_srv, Empty)
        self.reset_srv = '/gazebo/reset_simulation'
        self.reset_sim = rospy.ServiceProxy(self.reset_srv, Empty)
        self.timeout = 5
    
    def pauseSim(self):
        rospy.wait_for_service(self.pause_srv, self.timeout)
        try:
            self.pause_sim()
        except rospy.ServiceException:
            print("some issue in pause sim service")

    def resumeSim(self):
        rospy.wait_for_service(self.resume_srv, self.timeout)
        try:
            self.resume_sim()
        except rospy.ServiceException:
            print("some issue in resume sim service")

    def resetSim(self):
        rospy.wait_for_service(self.reset_srv, self.timeout)
        try:
            self.reset_sim()
        except rospy.ServiceException:
            print("some issue in reset sim service")