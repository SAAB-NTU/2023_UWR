;; Auto-generated. Do not edit!


(when (boundp 'sonar::TwoSonar)
  (if (not (find-package "SONAR"))
    (make-package "SONAR"))
  (shadow 'TwoSonar (find-package "SONAR")))
(unless (find-package "SONAR::TWOSONAR")
  (make-package "SONAR::TWOSONAR"))

(in-package "ROS")
;;//! \htmlinclude TwoSonar.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass sonar::TwoSonar
  :super ros::object
  :slots (_header _distance_1 _confidence_1 _distance_2 _confidence_2 ))

(defmethod sonar::TwoSonar
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:distance_1 __distance_1) 0.0)
    ((:confidence_1 __confidence_1) 0.0)
    ((:distance_2 __distance_2) 0.0)
    ((:confidence_2 __confidence_2) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _distance_1 (float __distance_1))
   (setq _confidence_1 (float __confidence_1))
   (setq _distance_2 (float __distance_2))
   (setq _confidence_2 (float __confidence_2))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:distance_1
   (&optional __distance_1)
   (if __distance_1 (setq _distance_1 __distance_1)) _distance_1)
  (:confidence_1
   (&optional __confidence_1)
   (if __confidence_1 (setq _confidence_1 __confidence_1)) _confidence_1)
  (:distance_2
   (&optional __distance_2)
   (if __distance_2 (setq _distance_2 __distance_2)) _distance_2)
  (:confidence_2
   (&optional __confidence_2)
   (if __confidence_2 (setq _confidence_2 __confidence_2)) _confidence_2)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float32 _distance_1
    4
    ;; float32 _confidence_1
    4
    ;; float32 _distance_2
    4
    ;; float32 _confidence_2
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float32 _distance_1
       (sys::poke _distance_1 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _confidence_1
       (sys::poke _confidence_1 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _distance_2
       (sys::poke _distance_2 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _confidence_2
       (sys::poke _confidence_2 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float32 _distance_1
     (setq _distance_1 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _confidence_1
     (setq _confidence_1 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _distance_2
     (setq _distance_2 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _confidence_2
     (setq _confidence_2 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get sonar::TwoSonar :md5sum-) "511d902ba05d070d68faabdedabf3289")
(setf (get sonar::TwoSonar :datatype-) "sonar/TwoSonar")
(setf (get sonar::TwoSonar :definition-)
      "Header header 
float32 distance_1 
float32 confidence_1
float32 distance_2
float32 confidence_2
================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

")



(provide :sonar/TwoSonar "511d902ba05d070d68faabdedabf3289")


