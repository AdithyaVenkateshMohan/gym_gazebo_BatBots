; Auto-generated. Do not edit!


(cl:in-package yocs_msgs-msg)


;//! \htmlinclude DockingInteractorFeedback.msg.html

(cl:defclass <DockingInteractorFeedback> (roslisp-msg-protocol:ros-message)
  ((level
    :reader level
    :initarg :level
    :type cl:fixnum
    :initform 0)
   (message
    :reader message
    :initarg :message
    :type cl:string
    :initform ""))
)

(cl:defclass DockingInteractorFeedback (<DockingInteractorFeedback>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <DockingInteractorFeedback>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'DockingInteractorFeedback)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name yocs_msgs-msg:<DockingInteractorFeedback> is deprecated: use yocs_msgs-msg:DockingInteractorFeedback instead.")))

(cl:ensure-generic-function 'level-val :lambda-list '(m))
(cl:defmethod level-val ((m <DockingInteractorFeedback>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader yocs_msgs-msg:level-val is deprecated.  Use yocs_msgs-msg:level instead.")
  (level m))

(cl:ensure-generic-function 'message-val :lambda-list '(m))
(cl:defmethod message-val ((m <DockingInteractorFeedback>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader yocs_msgs-msg:message-val is deprecated.  Use yocs_msgs-msg:message instead.")
  (message m))
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql '<DockingInteractorFeedback>)))
    "Constants for message type '<DockingInteractorFeedback>"
  '((:DEBUG . 1)
    (:INFO . 2)
    (:WARN . 4)
    (:ERROR . 8))
)
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql 'DockingInteractorFeedback)))
    "Constants for message type 'DockingInteractorFeedback"
  '((:DEBUG . 1)
    (:INFO . 2)
    (:WARN . 4)
    (:ERROR . 8))
)
(cl:defmethod roslisp-msg-protocol:serialize ((msg <DockingInteractorFeedback>) ostream)
  "Serializes a message object of type '<DockingInteractorFeedback>"
  (cl:let* ((signed (cl:slot-value msg 'level)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'message))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'message))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <DockingInteractorFeedback>) istream)
  "Deserializes a message object of type '<DockingInteractorFeedback>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'level) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'message) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'message) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<DockingInteractorFeedback>)))
  "Returns string type for a message object of type '<DockingInteractorFeedback>"
  "yocs_msgs/DockingInteractorFeedback")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'DockingInteractorFeedback)))
  "Returns string type for a message object of type 'DockingInteractorFeedback"
  "yocs_msgs/DockingInteractorFeedback")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<DockingInteractorFeedback>)))
  "Returns md5sum for a message object of type '<DockingInteractorFeedback>"
  "b042f523c61fe97bdf0d4da2f2289c63")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'DockingInteractorFeedback)))
  "Returns md5sum for a message object of type 'DockingInteractorFeedback"
  "b042f523c61fe97bdf0d4da2f2289c63")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<DockingInteractorFeedback>)))
  "Returns full string definition for message of type '<DockingInteractorFeedback>"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%# Feedback~%int8 level~%~%int8 DEBUG=1~%int8 INFO=2~%int8 WARN=4~%int8 ERROR=8~%~%string message~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'DockingInteractorFeedback)))
  "Returns full string definition for message of type 'DockingInteractorFeedback"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%# Feedback~%int8 level~%~%int8 DEBUG=1~%int8 INFO=2~%int8 WARN=4~%int8 ERROR=8~%~%string message~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <DockingInteractorFeedback>))
  (cl:+ 0
     1
     4 (cl:length (cl:slot-value msg 'message))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <DockingInteractorFeedback>))
  "Converts a ROS message object to a list"
  (cl:list 'DockingInteractorFeedback
    (cl:cons ':level (level msg))
    (cl:cons ':message (message msg))
))
