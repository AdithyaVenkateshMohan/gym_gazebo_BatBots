# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "SetPoseforObjects: 0 messages, 1 services")

set(MSG_I_FLAGS "-Igazebo_msgs:/home/caplab/Batbots/gymBatbot/gym_gazebo_BatBots/gym_gazebo/envs/installation/catkin_ws/src/gazebo_ros_pkgs/gazebo_msgs/msg;-Igeometry_msgs:/opt/ros/kinetic/share/geometry_msgs/cmake/../msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg;-Isensor_msgs:/opt/ros/kinetic/share/sensor_msgs/cmake/../msg;-Itrajectory_msgs:/opt/ros/kinetic/share/trajectory_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(SetPoseforObjects_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/caplab/Batbots/gymBatbot/gym_gazebo_BatBots/gym_gazebo/envs/installation/catkin_ws/src/batbot_simulator/SetPoseforObjects/srv/MoveToPtr.srv" NAME_WE)
add_custom_target(_SetPoseforObjects_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "SetPoseforObjects" "/home/caplab/Batbots/gymBatbot/gym_gazebo_BatBots/gym_gazebo/envs/installation/catkin_ws/src/batbot_simulator/SetPoseforObjects/srv/MoveToPtr.srv" "geometry_msgs/Quaternion:geometry_msgs/Pose:geometry_msgs/Point"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages

### Generating Services
_generate_srv_cpp(SetPoseforObjects
  "/home/caplab/Batbots/gymBatbot/gym_gazebo_BatBots/gym_gazebo/envs/installation/catkin_ws/src/batbot_simulator/SetPoseforObjects/srv/MoveToPtr.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/SetPoseforObjects
)

### Generating Module File
_generate_module_cpp(SetPoseforObjects
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/SetPoseforObjects
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(SetPoseforObjects_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(SetPoseforObjects_generate_messages SetPoseforObjects_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/caplab/Batbots/gymBatbot/gym_gazebo_BatBots/gym_gazebo/envs/installation/catkin_ws/src/batbot_simulator/SetPoseforObjects/srv/MoveToPtr.srv" NAME_WE)
add_dependencies(SetPoseforObjects_generate_messages_cpp _SetPoseforObjects_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(SetPoseforObjects_gencpp)
add_dependencies(SetPoseforObjects_gencpp SetPoseforObjects_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS SetPoseforObjects_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages

### Generating Services
_generate_srv_eus(SetPoseforObjects
  "/home/caplab/Batbots/gymBatbot/gym_gazebo_BatBots/gym_gazebo/envs/installation/catkin_ws/src/batbot_simulator/SetPoseforObjects/srv/MoveToPtr.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/SetPoseforObjects
)

### Generating Module File
_generate_module_eus(SetPoseforObjects
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/SetPoseforObjects
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(SetPoseforObjects_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(SetPoseforObjects_generate_messages SetPoseforObjects_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/caplab/Batbots/gymBatbot/gym_gazebo_BatBots/gym_gazebo/envs/installation/catkin_ws/src/batbot_simulator/SetPoseforObjects/srv/MoveToPtr.srv" NAME_WE)
add_dependencies(SetPoseforObjects_generate_messages_eus _SetPoseforObjects_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(SetPoseforObjects_geneus)
add_dependencies(SetPoseforObjects_geneus SetPoseforObjects_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS SetPoseforObjects_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages

### Generating Services
_generate_srv_lisp(SetPoseforObjects
  "/home/caplab/Batbots/gymBatbot/gym_gazebo_BatBots/gym_gazebo/envs/installation/catkin_ws/src/batbot_simulator/SetPoseforObjects/srv/MoveToPtr.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/SetPoseforObjects
)

### Generating Module File
_generate_module_lisp(SetPoseforObjects
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/SetPoseforObjects
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(SetPoseforObjects_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(SetPoseforObjects_generate_messages SetPoseforObjects_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/caplab/Batbots/gymBatbot/gym_gazebo_BatBots/gym_gazebo/envs/installation/catkin_ws/src/batbot_simulator/SetPoseforObjects/srv/MoveToPtr.srv" NAME_WE)
add_dependencies(SetPoseforObjects_generate_messages_lisp _SetPoseforObjects_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(SetPoseforObjects_genlisp)
add_dependencies(SetPoseforObjects_genlisp SetPoseforObjects_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS SetPoseforObjects_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages

### Generating Services
_generate_srv_nodejs(SetPoseforObjects
  "/home/caplab/Batbots/gymBatbot/gym_gazebo_BatBots/gym_gazebo/envs/installation/catkin_ws/src/batbot_simulator/SetPoseforObjects/srv/MoveToPtr.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/SetPoseforObjects
)

### Generating Module File
_generate_module_nodejs(SetPoseforObjects
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/SetPoseforObjects
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(SetPoseforObjects_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(SetPoseforObjects_generate_messages SetPoseforObjects_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/caplab/Batbots/gymBatbot/gym_gazebo_BatBots/gym_gazebo/envs/installation/catkin_ws/src/batbot_simulator/SetPoseforObjects/srv/MoveToPtr.srv" NAME_WE)
add_dependencies(SetPoseforObjects_generate_messages_nodejs _SetPoseforObjects_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(SetPoseforObjects_gennodejs)
add_dependencies(SetPoseforObjects_gennodejs SetPoseforObjects_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS SetPoseforObjects_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages

### Generating Services
_generate_srv_py(SetPoseforObjects
  "/home/caplab/Batbots/gymBatbot/gym_gazebo_BatBots/gym_gazebo/envs/installation/catkin_ws/src/batbot_simulator/SetPoseforObjects/srv/MoveToPtr.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/SetPoseforObjects
)

### Generating Module File
_generate_module_py(SetPoseforObjects
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/SetPoseforObjects
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(SetPoseforObjects_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(SetPoseforObjects_generate_messages SetPoseforObjects_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/caplab/Batbots/gymBatbot/gym_gazebo_BatBots/gym_gazebo/envs/installation/catkin_ws/src/batbot_simulator/SetPoseforObjects/srv/MoveToPtr.srv" NAME_WE)
add_dependencies(SetPoseforObjects_generate_messages_py _SetPoseforObjects_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(SetPoseforObjects_genpy)
add_dependencies(SetPoseforObjects_genpy SetPoseforObjects_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS SetPoseforObjects_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/SetPoseforObjects)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/SetPoseforObjects
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET gazebo_msgs_generate_messages_cpp)
  add_dependencies(SetPoseforObjects_generate_messages_cpp gazebo_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(SetPoseforObjects_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(SetPoseforObjects_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/SetPoseforObjects)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/SetPoseforObjects
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET gazebo_msgs_generate_messages_eus)
  add_dependencies(SetPoseforObjects_generate_messages_eus gazebo_msgs_generate_messages_eus)
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(SetPoseforObjects_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(SetPoseforObjects_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/SetPoseforObjects)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/SetPoseforObjects
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET gazebo_msgs_generate_messages_lisp)
  add_dependencies(SetPoseforObjects_generate_messages_lisp gazebo_msgs_generate_messages_lisp)
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(SetPoseforObjects_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(SetPoseforObjects_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/SetPoseforObjects)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/SetPoseforObjects
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET gazebo_msgs_generate_messages_nodejs)
  add_dependencies(SetPoseforObjects_generate_messages_nodejs gazebo_msgs_generate_messages_nodejs)
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(SetPoseforObjects_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(SetPoseforObjects_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/SetPoseforObjects)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/SetPoseforObjects\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/SetPoseforObjects
    DESTINATION ${genpy_INSTALL_DIR}
    # skip all init files
    PATTERN "__init__.py" EXCLUDE
    PATTERN "__init__.pyc" EXCLUDE
  )
  # install init files which are not in the root folder of the generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/SetPoseforObjects
    DESTINATION ${genpy_INSTALL_DIR}
    FILES_MATCHING
    REGEX "${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/SetPoseforObjects/.+/__init__.pyc?$"
  )
endif()
if(TARGET gazebo_msgs_generate_messages_py)
  add_dependencies(SetPoseforObjects_generate_messages_py gazebo_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(SetPoseforObjects_generate_messages_py geometry_msgs_generate_messages_py)
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(SetPoseforObjects_generate_messages_py std_msgs_generate_messages_py)
endif()
