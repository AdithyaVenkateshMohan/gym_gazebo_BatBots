## *********************************************************
##
## File autogenerated for the create_node package
## by the dynamic_reconfigure package.
## Please do not edit.
##
## ********************************************************/

from dynamic_reconfigure.encoding import extract_params

inf = float('inf')

config_description = {'upper': 'DEFAULT', 'lower': 'groups', 'srcline': 245, 'name': 'Default', 'parent': 0, 'srcfile': '/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'cstate': 'true', 'parentname': 'Default', 'class': 'DEFAULT', 'field': 'default', 'state': True, 'parentclass': '', 'groups': [], 'parameters': [{'srcline': 290, 'description': 'Polling rate for the irobot create.', 'max': 30.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'update_rate', 'edit_method': '', 'default': 30.0, 'level': 0, 'min': 5.0, 'type': 'double'}, {'srcline': 290, 'description': 'The possible drive modes (twist, turtle, drive).', 'max': '', 'cconsttype': 'const char * const', 'ctype': 'std::string', 'srcfile': '/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'drive_mode', 'edit_method': "{'enum_description': '', 'enum': [{'srcline': 10, 'description': 'Takes a geometry_msgs/Twist message and is navigation compatible.', 'srcfile': '/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/src/turtlebot_create/create_node/cfg/TurtleBot.cfg', 'cconsttype': 'const char * const', 'value': 'twist', 'ctype': 'std::string', 'type': 'str', 'name': 'twist'}, {'srcline': 11, 'description': 'Takes a create_node/Turtle message and is turtlesim compatible.', 'srcfile': '/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/src/turtlebot_create/create_node/cfg/TurtleBot.cfg', 'cconsttype': 'const char * const', 'value': 'turtle', 'ctype': 'std::string', 'type': 'str', 'name': 'turtle'}, {'srcline': 12, 'description': 'Takes a create_node/Drive message which drives the TurtleBot as described in the iRobot Create manual.', 'srcfile': '/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/src/turtlebot_create/create_node/cfg/TurtleBot.cfg', 'cconsttype': 'const char * const', 'value': 'drive', 'ctype': 'std::string', 'type': 'str', 'name': 'drive'}]}", 'default': 'twist', 'level': 0, 'min': '', 'type': 'str'}, {'srcline': 290, 'description': 'How long to wait before timing out on a velocity command..', 'max': 1.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'cmd_vel_timeout', 'edit_method': '', 'default': 0.6, 'level': 0, 'min': 0.0, 'type': 'double'}, {'srcline': 290, 'description': 'Stops motors when the bumps sensor is hit.', 'max': True, 'cconsttype': 'const bool', 'ctype': 'bool', 'srcfile': '/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'stop_motors_on_bump', 'edit_method': '', 'default': True, 'level': 0, 'min': False, 'type': 'bool'}, {'srcline': 290, 'description': 'Enables or disables the gyro.', 'max': True, 'cconsttype': 'const bool', 'ctype': 'bool', 'srcfile': '/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'has_gyro', 'edit_method': '', 'default': True, 'level': 0, 'min': False, 'type': 'bool'}, {'srcline': 290, 'description': 'Scaling factor for correct gyro operation.', 'max': 6.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'gyro_scale_correction', 'edit_method': '', 'default': 1.35, 'level': 0, 'min': 0.0, 'type': 'double'}, {'srcline': 290, 'description': 'Measurement range supported by gyro.', 'max': 300.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'gyro_measurement_range', 'edit_method': "{'enum_description': 'Gyro Options', 'enum': [{'srcline': 24, 'description': 'ADXRS613 150deg/s', 'srcfile': '/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/src/turtlebot_create/create_node/cfg/TurtleBot.cfg', 'cconsttype': 'const double', 'value': 150.0, 'ctype': 'double', 'type': 'double', 'name': 'ADXRS613'}, {'srcline': 25, 'description': 'ADXRS652 250deg/s', 'srcfile': '/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/src/turtlebot_create/create_node/cfg/TurtleBot.cfg', 'cconsttype': 'const double', 'value': 250.0, 'ctype': 'double', 'type': 'double', 'name': 'ADXRS652'}, {'srcline': 26, 'description': 'ADXRS642 300deg/s', 'srcfile': '/home/adithya/ReinfLearn/gym/gym-gazebo/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/src/turtlebot_create/create_node/cfg/TurtleBot.cfg', 'cconsttype': 'const double', 'value': 300.0, 'ctype': 'double', 'type': 'double', 'name': 'ADXRS642'}]}", 'default': 150.0, 'level': 0, 'min': 0.0, 'type': 'double'}, {'srcline': 290, 'description': 'A correction applied to the computation of the rotation in the odometry.', 'max': 3.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'odom_angular_scale_correction', 'edit_method': '', 'default': 1.0, 'level': 0, 'min': 0.0, 'type': 'double'}, {'srcline': 290, 'description': 'A correction applied to the computation of the translation in odometry.', 'max': 3.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'odom_linear_scale_correction', 'edit_method': '', 'default': 1.0, 'level': 0, 'min': 0.0, 'type': 'double'}, {'srcline': 290, 'description': 'Minimum angular velocity of the TurtleBot.', 'max': 3.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'min_abs_yaw_vel', 'edit_method': '', 'default': 0, 'level': 0, 'min': 0.0, 'type': 'double'}, {'srcline': 290, 'description': 'Maximum angular velocity of the TurtleBot.', 'max': 3.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'max_abs_yaw_vel', 'edit_method': '', 'default': 0, 'level': 0, 'min': 0.0, 'type': 'double'}], 'type': '', 'id': 0}

min = {}
max = {}
defaults = {}
level = {}
type = {}
all_level = 0

#def extract_params(config):
#    params = []
#    params.extend(config['parameters'])
#    for group in config['groups']:
#        params.extend(extract_params(group))
#    return params

for param in extract_params(config_description):
    min[param['name']] = param['min']
    max[param['name']] = param['max']
    defaults[param['name']] = param['default']
    level[param['name']] = param['level']
    type[param['name']] = param['type']
    all_level = all_level | param['level']

TurtleBot_twist = 'twist'
TurtleBot_turtle = 'turtle'
TurtleBot_drive = 'drive'
TurtleBot_ADXRS613 = 150.0
TurtleBot_ADXRS652 = 250.0
TurtleBot_ADXRS642 = 300.0
