# -*- coding: utf-8 -*-
from __future__ import print_function
import argparse
import os
import stat
import sys

# find the import for catkin's python package - either from source space or from an installed underlay
if os.path.exists(os.path.join('/opt/ros/kinetic/share/catkin/cmake', 'catkinConfig.cmake.in')):
    sys.path.insert(0, os.path.join('/opt/ros/kinetic/share/catkin/cmake', '..', 'python'))
try:
    from catkin.environment_cache import generate_environment_script
except ImportError:
    # search for catkin package in all workspaces and prepend to path
    for workspace in "/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/controller_manager_tests;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/controller_manager;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/control_toolbox;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/realtime_tools;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/ps3joy;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/kobuki_gazebo_plugins;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/hector_gazebo_thermal_camera;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/gazebo_plugins;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/polled_camera;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/planning_msgs;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/perception_pcl;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/pcl_ros;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/navigation;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/move_base_msgs;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/mavros_extras;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/mavros;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/mavros_msgs;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/mav_msgs;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/mav_comm;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/amcl;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/map_server;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/libmavconn;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/kobuki_rviz_launchers;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/kobuki_rapps;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/kobuki_keyop;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/kobuki_dashboard;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/kobuki_bumper2pc;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/kobuki_auto_docking;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/kobuki_msgs;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/kobuki_gazebo;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/kobuki_ftdi;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/kobuki_driver;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/kobuki_dock_drive;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/kobuki_desktop;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/kobuki_core;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/kobuki_capabilities;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/kobuki;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/joystick_drivers;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/joy;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/joint_limits_interface;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/camera_info_manager;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/image_transport;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/image_common;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/hector_sensors_gazebo;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/hector_gazebo_worlds;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/hector_gazebo_plugins;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/hector_gazebo;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/controller_interface;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/hardware_interface;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/gazebo_ros_pkgs;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/gazebo_ros;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/gazebo_msgs;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/fake_localization;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/driver_common;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/driver_base;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/create_node;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/create_driver;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/create_description;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/controller_manager_msgs;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/catkin_simple;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/camera_calibration_parsers;/opt/ros/kinetic".split(';'):
        python_path = os.path.join(workspace, 'lib/python2.7/dist-packages')
        if os.path.isdir(os.path.join(python_path, 'catkin')):
            sys.path.insert(0, python_path)
            break
    from catkin.environment_cache import generate_environment_script

code = generate_environment_script('/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/robot_pose_ekf/env.sh')

output_filename = '/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/build_isolated/robot_pose_ekf/catkin_generated/setup_cached.sh'
with open(output_filename, 'w') as f:
    #print('Generate script for cached setup "%s"' % output_filename)
    f.write('\n'.join(code))

mode = os.stat(output_filename).st_mode
os.chmod(output_filename, mode | stat.S_IXUSR)
