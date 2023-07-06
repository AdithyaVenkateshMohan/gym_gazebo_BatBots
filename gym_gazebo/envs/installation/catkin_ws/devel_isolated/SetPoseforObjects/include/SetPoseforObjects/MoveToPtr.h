// Generated by gencpp from file SetPoseforObjects/MoveToPtr.msg
// DO NOT EDIT!


#ifndef SETPOSEFOROBJECTS_MESSAGE_MOVETOPTR_H
#define SETPOSEFOROBJECTS_MESSAGE_MOVETOPTR_H

#include <ros/service_traits.h>


#include <SetPoseforObjects/MoveToPtrRequest.h>
#include <SetPoseforObjects/MoveToPtrResponse.h>


namespace SetPoseforObjects
{

struct MoveToPtr
{

typedef MoveToPtrRequest Request;
typedef MoveToPtrResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct MoveToPtr
} // namespace SetPoseforObjects


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::SetPoseforObjects::MoveToPtr > {
  static const char* value()
  {
    return "fc1a53656a802a1870723eb9f98ec389";
  }

  static const char* value(const ::SetPoseforObjects::MoveToPtr&) { return value(); }
};

template<>
struct DataType< ::SetPoseforObjects::MoveToPtr > {
  static const char* value()
  {
    return "SetPoseforObjects/MoveToPtr";
  }

  static const char* value(const ::SetPoseforObjects::MoveToPtr&) { return value(); }
};


// service_traits::MD5Sum< ::SetPoseforObjects::MoveToPtrRequest> should match 
// service_traits::MD5Sum< ::SetPoseforObjects::MoveToPtr > 
template<>
struct MD5Sum< ::SetPoseforObjects::MoveToPtrRequest>
{
  static const char* value()
  {
    return MD5Sum< ::SetPoseforObjects::MoveToPtr >::value();
  }
  static const char* value(const ::SetPoseforObjects::MoveToPtrRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::SetPoseforObjects::MoveToPtrRequest> should match 
// service_traits::DataType< ::SetPoseforObjects::MoveToPtr > 
template<>
struct DataType< ::SetPoseforObjects::MoveToPtrRequest>
{
  static const char* value()
  {
    return DataType< ::SetPoseforObjects::MoveToPtr >::value();
  }
  static const char* value(const ::SetPoseforObjects::MoveToPtrRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::SetPoseforObjects::MoveToPtrResponse> should match 
// service_traits::MD5Sum< ::SetPoseforObjects::MoveToPtr > 
template<>
struct MD5Sum< ::SetPoseforObjects::MoveToPtrResponse>
{
  static const char* value()
  {
    return MD5Sum< ::SetPoseforObjects::MoveToPtr >::value();
  }
  static const char* value(const ::SetPoseforObjects::MoveToPtrResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::SetPoseforObjects::MoveToPtrResponse> should match 
// service_traits::DataType< ::SetPoseforObjects::MoveToPtr > 
template<>
struct DataType< ::SetPoseforObjects::MoveToPtrResponse>
{
  static const char* value()
  {
    return DataType< ::SetPoseforObjects::MoveToPtr >::value();
  }
  static const char* value(const ::SetPoseforObjects::MoveToPtrResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // SETPOSEFOROBJECTS_MESSAGE_MOVETOPTR_H