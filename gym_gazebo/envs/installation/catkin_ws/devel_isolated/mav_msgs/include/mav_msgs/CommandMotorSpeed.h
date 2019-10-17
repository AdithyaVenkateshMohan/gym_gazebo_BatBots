// Generated by gencpp from file mav_msgs/CommandMotorSpeed.msg
// DO NOT EDIT!


#ifndef MAV_MSGS_MESSAGE_COMMANDMOTORSPEED_H
#define MAV_MSGS_MESSAGE_COMMANDMOTORSPEED_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace mav_msgs
{
template <class ContainerAllocator>
struct CommandMotorSpeed_
{
  typedef CommandMotorSpeed_<ContainerAllocator> Type;

  CommandMotorSpeed_()
    : header()
    , motor_speed()  {
    }
  CommandMotorSpeed_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , motor_speed(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef std::vector<double, typename ContainerAllocator::template rebind<double>::other >  _motor_speed_type;
  _motor_speed_type motor_speed;





  typedef boost::shared_ptr< ::mav_msgs::CommandMotorSpeed_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::mav_msgs::CommandMotorSpeed_<ContainerAllocator> const> ConstPtr;

}; // struct CommandMotorSpeed_

typedef ::mav_msgs::CommandMotorSpeed_<std::allocator<void> > CommandMotorSpeed;

typedef boost::shared_ptr< ::mav_msgs::CommandMotorSpeed > CommandMotorSpeedPtr;
typedef boost::shared_ptr< ::mav_msgs::CommandMotorSpeed const> CommandMotorSpeedConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::mav_msgs::CommandMotorSpeed_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::mav_msgs::CommandMotorSpeed_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace mav_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'mav_msgs': ['/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/src/mav_comm/mav_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::mav_msgs::CommandMotorSpeed_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mav_msgs::CommandMotorSpeed_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mav_msgs::CommandMotorSpeed_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mav_msgs::CommandMotorSpeed_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mav_msgs::CommandMotorSpeed_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mav_msgs::CommandMotorSpeed_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::mav_msgs::CommandMotorSpeed_<ContainerAllocator> >
{
  static const char* value()
  {
    return "061082200f78e4ff571a825255200c0d";
  }

  static const char* value(const ::mav_msgs::CommandMotorSpeed_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x061082200f78e4ffULL;
  static const uint64_t static_value2 = 0x571a825255200c0dULL;
};

template<class ContainerAllocator>
struct DataType< ::mav_msgs::CommandMotorSpeed_<ContainerAllocator> >
{
  static const char* value()
  {
    return "mav_msgs/CommandMotorSpeed";
  }

  static const char* value(const ::mav_msgs::CommandMotorSpeed_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::mav_msgs::CommandMotorSpeed_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
\n\
float64[] motor_speed  # motor speed [rad/s]\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const ::mav_msgs::CommandMotorSpeed_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::mav_msgs::CommandMotorSpeed_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.motor_speed);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct CommandMotorSpeed_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::mav_msgs::CommandMotorSpeed_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::mav_msgs::CommandMotorSpeed_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "motor_speed[]" << std::endl;
    for (size_t i = 0; i < v.motor_speed.size(); ++i)
    {
      s << indent << "  motor_speed[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.motor_speed[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // MAV_MSGS_MESSAGE_COMMANDMOTORSPEED_H
