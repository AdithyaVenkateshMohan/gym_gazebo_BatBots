// Auto-generated. Do not edit!

// (in-package planning_msgs.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let geometry_msgs = _finder('geometry_msgs');

//-----------------------------------------------------------

let PlanningResponse = require('../msg/PlanningResponse.js');

//-----------------------------------------------------------

class PlannerServiceRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.start_pose = null;
      this.start_velocity = null;
      this.goal_pose = null;
      this.goal_velocity = null;
      this.bounding_box = null;
    }
    else {
      if (initObj.hasOwnProperty('start_pose')) {
        this.start_pose = initObj.start_pose
      }
      else {
        this.start_pose = new geometry_msgs.msg.PoseStamped();
      }
      if (initObj.hasOwnProperty('start_velocity')) {
        this.start_velocity = initObj.start_velocity
      }
      else {
        this.start_velocity = new geometry_msgs.msg.Vector3();
      }
      if (initObj.hasOwnProperty('goal_pose')) {
        this.goal_pose = initObj.goal_pose
      }
      else {
        this.goal_pose = new geometry_msgs.msg.PoseStamped();
      }
      if (initObj.hasOwnProperty('goal_velocity')) {
        this.goal_velocity = initObj.goal_velocity
      }
      else {
        this.goal_velocity = new geometry_msgs.msg.Vector3();
      }
      if (initObj.hasOwnProperty('bounding_box')) {
        this.bounding_box = initObj.bounding_box
      }
      else {
        this.bounding_box = new geometry_msgs.msg.Vector3();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type PlannerServiceRequest
    // Serialize message field [start_pose]
    bufferOffset = geometry_msgs.msg.PoseStamped.serialize(obj.start_pose, buffer, bufferOffset);
    // Serialize message field [start_velocity]
    bufferOffset = geometry_msgs.msg.Vector3.serialize(obj.start_velocity, buffer, bufferOffset);
    // Serialize message field [goal_pose]
    bufferOffset = geometry_msgs.msg.PoseStamped.serialize(obj.goal_pose, buffer, bufferOffset);
    // Serialize message field [goal_velocity]
    bufferOffset = geometry_msgs.msg.Vector3.serialize(obj.goal_velocity, buffer, bufferOffset);
    // Serialize message field [bounding_box]
    bufferOffset = geometry_msgs.msg.Vector3.serialize(obj.bounding_box, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type PlannerServiceRequest
    let len;
    let data = new PlannerServiceRequest(null);
    // Deserialize message field [start_pose]
    data.start_pose = geometry_msgs.msg.PoseStamped.deserialize(buffer, bufferOffset);
    // Deserialize message field [start_velocity]
    data.start_velocity = geometry_msgs.msg.Vector3.deserialize(buffer, bufferOffset);
    // Deserialize message field [goal_pose]
    data.goal_pose = geometry_msgs.msg.PoseStamped.deserialize(buffer, bufferOffset);
    // Deserialize message field [goal_velocity]
    data.goal_velocity = geometry_msgs.msg.Vector3.deserialize(buffer, bufferOffset);
    // Deserialize message field [bounding_box]
    data.bounding_box = geometry_msgs.msg.Vector3.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += geometry_msgs.msg.PoseStamped.getMessageSize(object.start_pose);
    length += geometry_msgs.msg.PoseStamped.getMessageSize(object.goal_pose);
    return length + 72;
  }

  static datatype() {
    // Returns string type for a service object
    return 'planning_msgs/PlannerServiceRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '6090fe8ab3df1362b8c26859b8850940';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    
    geometry_msgs/PoseStamped start_pose
    geometry_msgs/Vector3 start_velocity
    geometry_msgs/PoseStamped goal_pose
    geometry_msgs/Vector3 goal_velocity
    geometry_msgs/Vector3 bounding_box
    
    ================================================================================
    MSG: geometry_msgs/PoseStamped
    # A Pose with reference coordinate frame and timestamp
    Header header
    Pose pose
    
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
    
    ================================================================================
    MSG: geometry_msgs/Pose
    # A representation of pose in free space, composed of position and orientation. 
    Point position
    Quaternion orientation
    
    ================================================================================
    MSG: geometry_msgs/Point
    # This contains the position of a point in free space
    float64 x
    float64 y
    float64 z
    
    ================================================================================
    MSG: geometry_msgs/Quaternion
    # This represents an orientation in free space in quaternion form.
    
    float64 x
    float64 y
    float64 z
    float64 w
    
    ================================================================================
    MSG: geometry_msgs/Vector3
    # This represents a vector in free space. 
    # It is only meant to represent a direction. Therefore, it does not
    # make sense to apply a translation to it (e.g., when applying a 
    # generic rigid transformation to a Vector3, tf2 will only apply the
    # rotation). If you want your data to be translatable too, use the
    # geometry_msgs/Point message instead.
    
    float64 x
    float64 y
    float64 z
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new PlannerServiceRequest(null);
    if (msg.start_pose !== undefined) {
      resolved.start_pose = geometry_msgs.msg.PoseStamped.Resolve(msg.start_pose)
    }
    else {
      resolved.start_pose = new geometry_msgs.msg.PoseStamped()
    }

    if (msg.start_velocity !== undefined) {
      resolved.start_velocity = geometry_msgs.msg.Vector3.Resolve(msg.start_velocity)
    }
    else {
      resolved.start_velocity = new geometry_msgs.msg.Vector3()
    }

    if (msg.goal_pose !== undefined) {
      resolved.goal_pose = geometry_msgs.msg.PoseStamped.Resolve(msg.goal_pose)
    }
    else {
      resolved.goal_pose = new geometry_msgs.msg.PoseStamped()
    }

    if (msg.goal_velocity !== undefined) {
      resolved.goal_velocity = geometry_msgs.msg.Vector3.Resolve(msg.goal_velocity)
    }
    else {
      resolved.goal_velocity = new geometry_msgs.msg.Vector3()
    }

    if (msg.bounding_box !== undefined) {
      resolved.bounding_box = geometry_msgs.msg.Vector3.Resolve(msg.bounding_box)
    }
    else {
      resolved.bounding_box = new geometry_msgs.msg.Vector3()
    }

    return resolved;
    }
};

class PlannerServiceResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.status = null;
      this.plan = null;
    }
    else {
      if (initObj.hasOwnProperty('status')) {
        this.status = initObj.status
      }
      else {
        this.status = 0;
      }
      if (initObj.hasOwnProperty('plan')) {
        this.plan = initObj.plan
      }
      else {
        this.plan = new PlanningResponse();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type PlannerServiceResponse
    // Serialize message field [status]
    bufferOffset = _serializer.uint8(obj.status, buffer, bufferOffset);
    // Serialize message field [plan]
    bufferOffset = PlanningResponse.serialize(obj.plan, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type PlannerServiceResponse
    let len;
    let data = new PlannerServiceResponse(null);
    // Deserialize message field [status]
    data.status = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [plan]
    data.plan = PlanningResponse.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += PlanningResponse.getMessageSize(object.plan);
    return length + 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'planning_msgs/PlannerServiceResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '6901798f4fe8af616256b39b5ffdd5e6';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    
    uint8 PLANNINGSUCCESS=1
    uint8 PLANNINGFAILED=2
    
    uint8 status
    PlanningResponse plan
    
    
    
    ================================================================================
    MSG: planning_msgs/PlanningResponse
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
    const resolved = new PlannerServiceResponse(null);
    if (msg.status !== undefined) {
      resolved.status = msg.status;
    }
    else {
      resolved.status = 0
    }

    if (msg.plan !== undefined) {
      resolved.plan = PlanningResponse.Resolve(msg.plan)
    }
    else {
      resolved.plan = new PlanningResponse()
    }

    return resolved;
    }
};

// Constants for message
PlannerServiceResponse.Constants = {
  PLANNINGSUCCESS: 1,
  PLANNINGFAILED: 2,
}

module.exports = {
  Request: PlannerServiceRequest,
  Response: PlannerServiceResponse,
  md5sum() { return 'e7bc30e0b0a79c76a0ad1244f8818092'; },
  datatype() { return 'planning_msgs/PlannerService'; }
};
