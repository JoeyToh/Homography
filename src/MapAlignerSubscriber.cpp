#include "ros/ros.h"
#include "std_msgs/Bool.h"
#include "Homography.h"

void mapAlignerCallback(const std_msgs::Bool::ConstPtr& msg) {
  run();
}

int main(int argc, char **argv) {

  ros::init(argc, argv, "map_aligner_subscriber");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("map_aligner", 1000, mapAlignerCallback);
  ros::spin();

  return 0;
}