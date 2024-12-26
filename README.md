# ROS2 different Cpp packages library include example 

This is an example showing how to include a library from a package to another package. The folder tree is shown as below:
```
src/
├── listener_pkg
│   ├── CMakeLists.txt
│   ├── include
│   │   └── listener_pkg
│   └── src
│       └── listener.cpp
└── talker_pkg
    ├── CMakeLists.txt
    ├── include
    │   └── talker_pkg
    │       └── hello_world.hpp
    └── src
        ├── hello_world.cpp
        └── talker.cpp

```
Inside the `talker_pkg`, there is a `hello_world.hpp` which will simply print a "Hello world from talker_pkg." line. The goal of this example is to let listener_pkg able to include the `hello_world.hpp` as well.

## Installation
Clone the whole workspace to local.
```
git clone https://github.com/richard98hess444/ros2_cpp_ws.git
```
Build it with compile commands, it allows Vscode to correctly configure the ROS2 environment inside the `c_cpp_properties.json` file.
```
colcon build --symlink-install --cmake-args -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
```

## Run the code
The `talker_pkg` and `listener_pkg` are just the examples from the [ROS2 Tutorial](https://docs.ros.org/en/foxy/Tutorials/Beginner-Client-Libraries/Writing-A-Simple-Cpp-Publisher-And-Subscriber.html#writing-a-simple-publisher-and-subscriber-c). We modify the `CMakeLists.txt` of `talker_pkg` and export the `hello_world.hpp` library so that `listener_pkg` can use it if its `CMakeLists.txt` is set correctly.

To play the two packages, source the environment and run these command in separate terminals.
```
ros2 run talker_pkg talker
ros2 run listener_pkg listener
```

The listener is able to hear the topic from talker and print "Hello world from talker_pkg.".