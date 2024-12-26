#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "hello_world.hpp"

using namespace std::chrono_literals;

class TalkerPublisher : public rclcpp::Node
{
private:
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  size_t count_;
  void timer_callback()
  {
    auto message = std_msgs::msg::String();
    std_msgs::msg::String();
    message.data = "Hello, world! " + std::to_string(count_++);
    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
    publisher_->publish(message);
  }

public:
  TalkerPublisher() : Node("minimal_publisher"),
                      count_(0)
  {
    publisher_ = this->create_publisher<std_msgs::msg::String>("talker_topic", 10);
    timer_ = this->create_wall_timer(
        500ms, std::bind(&TalkerPublisher::timer_callback, this));
  }
};

int main(int argc, char *argv[])
{
  HelloWorld();
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<TalkerPublisher>());
  rclcpp::shutdown();
  return 0;
}