;; Auto-generated. Do not edit!


(when (boundp 'mav_msgs::CommandAttitudeThrust)
  (if (not (find-package "MAV_MSGS"))
    (make-package "MAV_MSGS"))
  (shadow 'CommandAttitudeThrust (find-package "MAV_MSGS")))
(unless (find-package "MAV_MSGS::COMMANDATTITUDETHRUST")
  (make-package "MAV_MSGS::COMMANDATTITUDETHRUST"))

(in-package "ROS")
;;//! \htmlinclude CommandAttitudeThrust.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass mav_msgs::CommandAttitudeThrust
  :super ros::object
  :slots (_header _attitude _thrust ))

(defmethod mav_msgs::CommandAttitudeThrust
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:attitude __attitude) (instance geometry_msgs::Quaternion :init))
    ((:thrust __thrust) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _attitude __attitude)
   (setq _thrust (float __thrust))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:attitude
   (&rest __attitude)
   (if (keywordp (car __attitude))
       (send* _attitude __attitude)
     (progn
       (if __attitude (setq _attitude (car __attitude)))
       _attitude)))
  (:thrust
   (&optional __thrust)
   (if __thrust (setq _thrust __thrust)) _thrust)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; geometry_msgs/Quaternion _attitude
    (send _attitude :serialization-length)
    ;; float64 _thrust
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; geometry_msgs/Quaternion _attitude
       (send _attitude :serialize s)
     ;; float64 _thrust
       (sys::poke _thrust (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; geometry_msgs/Quaternion _attitude
     (send _attitude :deserialize buf ptr-) (incf ptr- (send _attitude :serialization-length))
   ;; float64 _thrust
     (setq _thrust (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get mav_msgs::CommandAttitudeThrust :md5sum-) "d4f9a597f2a4d4943a3be2c915e3f97d")
(setf (get mav_msgs::CommandAttitudeThrust :datatype-) "mav_msgs/CommandAttitudeThrust")
(setf (get mav_msgs::CommandAttitudeThrust :definition-)
      "Header header

# Message should be specified in the world coordinate frame.

geometry_msgs/Quaternion attitude
float64 thrust    # thrust [N]

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
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w

")



(provide :mav_msgs/CommandAttitudeThrust "d4f9a597f2a4d4943a3be2c915e3f97d")


