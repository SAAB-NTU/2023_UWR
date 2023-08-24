
(cl:in-package :asdf)

(defsystem "logger-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "Motor" :depends-on ("_package_Motor"))
    (:file "_package_Motor" :depends-on ("_package"))
  ))