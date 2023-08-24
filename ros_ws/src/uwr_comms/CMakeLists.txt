cmake_minimum_required(VERSION 3.0.2)
project(uwr_comms)

find_package(catkin REQUIRED COMPONENTS
  rospy
  message_generation
  std_msgs
)

## Generate services in the 'srv' folder
 add_service_files(
   FILES
  comms1.srv
)

generate_messages(
  DEPENDENCIES
  std_msgs  # Or other packages containing msgs
)


catkin_package(

#  INCLUDE_DIRS include
  #LIBRARIES uwr_comms
  CATKIN_DEPENDS message_runtime
  DEPENDS std_msgs
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)



