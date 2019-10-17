// Generated by gencpp from file mavros_msgs/CommandBool.msg
// DO NOT EDIT!


#ifndef MAVROS_MSGS_MESSAGE_COMMANDBOOL_H
#define MAVROS_MSGS_MESSAGE_COMMANDBOOL_H

#include <ros/service_traits.h>


#include <mavros_msgs/CommandBoolRequest.h>
#include <mavros_msgs/CommandBoolResponse.h>


namespace mavros_msgs
{

struct CommandBool
{

typedef CommandBoolRequest Request;
typedef CommandBoolResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct CommandBool
} // namespace mavros_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::mavros_msgs::CommandBool > {
  static const char* value()
  {
    return "e09abbb4e5bae6b558e5010966eb6e9e";
  }

  static const char* value(const ::mavros_msgs::CommandBool&) { return value(); }
};

template<>
struct DataType< ::mavros_msgs::CommandBool > {
  static const char* value()
  {
    return "mavros_msgs/CommandBool";
  }

  static const char* value(const ::mavros_msgs::CommandBool&) { return value(); }
};


// service_traits::MD5Sum< ::mavros_msgs::CommandBoolRequest> should match 
// service_traits::MD5Sum< ::mavros_msgs::CommandBool > 
template<>
struct MD5Sum< ::mavros_msgs::CommandBoolRequest>
{
  static const char* value()
  {
    return MD5Sum< ::mavros_msgs::CommandBool >::value();
  }
  static const char* value(const ::mavros_msgs::CommandBoolRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::mavros_msgs::CommandBoolRequest> should match 
// service_traits::DataType< ::mavros_msgs::CommandBool > 
template<>
struct DataType< ::mavros_msgs::CommandBoolRequest>
{
  static const char* value()
  {
    return DataType< ::mavros_msgs::CommandBool >::value();
  }
  static const char* value(const ::mavros_msgs::CommandBoolRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::mavros_msgs::CommandBoolResponse> should match 
// service_traits::MD5Sum< ::mavros_msgs::CommandBool > 
template<>
struct MD5Sum< ::mavros_msgs::CommandBoolResponse>
{
  static const char* value()
  {
    return MD5Sum< ::mavros_msgs::CommandBool >::value();
  }
  static const char* value(const ::mavros_msgs::CommandBoolResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::mavros_msgs::CommandBoolResponse> should match 
// service_traits::DataType< ::mavros_msgs::CommandBool > 
template<>
struct DataType< ::mavros_msgs::CommandBoolResponse>
{
  static const char* value()
  {
    return DataType< ::mavros_msgs::CommandBool >::value();
  }
  static const char* value(const ::mavros_msgs::CommandBoolResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // MAVROS_MSGS_MESSAGE_COMMANDBOOL_H