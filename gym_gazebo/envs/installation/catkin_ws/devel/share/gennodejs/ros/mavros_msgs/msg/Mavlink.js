// Auto-generated. Do not edit!

// (in-package mavros_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class Mavlink {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.is_valid = null;
      this.len = null;
      this.seq = null;
      this.sysid = null;
      this.compid = null;
      this.msgid = null;
      this.checksum = null;
      this.payload64 = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('is_valid')) {
        this.is_valid = initObj.is_valid
      }
      else {
        this.is_valid = false;
      }
      if (initObj.hasOwnProperty('len')) {
        this.len = initObj.len
      }
      else {
        this.len = 0;
      }
      if (initObj.hasOwnProperty('seq')) {
        this.seq = initObj.seq
      }
      else {
        this.seq = 0;
      }
      if (initObj.hasOwnProperty('sysid')) {
        this.sysid = initObj.sysid
      }
      else {
        this.sysid = 0;
      }
      if (initObj.hasOwnProperty('compid')) {
        this.compid = initObj.compid
      }
      else {
        this.compid = 0;
      }
      if (initObj.hasOwnProperty('msgid')) {
        this.msgid = initObj.msgid
      }
      else {
        this.msgid = 0;
      }
      if (initObj.hasOwnProperty('checksum')) {
        this.checksum = initObj.checksum
      }
      else {
        this.checksum = 0;
      }
      if (initObj.hasOwnProperty('payload64')) {
        this.payload64 = initObj.payload64
      }
      else {
        this.payload64 = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Mavlink
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [is_valid]
    bufferOffset = _serializer.bool(obj.is_valid, buffer, bufferOffset);
    // Serialize message field [len]
    bufferOffset = _serializer.uint8(obj.len, buffer, bufferOffset);
    // Serialize message field [seq]
    bufferOffset = _serializer.uint8(obj.seq, buffer, bufferOffset);
    // Serialize message field [sysid]
    bufferOffset = _serializer.uint8(obj.sysid, buffer, bufferOffset);
    // Serialize message field [compid]
    bufferOffset = _serializer.uint8(obj.compid, buffer, bufferOffset);
    // Serialize message field [msgid]
    bufferOffset = _serializer.uint8(obj.msgid, buffer, bufferOffset);
    // Serialize message field [checksum]
    bufferOffset = _serializer.uint16(obj.checksum, buffer, bufferOffset);
    // Serialize message field [payload64]
    bufferOffset = _arraySerializer.uint64(obj.payload64, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Mavlink
    let len;
    let data = new Mavlink(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [is_valid]
    data.is_valid = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [len]
    data.len = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [seq]
    data.seq = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [sysid]
    data.sysid = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [compid]
    data.compid = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [msgid]
    data.msgid = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [checksum]
    data.checksum = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [payload64]
    data.payload64 = _arrayDeserializer.uint64(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += 8 * object.payload64.length;
    return length + 12;
  }

  static datatype() {
    // Returns string type for a message object
    return 'mavros_msgs/Mavlink';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '6dd71a38b8541fdc2de89a548c7dbc2f';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # Mavlink message transport type.
    #
    # Used to transport mavlink_message_t via ROS topic
    #
    # :is_valid: flag meaning that there CRC16 error or message is unknown by libmavconn.
    #            You may simply drop all non valid messages. Used for GCS Bridge to transport
    #            unknown messages.
    #
    # Please use mavros_msgs::mavlink::convert() from <mavros_msgs/mavlink_convert.h>
    # to convert between ROS and MAVLink message type
    
    std_msgs/Header header
    bool is_valid
    
    uint8 len
    uint8 seq
    uint8 sysid
    uint8 compid
    uint8 msgid
    uint16 checksum
    uint64[] payload64
    
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
    # 0: no frame
    # 1: global frame
    string frame_id
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Mavlink(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.is_valid !== undefined) {
      resolved.is_valid = msg.is_valid;
    }
    else {
      resolved.is_valid = false
    }

    if (msg.len !== undefined) {
      resolved.len = msg.len;
    }
    else {
      resolved.len = 0
    }

    if (msg.seq !== undefined) {
      resolved.seq = msg.seq;
    }
    else {
      resolved.seq = 0
    }

    if (msg.sysid !== undefined) {
      resolved.sysid = msg.sysid;
    }
    else {
      resolved.sysid = 0
    }

    if (msg.compid !== undefined) {
      resolved.compid = msg.compid;
    }
    else {
      resolved.compid = 0
    }

    if (msg.msgid !== undefined) {
      resolved.msgid = msg.msgid;
    }
    else {
      resolved.msgid = 0
    }

    if (msg.checksum !== undefined) {
      resolved.checksum = msg.checksum;
    }
    else {
      resolved.checksum = 0
    }

    if (msg.payload64 !== undefined) {
      resolved.payload64 = msg.payload64;
    }
    else {
      resolved.payload64 = []
    }

    return resolved;
    }
};

module.exports = Mavlink;
