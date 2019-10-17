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

class PlanningResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.path = null;
      this.time = null;
      this.number_primitives = null;
      this.waypoint_type = null;
    }
    else {
      if (initObj.hasOwnProperty('path')) {
        this.path = initObj.path
      }
      else {
        this.path = [];
      }
      if (initObj.hasOwnProperty('time')) {
        this.time = initObj.time
      }
      else {
        this.time = [];
      }
      if (initObj.hasOwnProperty('number_primitives')) {
        this.number_primitives = initObj.number_primitives
      }
      else {
        this.number_primitives = 0;
      }
      if (initObj.hasOwnProperty('waypoint_type')) {
        this.waypoint_type = initObj.waypoint_type
      }
      else {
        this.waypoint_type = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type PlanningResponse
    // Serialize message field [path]
    bufferOffset = _arraySerializer.float64(obj.path, buffer, bufferOffset, null);
    // Serialize message field [time]
    bufferOffset = _arraySerializer.float64(obj.time, buffer, bufferOffset, null);
    // Serialize message field [number_primitives]
    bufferOffset = _serializer.int32(obj.number_primitives, buffer, bufferOffset);
    // Serialize message field [waypoint_type]
    bufferOffset = _serializer.int32(obj.waypoint_type, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type PlanningResponse
    let len;
    let data = new PlanningResponse(null);
    // Deserialize message field [path]
    data.path = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [time]
    data.time = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [number_primitives]
    data.number_primitives = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [waypoint_type]
    data.waypoint_type = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 8 * object.path.length;
    length += 8 * object.time.length;
    return length + 16;
  }

  static datatype() {
    // Returns string type for a message object
    return 'planning_msgs/PlanningResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'cb7dd897470b7e4529896a33d9fa75c9';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64[] path # m x n matrix
    float64[] time # n vector with times
    int32 number_primitives  # = n
    int32 waypoint_type #polynom, pose etc.
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new PlanningResponse(null);
    if (msg.path !== undefined) {
      resolved.path = msg.path;
    }
    else {
      resolved.path = []
    }

    if (msg.time !== undefined) {
      resolved.time = msg.time;
    }
    else {
      resolved.time = []
    }

    if (msg.number_primitives !== undefined) {
      resolved.number_primitives = msg.number_primitives;
    }
    else {
      resolved.number_primitives = 0
    }

    if (msg.waypoint_type !== undefined) {
      resolved.waypoint_type = msg.waypoint_type;
    }
    else {
      resolved.waypoint_type = 0
    }

    return resolved;
    }
};

module.exports = PlanningResponse;
