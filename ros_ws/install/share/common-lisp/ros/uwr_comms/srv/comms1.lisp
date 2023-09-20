; Auto-generated. Do not edit!


(cl:in-package uwr_comms-srv)


;//! \htmlinclude comms1-request.msg.html

(cl:defclass <comms1-request> (roslisp-msg-protocol:ros-message)
  ((data
    :reader data
    :initarg :data
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass comms1-request (<comms1-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <comms1-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'comms1-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name uwr_comms-srv:<comms1-request> is deprecated: use uwr_comms-srv:comms1-request instead.")))

(cl:ensure-generic-function 'data-val :lambda-list '(m))
(cl:defmethod data-val ((m <comms1-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader uwr_comms-srv:data-val is deprecated.  Use uwr_comms-srv:data instead.")
  (data m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <comms1-request>) ostream)
  "Serializes a message object of type '<comms1-request>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'data))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'data))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <comms1-request>) istream)
  "Deserializes a message object of type '<comms1-request>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'data) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'data)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<comms1-request>)))
  "Returns string type for a service object of type '<comms1-request>"
  "uwr_comms/comms1Request")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'comms1-request)))
  "Returns string type for a service object of type 'comms1-request"
  "uwr_comms/comms1Request")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<comms1-request>)))
  "Returns md5sum for a message object of type '<comms1-request>"
  "0242c4536209073ea8ef950661c5aa97")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'comms1-request)))
  "Returns md5sum for a message object of type 'comms1-request"
  "0242c4536209073ea8ef950661c5aa97")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<comms1-request>)))
  "Returns full string definition for message of type '<comms1-request>"
  (cl:format cl:nil "float32[] data~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'comms1-request)))
  "Returns full string definition for message of type 'comms1-request"
  (cl:format cl:nil "float32[] data~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <comms1-request>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'data) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <comms1-request>))
  "Converts a ROS message object to a list"
  (cl:list 'comms1-request
    (cl:cons ':data (data msg))
))
;//! \htmlinclude comms1-response.msg.html

(cl:defclass <comms1-response> (roslisp-msg-protocol:ros-message)
  ((response
    :reader response
    :initarg :response
    :type cl:string
    :initform "")
   (data
    :reader data
    :initarg :data
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass comms1-response (<comms1-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <comms1-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'comms1-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name uwr_comms-srv:<comms1-response> is deprecated: use uwr_comms-srv:comms1-response instead.")))

(cl:ensure-generic-function 'response-val :lambda-list '(m))
(cl:defmethod response-val ((m <comms1-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader uwr_comms-srv:response-val is deprecated.  Use uwr_comms-srv:response instead.")
  (response m))

(cl:ensure-generic-function 'data-val :lambda-list '(m))
(cl:defmethod data-val ((m <comms1-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader uwr_comms-srv:data-val is deprecated.  Use uwr_comms-srv:data instead.")
  (data m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <comms1-response>) ostream)
  "Serializes a message object of type '<comms1-response>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'response))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'response))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'data))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'data))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <comms1-response>) istream)
  "Deserializes a message object of type '<comms1-response>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'response) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'response) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'data) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'data)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<comms1-response>)))
  "Returns string type for a service object of type '<comms1-response>"
  "uwr_comms/comms1Response")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'comms1-response)))
  "Returns string type for a service object of type 'comms1-response"
  "uwr_comms/comms1Response")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<comms1-response>)))
  "Returns md5sum for a message object of type '<comms1-response>"
  "0242c4536209073ea8ef950661c5aa97")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'comms1-response)))
  "Returns md5sum for a message object of type 'comms1-response"
  "0242c4536209073ea8ef950661c5aa97")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<comms1-response>)))
  "Returns full string definition for message of type '<comms1-response>"
  (cl:format cl:nil "string response~%float32[] data~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'comms1-response)))
  "Returns full string definition for message of type 'comms1-response"
  (cl:format cl:nil "string response~%float32[] data~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <comms1-response>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'response))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'data) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <comms1-response>))
  "Converts a ROS message object to a list"
  (cl:list 'comms1-response
    (cl:cons ':response (response msg))
    (cl:cons ':data (data msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'comms1)))
  'comms1-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'comms1)))
  'comms1-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'comms1)))
  "Returns string type for a service object of type '<comms1>"
  "uwr_comms/comms1")