/*
Publisher node to send a random float between 0.1 - 2.0 to the 'temperature_topic' topic, simulating temperature changes received by a
temperature checker. The random float function is inside the PackageSubystem.cpp file.
*/

#include <chrono>
#include <memory>

#include "PackageSubsystem.hpp"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"

using namespace std::chrono_literals;

class temperaturePublisher : public rclcpp::Node {
  public:
    // Initializing a new node
    temperaturePublisher() : Node("temperature_publisher") { 
    // Create publisher topic
    publisher_ = this->create_publisher<std_msgs::msg::Float32>("temperature_topic", 10); 
    // Publish interval
    timer_ = this->create_wall_timer(500ms, std::bind(&temperaturePublisher::timer_callback, this)); 
    }

  private:
  // On publish interval
  void timer_callback() {
    // Create Message
    std_msgs::msg::Float32 temp_reading;
    temp_reading.data = temperatureChange();
    // Publish and log Message
    RCLCPP_INFO(this->get_logger(), "Temperature Change Published: '%f'", temp_reading.data);
    publisher_->publish(temp_reading);
  }
  // Publisher and Timer variables
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr publisher_;
};