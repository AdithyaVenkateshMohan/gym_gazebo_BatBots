;; Auto-generated. Do not edit!


(when (boundp 'planning_msgs::PlannerService)
  (if (not (find-package "PLANNING_MSGS"))
    (make-package "PLANNING_MSGS"))
  (shadow 'PlannerService (find-package "PLANNING_MSGS")))
(unless (find-package "PLANNING_MSGS::PLANNERSERVICE")
  (make-package "PLANNING_MSGS::PLANNERSERVICE"))
(unless (find-package "PLANNING_MSGS::PLANNERSERVICEREQUEST")
  (make-package "PLANNING_MSGS::PLANNERSERVICEREQUEST"))
(unless (find-package "PLANNING_MSGS::PLANNERSERVICERESPONSE")
  (make-package "PLANNING_MSGS::PLANNERSERVICERESPONSE"))

(in-package "ROS")

(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))




(defclass planning_msgs::PlannerServiceRequest
  :super ros::object
  :slots (_start_pose _start_velocity _goal_pose _goal_velocity _bounding_box ))

(defmethod planning_msgs::PlannerServiceRequest
  (:init
   (&key
    ((:start_pose __start_pose) (instance geometry_msgs::PoseStamped :init))
    ((:start_velocity __start_velocity) (instance geometry_msgs::Vector3 :init))
    ((:goal_pose __goal_pose) (instance geometry_msgs::PoseStamped :init))
    ((:goal_velocity __goal_velocity) (instance geometry_msgs::Vector3 :init))
    ((:bounding_box __bounding_box) (instance geometry_msgs::Vector3 :init))
    )
   (send-super :init)
   (setq _start_pose __start_pose)
   (setq _start_velocity __start_velocity)
   (setq _goal_pose __goal_pose)
   (setq _goal_velocity __goal_velocity)
   (setq _bounding_box __bounding_box)
   self)
  (:start_pose
   (&rest __start_pose)
   (if (keywordp (car __start_pose))
       (send* _start_pose __start_pose)
     (progn
       (if __start_pose (setq _start_pose (car __start_pose)))
       _start_pose)))
  (:start_velocity
   (&rest __start_velocity)
   (if (keywordp (car __start_velocity))
       (send* _start_velocity __start_velocity)
     (progn
       (if __start_velocity (setq _start_velocity (car __start_velocity)))
       _start_velocity)))
  (:goal_pose
   (&rest __goal_pose)
   (if (keywordp (car __goal_pose))
       (send* _goal_pose __goal_pose)
     (progn
       (if __goal_pose (setq _goal_pose (car __goal_pose)))
       _goal_pose)))
  (:goal_velocity
   (&rest __goal_velocity)
   (if (keywordp (car __goal_velocity))
       (send* _goal_velocity __goal_velocity)
     (progn
       (if __goal_velocity (setq _goal_velocity (car __goal_velocity)))
       _goal_velocity)))
  (:bounding_box
   (&rest __bounding_box)
   (if (keywordp (car __bounding_box))
       (send* _bounding_box __bounding_box)
     (progn
       (if __bounding_box (setq _bounding_box (car __bounding_box)))
       _bounding_box)))
  (:serialization-length
   ()
   (+
    ;; geometry_msgs/PoseStamped _start_pose
    (send _start_pose :serialization-length)
    ;; geometry_msgs/Vector3 _start_velocity
    (send _start_velocity :serialization-length)
    ;; geometry_msgs/PoseStamped _goal_pose
    (send _goal_pose :serialization-length)
    ;; geometry_msgs/Vector3 _goal_velocity
    (send _goal_velocity :serialization-length)
    ;; geometry_msgs/Vector3 _bounding_box
    (send _bounding_box :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; geometry_msgs/PoseStamped _start_pose
       (send _start_pose :serialize s)
     ;; geometry_msgs/Vector3 _start_velocity
       (send _start_velocity :serialize s)
     ;; geometry_msgs/PoseStamped _goal_pose
       (send _goal_pose :serialize s)
     ;; geometry_msgs/Vector3 _goal_velocity
       (send _goal_velocity :serialize s)
     ;; geometry_msgs/Vector3 _bounding_box
       (send _bounding_box :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; geometry_msgs/PoseStamped _start_pose
     (send _start_pose :deserialize buf ptr-) (incf ptr- (send _start_pose :serialization-length))
   ;; geometry_msgs/Vector3 _start_velocity
     (send _start_velocity :deserialize buf ptr-) (incf ptr- (send _start_velocity :serialization-length))
   ;; geometry_msgs/PoseStamped _goal_pose
     (send _goal_pose :deserialize buf ptr-) (incf ptr- (send _goal_pose :serialization-length))
   ;; geometry_msgs/Vector3 _goal_velocity
     (send _goal_velocity :deserialize buf ptr-) (incf ptr- (send _goal_velocity :serialization-length))
   ;; geometry_msgs/Vector3 _bounding_box
     (send _bounding_box :deserialize buf ptr-) (incf ptr- (send _bounding_box :serialization-length))
   ;;
   self)
  )

(intern "*PLANNINGSUCCESS*" (find-package "PLANNING_MSGS::PLANNERSERVICERESPONSE"))
(shadow '*PLANNINGSUCCESS* (find-package "PLANNING_MSGS::PLANNERSERVICERESPONSE"))
(defconstant planning_msgs::PlannerServiceResponse::*PLANNINGSUCCESS* 1)
(intern "*PLANNINGFAILED*" (find-package "PLANNING_MSGS::PLANNERSERVICERESPONSE"))
(shadow '*PLANNINGFAILED* (find-package "PLANNING_MSGS::PLANNERSERVICERESPONSE"))
(defconstant planning_msgs::PlannerServiceResponse::*PLANNINGFAILED* 2)
(defclass planning_msgs::PlannerServiceResponse
  :super ros::object
  :slots (_status _plan ))

(defmethod planning_msgs::PlannerServiceResponse
  (:init
   (&key
    ((:status __status) 0)
    ((:plan __plan) (instance planning_msgs::PlanningResponse :init))
    )
   (send-super :init)
   (setq _status (round __status))
   (setq _plan __plan)
   self)
  (:status
   (&optional __status)
   (if __status (setq _status __status)) _status)
  (:plan
   (&rest __plan)
   (if (keywordp (car __plan))
       (send* _plan __plan)
     (progn
       (if __plan (setq _plan (car __plan)))
       _plan)))
  (:serialization-length
   ()
   (+
    ;; uint8 _status
    1
    ;; planning_msgs/PlanningResponse _plan
    (send _plan :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _status
       (write-byte _status s)
     ;; planning_msgs/PlanningResponse _plan
       (send _plan :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _status
     (setq _status (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; planning_msgs/PlanningResponse _plan
     (send _plan :deserialize buf ptr-) (incf ptr- (send _plan :serialization-length))
   ;;
   self)
  )

(defclass planning_msgs::PlannerService
  :super ros::object
  :slots ())

(setf (get planning_msgs::PlannerService :md5sum-) "e7bc30e0b0a79c76a0ad1244f8818092")
(setf (get planning_msgs::PlannerService :datatype-) "planning_msgs/PlannerService")
(setf (get planning_msgs::PlannerService :request) planning_msgs::PlannerServiceRequest)
(setf (get planning_msgs::PlannerService :response) planning_msgs::PlannerServiceResponse)

(defmethod planning_msgs::PlannerServiceRequest
  (:response () (instance planning_msgs::PlannerServiceResponse :init)))

(setf (get planning_msgs::PlannerServiceRequest :md5sum-) "e7bc30e0b0a79c76a0ad1244f8818092")
(setf (get planning_msgs::PlannerServiceRequest :datatype-) "planning_msgs/PlannerServiceRequest")
(setf (get planning_msgs::PlannerServiceRequest :definition-)
      "
geometry_msgs/PoseStamped start_pose
geometry_msgs/Vector3 start_velocity
geometry_msgs/PoseStamped goal_pose
geometry_msgs/Vector3 goal_velocity
geometry_msgs/Vector3 bounding_box

================================================================================
MSG: geometry_msgs/PoseStamped
# A Pose with reference coordinate frame and timestamp
Header header
Pose pose

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

================================================================================
MSG: geometry_msgs/Pose
# A representation of pose in free space, composed of position and orientation. 
Point position
Quaternion orientation

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w

================================================================================
MSG: geometry_msgs/Vector3
# This represents a vector in free space. 
# It is only meant to represent a direction. Therefore, it does not
# make sense to apply a translation to it (e.g., when applying a 
# generic rigid transformation to a Vector3, tf2 will only apply the
# rotation). If you want your data to be translatable too, use the
# geometry_msgs/Point message instead.

float64 x
float64 y
---

uint8 PLANNINGSUCCESS=1
uint8 PLANNINGFAILED=2

uint8 status
PlanningResponse plan



================================================================================
MSG: planning_msgs/PlanningResponse
float64[] path # m x n matrix
float64[] time # n vector with times
int32 number_primitives  # = n
int32 waypoint_type #polynom, pose etc.
")

(setf (get planning_msgs::PlannerServiceResponse :md5sum-) "e7bc30e0b0a79c76a0ad1244f8818092")
(setf (get planning_msgs::PlannerServiceResponse :datatype-) "planning_msgs/PlannerServiceResponse")
(setf (get planning_msgs::PlannerServiceResponse :definition-)
      "
geometry_msgs/PoseStamped start_pose
geometry_msgs/Vector3 start_velocity
geometry_msgs/PoseStamped goal_pose
geometry_msgs/Vector3 goal_velocity
geometry_msgs/Vector3 bounding_box

================================================================================
MSG: geometry_msgs/PoseStamped
# A Pose with reference coordinate frame and timestamp
Header header
Pose pose

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

================================================================================
MSG: geometry_msgs/Pose
# A representation of pose in free space, composed of position and orientation. 
Point position
Quaternion orientation

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w

================================================================================
MSG: geometry_msgs/Vector3
# This represents a vector in free space. 
# It is only meant to represent a direction. Therefore, it does not
# make sense to apply a translation to it (e.g., when applying a 
# generic rigid transformation to a Vector3, tf2 will only apply the
# rotation). If you want your data to be translatable too, use the
# geometry_msgs/Point message instead.

float64 x
float64 y
---

uint8 PLANNINGSUCCESS=1
uint8 PLANNINGFAILED=2

uint8 status
PlanningResponse plan



================================================================================
MSG: planning_msgs/PlanningResponse
float64[] path # m x n matrix
float64[] time # n vector with times
int32 number_primitives  # = n
int32 waypoint_type #polynom, pose etc.
")



(provide :planning_msgs/PlannerService "e7bc30e0b0a79c76a0ad1244f8818092")


