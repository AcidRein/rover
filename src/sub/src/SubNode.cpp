#include <memory>

#include "PackageSubsystem.hpp"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"

class temperatureSubscriber : public rclcpp::Node
{
public:
  temperatureSubscriber() : Node("temperature_subscriber") {
    // On subscription topic receive, call 'topic_callback()' with the temperature changes
    subscription_ = this->create_subscription<std_msgs::msg::Float32>("temperature_topic", 10, 
        std::bind(&temperatureSubscriber::topic_callback, this, std::placeholders::_1));
  }

private:
  void topic_callback(const std_msgs::msg::Float32::SharedPtr msg) {
    // Output incoming topic
    RCLCPP_INFO(this->get_logger(), "Temperature Change Received: '%f'", msg->data);
    // Store new temperature (inside of PackagSubsystem.cpp)
    float temp = msg->data;
    temp_memory.temperatureChange(temp);
    // Get new temperature
    float currTemp = temp_memory.getTemperature();
    // Optional usage of new temperature (such as notifying when it is overheating)
    printf("Current Temperature: %f\n", currTemp);
    if (currTemp > 50.0f) {
        printf("Temperature Too Hot!\n");
    }
  }
  // Initialize variables
  CurrentTemperature temp_memory;
  rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr subscription_;
};