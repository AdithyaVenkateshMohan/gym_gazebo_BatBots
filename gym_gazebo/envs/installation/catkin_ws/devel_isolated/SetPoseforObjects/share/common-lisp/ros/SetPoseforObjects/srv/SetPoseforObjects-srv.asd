
(cl:in-package :asdf)

(defsystem "SetPoseforObjects-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
)
  :components ((:file "_package")
    (:file "MoveToPtr" :depends-on ("_package_MoveToPtr"))
    (:file "_package_MoveToPtr" :depends-on ("_package"))
  ))