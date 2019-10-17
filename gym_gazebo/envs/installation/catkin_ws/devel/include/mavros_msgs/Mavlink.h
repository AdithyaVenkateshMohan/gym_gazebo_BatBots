// Generated by gencpp from file mavros_msgs/Mavlink.msg
// DO NOT EDIT!


#ifndef MAVROS_MSGS_MESSAGE_MAVLINK_H
#define MAVROS_MSGS_MESSAGE_MAVLINK_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace mavros_msgs
{
template <class ContainerAllocator>
struct Mavlink_
{
  typedef Mavlink_<ContainerAllocator> Type;

  Mavlink_()
    : header()
    , is_valid(false)
    , len(0)
    , seq(0)
    , sysid(0)
    , compid(0)
    , msgid(0)
    , checksum(0)
    , payload64()  {
    }
  Mavlink_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , is_valid(false)
    , len(0)
    , seq(0)
    , sysid(0)
    , compid(0)
    , msgid(0)
    , checksum(0)
    , payload64(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef uint8_t _is_valid_type;
  _is_valid_type is_valid;

   typedef uint8_t _len_type;
  _len_type len;

   typedef uint8_t _seq_type;
  _seq_type seq;

   typedef uint8_t _sysid_type;
  _sysid_type sysid;

   typedef uint8_t _compid_type;
  _compid_type compid;

   typedef uint8_t _msgid_type;
  _msgid_type msgid;

   typedef uint16_t _checksum_type;
  _checksum_type checksum;

   typedef std::vector<uint64_t, typename ContainerAllocator::template rebind<uint64_t>::other >  _payload64_type;
  _payload64_type payload64;





  typedef boost::shared_ptr< ::mavros_msgs::Mavlink_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::mavros_msgs::Mavlink_<ContainerAllocator> const> ConstPtr;

}; // struct Mavlink_

typedef ::mavros_msgs::Mavlink_<std::allocator<void> > Mavlink;

typedef boost::shared_ptr< ::mavros_msgs::Mavlink > MavlinkPtr;
typedef boost::shared_ptr< ::mavros_msgs::Mavlink const> MavlinkConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::mavros_msgs::Mavlink_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::mavros_msgs::Mavlink_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace mavros_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'mavros_msgs': ['/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/src/mavros/mavros_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::mavros_msgs::Mavlink_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mavros_msgs::Mavlink_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mavros_msgs::Mavlink_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mavros_msgs::Mavlink_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mavros_msgs::Mavlink_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mavros_msgs::Mavlink_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::mavros_msgs::Mavlink_<ContainerAllocator> >
{
  static const char* value()
  {
    return "6dd71a38b8541fdc2de89a548c7dbc2f";
  }

  static const char* value(const ::mavros_msgs::Mavlink_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x6dd71a38b8541fdcULL;
  static const uint64_t static_value2 = 0x2de89a548c7dbc2fULL;
};

template<class ContainerAllocator>
struct DataType< ::mavros_msgs::Mavlink_<ContainerAllocator> >
{
  static const char* value()
  {
    return "mavros_msgs/Mavlink";
  }

  static const char* value(const ::mavros_msgs::Mavlink_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::mavros_msgs::Mavlink_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Mavlink message transport type.\n\
#\n\
# Used to transport mavlink_message_t via ROS topic\n\
#\n\
# :is_valid: flag meaning that there CRC16 error or message is unknown by libmavconn.\n\
#            You may simply drop all non valid messages. Used for GCS Bridge to transport\n\
#            unknown messages.\n\
#\n\
# Please use mavros_msgs::mavlink::convert() from <mavros_msgs/mavlink_convert.h>\n\
# to convert between ROS and MAVLink message type\n\
\n\
std_msgs/Header header\n\
bool is_valid\n\
\n\
uint8 len\n\
uint8 seq\n\
uint8 sysid\n\
uint8 compid\n\
uint8 msgid\n\
uint16 checksum\n\
uint64[] payload64\n\
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

  static const char* value(const ::mavros_msgs::Mavlink_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::mavros_msgs::Mavlink_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.is_valid);
      stream.next(m.len);
      stream.next(m.seq);
      stream.next(m.sysid);
      stream.next(m.compid);
      stream.next(m.msgid);
      stream.next(m.checksum);
      stream.next(m.payload64);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Mavlink_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::mavros_msgs::Mavlink_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::mavros_msgs::Mavlink_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "is_valid: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.is_valid);
    s << indent << "len: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.len);
    s << indent << "seq: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.seq);
    s << indent << "sysid: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.sysid);
    s << indent << "compid: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.compid);
    s << indent << "msgid: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.msgid);
    s << indent << "checksum: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.checksum);
    s << indent << "payload64[]" << std::endl;
    for (size_t i = 0; i < v.payload64.size(); ++i)
    {
      s << indent << "  payload64[" << i << "]: ";
      Printer<uint64_t>::stream(s, indent + "  ", v.payload64[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // MAVROS_MSGS_MESSAGE_MAVLINK_H
