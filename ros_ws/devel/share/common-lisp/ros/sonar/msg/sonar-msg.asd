
(cl:in-package :asdf)

(defsystem "sonar-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "Sonar" :depends-on ("_package_Sonar"))
    (:file "_package_Sonar" :depends-on ("_package"))
    (:file "ThreeSonarDepth" :depends-on ("_package_ThreeSonarDepth"))
    (:file "_package_ThreeSonarDepth" :depends-on ("_package"))
    (:file "TwoSonar" :depends-on ("_package_TwoSonar"))
    (:file "_package_TwoSonar" :depends-on ("_package"))
    (:file "TwoSonarDepth" :depends-on ("_package_TwoSonarDepth"))
    (:file "_package_TwoSonarDepth" :depends-on ("_package"))
  ))