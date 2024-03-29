// Generated by gencpp from file mavros_msgs/HomePosition.msg
// DO NOT EDIT!


#ifndef MAVROS_MSGS_MESSAGE_HOMEPOSITION_H
#define MAVROS_MSGS_MESSAGE_HOMEPOSITION_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/Vector3.h>

namespace mavros_msgs
{
template <class ContainerAllocator>
struct HomePosition_
{
  typedef HomePosition_<ContainerAllocator> Type;

  HomePosition_()
    : header()
    , latitude(0.0)
    , longitude(0.0)
    , altitude(0.0)
    , position()
    , orientation()
    , approach()  {
    }
  HomePosition_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , latitude(0.0)
    , longitude(0.0)
    , altitude(0.0)
    , position(_alloc)
    , orientation(_alloc)
    , approach(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef double _latitude_type;
  _latitude_type latitude;

   typedef double _longitude_type;
  _longitude_type longitude;

   typedef float _altitude_type;
  _altitude_type altitude;

   typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _position_type;
  _position_type position;

   typedef  ::geometry_msgs::Quaternion_<ContainerAllocator>  _orientation_type;
  _orientation_type orientation;

   typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _approach_type;
  _approach_type approach;





  typedef boost::shared_ptr< ::mavros_msgs::HomePosition_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::mavros_msgs::HomePosition_<ContainerAllocator> const> ConstPtr;

}; // struct HomePosition_

typedef ::mavros_msgs::HomePosition_<std::allocator<void> > HomePosition;

typedef boost::shared_ptr< ::mavros_msgs::HomePosition > HomePositionPtr;
typedef boost::shared_ptr< ::mavros_msgs::HomePosition const> HomePositionConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::mavros_msgs::HomePosition_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::mavros_msgs::HomePosition_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::mavros_msgs::HomePosition_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mavros_msgs::HomePosition_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mavros_msgs::HomePosition_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mavros_msgs::HomePosition_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mavros_msgs::HomePosition_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mavros_msgs::HomePosition_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::mavros_msgs::HomePosition_<ContainerAllocator> >
{
  static const char* value()
  {
    return "fe09e06cf41e29a63fae614876d148fa";
  }

  static const char* value(const ::mavros_msgs::HomePosition_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xfe09e06cf41e29a6ULL;
  static const uint64_t static_value2 = 0x3fae614876d148faULL;
};

template<class ContainerAllocator>
struct DataType< ::mavros_msgs::HomePosition_<ContainerAllocator> >
{
  static const char* value()
  {
    return "mavros_msgs/HomePosition";
  }

  static const char* value(const ::mavros_msgs::HomePosition_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::mavros_msgs::HomePosition_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# MAVLink message: HOME_POSITION\n\
# http://mavlink.org/messages/common#HOME_POSITION\n\
\n\
std_msgs/Header header\n\
\n\
float64 latitude	# WGS84\n\
float64 longitude\n\
float32 altitude	# AMSL\n\
\n\
geometry_msgs/Vector3 position	# local position\n\
geometry_msgs/Quaternion orientation	# XXX: verify field name (q[4])\n\
geometry_msgs/Vector3 approach	# position of the end of approach vector\n\
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
\n\
================================================================================\n\
MSG: geometry_msgs/Vector3\n\
# This represents a vector in free space. \n\
# It is only meant to represent a direction. Therefore, it does not\n\
# make sense to apply a translation to it (e.g., when applying a \n\
# generic rigid transformation to a Vector3, tf2 will only apply the\n\
# rotation). If you want your data to be translatable too, use the\n\
# geometry_msgs/Point message instead.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
================================================================================\n\
MSG: geometry_msgs/Quaternion\n\
# This represents an orientation in free space in quaternion form.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 w\n\
";
  }

  static const char* value(const ::mavros_msgs::HomePosition_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::mavros_msgs::HomePosition_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.latitude);
      stream.next(m.longitude);
      stream.next(m.altitude);
      stream.next(m.position);
      stream.next(m.orientation);
      stream.next(m.approach);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct HomePosition_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::mavros_msgs::HomePosition_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::mavros_msgs::HomePosition_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "latitude: ";
    Printer<double>::stream(s, indent + "  ", v.latitude);
    s << indent << "longitude: ";
    Printer<double>::stream(s, indent + "  ", v.longitude);
    s << indent << "altitude: ";
    Printer<float>::stream(s, indent + "  ", v.altitude);
    s << indent << "position: ";
    s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.position);
    s << indent << "orientation: ";
    s << std::endl;
    Printer< ::geometry_msgs::Quaternion_<ContainerAllocator> >::stream(s, indent + "  ", v.orientation);
    s << indent << "approach: ";
    s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.approach);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MAVROS_MSGS_MESSAGE_HOMEPOSITION_H
