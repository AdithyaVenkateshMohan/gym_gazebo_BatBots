;; Auto-generated. Do not edit!


(when (boundp 'planning_msgs::WayPointArray)
  (if (not (find-package "PLANNING_MSGS"))
    (make-package "PLANNING_MSGS"))
  (shadow 'WayPointArray (find-package "PLANNING_MSGS")))
(unless (find-package "PLANNING_MSGS::WAYPOINTARRAY")
  (make-package "PLANNING_MSGS::WAYPOINTARRAY"))

(in-package "ROS")
;;//! \htmlinclude WayPointArray.msg.html


(defclass planning_msgs::WayPointArray
  :super ros::object
  :slots (_waypoints ))

(defmethod planning_msgs::WayPointArray
  (:init
   (&key
    ((:waypoints __waypoints) (let (r) (dotimes (i 0) (push (instance planning_msgs::WayPoint :init) r)) r))
    )
   (send-super :init)
   (setq _waypoints __waypoints)
   self)
  (:waypoints
   (&rest __waypoints)
   (if (keywordp (car __waypoints))
       (send* _waypoints __waypoints)
     (progn
       (if __waypoints (setq _waypoints (car __waypoints)))
       _waypoints)))
  (:serialization-length
   ()
   (+
    ;; planning_msgs/WayPoint[] _waypoints
    (apply #'+ (send-all _waypoints :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; planning_msgs/WayPoint[] _waypoints
     (write-long (length _waypoints) s)
     (dolist (elem _waypoints)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; planning_msgs/WayPoint[] _waypoints
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _waypoints (let (r) (dotimes (i n) (push (instance planning_msgs::WayPoint :init) r)) r))
     (dolist (elem- _waypoints)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get planning_msgs::WayPointArray :md5sum-) "016d2aea6905a87be0cba110c54b2674")
(setf (get planning_msgs::WayPointArray :datatype-) "planning_msgs/WayPointArray")
(setf (get planning_msgs::WayPointArray :definition-)
      "WayPoint[] waypoints

================================================================================
MSG: planning_msgs/WayPoint
Header header
float64[] x       # holds motion primitive for the x-axis
float64[] y       # holds motion primitive for the y-axis
float64[] z       # holds motion primitive for the z-axis
float64[] yaw     # holds motion primitive for yaw
int32 type        # defines the type of the waypoint
float64 time      # time for that waypoint. If it is a \"real\" point, this is the time to stay on that point. In case of a polynomial, it is the time [0...time] for which the polynomial is valid

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

")



(provide :planning_msgs/WayPointArray "016d2aea6905a87be0cba110c54b2674")


