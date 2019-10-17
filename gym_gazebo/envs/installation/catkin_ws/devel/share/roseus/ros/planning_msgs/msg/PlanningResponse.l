;; Auto-generated. Do not edit!


(when (boundp 'planning_msgs::PlanningResponse)
  (if (not (find-package "PLANNING_MSGS"))
    (make-package "PLANNING_MSGS"))
  (shadow 'PlanningResponse (find-package "PLANNING_MSGS")))
(unless (find-package "PLANNING_MSGS::PLANNINGRESPONSE")
  (make-package "PLANNING_MSGS::PLANNINGRESPONSE"))

(in-package "ROS")
;;//! \htmlinclude PlanningResponse.msg.html


(defclass planning_msgs::PlanningResponse
  :super ros::object
  :slots (_path _time _number_primitives _waypoint_type ))

(defmethod planning_msgs::PlanningResponse
  (:init
   (&key
    ((:path __path) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:time __time) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:number_primitives __number_primitives) 0)
    ((:waypoint_type __waypoint_type) 0)
    )
   (send-super :init)
   (setq _path __path)
   (setq _time __time)
   (setq _number_primitives (round __number_primitives))
   (setq _waypoint_type (round __waypoint_type))
   self)
  (:path
   (&optional __path)
   (if __path (setq _path __path)) _path)
  (:time
   (&optional __time)
   (if __time (setq _time __time)) _time)
  (:number_primitives
   (&optional __number_primitives)
   (if __number_primitives (setq _number_primitives __number_primitives)) _number_primitives)
  (:waypoint_type
   (&optional __waypoint_type)
   (if __waypoint_type (setq _waypoint_type __waypoint_type)) _waypoint_type)
  (:serialization-length
   ()
   (+
    ;; float64[] _path
    (* 8    (length _path)) 4
    ;; float64[] _time
    (* 8    (length _time)) 4
    ;; int32 _number_primitives
    4
    ;; int32 _waypoint_type
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64[] _path
     (write-long (length _path) s)
     (dotimes (i (length _path))
       (sys::poke (elt _path i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[] _time
     (write-long (length _time) s)
     (dotimes (i (length _time))
       (sys::poke (elt _time i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; int32 _number_primitives
       (write-long _number_primitives s)
     ;; int32 _waypoint_type
       (write-long _waypoint_type s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64[] _path
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _path (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _path i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;; float64[] _time
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _time (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _time i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;; int32 _number_primitives
     (setq _number_primitives (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _waypoint_type
     (setq _waypoint_type (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get planning_msgs::PlanningResponse :md5sum-) "cb7dd897470b7e4529896a33d9fa75c9")
(setf (get planning_msgs::PlanningResponse :datatype-) "planning_msgs/PlanningResponse")
(setf (get planning_msgs::PlanningResponse :definition-)
      "float64[] path # m x n matrix
float64[] time # n vector with times
int32 number_primitives  # = n
int32 waypoint_type #polynom, pose etc.

")



(provide :planning_msgs/PlanningResponse "cb7dd897470b7e4529896a33d9fa75c9")


