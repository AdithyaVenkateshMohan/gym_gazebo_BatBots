//#line 2 "/opt/ros/kinetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"
// *********************************************************
//
// File autogenerated for the create_node package
// by the dynamic_reconfigure package.
// Please do not edit.
//
// ********************************************************/

#ifndef __create_node__TURTLEBOTCONFIG_H__
#define __create_node__TURTLEBOTCONFIG_H__

#if __cplusplus >= 201103L
#define DYNAMIC_RECONFIGURE_FINAL final
#else
#define DYNAMIC_RECONFIGURE_FINAL
#endif

#include <dynamic_reconfigure/config_tools.h>
#include <limits>
#include <ros/node_handle.h>
#include <dynamic_reconfigure/ConfigDescription.h>
#include <dynamic_reconfigure/ParamDescription.h>
#include <dynamic_reconfigure/Group.h>
#include <dynamic_reconfigure/config_init_mutex.h>
#include <boost/any.hpp>

namespace create_node
{
  class TurtleBotConfigStatics;

  class TurtleBotConfig
  {
  public:
    class AbstractParamDescription : public dynamic_reconfigure::ParamDescription
    {
    public:
      AbstractParamDescription(std::string n, std::string t, uint32_t l,
          std::string d, std::string e)
      {
        name = n;
        type = t;
        level = l;
        description = d;
        edit_method = e;
      }

      virtual void clamp(TurtleBotConfig &config, const TurtleBotConfig &max, const TurtleBotConfig &min) const = 0;
      virtual void calcLevel(uint32_t &level, const TurtleBotConfig &config1, const TurtleBotConfig &config2) const = 0;
      virtual void fromServer(const ros::NodeHandle &nh, TurtleBotConfig &config) const = 0;
      virtual void toServer(const ros::NodeHandle &nh, const TurtleBotConfig &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, TurtleBotConfig &config) const = 0;
      virtual void toMessage(dynamic_reconfigure::Config &msg, const TurtleBotConfig &config) const = 0;
      virtual void getValue(const TurtleBotConfig &config, boost::any &val) const = 0;
    };

    typedef boost::shared_ptr<AbstractParamDescription> AbstractParamDescriptionPtr;
    typedef boost::shared_ptr<const AbstractParamDescription> AbstractParamDescriptionConstPtr;

    // Final keyword added to class because it has virtual methods and inherits
    // from a class with a non-virtual destructor.
    template <class T>
    class ParamDescription DYNAMIC_RECONFIGURE_FINAL : public AbstractParamDescription
    {
    public:
      ParamDescription(std::string a_name, std::string a_type, uint32_t a_level,
          std::string a_description, std::string a_edit_method, T TurtleBotConfig::* a_f) :
        AbstractParamDescription(a_name, a_type, a_level, a_description, a_edit_method),
        field(a_f)
      {}

      T (TurtleBotConfig::* field);

      virtual void clamp(TurtleBotConfig &config, const TurtleBotConfig &max, const TurtleBotConfig &min) const
      {
        if (config.*field > max.*field)
          config.*field = max.*field;

        if (config.*field < min.*field)
          config.*field = min.*field;
      }

      virtual void calcLevel(uint32_t &comb_level, const TurtleBotConfig &config1, const TurtleBotConfig &config2) const
      {
        if (config1.*field != config2.*field)
          comb_level |= level;
      }

      virtual void fromServer(const ros::NodeHandle &nh, TurtleBotConfig &config) const
      {
        nh.getParam(name, config.*field);
      }

      virtual void toServer(const ros::NodeHandle &nh, const TurtleBotConfig &config) const
      {
        nh.setParam(name, config.*field);
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, TurtleBotConfig &config) const
      {
        return dynamic_reconfigure::ConfigTools::getParameter(msg, name, config.*field);
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const TurtleBotConfig &config) const
      {
        dynamic_reconfigure::ConfigTools::appendParameter(msg, name, config.*field);
      }

      virtual void getValue(const TurtleBotConfig &config, boost::any &val) const
      {
        val = config.*field;
      }
    };

