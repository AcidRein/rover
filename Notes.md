# Basic Notes #
Source ROS2 essentials (On each new terminal) `source /opt/ros/humble/setup.bash`
Created packages using (in src dir) `ros2 pkg create --build-type ament_cmake --license Apache-2.0 --node-name my_node my_package`
Check dependencies `rosdep install -i --from-path src --rosdistro humble -y`
build specific packages (in root ws) `colcon build --packages-select your_package_name`
build all packages (in root ws) `colcon build`
Add/update packages to environment (After building packages, inside root ws) `source install/setup.bash`
Run node `ros2 run my_package_name my_node_name`

# Other
include `<depend> dependency_name </depend>` in package.xml
include (optional) `ament_target_dependencies(talker rclcpp std_msgs)` in CMakeLists.txt