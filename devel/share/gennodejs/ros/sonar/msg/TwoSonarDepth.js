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

class TwoSonarDepth {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.distance_1 = null;
      this.confidence_1 = null;
      this.distance_2 = null;
      this.confidence_2 = null;
      this.depth = null;
      this.altitude = null;
      this.pressure = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('distance_1')) {
        this.distance_1 = initObj.distance_1
      }
      else {
        this.distance_1 = 0.0;
      }
      if (initObj.hasOwnProperty('confidence_1')) {
        this.confidence_1 = initObj.confidence_1
      }
      else {
        this.confidence_1 = 0.0;
      }
      if (initObj.hasOwnProperty('distance_2')) {
        this.distance_2 = initObj.distance_2
      }
      else {
        this.distance_2 = 0.0;
      }
      if (initObj.hasOwnProperty('confidence_2')) {
        this.confidence_2 = initObj.confidence_2
      }
      else {
        this.confidence_2 = 0.0;
      }
      if (initObj.hasOwnProperty('depth')) {
        this.depth = initObj.depth
      }
      else {
        this.depth = 0.0;
      }
      if (initObj.hasOwnProperty('altitude')) {
        this.altitude = initObj.altitude
      }
      else {
        this.altitude = 0.0;
      }
      if (initObj.hasOwnProperty('pressure')) {
        this.pressure = initObj.pressure
      }
      else {
        this.pressure = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type TwoSonarDepth
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [distance_1]
    bufferOffset = _serializer.float32(obj.distance_1, buffer, bufferOffset);
    // Serialize message field [confidence_1]
    bufferOffset = _serializer.float32(obj.confidence_1, buffer, bufferOffset);
    // Serialize message field [distance_2]
    bufferOffset = _serializer.float32(obj.distance_2, buffer, bufferOffset);
    // Serialize message field [confidence_2]
    bufferOffset = _serializer.float32(obj.confidence_2, buffer, bufferOffset);
    // Serialize message field [depth]
    bufferOffset = _serializer.float32(obj.depth, buffer, bufferOffset);
    // Serialize message field [altitude]
    bufferOffset = _serializer.float32(obj.altitude, buffer, bufferOffset);
    // Serialize message field [pressure]
    bufferOffset = _serializer.float32(obj.pressure, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type TwoSonarDepth
    let len;
    let data = new TwoSonarDepth(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [distance_1]
    data.distance_1 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [confidence_1]
    data.confidence_1 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [distance_2]
    data.distance_2 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [confidence_2]
    data.confidence_2 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [depth]
    data.depth = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [altitude]
    data.altitude = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [pressure]
    data.pressure = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 28;
  }

  static datatype() {
    // Returns string type for a message object
    return 'sonar/TwoSonarDepth';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'facf9d4c6b34b990b26468acb341d2ba';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header 
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new TwoSonarDepth(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.distance_1 !== undefined) {
      resolved.distance_1 = msg.distance_1;
    }
    else {
      resolved.distance_1 = 0.0
    }

    if (msg.confidence_1 !== undefined) {
      resolved.confidence_1 = msg.confidence_1;
    }
    else {
      resolved.confidence_1 = 0.0
    }

    if (msg.distance_2 !== undefined) {
      resolved.distance_2 = msg.distance_2;
    }
    else {
      resolved.distance_2 = 0.0
    }

    if (msg.confidence_2 !== undefined) {
      resolved.confidence_2 = msg.confidence_2;
    }
    else {
      resolved.confidence_2 = 0.0
    }

    if (msg.depth !== undefined) {
      resolved.depth = msg.depth;
    }
    else {
      resolved.depth = 0.0
    }

    if (msg.altitude !== undefined) {
      resolved.altitude = msg.altitude;
    }
    else {
      resolved.altitude = 0.0
    }

    if (msg.pressure !== undefined) {
      resolved.pressure = msg.pressure;
    }
    else {
      resolved.pressure = 0.0
    }

    return resolved;
    }
};

module.exports = TwoSonarDepth;
