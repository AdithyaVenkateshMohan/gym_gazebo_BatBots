;; Auto-generated. Do not edit!


(when (boundp 'planning_msgs::WaypointType)
  (if (not (find-package "PLANNING_MSGS"))
    (make-package "PLANNING_MSGS"))
  (shadow 'WaypointType (find-package "PLANNING_MSGS")))
(unless (find-package "PLANNING_MSGS::WAYPOINTTYPE")
  (make-package "PLANNING_MSGS::WAYPOINTTYPE"))

(in-package "ROS")
;;//! \htmlinclude WaypointType.msg.html


(intern "*POSE*" (find-package "PLANNING_MSGS::WAYPOINTTYPE"))
(shadow '*POSE* (find-package "PLANNING_MSGS::WAYPOINTTYPE"))
(defconstant planning_msgs::WaypointType::*POSE* 1)
(intern "*POLYNOMIAL*" (find-package "PLANNING_MSGS::WAYPOINTTYPE"))
(shadow '*POLYNOMIAL* (find-package "PLANNING_MSGS::WAYPOINTTYPE"))
(defconstant planning_msgs::WaypointType::*POLYNOMIAL* 2)
(intern "*POLYNOMIAL_10*" (find-package "PLANNING_MSGS::WAYPOINTTYPE"))
(shadow '*POLYNOMIAL_10* (find-package "PLANNING_MSGS::WAYPOINTTYPE"))
(defconstant planning_msgs::WaypointType::*POLYNOMIAL_10* 210)
(intern "*POLYNOMIAL_12*" (find-package "PLANNING_MSGS::WAYPOINTTYPE"))
(shadow '*POLYNOMIAL_12* (find-package "PLANNING_MSGS::WAYPOINTTYPE"))
(defconstant planning_msgs::WaypointType::*POLYNOMIAL_12* 212)
(defclass planning_msgs::WaypointType
  :super ros::object
  :slots ())

(defmethod planning_msgs::WaypointType
  (:init
   (&key
    )
   (send-super :init)
   self)
  (:serialization-length
   ()
   (+
    0
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;;
   self)
  )

(setf (get planning_msgs::WaypointType :md5sum-) "ab2317fe7228faf4b4c92459f5353963")
(setf (get planning_msgs::WaypointType :datatype-) "planning_msgs/WaypointType")
(setf (get planning_msgs::WaypointType :definition-)
      "int32 POSE=1
int32 POLYNOMIAL=2 # stores the coefficients of a polynomial in the waypoint fields. Coefficients are stored in increasing order, i.e. c0 + c1*t + c2*t^2 ...
int32 POLYNOMIAL_10=210 # polynomial with 10 coefficients, i.e. 9th order
int32 POLYNOMIAL_12=212 # polynomial with 12 coefficients, i.e. 11th order

")



(provide :planning_msgs/WaypointType "ab2317fe7228faf4b4c92459f5353963")


