;; Auto-generated. Do not edit!


(when (boundp 'mav_msgs::CommandMotorSpeed)
  (if (not (find-package "MAV_MSGS"))
    (make-package "MAV_MSGS"))
  (shadow 'CommandMotorSpeed (find-package "MAV_MSGS")))
(unless (find-package "MAV_MSGS::COMMANDMOTORSPEED")
  (make-package "MAV_MSGS::COMMANDMOTORSPEED"))

(in-package "ROS")
;;//! \htmlinclude CommandMotorSpeed.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass mav_msgs::CommandMotorSpeed
  :super ros::object
  :slots (_header _motor_speed ))

(defmethod mav_msgs::CommandMotorSpeed
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:motor_speed __motor_speed) (make-array 0 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _header __header)
   (setq _motor_speed __motor_speed)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:motor_speed
   (&optional __motor_speed)
   (if __motor_speed (setq _motor_speed __motor_speed)) _motor_speed)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float64[] _motor_speed
    (* 8    (length _motor_speed)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float64[] _motor_speed
     (write-long (length _motor_speed) s)
     (dotimes (i (length _motor_speed))
       (sys::poke (elt _motor_speed i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float64[] _motor_speed
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _motor_speed (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _motor_speed i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;;
   self)
  )

(setf (get mav_msgs::CommandMotorSpeed :md5sum-) "061082200f78e4ff571a825255200c0d")
(setf (get mav_msgs::CommandMotorSpeed :datatype-) "mav_msgs/CommandMotorSpeed")
(setf (get mav_msgs::CommandMotorSpeed :definition-)
      "Header header

float64[] motor_speed  # motor speed [rad/s]

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



(provide :mav_msgs/CommandMotorSpeed "061082200f78e4ff571a825255200c0d")


