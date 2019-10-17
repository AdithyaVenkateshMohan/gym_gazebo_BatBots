// Generated by gencpp from file mav_msgs/CommandTrajectory.msg
// DO NOT EDIT!


#ifndef MAV_MSGS_MESSAGE_COMMANDTRAJECTORY_H
#define MAV_MSGS_MESSAGE_COMMANDTRAJECTORY_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Vector3.h>

namespace mav_msgs
{
template <class ContainerAllocator>
struct CommandTrajectory_
{
  typedef CommandTrajectory_<ContainerAllocator> Type;

  CommandTrajectory_()
    : header()
    , position()
    , velocity()
    , acceleration()
    , jerk()
    , snap()
    , yaw(0.0)
    , yaw_rate(0.0)  {
    }
  CommandTrajectory_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , position(_alloc)
    , velocity(_alloc)
    , acceleration(_alloc)
    , jerk(_alloc)
    , snap(_alloc)
    , yaw(0.0)
    , yaw_rate(0.0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _position_type;
  _position_type position;

   typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _velocity_type;
  _velocity_type velocity;

   typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _acceleration_type;
  _acceleration_type acceleration;

   typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _jerk_type;
  _jerk_type jerk;

   typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _snap_type;
  _snap_type snap;

   typedef double _yaw_type;
  _yaw_type yaw;

   typedef double _yaw_rate_type;
  _yaw_rate_type yaw_rate;





  typedef boost::shared_ptr< ::mav_msgs::CommandTrajectory_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::mav_msgs::CommandTrajectory_<ContainerAllocator> const> ConstPtr;

}; // struct CommandTrajectory_

typedef ::mav_msgs::CommandTrajectory_<std::allocator<void> > CommandTrajectory;

typedef boost::shared_ptr< ::mav_msgs::CommandTrajectory > CommandTrajectoryPtr;
typedef boost::shared_ptr< ::mav_msgs::CommandTrajectory const> CommandTrajectoryConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::mav_msgs::CommandTrajectory_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::mav_msgs::CommandTrajectory_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::mav_msgs::CommandTrajectory_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mav_msgs::CommandTrajectory_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mav_msgs::CommandTrajectory_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mav_msgs::CommandTrajectory_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mav_msgs::CommandTrajectory_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mav_msgs::CommandTrajectory_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::mav_msgs::CommandTrajectory_<ContainerAllocator> >
{
  static const char* value()
  {
    return "1993f299145e41178a7764791630d855";
  }

  static const char* value(const ::mav_msgs::CommandTrajectory_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x1993f299145e4117ULL;
  static const uint64_t static_value2 = 0x8a7764791630d855ULL;
};

template<class ContainerAllocator>
struct DataType< ::mav_msgs::CommandTrajectory_<ContainerAllocator> >
{
  static const char* value()
  {
    return "mav_msgs/CommandTrajectory";
  }

  static const char* value(const ::mav_msgs::CommandTrajectory_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::mav_msgs::CommandTrajectory_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
\n\
# Message should be expressed in the frame_id specified in the header.\n\
\n\
geometry_msgs/Vector3 position      # [m]\n\
geometry_msgs/Vector3 velocity      # [m/s]\n\
geometry_msgs/Vector3 acceleration  # [m/s^2]\n\
geometry_msgs/Vector3 jerk          # [m/s^3]\n\
geometry_msgs/Vector3 snap          # [m/s^4]\n\
float64 yaw                         # [rad]\n\
float64 yaw_rate                    # [rad/s]\n\
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
";
  }

  static const char* value(const ::mav_msgs::CommandTrajectory_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::mav_msgs::CommandTrajectory_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.position);
      stream.next(m.velocity);
      stream.next(m.acceleration);
      stream.next(m.jerk);
      stream.next(m.snap);
      stream.next(m.yaw);
      stream.next(m.yaw_rate);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct CommandTrajectory_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::mav_msgs::CommandTrajectory_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::mav_msgs::CommandTrajectory_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "position: ";
    s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.position);
    s << indent << "velocity: ";
    s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.velocity);
    s << indent << "acceleration: ";
    s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.acceleration);
    s << indent << "jerk: ";
    s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.jerk);
    s << indent << "snap: ";
    s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.snap);
    s << indent << "yaw: ";
    Printer<double>::stream(s, indent + "  ", v.yaw);
    s << indent << "yaw_rate: ";
    Printer<double>::stream(s, indent + "  ", v.yaw_rate);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MAV_MSGS_MESSAGE_COMMANDTRAJECTORY_H
