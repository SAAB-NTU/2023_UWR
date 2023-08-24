# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "logger: 1 messages, 0 services")

set(MSG_I_FLAGS "-Ilogger:/home/saab/Desktop/2023_UWR/ros_ws/src/Rpi_logger_v2/src/logger/msg;-Istd_msgs:/opt/ros/noetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(logger_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/saab/Desktop/2023_UWR/ros_ws/src/Rpi_logger_v2/src/logger/msg/Motor.msg" NAME_WE)
add_custom_target(_logger_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "logger" "/home/saab/Desktop/2023_UWR/ros_ws/src/Rpi_logger_v2/src/logger/msg/Motor.msg" "std_msgs/Header"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(logger
  "/home/saab/Desktop/2023_UWR/ros_ws/src/Rpi_logger_v2/src/logger/msg/Motor.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/logger
)

### Generating Services

### Generating Module File
_generate_module_cpp(logger
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/logger
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(logger_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(logger_generate_messages logger_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/saab/Desktop/2023_UWR/ros_ws/src/Rpi_logger_v2/src/logger/msg/Motor.msg" NAME_WE)
add_dependencies(logger_generate_messages_cpp _logger_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(logger_gencpp)
add_dependencies(logger_gencpp logger_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS logger_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(logger
  "/home/saab/Desktop/2023_UWR/ros_ws/src/Rpi_logger_v2/src/logger/msg/Motor.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/logger
)

### Generating Services

### Generating Module File
_generate_module_eus(logger
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/logger
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(logger_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(logger_generate_messages logger_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/saab/Desktop/2023_UWR/ros_ws/src/Rpi_logger_v2/src/logger/msg/Motor.msg" NAME_WE)
add_dependencies(logger_generate_messages_eus _logger_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(logger_geneus)
add_dependencies(logger_geneus logger_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS logger_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(logger
  "/home/saab/Desktop/2023_UWR/ros_ws/src/Rpi_logger_v2/src/logger/msg/Motor.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/logger
)

### Generating Services

### Generating Module File
_generate_module_lisp(logger
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/logger
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(logger_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(logger_generate_messages logger_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/saab/Desktop/2023_UWR/ros_ws/src/Rpi_logger_v2/src/logger/msg/Motor.msg" NAME_WE)
add_dependencies(logger_generate_messages_lisp _logger_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(logger_genlisp)
add_dependencies(logger_genlisp logger_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS logger_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(logger
  "/home/saab/Desktop/2023_UWR/ros_ws/src/Rpi_logger_v2/src/logger/msg/Motor.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/logger
)

### Generating Services

### Generating Module File
_generate_module_nodejs(logger
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/logger
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(logger_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(logger_generate_messages logger_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/saab/Desktop/2023_UWR/ros_ws/src/Rpi_logger_v2/src/logger/msg/Motor.msg" NAME_WE)
add_dependencies(logger_generate_messages_nodejs _logger_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(logger_gennodejs)
add_dependencies(logger_gennodejs logger_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS logger_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(logger
  "/home/saab/Desktop/2023_UWR/ros_ws/src/Rpi_logger_v2/src/logger/msg/Motor.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/logger
)

### Generating Services

### Generating Module File
_generate_module_py(logger
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/logger
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(logger_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(logger_generate_messages logger_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/saab/Desktop/2023_UWR/ros_ws/src/Rpi_logger_v2/src/logger/msg/Motor.msg" NAME_WE)
add_dependencies(logger_generate_messages_py _logger_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(logger_genpy)
add_dependencies(logger_genpy logger_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS logger_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/logger)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/logger
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(logger_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/logger)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/logger
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(logger_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/logger)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/logger
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(logger_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/logger)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/logger
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(logger_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/logger)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/logger\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/logger
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(logger_generate_messages_py std_msgs_generate_messages_py)
endif()
