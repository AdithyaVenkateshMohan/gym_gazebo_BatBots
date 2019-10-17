# generated from catkin/cmake/template/pkgConfig.cmake.in

# append elements to a list and remove existing duplicates from the list
# copied from catkin/cmake/list_append_deduplicate.cmake to keep pkgConfig
# self contained
macro(_list_append_deduplicate listname)
  if(NOT "${ARGN}" STREQUAL "")
    if(${listname})
      list(REMOVE_ITEM ${listname} ${ARGN})
    endif()
    list(APPEND ${listname} ${ARGN})
  endif()
endmacro()

# append elements to a list if they are not already in the list
# copied from catkin/cmake/list_append_unique.cmake to keep pkgConfig
# self contained
macro(_list_append_unique listname)
  foreach(_item ${ARGN})
    list(FIND ${listname} ${_item} _index)
    if(_index EQUAL -1)
      list(APPEND ${listname} ${_item})
    endif()
  endforeach()
endmacro()

# pack a list of libraries with optional build configuration keywords
# copied from catkin/cmake/catkin_libraries.cmake to keep pkgConfig
# self contained
macro(_pack_libraries_with_build_configuration VAR)
  set(${VAR} "")
  set(_argn ${ARGN})
  list(LENGTH _argn _count)
  set(_index 0)
  while(${_index} LESS ${_count})
    list(GET _argn ${_index} lib)
    if("${lib}" MATCHES "^(debug|optimized|general)$")
      math(EXPR _index "${_index} + 1")
      if(${_index} EQUAL ${_count})
        message(FATAL_ERROR "_pack_libraries_with_build_configuration() the list of libraries '${ARGN}' ends with '${lib}' which is a build configuration keyword and must be followed by a library")
      endif()
      list(GET _argn ${_index} library)
      list(APPEND ${VAR} "${lib}${CATKIN_BUILD_CONFIGURATION_KEYWORD_SEPARATOR}${library}")
    else()
      list(APPEND ${VAR} "${lib}")
    endif()
    math(EXPR _index "${_index} + 1")
  endwhile()
endmacro()

# unpack a list of libraries with optional build configuration keyword prefixes
# copied from catkin/cmake/catkin_libraries.cmake to keep pkgConfig
# self contained
macro(_unpack_libraries_with_build_configuration VAR)
  set(${VAR} "")
  foreach(lib ${ARGN})
    string(REGEX REPLACE "^(debug|optimized|general)${CATKIN_BUILD_CONFIGURATION_KEYWORD_SEPARATOR}(.+)$" "\\1;\\2" lib "${lib}")
    list(APPEND ${VAR} "${lib}")
  endforeach()
endmacro()


if(joint_limits_interface_CONFIG_INCLUDED)
  return()
endif()
set(joint_limits_interface_CONFIG_INCLUDED TRUE)

# set variables for source/devel/install prefixes
if("TRUE" STREQUAL "TRUE")
  set(joint_limits_interface_SOURCE_PREFIX /home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/src/ros_control/joint_limits_interface)
  set(joint_limits_interface_DEVEL_PREFIX /home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/joint_limits_interface)
  set(joint_limits_interface_INSTALL_PREFIX "")
  set(joint_limits_interface_PREFIX ${joint_limits_interface_DEVEL_PREFIX})
else()
  set(joint_limits_interface_SOURCE_PREFIX "")
  set(joint_limits_interface_DEVEL_PREFIX "")
  set(joint_limits_interface_INSTALL_PREFIX /home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/install_isolated)
  set(joint_limits_interface_PREFIX ${joint_limits_interface_INSTALL_PREFIX})
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "WARNING: package 'joint_limits_interface' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  message("${_msg}")
endif()

# flag project as catkin-based to distinguish if a find_package()-ed project is a catkin project
set(joint_limits_interface_FOUND_CATKIN_PROJECT TRUE)

