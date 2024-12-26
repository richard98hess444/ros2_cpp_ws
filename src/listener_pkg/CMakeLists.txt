cmake_minimum_required(VERSION 3.8)
project(listener_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(talker_pkg REQUIRED)

include_directories(include/listener_pkg)

add_executable(listener src/listener.cpp)
target_link_libraries(listener talker_pkg::talker_function)
ament_target_dependencies(listener rclcpp std_msgs talker_pkg)

install(
  TARGETS listener
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
