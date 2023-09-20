
(cl:in-package :asdf)

(defsystem "uwr_comms-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "comms1" :depends-on ("_package_comms1"))
    (:file "_package_comms1" :depends-on ("_package"))
  ))