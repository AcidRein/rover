/*
Main Script will initialize ROS2 and spin the nodes to life.
*/
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"
#include "PubNode.cpp"

int main(int argc, char ** argv) {
  // Init ROS2
  rclcpp::init(argc, argv);
  // Spin publisher node
  rclcpp::spin(std::make_shared<temperaturePublisher>());
  rclcpp::shutdown();
  return 0;
}
