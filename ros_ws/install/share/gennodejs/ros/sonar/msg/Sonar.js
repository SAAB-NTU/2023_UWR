// Auto-generated. Do not edit!

// (in-package sonar.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class Sonar {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.distance = null;
      this.confidence = null;
      this.transmit_duration = null;
      this.ping_number = null;
      this.scan_start = null;
      this.scan_length = null;
      this.gain_setting = null;
      this.profile_data = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('distance')) {
        this.distance = initObj.distance
      }
      else {
        this.distance = 0.0;
      }
      if (initObj.hasOwnProperty('confidence')) {
        this.confidence = initObj.confidence
      }
      else {
        this.confidence = 0.0;
      }
      if (initObj.hasOwnProperty('transmit_duration')) {
        this.transmit_duration = initObj.transmit_duration
      }
      else {
        this.transmit_duration = 0.0;
      }
      if (initObj.hasOwnProperty('ping_number')) {
        this.ping_number = initObj.ping_number
      }
      else {
        this.ping_number = 0.0;
      }
      if (initObj.hasOwnProperty('scan_start')) {
        this.scan_start = initObj.scan_start
      }
      else {
        this.scan_start = 0.0;
      }
      if (initObj.hasOwnProperty('scan_length')) {
        this.scan_length = initObj.scan_length
      }
      else {
        this.scan_length = 0.0;
      }
      if (initObj.hasOwnProperty('gain_setting')) {
        this.gain_setting = initObj.gain_setting
      }
      else {
        this.gain_setting = 0.0;
      }
      if (initObj.hasOwnProperty('profile_data')) {
        this.profile_data = initObj.profile_data
      }
      else {
        this.profile_data = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Sonar
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [distance]
    bufferOffset = _serializer.float32(obj.distance, buffer, bufferOffset);
    // Serialize message field [confidence]
    bufferOffset = _serializer.float32(obj.confidence, buffer, bufferOffset);
    // Serialize message field [transmit_duration]
    bufferOffset = _serializer.float32(obj.transmit_duration, buffer, bufferOffset);
    // Serialize message field [ping_number]
    bufferOffset = _serializer.float32(obj.ping_number, buffer, bufferOffset);
    // Serialize message field [scan_start]
    bufferOffset = _serializer.float32(obj.scan_start, buffer, bufferOffset);
    // Serialize message field [scan_length]
    bufferOffset = _serializer.float32(obj.scan_length, buffer, bufferOffset);
    // Serialize message field [gain_setting]
    bufferOffset = _serializer.float32(obj.gain_setting, buffer, bufferOffset);
    // Serialize message field [profile_data]
    bufferOffset = _arraySerializer.uint8(obj.profile_data, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Sonar
    let len;
    let data = new Sonar(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [distance]
    data.distance = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [confidence]
    data.confidence = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [transmit_duration]
    data.transmit_duration = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [ping_number]
    data.ping_number = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [scan_start]
    data.scan_start = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [scan_length]
    data.scan_length = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [gain_setting]
    data.gain_setting = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [profile_data]
    data.profile_data = _arrayDeserializer.uint8(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += object.profile_data.length;
    return length + 32;
  }

  static datatype() {
    // Returns string type for a message object
    return 'sonar/Sonar';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '9e4a4d737f58de7be4dcffacf14f18c8';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header 
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Sonar(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.distance !== undefined) {
      resolved.distance = msg.distance;
    }
    else {
      resolved.distance = 0.0
    }

    if (msg.confidence !== undefined) {
      resolved.confidence = msg.confidence;
    }
    else {
      resolved.confidence = 0.0
    }

    if (msg.transmit_duration !== undefined) {
      resolved.transmit_duration = msg.transmit_duration;
    }
    else {
      resolved.transmit_duration = 0.0
    }

    if (msg.ping_number !== undefined) {
      resolved.ping_number = msg.ping_number;
    }
    else {
      resolved.ping_number = 0.0
    }

    if (msg.scan_start !== undefined) {
      resolved.scan_start = msg.scan_start;
    }
    else {
      resolved.scan_start = 0.0
    }

    if (msg.scan_length !== undefined) {
      resolved.scan_length = msg.scan_length;
    }
    else {
      resolved.scan_length = 0.0
    }

    if (msg.gain_setting !== undefined) {
      resolved.gain_setting = msg.gain_setting;
    }
    else {
      resolved.gain_setting = 0.0
    }

    if (msg.profile_data !== undefined) {
      resolved.profile_data = msg.profile_data;
    }
    else {
      resolved.profile_data = []
    }

    return resolved;
    }
};

module.exports = Sonar;
