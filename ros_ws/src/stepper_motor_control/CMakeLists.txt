cmake_minimum_required(VERSION 3.0.2)
project(stepper_motor_control)


find_package(catkin REQUIRED COMPONENTS
  rospy
  rosserial_arduino
  message_generation
  std_msgs
)


 add_service_files(
   FILES
  comms1.srv
)


 generate_messages(
   DEPENDENCIES
   std_msgs
 )



catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES stepper_motor_control
  CATKIN_DEPENDS message_runtime
  DEPENDS std_msgs
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)


