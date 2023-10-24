;; Auto-generated. Do not edit!


(when (boundp 'sonar::TwoSonarDepth)
  (if (not (find-package "SONAR"))
    (make-package "SONAR"))
  (shadow 'TwoSonarDepth (find-package "SONAR")))
(unless (find-package "SONAR::TWOSONARDEPTH")
  (make-package "SONAR::TWOSONARDEPTH"))

(in-package "ROS")
;;//! \htmlinclude TwoSonarDepth.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass sonar::TwoSonarDepth
  :super ros::object
  :slots (_header _distance_1 _confidence_1 _distance_2 _confidence_2 _depth _altitude _pressure ))

(defmethod sonar::TwoSonarDepth
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:distance_1 __distance_1) 0.0)
    ((:confidence_1 __confidence_1) 0.0)
    ((:distance_2 __distance_2) 0.0)
    ((:confidence_2 __confidence_2) 0.0)
    ((:depth __depth) 0.0)
    ((:altitude __altitude) 0.0)
    ((:pressure __pressure) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _distance_1 (float __distance_1))
   (setq _confidence_1 (float __confidence_1))
   (setq _distance_2 (float __distance_2))
   (setq _confidence_2 (float __confidence_2))
   (setq _depth (float __depth))
   (setq _altitude (float __altitude))
   (setq _pressure (float __pressure))
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
  (:depth
   (&optional __depth)
   (if __depth (setq _depth __depth)) _depth)
  (:altitude
   (&optional __altitude)
   (if __altitude (setq _altitude __altitude)) _altitude)
  (:pressure
   (&optional __pressure)
   (if __pressure (setq _pressure __pressure)) _pressure)
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
    ;; float32 _depth
    4
    ;; float32 _altitude
    4
    ;; float32 _pressure
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
     ;; float32 _depth
       (sys::poke _depth (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _altitude
       (sys::poke _altitude (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _pressure
       (sys::poke _pressure (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
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
   ;; float32 _depth
     (setq _depth (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _altitude
     (setq _altitude (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _pressure
     (setq _pressure (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get sonar::TwoSonarDepth :md5sum-) "facf9d4c6b34b990b26468acb341d2ba")
(setf (get sonar::TwoSonarDepth :datatype-) "sonar/TwoSonarDepth")
(setf (get sonar::TwoSonarDepth :definition-)
      "Header header 
float32 distance_1 
float32 confidence_1
float32 distance_2
float32 confidence_2
float32 depth 
float32 altitude
float32 pressure

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



(provide :sonar/TwoSonarDepth "facf9d4c6b34b990b26468acb341d2ba")


