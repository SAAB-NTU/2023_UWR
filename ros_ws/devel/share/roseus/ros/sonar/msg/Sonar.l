;; Auto-generated. Do not edit!


(when (boundp 'sonar::Sonar)
  (if (not (find-package "SONAR"))
    (make-package "SONAR"))
  (shadow 'Sonar (find-package "SONAR")))
(unless (find-package "SONAR::SONAR")
  (make-package "SONAR::SONAR"))

(in-package "ROS")
;;//! \htmlinclude Sonar.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass sonar::Sonar
  :super ros::object
  :slots (_header _distance _confidence _transmit_duration _ping_number _scan_start _scan_length _gain_setting _profile_data ))

(defmethod sonar::Sonar
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:distance __distance) 0.0)
    ((:confidence __confidence) 0.0)
    ((:transmit_duration __transmit_duration) 0.0)
    ((:ping_number __ping_number) 0.0)
    ((:scan_start __scan_start) 0.0)
    ((:scan_length __scan_length) 0.0)
    ((:gain_setting __gain_setting) 0.0)
    ((:profile_data __profile_data) (make-array 0 :initial-element 0 :element-type :char))
    )
   (send-super :init)
   (setq _header __header)
   (setq _distance (float __distance))
   (setq _confidence (float __confidence))
   (setq _transmit_duration (float __transmit_duration))
   (setq _ping_number (float __ping_number))
   (setq _scan_start (float __scan_start))
   (setq _scan_length (float __scan_length))
   (setq _gain_setting (float __gain_setting))
   (setq _profile_data __profile_data)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:distance
   (&optional __distance)
   (if __distance (setq _distance __distance)) _distance)
  (:confidence
   (&optional __confidence)
   (if __confidence (setq _confidence __confidence)) _confidence)
  (:transmit_duration
   (&optional __transmit_duration)
   (if __transmit_duration (setq _transmit_duration __transmit_duration)) _transmit_duration)
  (:ping_number
   (&optional __ping_number)
   (if __ping_number (setq _ping_number __ping_number)) _ping_number)
  (:scan_start
   (&optional __scan_start)
   (if __scan_start (setq _scan_start __scan_start)) _scan_start)
  (:scan_length
   (&optional __scan_length)
   (if __scan_length (setq _scan_length __scan_length)) _scan_length)
  (:gain_setting
   (&optional __gain_setting)
   (if __gain_setting (setq _gain_setting __gain_setting)) _gain_setting)
  (:profile_data
   (&optional __profile_data)
   (if __profile_data (setq _profile_data __profile_data)) _profile_data)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float32 _distance
    4
    ;; float32 _confidence
    4
    ;; float32 _transmit_duration
    4
    ;; float32 _ping_number
    4
    ;; float32 _scan_start
    4
    ;; float32 _scan_length
    4
    ;; float32 _gain_setting
    4
    ;; uint8[] _profile_data
    (* 1    (length _profile_data)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float32 _distance
       (sys::poke _distance (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _confidence
       (sys::poke _confidence (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _transmit_duration
       (sys::poke _transmit_duration (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _ping_number
       (sys::poke _ping_number (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _scan_start
       (sys::poke _scan_start (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _scan_length
       (sys::poke _scan_length (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _gain_setting
       (sys::poke _gain_setting (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; uint8[] _profile_data
     (write-long (length _profile_data) s)
     (princ _profile_data s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float32 _distance
     (setq _distance (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _confidence
     (setq _confidence (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _transmit_duration
     (setq _transmit_duration (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _ping_number
     (setq _ping_number (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _scan_start
     (setq _scan_start (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _scan_length
     (setq _scan_length (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _gain_setting
     (setq _gain_setting (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; uint8[] _profile_data
   (let ((n (sys::peek buf ptr- :integer))) (incf ptr- 4)
     (setq _profile_data (make-array n :element-type :char))
     (replace _profile_data buf :start2 ptr-) (incf ptr- n))
   ;;
   self)
  )

(setf (get sonar::Sonar :md5sum-) "9e4a4d737f58de7be4dcffacf14f18c8")
(setf (get sonar::Sonar :datatype-) "sonar/Sonar")
(setf (get sonar::Sonar :definition-)
      "Header header 
float32 distance 
float32 confidence
float32 transmit_duration
float32 ping_number
float32 scan_start
float32 scan_length
float32 gain_setting
uint8[] profile_data
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



(provide :sonar/Sonar "9e4a4d737f58de7be4dcffacf14f18c8")


