- 首先进`/opt/ros/humble`
  
  运行：
  
  ```bash
  source setup.bash
  ```
  
  进ros2环境。

- 进目录
  
  ```bash
  mkdir -p ~/ros2_ws/src
  cd ~/ros2_ws/src
  ```

- 使用`colcon`构建工作区
  
  ```bash
  colcon build
  ```
  
  ls以下，colcon创建了新目录：
  
  ```bash
  build  install  log  src
  ```

- 创建包
  
  ```bash
  cd ~/ros2_ws/src
  ```
  
  ```bash
  ros2 pkg create --build-type ament_cmake --node-name my_node my_package
  ```

- 构建一个包
  
  ```bash
  cd ~/ros2_ws
  ```
  
  ```bash
  colcon build
  ```

- 覆盖原来的ros2环境
  
  ```bash
  cd install
  ```
  
  ```bash
  source local_setup.bash
  ```

- 使用包
  
  ```bash
  ros2 run my_package my_node
  ```
  
  输出如下：
  
  ```bash
  hello world my_package package
  ```
  
  
