; Auto-generated. Do not edit!


(cl:in-package sonar-msg)


;//! \htmlinclude TwoSonarDepth.msg.html

(cl:defclass <TwoSonarDepth> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (distance_1
    :reader distance_1
    :initarg :distance_1
    :type cl:float
    :initform 0.0)
   (confidence_1
    :reader confidence_1
    :initarg :confidence_1
    :type cl:float
    :initform 0.0)
   (distance_2
    :reader distance_2
    :initarg :distance_2
    :type cl:float
    :initform 0.0)
   (confidence_2
    :reader confidence_2
    :initarg :confidence_2
    :type cl:float
    :initform 0.0)
   (depth
    :reader depth
    :initarg :depth
    :type cl:float
    :initform 0.0)
   (altitude
    :reader altitude
    :initarg :altitude
    :type cl:float
    :initform 0.0)
   (pressure
    :reader pressure
    :initarg :pressure
    :type cl:float
    :initform 0.0))
)

(cl:defclass TwoSonarDepth (<TwoSonarDepth>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <TwoSonarDepth>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'TwoSonarDepth)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name sonar-msg:<TwoSonarDepth> is deprecated: use sonar-msg:TwoSonarDepth instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <TwoSonarDepth>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sonar-msg:header-val is deprecated.  Use sonar-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'distance_1-val :lambda-list '(m))
(cl:defmethod distance_1-val ((m <TwoSonarDepth>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sonar-msg:distance_1-val is deprecated.  Use sonar-msg:distance_1 instead.")
  (distance_1 m))

(cl:ensure-generic-function 'confidence_1-val :lambda-list '(m))
(cl:defmethod confidence_1-val ((m <TwoSonarDepth>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sonar-msg:confidence_1-val is deprecated.  Use sonar-msg:confidence_1 instead.")
  (confidence_1 m))

(cl:ensure-generic-function 'distance_2-val :lambda-list '(m))
(cl:defmethod distance_2-val ((m <TwoSonarDepth>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sonar-msg:distance_2-val is deprecated.  Use sonar-msg:distance_2 instead.")
  (distance_2 m))

(cl:ensure-generic-function 'confidence_2-val :lambda-list '(m))
(cl:defmethod confidence_2-val ((m <TwoSonarDepth>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sonar-msg:confidence_2-val is deprecated.  Use sonar-msg:confidence_2 instead.")
  (confidence_2 m))

(cl:ensure-generic-function 'depth-val :lambda-list '(m))
(cl:defmethod depth-val ((m <TwoSonarDepth>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sonar-msg:depth-val is deprecated.  Use sonar-msg:depth instead.")
  (depth m))

(cl:ensure-generic-function 'altitude-val :lambda-list '(m))
(cl:defmethod altitude-val ((m <TwoSonarDepth>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sonar-msg:altitude-val is deprecated.  Use sonar-msg:altitude instead.")
  (altitude m))

(cl:ensure-generic-function 'pressure-val :lambda-list '(m))
(cl:defmethod pressure-val ((m <TwoSonarDepth>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sonar-msg:pressure-val is deprecated.  Use sonar-msg:pressure instead.")
  (pressure m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <TwoSonarDepth>) ostream)
  "Serializes a message object of type '<TwoSonarDepth>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'distance_1))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'confidence_1))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'distance_2))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'confidence_2))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'depth))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'altitude))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'pressure))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <TwoSonarDepth>) istream)
  "Deserializes a message object of type '<TwoSonarDepth>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'distance_1) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'confidence_1) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'distance_2) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'confidence_2) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'depth) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'altitude) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'pressure) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<TwoSonarDepth>)))
  "Returns string type for a message object of type '<TwoSonarDepth>"
  "sonar/TwoSonarDepth")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'TwoSonarDepth)))
  "Returns string type for a message object of type 'TwoSonarDepth"
  "sonar/TwoSonarDepth")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<TwoSonarDepth>)))
  "Returns md5sum for a message object of type '<TwoSonarDepth>"
  "facf9d4c6b34b990b26468acb341d2ba")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'TwoSonarDepth)))
  "Returns md5sum for a message object of type 'TwoSonarDepth"
  "facf9d4c6b34b990b26468acb341d2ba")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<TwoSonarDepth>)))
  "Returns full string definition for message of type '<TwoSonarDepth>"
  (cl:format cl:nil "Header header ~%float32 distance_1 ~%float32 confidence_1~%float32 distance_2~%float32 confidence_2~%float32 depth ~%float32 altitude~%float32 pressure~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'TwoSonarDepth)))
  "Returns full string definition for message of type 'TwoSonarDepth"
  (cl:format cl:nil "Header header ~%float32 distance_1 ~%float32 confidence_1~%float32 distance_2~%float32 confidence_2~%float32 depth ~%float32 altitude~%float32 pressure~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <TwoSonarDepth>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
     4
     4
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <TwoSonarDepth>))
  "Converts a ROS message object to a list"
  (cl:list 'TwoSonarDepth
    (cl:cons ':header (header msg))
    (cl:cons ':distance_1 (distance_1 msg))
    (cl:cons ':confidence_1 (confidence_1 msg))
    (cl:cons ':distance_2 (distance_2 msg))
    (cl:cons ':confidence_2 (confidence_2 msg))
    (cl:cons ':depth (depth msg))
    (cl:cons ':altitude (altitude msg))
    (cl:cons ':pressure (pressure msg))
))