    class AbstractGroupDescription : public dynamic_reconfigure::Group
    {
      public:
      AbstractGroupDescription(std::string n, std::string t, int p, int i, bool s)
      {
        name = n;
        type = t;
        parent = p;
        state = s;
        id = i;
      }

      std::vector<AbstractParamDescriptionConstPtr> abstract_parameters;
      bool state;

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &config) const =0;
      virtual void updateParams(boost::any &cfg, TurtleBotConfig &top) const= 0;
      virtual void setInitialState(boost::any &cfg) const = 0;


      void convertParams()
      {
        for(std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = abstract_parameters.begin(); i != abstract_parameters.end(); ++i)
        {
          parameters.push_back(dynamic_reconfigure::ParamDescription(**i));
        }
      }
    };

    typedef boost::shared_ptr<AbstractGroupDescription> AbstractGroupDescriptionPtr;
    typedef boost::shared_ptr<const AbstractGroupDescription> AbstractGroupDescriptionConstPtr;

    // Final keyword added to class because it has virtual methods and inherits
    // from a class with a non-virtual destructor.
    template<class T, class PT>
    class GroupDescription DYNAMIC_RECONFIGURE_FINAL : public AbstractGroupDescription
    {
    public:
      GroupDescription(std::string a_name, std::string a_type, int a_parent, int a_id, bool a_s, T PT::* a_f) : AbstractGroupDescription(a_name, a_type, a_parent, a_id, a_s), field(a_f)
      {
      }

      GroupDescription(const GroupDescription<T, PT>& g): AbstractGroupDescription(g.name, g.type, g.parent, g.id, g.state), field(g.field), groups(g.groups)
      {
        parameters = g.parameters;
        abstract_parameters = g.abstract_parameters;
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        if(!dynamic_reconfigure::ConfigTools::getGroupState(msg, name, (*config).*field))
          return false;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          if(!(*i)->fromMessage(msg, n))
            return false;
        }

        return true;
      }

      virtual void setInitialState(boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        T* group = &((*config).*field);
        group->state = state;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = boost::any(&((*config).*field));
          (*i)->setInitialState(n);
        }

      }

      virtual void updateParams(boost::any &cfg, TurtleBotConfig &top) const
      {
        PT* config = boost::any_cast<PT*>(cfg);

        T* f = &((*config).*field);
        f->setParams(top, abstract_parameters);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          (*i)->updateParams(n, top);
        }
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &cfg) const
      {
        const PT config = boost::any_cast<PT>(cfg);
        dynamic_reconfigure::ConfigTools::appendGroup<T>(msg, name, id, parent, config.*field);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          (*i)->toMessage(msg, config.*field);
        }
      }

      T (PT::* field);
      std::vector<TurtleBotConfig::AbstractGroupDescriptionConstPtr> groups;
    };

class DEFAULT
{
  public:
    DEFAULT()
    {
      state = true;
      name = "Default";
    }

    void setParams(TurtleBotConfig &config, const std::vector<AbstractParamDescriptionConstPtr> params)
    {
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator _i = params.begin(); _i != params.end(); ++_i)
      {
        boost::any val;
        (*_i)->getValue(config, val);

        if("update_rate"==(*_i)->name){update_rate = boost::any_cast<double>(val);}
        if("drive_mode"==(*_i)->name){drive_mode = boost::any_cast<std::string>(val);}
        if("cmd_vel_timeout"==(*_i)->name){cmd_vel_timeout = boost::any_cast<double>(val);}
        if("stop_motors_on_bump"==(*_i)->name){stop_motors_on_bump = boost::any_cast<bool>(val);}
        if("has_gyro"==(*_i)->name){has_gyro = boost::any_cast<bool>(val);}
        if("gyro_scale_correction"==(*_i)->name){gyro_scale_correction = boost::any_cast<double>(val);}
        if("gyro_measurement_range"==(*_i)->name){gyro_measurement_range = boost::any_cast<double>(val);}
        if("odom_angular_scale_correction"==(*_i)->name){odom_angular_scale_correction = boost::any_cast<double>(val);}
        if("odom_linear_scale_correction"==(*_i)->name){odom_linear_scale_correction = boost::any_cast<double>(val);}
        if("min_abs_yaw_vel"==(*_i)->name){min_abs_yaw_vel = boost::any_cast<double>(val);}
        if("max_abs_yaw_vel"==(*_i)->name){max_abs_yaw_vel = boost::any_cast<double>(val);}
      }
    }

    double update_rate;
