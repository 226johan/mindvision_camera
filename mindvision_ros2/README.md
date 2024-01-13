###create 11_12 by johan

### build
    colcon build
    . install/setup.bash

### 启动相机节点

    ros2 launch mindvision_camera mv_launch.py

### 订阅发布的数据
    ros2 run ros2_cv_pkg cv_subscription

