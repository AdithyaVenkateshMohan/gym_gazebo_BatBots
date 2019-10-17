;; Auto-generated. Do not edit!


(when (boundp 'mav_msgs::CommandRateThrust)
  (if (not (find-package "MAV_MSGS"))
    (make-package "MAV_MSGS"))
  (shadow 'CommandRateThrust (find-package "MAV_MSGS")))
(unless (find-package "MAV_MSGS::COMMANDRATETHRUST")
  (make-package "MAV_MSGS::COMMANDRATETHRUST"))

(in-package "ROS")
;;//! \htmlinclude CommandRateThrust.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass mav_msgs::CommandRateThrust
  :super ros::object
  :slots (_header _angular_rates _thrust ))

(defmethod mav_msgs::CommandRateThrust
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:angular_rates __angular_rates) (instance geometry_msgs::Vector3 :init))
    ((:thrust __thrust) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _angular_rates __angular_rates)
   (setq _thrust (float __thrust))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:angular_rates
   (&rest __angular_rates)
   (if (keywordp (car __angular_rates))
       (send* _angular_rates __angular_rates)
     (progn
       (if __angular_rates (setq _angular_rates (car __angular_rates)))
       _angular_rates)))
  (:thrust
   (&optional __thrust)
   (if __thrust (setq _thrust __thrust)) _thrust)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; geometry_msgs/Vector3 _angular_rates
    (send _angular_rates :serialization-length)
    ;; float64 _thrust
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; geometry_msgs/Vector3 _angular_rates
       (send _angular_rates :serialize s)
     ;; float64 _thrust
       (sys::poke _thrust (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; geometry_msgs/Vector3 _angular_rates
     (send _angular_rates :deserialize buf ptr-) (incf ptr- (send _angular_rates :serialization-length))
   ;; float64 _thrust
     (setq _thrust (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get mav_msgs::CommandRateThrust :md5sum-) "64d07d2777f099a628b8b9dedf625a3d")
(setf (get mav_msgs::CommandRateThrust :datatype-) "mav_msgs/CommandRateThrust")
(setf (get mav_msgs::CommandRateThrust :definition-)
      "Header header

# Message should be specified in the body coordinate frame.

# We use the coordinate frames with the following convention:
#   x: forward
#   y: left
#   z: up

geometry_msgs/Vector3 angular_rates  # roll-, pitch-, yaw-rate around body axes [rad/s]
float64 thrust                       # thrust [N]

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
MSG: geometry_msgs/Vector3
# This represents a vector in free space. 
# It is only meant to represent a direction. Therefore, it does not
# make sense to apply a translation to it (e.g., when applying a 
# generic rigid transformation to a Vector3, tf2 will only apply the
# rotation). If you want your data to be translatable too, use the
# geometry_msgs/Point message instead.

float64 x
float64 y
float64 z
")



(provide :mav_msgs/CommandRateThrust "64d07d2777f099a628b8b9dedf625a3d")


