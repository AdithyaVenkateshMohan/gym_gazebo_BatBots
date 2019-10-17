// Auto-generated. Do not edit!

// (in-package planning_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class WaypointType {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
    }
    else {
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type WaypointType
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type WaypointType
    let len;
    let data = new WaypointType(null);
    return data;
  }

  static getMessageSize(object) {
    return 0;
  }

  static datatype() {
    // Returns string type for a message object
    return 'planning_msgs/WaypointType';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'ab2317fe7228faf4b4c92459f5353963';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 POSE=1
    int32 POLYNOMIAL=2 # stores the coefficients of a polynomial in the waypoint fields. Coefficients are stored in increasing order, i.e. c0 + c1*t + c2*t^2 ...
    int32 POLYNOMIAL_10=210 # polynomial with 10 coefficients, i.e. 9th order
    int32 POLYNOMIAL_12=212 # polynomial with 12 coefficients, i.e. 11th order
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new WaypointType(null);
    return resolved;
    }
};

// Constants for message
WaypointType.Constants = {
  POSE: 1,
  POLYNOMIAL: 2,
  POLYNOMIAL_10: 210,
  POLYNOMIAL_12: 212,
}

module.exports = WaypointType;
