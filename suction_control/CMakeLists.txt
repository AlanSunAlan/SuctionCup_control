cmake_minimum_required(VERSION 2.8.3)
project(suction_control)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  rosserial_python
  std_msgs
  message_generation
)

## Generate services in the 'srv' folder
add_service_files(
   DIRECTORY
   FILES
   Suction.srv
)


## Generate added messages and services with any dependencies listed here
generate_messages(
   DEPENDENCIES
   std_msgs
)

catkin_package(
   INCLUDE_DIRS include
#   LIBRARIES suction_control
#  CATKIN_DEPENDS roscpp rospy rosserial_python std_msgs
#  DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(suction_server src/suction_server.cpp)
target_link_libraries(suction_server ${catkin_LIBRARIES})
add_dependencies(suction_server suction_control_generate_messages_cpp)