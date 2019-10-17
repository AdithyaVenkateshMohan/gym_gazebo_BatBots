; Auto-generated. Do not edit!


(cl:in-package SetPoseforObjects-srv)


;//! \htmlinclude MoveToPtr-request.msg.html

(cl:defclass <MoveToPtr-request> (roslisp-msg-protocol:ros-message)
  ((px
    :reader px
    :initarg :px
    :type geometry_msgs-msg:Pose
    :initform (cl:make-instance 'geometry_msgs-msg:Pose)))
)

(cl:defclass MoveToPtr-request (<MoveToPtr-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MoveToPtr-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MoveToPtr-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name SetPoseforObjects-srv:<MoveToPtr-request> is deprecated: use SetPoseforObjects-srv:MoveToPtr-request instead.")))

(cl:ensure-generic-function 'px-val :lambda-list '(m))
(cl:defmethod px-val ((m <MoveToPtr-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader SetPoseforObjects-srv:px-val is deprecated.  Use SetPoseforObjects-srv:px instead.")
  (px m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MoveToPtr-request>) ostream)
  "Serializes a message object of type '<MoveToPtr-request>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'px) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MoveToPtr-request>) istream)
  "Deserializes a message object of type '<MoveToPtr-request>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'px) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MoveToPtr-request>)))
  "Returns string type for a service object of type '<MoveToPtr-request>"
  "SetPoseforObjects/MoveToPtrRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MoveToPtr-request)))
  "Returns string type for a service object of type 'MoveToPtr-request"
  "SetPoseforObjects/MoveToPtrRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MoveToPtr-request>)))
  "Returns md5sum for a message object of type '<MoveToPtr-request>"
  "fc1a53656a802a1870723eb9f98ec389")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MoveToPtr-request)))
  "Returns md5sum for a message object of type 'MoveToPtr-request"
  "fc1a53656a802a1870723eb9f98ec389")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MoveToPtr-request>)))
  "Returns full string definition for message of type '<MoveToPtr-request>"
  (cl:format cl:nil "geometry_msgs/Pose px~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MoveToPtr-request)))
  "Returns full string definition for message of type 'MoveToPtr-request"
  (cl:format cl:nil "geometry_msgs/Pose px~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MoveToPtr-request>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'px))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MoveToPtr-request>))
  "Converts a ROS message object to a list"
  (cl:list 'MoveToPtr-request
    (cl:cons ':px (px msg))
))
;//! \htmlinclude MoveToPtr-response.msg.html

(cl:defclass <MoveToPtr-response> (roslisp-msg-protocol:ros-message)
  ((done
    :reader done
    :initarg :done
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass MoveToPtr-response (<MoveToPtr-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MoveToPtr-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MoveToPtr-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name SetPoseforObjects-srv:<MoveToPtr-response> is deprecated: use SetPoseforObjects-srv:MoveToPtr-response instead.")))

(cl:ensure-generic-function 'done-val :lambda-list '(m))
(cl:defmethod done-val ((m <MoveToPtr-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader SetPoseforObjects-srv:done-val is deprecated.  Use SetPoseforObjects-srv:done instead.")
  (done m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MoveToPtr-response>) ostream)
  "Serializes a message object of type '<MoveToPtr-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'done) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MoveToPtr-response>) istream)
  "Deserializes a message object of type '<MoveToPtr-response>"
    (cl:setf (cl:slot-value msg 'done) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MoveToPtr-response>)))
  "Returns string type for a service object of type '<MoveToPtr-response>"
  "SetPoseforObjects/MoveToPtrResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MoveToPtr-response)))
  "Returns string type for a service object of type 'MoveToPtr-response"
  "SetPoseforObjects/MoveToPtrResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MoveToPtr-response>)))
  "Returns md5sum for a message object of type '<MoveToPtr-response>"
  "fc1a53656a802a1870723eb9f98ec389")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MoveToPtr-response)))
  "Returns md5sum for a message object of type 'MoveToPtr-response"
  "fc1a53656a802a1870723eb9f98ec389")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MoveToPtr-response>)))
  "Returns full string definition for message of type '<MoveToPtr-response>"
  (cl:format cl:nil "bool done~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MoveToPtr-response)))
  "Returns full string definition for message of type 'MoveToPtr-response"
  (cl:format cl:nil "bool done~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MoveToPtr-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MoveToPtr-response>))
  "Converts a ROS message object to a list"
  (cl:list 'MoveToPtr-response
    (cl:cons ':done (done msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'MoveToPtr)))
  'MoveToPtr-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'MoveToPtr)))
  'MoveToPtr-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MoveToPtr)))
  "Returns string type for a service object of type '<MoveToPtr>"
  "SetPoseforObjects/MoveToPtr")