if(NOT "/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/src/ros_control/joint_limits_interface/include;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/src/ros_control/hardware_interface/include;/opt/ros/kinetic/include;/opt/ros/kinetic/share/xmlrpcpp/cmake/../../../include/xmlrpcpp;/usr/include " STREQUAL " ")
  set(joint_limits_interface_INCLUDE_DIRS "")
  set(_include_dirs "/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/src/ros_control/joint_limits_interface/include;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/src/ros_control/hardware_interface/include;/opt/ros/kinetic/include;/opt/ros/kinetic/share/xmlrpcpp/cmake/../../../include/xmlrpcpp;/usr/include")
  if(NOT "https://github.com/ros-controls/ros_control/issues " STREQUAL " ")
    set(_report "Check the issue tracker 'https://github.com/ros-controls/ros_control/issues' and consider creating a ticket if the problem has not been reported yet.")
  elseif(NOT "https://github.com/ros-controls/ros_control/wiki " STREQUAL " ")
    set(_report "Check the website 'https://github.com/ros-controls/ros_control/wiki' for information and consider reporting the problem.")
  else()
    set(_report "Report the problem to the maintainer 'Adolfo Rodriguez Tsouroukdissian <adolfo.rodriguez@pal-robotics.com>' and request to fix the problem.")
  endif()
  foreach(idir ${_include_dirs})
    if(IS_ABSOLUTE ${idir} AND IS_DIRECTORY ${idir})
      set(include ${idir})
    elseif("${idir} " STREQUAL "include ")
      get_filename_component(include "${joint_limits_interface_DIR}/../../../include" ABSOLUTE)
      if(NOT IS_DIRECTORY ${include})
        message(FATAL_ERROR "Project 'joint_limits_interface' specifies '${idir}' as an include dir, which is not found.  It does not exist in '${include}'.  ${_report}")
      endif()
    else()
      message(FATAL_ERROR "Project 'joint_limits_interface' specifies '${idir}' as an include dir, which is not found.  It does neither exist as an absolute directory nor in '/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/src/ros_control/joint_limits_interface/${idir}'.  ${_report}")
    endif()
    _list_append_unique(joint_limits_interface_INCLUDE_DIRS ${include})
  endforeach()
endif()

set(libraries "/opt/ros/kinetic/lib/liburdf.so;/usr/lib/x86_64-linux-gnu/libtinyxml.so;/opt/ros/kinetic/lib/librosconsole_bridge.so;/opt/ros/kinetic/lib/libroscpp.so;/usr/lib/x86_64-linux-gnu/libboost_filesystem.so;/usr/lib/x86_64-linux-gnu/libboost_signals.so;/opt/ros/kinetic/lib/librosconsole.so;/opt/ros/kinetic/lib/librosconsole_log4cxx.so;/opt/ros/kinetic/lib/librosconsole_backend_interface.so;/usr/lib/x86_64-linux-gnu/liblog4cxx.so;/usr/lib/x86_64-linux-gnu/libboost_regex.so;/opt/ros/kinetic/lib/libroscpp_serialization.so;/opt/ros/kinetic/lib/libxmlrpcpp.so;/opt/ros/kinetic/lib/librostime.so;/opt/ros/kinetic/lib/libcpp_common.so;/usr/lib/x86_64-linux-gnu/libboost_system.so;/usr/lib/x86_64-linux-gnu/libboost_thread.so;/usr/lib/x86_64-linux-gnu/libboost_chrono.so;/usr/lib/x86_64-linux-gnu/libboost_date_time.so;/usr/lib/x86_64-linux-gnu/libboost_atomic.so;/usr/lib/x86_64-linux-gnu/libpthread.so;/usr/lib/x86_64-linux-gnu/liburdfdom_sensor.so;/usr/lib/x86_64-linux-gnu/liburdfdom_model_state.so;/usr/lib/x86_64-linux-gnu/liburdfdom_model.so;/usr/lib/x86_64-linux-gnu/liburdfdom_world.so;/usr/lib/x86_64-linux-gnu/libconsole_bridge.so")
foreach(library ${libraries})
  # keep build configuration keywords, target names and absolute libraries as-is
  if("${library}" MATCHES "^(debug|optimized|general)$")
    list(APPEND joint_limits_interface_LIBRARIES ${library})
  elseif(${library} MATCHES "^-l")
    list(APPEND joint_limits_interface_LIBRARIES ${library})
  elseif(TARGET ${library})
    list(APPEND joint_limits_interface_LIBRARIES ${library})
  elseif(IS_ABSOLUTE ${library})
    list(APPEND joint_limits_interface_LIBRARIES ${library})
  else()
    set(lib_path "")
    set(lib "${library}-NOTFOUND")
    # since the path where the library is found is returned we have to iterate over the paths manually
    foreach(path /home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/joint_limits_interface/lib;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/camera_info_manager/lib;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/image_transport/lib;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/image_common/lib;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/hector_sensors_gazebo/lib;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/hector_gazebo_worlds/lib;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/hector_gazebo_plugins/lib;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/hector_gazebo/lib;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/controller_interface/lib;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/hardware_interface/lib;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/gazebo_ros_pkgs/lib;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/gazebo_ros/lib;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/gazebo_msgs/lib;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/fake_localization/lib;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/driver_common/lib;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/driver_base/lib;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/create_node/lib;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/create_driver/lib;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/create_description/lib;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/controller_manager_msgs/lib;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/catkin_simple/lib;/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/devel_isolated/camera_calibration_parsers/lib;/opt/ros/kinetic/lib)
      find_library(lib ${library}
        PATHS ${path}
        NO_DEFAULT_PATH NO_CMAKE_FIND_ROOT_PATH)
      if(lib)
        set(lib_path ${path})
        break()
      endif()
    endforeach()
    if(lib)
      _list_append_unique(joint_limits_interface_LIBRARY_DIRS ${lib_path})
      list(APPEND joint_limits_interface_LIBRARIES ${lib})
    else()
      # as a fall back for non-catkin libraries try to search globally
      find_library(lib ${library})
      if(NOT lib)
        message(FATAL_ERROR "Project '${PROJECT_NAME}' tried to find library '${library}'.  The library is neither a target nor built/installed properly.  Did you compile project 'joint_limits_interface'?  Did you find_package() it before the subdirectory containing its code is included?")
      endif()
      list(APPEND joint_limits_interface_LIBRARIES ${lib})
    endif()
  endif()
