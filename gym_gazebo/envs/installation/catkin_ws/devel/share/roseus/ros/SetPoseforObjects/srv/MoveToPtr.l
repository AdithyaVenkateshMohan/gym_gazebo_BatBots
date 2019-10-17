;; Auto-generated. Do not edit!


(when (boundp 'SetPoseforObjects::MoveToPtr)
  (if (not (find-package "SETPOSEFOROBJECTS"))
    (make-package "SETPOSEFOROBJECTS"))
  (shadow 'MoveToPtr (find-package "SETPOSEFOROBJECTS")))
(unless (find-package "SETPOSEFOROBJECTS::MOVETOPTR")
  (make-package "SETPOSEFOROBJECTS::MOVETOPTR"))
(unless (find-package "SETPOSEFOROBJECTS::MOVETOPTRREQUEST")
  (make-package "SETPOSEFOROBJECTS::MOVETOPTRREQUEST"))
(unless (find-package "SETPOSEFOROBJECTS::MOVETOPTRRESPONSE")
  (make-package "SETPOSEFOROBJECTS::MOVETOPTRRESPONSE"))

(in-package "ROS")

(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))




(defclass SetPoseforObjects::MoveToPtrRequest
  :super ros::object
  :slots (_px ))

(defmethod SetPoseforObjects::MoveToPtrRequest
  (:init
   (&key
    ((:px __px) (instance geometry_msgs::Pose :init))
    )
   (send-super :init)
   (setq _px __px)
   self)
  (:px
   (&rest __px)
   (if (keywordp (car __px))
       (send* _px __px)
     (progn
       (if __px (setq _px (car __px)))
       _px)))
  (:serialization-length
   ()
   (+
    ;; geometry_msgs/Pose _px
    (send _px :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; geometry_msgs/Pose _px
       (send _px :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; geometry_msgs/Pose _px
     (send _px :deserialize buf ptr-) (incf ptr- (send _px :serialization-length))
   ;;
   self)
  )

(defclass SetPoseforObjects::MoveToPtrResponse
  :super ros::object
  :slots (_done ))

(defmethod SetPoseforObjects::MoveToPtrResponse
  (:init
   (&key
    ((:done __done) nil)
    )
   (send-super :init)
   (setq _done __done)
   self)
  (:done
   (&optional __done)
   (if __done (setq _done __done)) _done)
  (:serialization-length
   ()
   (+
    ;; bool _done
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _done
       (if _done (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _done
     (setq _done (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass SetPoseforObjects::MoveToPtr
  :super ros::object
  :slots ())

(setf (get SetPoseforObjects::MoveToPtr :md5sum-) "fc1a53656a802a1870723eb9f98ec389")
(setf (get SetPoseforObjects::MoveToPtr :datatype-) "SetPoseforObjects/MoveToPtr")
(setf (get SetPoseforObjects::MoveToPtr :request) SetPoseforObjects::MoveToPtrRequest)
(setf (get SetPoseforObjects::MoveToPtr :response) SetPoseforObjects::MoveToPtrResponse)

(defmethod SetPoseforObjects::MoveToPtrRequest
  (:response () (instance SetPoseforObjects::MoveToPtrResponse :init)))

(setf (get SetPoseforObjects::MoveToPtrRequest :md5sum-) "fc1a53656a802a1870723eb9f98ec389")
(setf (get SetPoseforObjects::MoveToPtrRequest :datatype-) "SetPoseforObjects/MoveToPtrRequest")
(setf (get SetPoseforObjects::MoveToPtrRequest :definition-)
      "geometry_msgs/Pose px

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
---
bool done

")

(setf (get SetPoseforObjects::MoveToPtrResponse :md5sum-) "fc1a53656a802a1870723eb9f98ec389")
(setf (get SetPoseforObjects::MoveToPtrResponse :datatype-) "SetPoseforObjects/MoveToPtrResponse")
(setf (get SetPoseforObjects::MoveToPtrResponse :definition-)
      "geometry_msgs/Pose px

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
---
bool done

")



(provide :SetPoseforObjects/MoveToPtr "fc1a53656a802a1870723eb9f98ec389")


