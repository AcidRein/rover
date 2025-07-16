/*
Main Script will initialize ROS2 and spin the node(s) to life.
*/
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"
#include "SubNode.cpp"

int main(int argc, char ** argv)
{
  // Init ROS2
  rclcpp::init(argc, argv);
  // Spin subscriber node
  rclcpp::spin(std::make_shared<temperatureSubscriber>());
  rclcpp::shutdown();
  return 0;
}
