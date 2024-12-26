cmake_minimum_required(VERSION 3.8)
project(talker_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

include_directories(include/talker_pkg)

# Export library from talker_pkg
set(HEADER_FILES include/talker_pkg/hello_world.hpp)
add_library(talker_function src/hello_world.cpp ${HEADER_FILES})
ament_export_targets(talker_function HAS_LIBRARY_TARGET)

install(
  DIRECTORY include/talker_pkg
  DESTINATION include
)

install(
  TARGETS talker_function 
  EXPORT talker_function
  # ARCHIVE DESTINATION lib
  # LIBRARY DESTINATION lib
  # RUNTIME DESTINATION bin
  # DESTINATION lib/${PROJECT_NAME}
  INCLUDES DESTINATION include
)

ament_export_include_directories(include/talker_pkg)
ament_export_libraries(talker_function)

# Executable from talker_pkg
add_executable(talker src/talker.cpp)
target_link_libraries(talker talker_function)
ament_target_dependencies(talker rclcpp std_msgs)

install(
  TARGETS talker
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
