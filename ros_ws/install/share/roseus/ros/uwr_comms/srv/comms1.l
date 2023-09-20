;; Auto-generated. Do not edit!


(when (boundp 'uwr_comms::comms1)
  (if (not (find-package "UWR_COMMS"))
    (make-package "UWR_COMMS"))
  (shadow 'comms1 (find-package "UWR_COMMS")))
(unless (find-package "UWR_COMMS::COMMS1")
  (make-package "UWR_COMMS::COMMS1"))
(unless (find-package "UWR_COMMS::COMMS1REQUEST")
  (make-package "UWR_COMMS::COMMS1REQUEST"))
(unless (find-package "UWR_COMMS::COMMS1RESPONSE")
  (make-package "UWR_COMMS::COMMS1RESPONSE"))

(in-package "ROS")





(defclass uwr_comms::comms1Request
  :super ros::object
  :slots (_data ))

(defmethod uwr_comms::comms1Request
  (:init
   (&key
    ((:data __data) (make-array 0 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _data __data)
   self)
  (:data
   (&optional __data)
   (if __data (setq _data __data)) _data)
  (:serialization-length
   ()
   (+
    ;; float32[] _data
    (* 4    (length _data)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32[] _data
     (write-long (length _data) s)
     (dotimes (i (length _data))
       (sys::poke (elt _data i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32[] _data
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _data (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _data i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     ))
   ;;
   self)
  )

(defclass uwr_comms::comms1Response
  :super ros::object
  :slots (_response _data ))

(defmethod uwr_comms::comms1Response
  (:init
   (&key
    ((:response __response) "")
    ((:data __data) (make-array 0 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _response (string __response))
   (setq _data __data)
   self)
  (:response
   (&optional __response)
   (if __response (setq _response __response)) _response)
  (:data
   (&optional __data)
   (if __data (setq _data __data)) _data)
  (:serialization-length
   ()
   (+
    ;; string _response
    4 (length _response)
    ;; float32[] _data
    (* 4    (length _data)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _response
       (write-long (length _response) s) (princ _response s)
     ;; float32[] _data
     (write-long (length _data) s)
     (dotimes (i (length _data))
       (sys::poke (elt _data i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _response
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _response (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; float32[] _data
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _data (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _data i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     ))
   ;;
   self)
  )

(defclass uwr_comms::comms1
  :super ros::object
  :slots ())

(setf (get uwr_comms::comms1 :md5sum-) "0242c4536209073ea8ef950661c5aa97")
(setf (get uwr_comms::comms1 :datatype-) "uwr_comms/comms1")
(setf (get uwr_comms::comms1 :request) uwr_comms::comms1Request)
(setf (get uwr_comms::comms1 :response) uwr_comms::comms1Response)

(defmethod uwr_comms::comms1Request
  (:response () (instance uwr_comms::comms1Response :init)))

(setf (get uwr_comms::comms1Request :md5sum-) "0242c4536209073ea8ef950661c5aa97")
(setf (get uwr_comms::comms1Request :datatype-) "uwr_comms/comms1Request")
(setf (get uwr_comms::comms1Request :definition-)
      "float32[] data
---
string response
float32[] data

")

(setf (get uwr_comms::comms1Response :md5sum-) "0242c4536209073ea8ef950661c5aa97")
(setf (get uwr_comms::comms1Response :datatype-) "uwr_comms/comms1Response")
(setf (get uwr_comms::comms1Response :definition-)
      "float32[] data
---
string response
float32[] data

")



(provide :uwr_comms/comms1 "0242c4536209073ea8ef950661c5aa97")