endforeach()

set(joint_limits_interface_EXPORTED_TARGETS "")
# create dummy targets for exported code generation targets to make life of users easier
foreach(t ${joint_limits_interface_EXPORTED_TARGETS})
  if(NOT TARGET ${t})
    add_custom_target(${t})
  endif()
endforeach()

set(depends "roscpp;hardware_interface;urdf")
foreach(depend ${depends})
  string(REPLACE " " ";" depend_list ${depend})
  # the package name of the dependency must be kept in a unique variable so that it is not overwritten in recursive calls
  list(GET depend_list 0 joint_limits_interface_dep)
  list(LENGTH depend_list count)
  if(${count} EQUAL 1)
    # simple dependencies must only be find_package()-ed once
    if(NOT ${joint_limits_interface_dep}_FOUND)
      find_package(${joint_limits_interface_dep} REQUIRED NO_MODULE)
    endif()
  else()
    # dependencies with components must be find_package()-ed again
    list(REMOVE_AT depend_list 0)
    find_package(${joint_limits_interface_dep} REQUIRED NO_MODULE ${depend_list})
  endif()
  _list_append_unique(joint_limits_interface_INCLUDE_DIRS ${${joint_limits_interface_dep}_INCLUDE_DIRS})

  # merge build configuration keywords with library names to correctly deduplicate
  _pack_libraries_with_build_configuration(joint_limits_interface_LIBRARIES ${joint_limits_interface_LIBRARIES})
  _pack_libraries_with_build_configuration(_libraries ${${joint_limits_interface_dep}_LIBRARIES})
  _list_append_deduplicate(joint_limits_interface_LIBRARIES ${_libraries})
  # undo build configuration keyword merging after deduplication
  _unpack_libraries_with_build_configuration(joint_limits_interface_LIBRARIES ${joint_limits_interface_LIBRARIES})

  _list_append_unique(joint_limits_interface_LIBRARY_DIRS ${${joint_limits_interface_dep}_LIBRARY_DIRS})
  list(APPEND joint_limits_interface_EXPORTED_TARGETS ${${joint_limits_interface_dep}_EXPORTED_TARGETS})
endforeach()

set(pkg_cfg_extras "")
foreach(extra ${pkg_cfg_extras})
  if(NOT IS_ABSOLUTE ${extra})
    set(extra ${joint_limits_interface_DIR}/${extra})
  endif()
  include(${extra})
endforeach()
