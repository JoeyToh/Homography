cmake_minimum_required(VERSION 3.0.2)
project(map_aligner_optimizer)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)

find_package(Ceres REQUIRED)
find_package(Eigen3 REQUIRED)

catkin_package(
  CATKIN_DEPENDS roscpp rospy std_msgs message_runtime
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(map_aligner_subscriber src/MapAlignerSubscriber.cpp)
target_link_libraries(map_aligner_subscriber ${catkin_LIBRARIES})