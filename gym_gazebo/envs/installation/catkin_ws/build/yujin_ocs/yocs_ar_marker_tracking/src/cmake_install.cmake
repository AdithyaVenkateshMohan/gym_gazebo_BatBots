# Install script for directory: /home/caplab/Batbots/gymBatbot/gym_gazebo_BatBots/gym_gazebo/envs/installation/catkin_ws/src/yujin_ocs/yocs_ar_marker_tracking/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/caplab/Batbots/gymBatbot/gym_gazebo_BatBots/gym_gazebo/envs/installation/catkin_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/yocs_ar_marker_tracking/yocs_ar_marker_tracking_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/yocs_ar_marker_tracking/yocs_ar_marker_tracking_node")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/yocs_ar_marker_tracking/yocs_ar_marker_tracking_node"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/yocs_ar_marker_tracking" TYPE EXECUTABLE FILES "/home/caplab/Batbots/gymBatbot/gym_gazebo_BatBots/gym_gazebo/envs/installation/catkin_ws/devel/lib/yocs_ar_marker_tracking/yocs_ar_marker_tracking_node")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/yocs_ar_marker_tracking/yocs_ar_marker_tracking_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/yocs_ar_marker_tracking/yocs_ar_marker_tracking_node")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/yocs_ar_marker_tracking/yocs_ar_marker_tracking_node"
         OLD_RPATH "/home/caplab/Batbots/gymBatbot/gym_gazebo_BatBots/gym_gazebo/envs/installation/catkin_ws/devel/lib:/opt/ros/kinetic/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/yocs_ar_marker_tracking/yocs_ar_marker_tracking_node")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/caplab/Batbots/gymBatbot/gym_gazebo_BatBots/gym_gazebo/envs/installation/catkin_ws/build/yujin_ocs/yocs_ar_marker_tracking/src/lib/cmake_install.cmake")

endif()

