// Generated by gencpp from file kobuki_msgs/SensorState.msg
// DO NOT EDIT!


#ifndef KOBUKI_MSGS_MESSAGE_SENSORSTATE_H
#define KOBUKI_MSGS_MESSAGE_SENSORSTATE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace kobuki_msgs
{
template <class ContainerAllocator>
struct SensorState_
{
  typedef SensorState_<ContainerAllocator> Type;

  SensorState_()
    : header()
    , time_stamp(0)
    , bumper(0)
    , wheel_drop(0)
    , cliff(0)
    , left_encoder(0)
    , right_encoder(0)
    , left_pwm(0)
    , right_pwm(0)
    , buttons(0)
    , charger(0)
    , battery(0)
    , bottom()
    , current()
    , over_current(0)
    , digital_input(0)
    , analog_input()  {
    }
  SensorState_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , time_stamp(0)
    , bumper(0)
    , wheel_drop(0)
    , cliff(0)
    , left_encoder(0)
    , right_encoder(0)
    , left_pwm(0)
    , right_pwm(0)
    , buttons(0)
    , charger(0)
    , battery(0)
    , bottom(_alloc)
    , current(_alloc)
    , over_current(0)
    , digital_input(0)
    , analog_input(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef uint16_t _time_stamp_type;
  _time_stamp_type time_stamp;

   typedef uint8_t _bumper_type;
  _bumper_type bumper;

   typedef uint8_t _wheel_drop_type;
  _wheel_drop_type wheel_drop;

   typedef uint8_t _cliff_type;
  _cliff_type cliff;

   typedef uint16_t _left_encoder_type;
  _left_encoder_type left_encoder;

   typedef uint16_t _right_encoder_type;
  _right_encoder_type right_encoder;

   typedef int8_t _left_pwm_type;
  _left_pwm_type left_pwm;

   typedef int8_t _right_pwm_type;
  _right_pwm_type right_pwm;

   typedef uint8_t _buttons_type;
  _buttons_type buttons;

   typedef uint8_t _charger_type;
  _charger_type charger;

   typedef uint8_t _battery_type;
  _battery_type battery;

   typedef std::vector<uint16_t, typename ContainerAllocator::template rebind<uint16_t>::other >  _bottom_type;
  _bottom_type bottom;

   typedef std::vector<uint8_t, typename ContainerAllocator::template rebind<uint8_t>::other >  _current_type;
  _current_type current;

   typedef uint8_t _over_current_type;
  _over_current_type over_current;

   typedef uint16_t _digital_input_type;
  _digital_input_type digital_input;

   typedef std::vector<uint16_t, typename ContainerAllocator::template rebind<uint16_t>::other >  _analog_input_type;
  _analog_input_type analog_input;



  enum {
    BUMPER_RIGHT = 1u,
    BUMPER_CENTRE = 2u,
    BUMPER_LEFT = 4u,
    WHEEL_DROP_RIGHT = 1u,
    WHEEL_DROP_LEFT = 2u,
    CLIFF_RIGHT = 1u,
    CLIFF_CENTRE = 2u,
    CLIFF_LEFT = 4u,
    BUTTON0 = 1u,
    BUTTON1 = 2u,
    BUTTON2 = 4u,
    DISCHARGING = 0u,
    DOCKING_CHARGED = 2u,
    DOCKING_CHARGING = 6u,
    ADAPTER_CHARGED = 18u,
    ADAPTER_CHARGING = 22u,
    OVER_CURRENT_LEFT_WHEEL = 1u,
    OVER_CURRENT_RIGHT_WHEEL = 2u,
    OVER_CURRENT_BOTH_WHEELS = 3u,
    DIGITAL_INPUT0 = 1u,
    DIGITAL_INPUT1 = 2u,
    DIGITAL_INPUT2 = 4u,
    DIGITAL_INPUT3 = 8u,
    DB25_TEST_BOARD_CONNECTED = 64u,
  };


  typedef boost::shared_ptr< ::kobuki_msgs::SensorState_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::kobuki_msgs::SensorState_<ContainerAllocator> const> ConstPtr;

}; // struct SensorState_

typedef ::kobuki_msgs::SensorState_<std::allocator<void> > SensorState;

typedef boost::shared_ptr< ::kobuki_msgs::SensorState > SensorStatePtr;
typedef boost::shared_ptr< ::kobuki_msgs::SensorState const> SensorStateConstPtr;

// constants requiring out of line definition

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::kobuki_msgs::SensorState_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::kobuki_msgs::SensorState_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace kobuki_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'kobuki_msgs': ['/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/src/kobuki_msgs/msg', '/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/kobuki_msgs/share/kobuki_msgs/msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::kobuki_msgs::SensorState_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::kobuki_msgs::SensorState_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::kobuki_msgs::SensorState_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::kobuki_msgs::SensorState_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::kobuki_msgs::SensorState_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::kobuki_msgs::SensorState_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::kobuki_msgs::SensorState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "430a4bfd78449c8740bfef32b26613a6";
  }

  static const char* value(const ::kobuki_msgs::SensorState_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x430a4bfd78449c87ULL;
  static const uint64_t static_value2 = 0x40bfef32b26613a6ULL;
};

template<class ContainerAllocator>
struct DataType< ::kobuki_msgs::SensorState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "kobuki_msgs/SensorState";
  }

  static const char* value(const ::kobuki_msgs::SensorState_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::kobuki_msgs::SensorState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Kobuki Sensor Data Messages\n\
#\n\
# For more direct simple interactions (buttons, leds, gyro, motor velocity\n\
# etc) use the other topics. This provides detailed information about the\n\
# entire state package that is transmitted at 50Hz from the robot.\n\
#\n\
\n\
\n\
###### CONSTANTS ######\n\
# Bumper states (states are combined, when multiple bumpers are pressed)\n\
uint8 BUMPER_RIGHT  = 1\n\
uint8 BUMPER_CENTRE = 2\n\
uint8 BUMPER_LEFT   = 4\n\
\n\
# Wheel drop sensor states (states are combined, when both wheel drop sensors are triggered)\n\
uint8 WHEEL_DROP_RIGHT = 1\n\
uint8 WHEEL_DROP_LEFT  = 2\n\
\n\
# Cliff sensor states (states are combined, when multiple cliff sensors are triggered)\n\
uint8 CLIFF_RIGHT  = 1\n\
uint8 CLIFF_CENTRE = 2\n\
uint8 CLIFF_LEFT   = 4\n\
\n\
# Button states (only one button can be triggered at a time)\n\
uint8 BUTTON0 = 1\n\
uint8 BUTTON1 = 2\n\
uint8 BUTTON2 = 4\n\
\n\
# Charger state is a combination of charging device (adapter, docking station)\n\
# and state (charging, charged, discharging):\n\
uint8 DISCHARGING      = 0\n\
uint8 DOCKING_CHARGED  = 2\n\
uint8 DOCKING_CHARGING = 6\n\
uint8 ADAPTER_CHARGED  = 18\n\
uint8 ADAPTER_CHARGING = 22\n\
\n\
# Over current states\n\
uint8 OVER_CURRENT_LEFT_WHEEL  = 1\n\
uint8 OVER_CURRENT_RIGHT_WHEEL = 2\n\
uint8 OVER_CURRENT_BOTH_WHEELS = 3\n\
\n\
# Digital input states (states are combined, when multiple inputs are set at the same time)\n\
# When connecting Yujin's test board, it acts as pull-up what inverts the behaviour:\n\
# No input: 79, all inputs set (e.g. buttons pressed): 64\n\
uint8 DIGITAL_INPUT0 = 1\n\
uint8 DIGITAL_INPUT1 = 2\n\
uint8 DIGITAL_INPUT2 = 4\n\
uint8 DIGITAL_INPUT3 = 8\n\
uint8 DB25_TEST_BOARD_CONNECTED = 64\n\
\n\
###### MESSAGE ######\n\
\n\
Header header\n\
\n\
###################\n\
# Core Packet\n\
###################\n\
uint16 time_stamp      # milliseconds starting when turning on Kobuki (max. 65536, then starts from 0 again)\n\
uint8  bumper          # see bumper states\n\
uint8  wheel_drop      # see wheel drop sensor states\n\
uint8  cliff           # see cliff sensor states\n\
uint16 left_encoder    # accumulated ticks left wheel starting with turning on Kobuki (max. 65535)\n\
uint16 right_encoder   # accumulated ticks right wheel starting with turning on Kobuki (max. 65535)\n\
int8   left_pwm        # % of applied maximum voltage left wheel: -100 (max. voltage backward) to +100 (max. voltage forward)\n\
int8   right_pwm       # % of applied maximum voltage right wheel: -100 (max. voltage backward) to +100 (max. voltage forward)\n\
uint8  buttons         # see button states\n\
uint8  charger         # see charger states\n\
uint8  battery         # battery voltage in 0.1V (ex. 16.1V -> 161)\n\
\n\
###################\n\
# Cliff Packet\n\
###################\n\
uint16[] bottom        # ADC output of the right, centre, left cliff PSD sensor (0 - 4095, distance measure is non-linear)\n\
\n\
###################\n\
# Current Packet\n\
###################\n\
uint8[] current        # motor current for the left and right motor in 10mA (ex. 12 -> 120mA)\n\
uint8   over_current   # see over current states\n\
\n\
###################\n\
# Input Packet\n\
###################\n\
uint16   digital_input # see digital input states; will show garbage when nothing is connected\n\
uint16[] analog_input  # ADC values for the 4 analog inputs; 0 - 4095: 0.0 - 3.3V; will show garbage when nothing is connected\n\
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

  static const char* value(const ::kobuki_msgs::SensorState_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::kobuki_msgs::SensorState_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.time_stamp);
      stream.next(m.bumper);
      stream.next(m.wheel_drop);
      stream.next(m.cliff);
      stream.next(m.left_encoder);
      stream.next(m.right_encoder);
      stream.next(m.left_pwm);
      stream.next(m.right_pwm);
      stream.next(m.buttons);
      stream.next(m.charger);
      stream.next(m.battery);
      stream.next(m.bottom);
      stream.next(m.current);
      stream.next(m.over_current);
      stream.next(m.digital_input);
      stream.next(m.analog_input);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SensorState_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::kobuki_msgs::SensorState_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::kobuki_msgs::SensorState_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "time_stamp: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.time_stamp);
    s << indent << "bumper: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.bumper);
    s << indent << "wheel_drop: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.wheel_drop);
    s << indent << "cliff: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.cliff);
    s << indent << "left_encoder: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.left_encoder);
    s << indent << "right_encoder: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.right_encoder);
    s << indent << "left_pwm: ";
    Printer<int8_t>::stream(s, indent + "  ", v.left_pwm);
    s << indent << "right_pwm: ";
    Printer<int8_t>::stream(s, indent + "  ", v.right_pwm);
    s << indent << "buttons: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.buttons);
    s << indent << "charger: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.charger);
    s << indent << "battery: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.battery);
    s << indent << "bottom[]" << std::endl;
    for (size_t i = 0; i < v.bottom.size(); ++i)
    {
      s << indent << "  bottom[" << i << "]: ";
      Printer<uint16_t>::stream(s, indent + "  ", v.bottom[i]);
    }
    s << indent << "current[]" << std::endl;
    for (size_t i = 0; i < v.current.size(); ++i)
    {
      s << indent << "  current[" << i << "]: ";
      Printer<uint8_t>::stream(s, indent + "  ", v.current[i]);
    }
    s << indent << "over_current: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.over_current);
    s << indent << "digital_input: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.digital_input);
    s << indent << "analog_input[]" << std::endl;
    for (size_t i = 0; i < v.analog_input.size(); ++i)
    {
      s << indent << "  analog_input[" << i << "]: ";
      Printer<uint16_t>::stream(s, indent + "  ", v.analog_input[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // KOBUKI_MSGS_MESSAGE_SENSORSTATE_H