std::string drive_mode;
double cmd_vel_timeout;
bool stop_motors_on_bump;
bool has_gyro;
double gyro_scale_correction;
double gyro_measurement_range;
double odom_angular_scale_correction;
double odom_linear_scale_correction;
double min_abs_yaw_vel;
double max_abs_yaw_vel;

    bool state;
    std::string name;

    
}groups;



//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double update_rate;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      std::string drive_mode;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double cmd_vel_timeout;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      bool stop_motors_on_bump;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      bool has_gyro;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double gyro_scale_correction;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double gyro_measurement_range;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double odom_angular_scale_correction;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double odom_linear_scale_correction;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double min_abs_yaw_vel;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double max_abs_yaw_vel;
//#line 228 "/opt/ros/kinetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

    bool __fromMessage__(dynamic_reconfigure::Config &msg)
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();

      int count = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        if ((*i)->fromMessage(msg, *this))
          count++;

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i ++)
      {
        if ((*i)->id == 0)
        {
          boost::any n = boost::any(this);
          (*i)->updateParams(n, *this);
          (*i)->fromMessage(msg, n);
        }
      }

      if (count != dynamic_reconfigure::ConfigTools::size(msg))
      {
        ROS_ERROR("TurtleBotConfig::__fromMessage__ called with an unexpected parameter.");
        ROS_ERROR("Booleans:");
        for (unsigned int i = 0; i < msg.bools.size(); i++)
          ROS_ERROR("  %s", msg.bools[i].name.c_str());
        ROS_ERROR("Integers:");
        for (unsigned int i = 0; i < msg.ints.size(); i++)
          ROS_ERROR("  %s", msg.ints[i].name.c_str());
        ROS_ERROR("Doubles:");
        for (unsigned int i = 0; i < msg.doubles.size(); i++)
          ROS_ERROR("  %s", msg.doubles[i].name.c_str());
        ROS_ERROR("Strings:");
        for (unsigned int i = 0; i < msg.strs.size(); i++)
          ROS_ERROR("  %s", msg.strs[i].name.c_str());
        // @todo Check that there are no duplicates. Make this error more
        // explicit.
        return false;
      }
      return true;
    }

    // This version of __toMessage__ is used during initialization of
    // statics when __getParamDescriptions__ can't be called yet.
    void __toMessage__(dynamic_reconfigure::Config &msg, const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__, const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__) const
    {
      dynamic_reconfigure::ConfigTools::clear(msg);
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toMessage(msg, *this);

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        if((*i)->id == 0)
        {
          (*i)->toMessage(msg, *this);
        }
      }
    }

    void __toMessage__(dynamic_reconfigure::Config &msg) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      __toMessage__(msg, __param_descriptions__, __group_descriptions__);
    }

    void __toServer__(const ros::NodeHandle &nh) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toServer(nh, *this);
    }

    void __fromServer__(const ros::NodeHandle &nh)
    {
      static bool setup=false;

      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->fromServer(nh, *this);

      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i++){
        if (!setup && (*i)->id == 0) {
          setup = true;
          boost::any n = boost::any(this);
          (*i)->setInitialState(n);
        }
      }
    }

    void __clamp__()
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const TurtleBotConfig &__max__ = __getMax__();
      const TurtleBotConfig &__min__ = __getMin__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->clamp(*this, __max__, __min__);
    }

    uint32_t __level__(const TurtleBotConfig &config) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      uint32_t level = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->calcLevel(level, config, *this);
      return level;
    }

    static const dynamic_reconfigure::ConfigDescription &__getDescriptionMessage__();
    static const TurtleBotConfig &__getDefault__();
    static const TurtleBotConfig &__getMax__();
    static const TurtleBotConfig &__getMin__();
    static const std::vector<AbstractParamDescriptionConstPtr> &__getParamDescriptions__();
    static const std::vector<AbstractGroupDescriptionConstPtr> &__getGroupDescriptions__();

  private:
    static const TurtleBotConfigStatics *__get_statics__();
  };

  template <> // Max and min are ignored for strings.
  inline void TurtleBotConfig::ParamDescription<std::string>::clamp(TurtleBotConfig &config, const TurtleBotConfig &max, const TurtleBotConfig &min) const
  {
    (void) config;
    (void) min;
    (void) max;
    return;
  }

  class TurtleBotConfigStatics
  {
    friend class TurtleBotConfig;

    TurtleBotConfigStatics()
    {
TurtleBotConfig::GroupDescription<TurtleBotConfig::DEFAULT, TurtleBotConfig> Default("Default", "", 0, 0, true, &TurtleBotConfig::groups);
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.update_rate = 5.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.update_rate = 30.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.update_rate = 30.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(TurtleBotConfig::AbstractParamDescriptionConstPtr(new TurtleBotConfig::ParamDescription<double>("update_rate", "double", 0, "Polling rate for the irobot create.", "", &TurtleBotConfig::update_rate)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(TurtleBotConfig::AbstractParamDescriptionConstPtr(new TurtleBotConfig::ParamDescription<double>("update_rate", "double", 0, "Polling rate for the irobot create.", "", &TurtleBotConfig::update_rate)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.drive_mode = "";
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.drive_mode = "";
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.drive_mode = "twist";
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(TurtleBotConfig::AbstractParamDescriptionConstPtr(new TurtleBotConfig::ParamDescription<std::string>("drive_mode", "str", 0, "The possible drive modes (twist, turtle, drive).", "{'enum_description': '', 'enum': [{'srcline': 10, 'description': 'Takes a geometry_msgs/Twist message and is navigation compatible.', 'srcfile': '/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/src/turtlebot_create/create_node/cfg/TurtleBot.cfg', 'cconsttype': 'const char * const', 'value': 'twist', 'ctype': 'std::string', 'type': 'str', 'name': 'twist'}, {'srcline': 11, 'description': 'Takes a create_node/Turtle message and is turtlesim compatible.', 'srcfile': '/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/src/turtlebot_create/create_node/cfg/TurtleBot.cfg', 'cconsttype': 'const char * const', 'value': 'turtle', 'ctype': 'std::string', 'type': 'str', 'name': 'turtle'}, {'srcline': 12, 'description': 'Takes a create_node/Drive message which drives the TurtleBot as described in the iRobot Create manual.', 'srcfile': '/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/src/turtlebot_create/create_node/cfg/TurtleBot.cfg', 'cconsttype': 'const char * const', 'value': 'drive', 'ctype': 'std::string', 'type': 'str', 'name': 'drive'}]}", &TurtleBotConfig::drive_mode)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(TurtleBotConfig::AbstractParamDescriptionConstPtr(new TurtleBotConfig::ParamDescription<std::string>("drive_mode", "str", 0, "The possible drive modes (twist, turtle, drive).", "{'enum_description': '', 'enum': [{'srcline': 10, 'description': 'Takes a geometry_msgs/Twist message and is navigation compatible.', 'srcfile': '/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/src/turtlebot_create/create_node/cfg/TurtleBot.cfg', 'cconsttype': 'const char * const', 'value': 'twist', 'ctype': 'std::string', 'type': 'str', 'name': 'twist'}, {'srcline': 11, 'description': 'Takes a create_node/Turtle message and is turtlesim compatible.', 'srcfile': '/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/src/turtlebot_create/create_node/cfg/TurtleBot.cfg', 'cconsttype': 'const char * const', 'value': 'turtle', 'ctype': 'std::string', 'type': 'str', 'name': 'turtle'}, {'srcline': 12, 'description': 'Takes a create_node/Drive message which drives the TurtleBot as described in the iRobot Create manual.', 'srcfile': '/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/src/turtlebot_create/create_node/cfg/TurtleBot.cfg', 'cconsttype': 'const char * const', 'value': 'drive', 'ctype': 'std::string', 'type': 'str', 'name': 'drive'}]}", &TurtleBotConfig::drive_mode)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.cmd_vel_timeout = 0.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.cmd_vel_timeout = 1.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.cmd_vel_timeout = 0.6;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(TurtleBotConfig::AbstractParamDescriptionConstPtr(new TurtleBotConfig::ParamDescription<double>("cmd_vel_timeout", "double", 0, "How long to wait before timing out on a velocity command..", "", &TurtleBotConfig::cmd_vel_timeout)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(TurtleBotConfig::AbstractParamDescriptionConstPtr(new TurtleBotConfig::ParamDescription<double>("cmd_vel_timeout", "double", 0, "How long to wait before timing out on a velocity command..", "", &TurtleBotConfig::cmd_vel_timeout)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.stop_motors_on_bump = 0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.stop_motors_on_bump = 1;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.stop_motors_on_bump = 1;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(TurtleBotConfig::AbstractParamDescriptionConstPtr(new TurtleBotConfig::ParamDescription<bool>("stop_motors_on_bump", "bool", 0, "Stops motors when the bumps sensor is hit.", "", &TurtleBotConfig::stop_motors_on_bump)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(TurtleBotConfig::AbstractParamDescriptionConstPtr(new TurtleBotConfig::ParamDescription<bool>("stop_motors_on_bump", "bool", 0, "Stops motors when the bumps sensor is hit.", "", &TurtleBotConfig::stop_motors_on_bump)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.has_gyro = 0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.has_gyro = 1;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.has_gyro = 1;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(TurtleBotConfig::AbstractParamDescriptionConstPtr(new TurtleBotConfig::ParamDescription<bool>("has_gyro", "bool", 0, "Enables or disables the gyro.", "", &TurtleBotConfig::has_gyro)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(TurtleBotConfig::AbstractParamDescriptionConstPtr(new TurtleBotConfig::ParamDescription<bool>("has_gyro", "bool", 0, "Enables or disables the gyro.", "", &TurtleBotConfig::has_gyro)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.gyro_scale_correction = 0.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.gyro_scale_correction = 6.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.gyro_scale_correction = 1.35;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(TurtleBotConfig::AbstractParamDescriptionConstPtr(new TurtleBotConfig::ParamDescription<double>("gyro_scale_correction", "double", 0, "Scaling factor for correct gyro operation.", "", &TurtleBotConfig::gyro_scale_correction)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(TurtleBotConfig::AbstractParamDescriptionConstPtr(new TurtleBotConfig::ParamDescription<double>("gyro_scale_correction", "double", 0, "Scaling factor for correct gyro operation.", "", &TurtleBotConfig::gyro_scale_correction)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.gyro_measurement_range = 0.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.gyro_measurement_range = 300.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.gyro_measurement_range = 150.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(TurtleBotConfig::AbstractParamDescriptionConstPtr(new TurtleBotConfig::ParamDescription<double>("gyro_measurement_range", "double", 0, "Measurement range supported by gyro.", "{'enum_description': 'Gyro Options', 'enum': [{'srcline': 24, 'description': 'ADXRS613 150deg/s', 'srcfile': '/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/src/turtlebot_create/create_node/cfg/TurtleBot.cfg', 'cconsttype': 'const double', 'value': 150.0, 'ctype': 'double', 'type': 'double', 'name': 'ADXRS613'}, {'srcline': 25, 'description': 'ADXRS652 250deg/s', 'srcfile': '/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/src/turtlebot_create/create_node/cfg/TurtleBot.cfg', 'cconsttype': 'const double', 'value': 250.0, 'ctype': 'double', 'type': 'double', 'name': 'ADXRS652'}, {'srcline': 26, 'description': 'ADXRS642 300deg/s', 'srcfile': '/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/src/turtlebot_create/create_node/cfg/TurtleBot.cfg', 'cconsttype': 'const double', 'value': 300.0, 'ctype': 'double', 'type': 'double', 'name': 'ADXRS642'}]}", &TurtleBotConfig::gyro_measurement_range)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(TurtleBotConfig::AbstractParamDescriptionConstPtr(new TurtleBotConfig::ParamDescription<double>("gyro_measurement_range", "double", 0, "Measurement range supported by gyro.", "{'enum_description': 'Gyro Options', 'enum': [{'srcline': 24, 'description': 'ADXRS613 150deg/s', 'srcfile': '/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/src/turtlebot_create/create_node/cfg/TurtleBot.cfg', 'cconsttype': 'const double', 'value': 150.0, 'ctype': 'double', 'type': 'double', 'name': 'ADXRS613'}, {'srcline': 25, 'description': 'ADXRS652 250deg/s', 'srcfile': '/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/src/turtlebot_create/create_node/cfg/TurtleBot.cfg', 'cconsttype': 'const double', 'value': 250.0, 'ctype': 'double', 'type': 'double', 'name': 'ADXRS652'}, {'srcline': 26, 'description': 'ADXRS642 300deg/s', 'srcfile': '/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/src/turtlebot_create/create_node/cfg/TurtleBot.cfg', 'cconsttype': 'const double', 'value': 300.0, 'ctype': 'double', 'type': 'double', 'name': 'ADXRS642'}]}", &TurtleBotConfig::gyro_measurement_range)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.odom_angular_scale_correction = 0.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.odom_angular_scale_correction = 3.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.odom_angular_scale_correction = 1.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(TurtleBotConfig::AbstractParamDescriptionConstPtr(new TurtleBotConfig::ParamDescription<double>("odom_angular_scale_correction", "double", 0, "A correction applied to the computation of the rotation in the odometry.", "", &TurtleBotConfig::odom_angular_scale_correction)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(TurtleBotConfig::AbstractParamDescriptionConstPtr(new TurtleBotConfig::ParamDescription<double>("odom_angular_scale_correction", "double", 0, "A correction applied to the computation of the rotation in the odometry.", "", &TurtleBotConfig::odom_angular_scale_correction)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.odom_linear_scale_correction = 0.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.odom_linear_scale_correction = 3.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.odom_linear_scale_correction = 1.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(TurtleBotConfig::AbstractParamDescriptionConstPtr(new TurtleBotConfig::ParamDescription<double>("odom_linear_scale_correction", "double", 0, "A correction applied to the computation of the translation in odometry.", "", &TurtleBotConfig::odom_linear_scale_correction)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(TurtleBotConfig::AbstractParamDescriptionConstPtr(new TurtleBotConfig::ParamDescription<double>("odom_linear_scale_correction", "double", 0, "A correction applied to the computation of the translation in odometry.", "", &TurtleBotConfig::odom_linear_scale_correction)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.min_abs_yaw_vel = 0.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.min_abs_yaw_vel = 3.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.min_abs_yaw_vel = 0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(TurtleBotConfig::AbstractParamDescriptionConstPtr(new TurtleBotConfig::ParamDescription<double>("min_abs_yaw_vel", "double", 0, "Minimum angular velocity of the TurtleBot.", "", &TurtleBotConfig::min_abs_yaw_vel)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(TurtleBotConfig::AbstractParamDescriptionConstPtr(new TurtleBotConfig::ParamDescription<double>("min_abs_yaw_vel", "double", 0, "Minimum angular velocity of the TurtleBot.", "", &TurtleBotConfig::min_abs_yaw_vel)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.max_abs_yaw_vel = 0.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.max_abs_yaw_vel = 3.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.max_abs_yaw_vel = 0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(TurtleBotConfig::AbstractParamDescriptionConstPtr(new TurtleBotConfig::ParamDescription<double>("max_abs_yaw_vel", "double", 0, "Maximum angular velocity of the TurtleBot.", "", &TurtleBotConfig::max_abs_yaw_vel)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(TurtleBotConfig::AbstractParamDescriptionConstPtr(new TurtleBotConfig::ParamDescription<double>("max_abs_yaw_vel", "double", 0, "Maximum angular velocity of the TurtleBot.", "", &TurtleBotConfig::max_abs_yaw_vel)));
//#line 245 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.convertParams();
//#line 245 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __group_descriptions__.push_back(TurtleBotConfig::AbstractGroupDescriptionConstPtr(new TurtleBotConfig::GroupDescription<TurtleBotConfig::DEFAULT, TurtleBotConfig>(Default)));
//#line 366 "/opt/ros/kinetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

      for (std::vector<TurtleBotConfig::AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        __description_message__.groups.push_back(**i);
      }
      __max__.__toMessage__(__description_message__.max, __param_descriptions__, __group_descriptions__);
      __min__.__toMessage__(__description_message__.min, __param_descriptions__, __group_descriptions__);
      __default__.__toMessage__(__description_message__.dflt, __param_descriptions__, __group_descriptions__);
    }
    std::vector<TurtleBotConfig::AbstractParamDescriptionConstPtr> __param_descriptions__;
    std::vector<TurtleBotConfig::AbstractGroupDescriptionConstPtr> __group_descriptions__;
    TurtleBotConfig __max__;
    TurtleBotConfig __min__;
    TurtleBotConfig __default__;
    dynamic_reconfigure::ConfigDescription __description_message__;

    static const TurtleBotConfigStatics *get_instance()
    {
      // Split this off in a separate function because I know that
      // instance will get initialized the first time get_instance is
      // called, and I am guaranteeing that get_instance gets called at
      // most once.
      static TurtleBotConfigStatics instance;
      return &instance;
    }
  };

  inline const dynamic_reconfigure::ConfigDescription &TurtleBotConfig::__getDescriptionMessage__()
  {
    return __get_statics__()->__description_message__;
  }

  inline const TurtleBotConfig &TurtleBotConfig::__getDefault__()
  {
    return __get_statics__()->__default__;
  }

  inline const TurtleBotConfig &TurtleBotConfig::__getMax__()
  {
    return __get_statics__()->__max__;
  }

  inline const TurtleBotConfig &TurtleBotConfig::__getMin__()
  {
    return __get_statics__()->__min__;
  }

  inline const std::vector<TurtleBotConfig::AbstractParamDescriptionConstPtr> &TurtleBotConfig::__getParamDescriptions__()
  {
    return __get_statics__()->__param_descriptions__;
  }

  inline const std::vector<TurtleBotConfig::AbstractGroupDescriptionConstPtr> &TurtleBotConfig::__getGroupDescriptions__()
  {
    return __get_statics__()->__group_descriptions__;
  }

  inline const TurtleBotConfigStatics *TurtleBotConfig::__get_statics__()
  {
    const static TurtleBotConfigStatics *statics;

    if (statics) // Common case
      return statics;

    boost::mutex::scoped_lock lock(dynamic_reconfigure::__init_mutex__);

    if (statics) // In case we lost a race.
      return statics;

    statics = TurtleBotConfigStatics::get_instance();

    return statics;
  }

//#line 10 "/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/src/turtlebot_create/create_node/cfg/TurtleBot.cfg"
      const char * const TurtleBot_twist = "twist";
//#line 11 "/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/src/turtlebot_create/create_node/cfg/TurtleBot.cfg"
      const char * const TurtleBot_turtle = "turtle";
//#line 12 "/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/src/turtlebot_create/create_node/cfg/TurtleBot.cfg"
      const char * const TurtleBot_drive = "drive";
//#line 24 "/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/src/turtlebot_create/create_node/cfg/TurtleBot.cfg"
      const double TurtleBot_ADXRS613 = 150.0;
//#line 25 "/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/src/turtlebot_create/create_node/cfg/TurtleBot.cfg"
      const double TurtleBot_ADXRS652 = 250.0;
//#line 26 "/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/src/turtlebot_create/create_node/cfg/TurtleBot.cfg"
      const double TurtleBot_ADXRS642 = 300.0;
}

#undef DYNAMIC_RECONFIGURE_FINAL

#endif // __TURTLEBOTRECONFIGURATOR_H__
