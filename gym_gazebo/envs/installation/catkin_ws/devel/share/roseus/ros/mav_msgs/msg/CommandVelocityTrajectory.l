;; Auto-generated. Do not edit!


(when (boundp 'mav_msgs::CommandVelocityTrajectory)
  (if (not (find-package "MAV_MSGS"))
    (make-package "MAV_MSGS"))
  (shadow 'CommandVelocityTrajectory (find-package "MAV_MSGS")))
(unless (find-package "MAV_MSGS::COMMANDVELOCITYTRAJECTORY")
  (make-package "MAV_MSGS::COMMANDVELOCITYTRAJECTORY"))

(in-package "ROS")
;;//! \htmlinclude CommandVelocityTrajectory.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass mav_msgs::CommandVelocityTrajectory
  :super ros::object
  :slots (_header _velocity _acceleration _jerk _snap _yaw_rate ))

(defmethod mav_msgs::CommandVelocityTrajectory
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:velocity __velocity) (instance geometry_msgs::Vector3 :init))
    ((:acceleration __acceleration) (instance geometry_msgs::Vector3 :init))
    ((:jerk __jerk) (instance geometry_msgs::Vector3 :init))
    ((:snap __snap) (instance geometry_msgs::Vector3 :init))
    ((:yaw_rate __yaw_rate) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _velocity __velocity)
   (setq _acceleration __acceleration)
   (setq _jerk __jerk)
   (setq _snap __snap)
   (setq _yaw_rate (float __yaw_rate))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:velocity
   (&rest __velocity)
   (if (keywordp (car __velocity))
       (send* _velocity __velocity)
     (progn
       (if __velocity (setq _velocity (car __velocity)))
       _velocity)))
  (:acceleration
   (&rest __acceleration)
   (if (keywordp (car __acceleration))
       (send* _acceleration __acceleration)
     (progn
       (if __acceleration (setq _acceleration (car __acceleration)))
       _acceleration)))
  (:jerk
   (&rest __jerk)
   (if (keywordp (car __jerk))
       (send* _jerk __jerk)
     (progn
       (if __jerk (setq _jerk (car __jerk)))
       _jerk)))
  (:snap
   (&rest __snap)
   (if (keywordp (car __snap))
       (send* _snap __snap)
     (progn
       (if __snap (setq _snap (car __snap)))
       _snap)))
  (:yaw_rate
   (&optional __yaw_rate)
   (if __yaw_rate (setq _yaw_rate __yaw_rate)) _yaw_rate)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; geometry_msgs/Vector3 _velocity
    (send _velocity :serialization-length)
    ;; geometry_msgs/Vector3 _acceleration
    (send _acceleration :serialization-length)
    ;; geometry_msgs/Vector3 _jerk
    (send _jerk :serialization-length)
    ;; geometry_msgs/Vector3 _snap
    (send _snap :serialization-length)
    ;; float64 _yaw_rate
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; geometry_msgs/Vector3 _velocity
       (send _velocity :serialize s)
     ;; geometry_msgs/Vector3 _acceleration
       (send _acceleration :serialize s)
     ;; geometry_msgs/Vector3 _jerk
       (send _jerk :serialize s)
     ;; geometry_msgs/Vector3 _snap
       (send _snap :serialize s)
     ;; float64 _yaw_rate
       (sys::poke _yaw_rate (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; geometry_msgs/Vector3 _velocity
     (send _velocity :deserialize buf ptr-) (incf ptr- (send _velocity :serialization-length))
   ;; geometry_msgs/Vector3 _acceleration
     (send _acceleration :deserialize buf ptr-) (incf ptr- (send _acceleration :serialization-length))
   ;; geometry_msgs/Vector3 _jerk
     (send _jerk :deserialize buf ptr-) (incf ptr- (send _jerk :serialization-length))
   ;; geometry_msgs/Vector3 _snap
     (send _snap :deserialize buf ptr-) (incf ptr- (send _snap :serialization-length))
   ;; float64 _yaw_rate
     (setq _yaw_rate (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get mav_msgs::CommandVelocityTrajectory :md5sum-) "7cfd9889bf7fbc922ff641f0b721492c")
(setf (get mav_msgs::CommandVelocityTrajectory :datatype-) "mav_msgs/CommandVelocityTrajectory")
(setf (get mav_msgs::CommandVelocityTrajectory :definition-)
      "Header header

# Message should be expressed in the frame_id specified in the header.

geometry_msgs/Vector3 velocity      # [m/s]
geometry_msgs/Vector3 acceleration  # [m/s^2]
geometry_msgs/Vector3 jerk          # [m/s^3]
geometry_msgs/Vector3 snap          # [m/s^4]
float64 yaw_rate                    # [rad/s]

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



(provide :mav_msgs/CommandVelocityTrajectory "7cfd9889bf7fbc922ff641f0b721492c")


