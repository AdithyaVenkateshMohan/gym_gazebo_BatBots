;; Auto-generated. Do not edit!


(when (boundp 'yocs_msgs::LocalizeFeedback)
  (if (not (find-package "YOCS_MSGS"))
    (make-package "YOCS_MSGS"))
  (shadow 'LocalizeFeedback (find-package "YOCS_MSGS")))
(unless (find-package "YOCS_MSGS::LOCALIZEFEEDBACK")
  (make-package "YOCS_MSGS::LOCALIZEFEEDBACK"))

(in-package "ROS")
;;//! \htmlinclude LocalizeFeedback.msg.html


(defclass yocs_msgs::LocalizeFeedback
  :super ros::object
  :slots (_message ))

(defmethod yocs_msgs::LocalizeFeedback
  (:init
   (&key
    ((:message __message) "")
    )
   (send-super :init)
   (setq _message (string __message))
   self)
  (:message
   (&optional __message)
   (if __message (setq _message __message)) _message)
  (:serialization-length
   ()
   (+
    ;; string _message
    4 (length _message)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _message
       (write-long (length _message) s) (princ _message s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _message
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _message (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get yocs_msgs::LocalizeFeedback :md5sum-) "5f003d6bcc824cbd51361d66d8e4f76c")
(setf (get yocs_msgs::LocalizeFeedback :datatype-) "yocs_msgs/LocalizeFeedback")
(setf (get yocs_msgs::LocalizeFeedback :definition-)
      "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======
string message


")



(provide :yocs_msgs/LocalizeFeedback "5f003d6bcc824cbd51361d66d8e4f76c")


