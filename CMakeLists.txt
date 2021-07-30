cmake_minimum_required(VERSION 3.5)
project(map_aligner_optimizer)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)

find_package(Ceres REQUIRED COMPONENTS)
find_package(Eigen3 REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(JSONCPP jsoncpp)

catkin_package(
  CATKIN_DEPENDS roscpp rospy std_msgs message_runtime
)

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${JSONCPP_INCLUDE_DIRS}
)

link_libraries(${JSONCPP_LIBRARIES})

add_executable(homography src/Homography.cc)
add_executable(map_aligner_subscriber src/MapAlignerSubscriber.cpp)

target_link_libraries(map_aligner_subscriber ${catkin_LIBRARIES})
target_link_libraries(homography Ceres::ceres)
target_link_libraries(homography ${JSONCPP_LIBRARIES})