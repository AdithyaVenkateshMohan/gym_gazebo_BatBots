// Generated by gencpp from file kobuki_msgs/RobotStateEvent.msg
// DO NOT EDIT!


#ifndef KOBUKI_MSGS_MESSAGE_ROBOTSTATEEVENT_H
#define KOBUKI_MSGS_MESSAGE_ROBOTSTATEEVENT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace kobuki_msgs
{
template <class ContainerAllocator>
struct RobotStateEvent_
{
  typedef RobotStateEvent_<ContainerAllocator> Type;

  RobotStateEvent_()
    : state(0)  {
    }
  RobotStateEvent_(const ContainerAllocator& _alloc)
    : state(0)  {
  (void)_alloc;
    }



   typedef uint8_t _state_type;
  _state_type state;



  enum {
    ONLINE = 1u,
    OFFLINE = 0u,
  };


  typedef boost::shared_ptr< ::kobuki_msgs::RobotStateEvent_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::kobuki_msgs::RobotStateEvent_<ContainerAllocator> const> ConstPtr;

}; // struct RobotStateEvent_

typedef ::kobuki_msgs::RobotStateEvent_<std::allocator<void> > RobotStateEvent;

typedef boost::shared_ptr< ::kobuki_msgs::RobotStateEvent > RobotStateEventPtr;
typedef boost::shared_ptr< ::kobuki_msgs::RobotStateEvent const> RobotStateEventConstPtr;

// constants requiring out of line definition

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::kobuki_msgs::RobotStateEvent_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::kobuki_msgs::RobotStateEvent_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace kobuki_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'kobuki_msgs': ['/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/src/kobuki_msgs/msg', '/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/kobuki_msgs/share/kobuki_msgs/msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::kobuki_msgs::RobotStateEvent_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::kobuki_msgs::RobotStateEvent_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::kobuki_msgs::RobotStateEvent_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::kobuki_msgs::RobotStateEvent_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::kobuki_msgs::RobotStateEvent_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::kobuki_msgs::RobotStateEvent_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::kobuki_msgs::RobotStateEvent_<ContainerAllocator> >
{
  static const char* value()
  {
    return "c6eccd4cb1f95df95635b56d6226ea32";
  }

  static const char* value(const ::kobuki_msgs::RobotStateEvent_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xc6eccd4cb1f95df9ULL;
  static const uint64_t static_value2 = 0x5635b56d6226ea32ULL;
};

template<class ContainerAllocator>
struct DataType< ::kobuki_msgs::RobotStateEvent_<ContainerAllocator> >
{
  static const char* value()
  {
    return "kobuki_msgs/RobotStateEvent";
  }

  static const char* value(const ::kobuki_msgs::RobotStateEvent_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::kobuki_msgs::RobotStateEvent_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Provides a robot state event\n\
# This message is generated whenever the robot gets online/offline\n\
\n\
uint8 ONLINE  = 1\n\
uint8 OFFLINE = 0\n\
\n\
uint8 state\n\
";
  }

  static const char* value(const ::kobuki_msgs::RobotStateEvent_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::kobuki_msgs::RobotStateEvent_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.state);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct RobotStateEvent_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::kobuki_msgs::RobotStateEvent_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::kobuki_msgs::RobotStateEvent_<ContainerAllocator>& v)
  {
    s << indent << "state: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.state);
  }
};

} // namespace message_operations
} // namespace ros

#endif // KOBUKI_MSGS_MESSAGE_ROBOTSTATEEVENT_H
