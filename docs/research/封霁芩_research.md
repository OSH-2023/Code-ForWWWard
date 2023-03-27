# 选题方向初调研（23/03/16）

## 可选范围(摘自PPT)

> 分布式OS
> 移动式OS：如Android
> 实时OS：如ucos freeRTOS
> 机器人操作系统：如ROS
> 分布式文件系统：如DFS
> 内存管理/虚拟化

## 我们可以做的事——

> 写内核
> 优化
> 分布式文件 存储 计算
> 硬件相关
> 安全相关
> 人机交互
> 内存管理/虚拟化
> 进程通信


## 个人调研


### 人机接口：AR  眼动  体感/手势

### 物联网操作系统：

要求：支持物联网硬件  轻量级  嵌入式系统 

[现有操作系统：](https://blog.csdn.net/unsv29/article/details/107894553?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522167885132116800182761790%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=167885132116800182761790&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-3-107894553-null-null.142^v73^insert_down3,201^v4^add_ask,239^v2^insert_chatgpt&utm_term=%E7%89%A9%E8%81%94%E7%BD%91%20%E6%93%8D%E4%BD%9C%E7%B3%BB%E7%BB%9F%20&spm=1018.2226.3001.4187)
1. FreeRTOS 
2. LiteOS
3. Linux裁剪：RT Linux   uClinux
4. AliOS Things  

### 可定制手机操作系统？？

### 汉字操作系统


## 2022OSH项目参考


|组名|方向|内容|
|:--:|:--:|:--:|
|[x-WowKiddy](https://github.com/OSH-2022/x-WowKiddy)|分布式数据平台|图像 视频在线共享|
|[x-runikraft](https://github.com/OSH-2022/x-runikraft)|unikernal|在RISC-V架构上运行的RUST unikernal?|
|[x-QvQ](https://github.com/OSH-2022/x-QvQ)|树莓派内核|语言安全在内核开发中的作用|
|[VR-fancy-office](https://github.com/OSH-2022/VR-fancy-office)|VR系统|导入 控制 操作3D文件|
|[x-NooBirds](https://github.com/OSH-2022/x-NooBirds)|实时操作系统|智能交通系统多个物理终端实时调度|
|[x-realism](https://github.com/OSH-2022/x-realism)|内核|注重性能、并发和安全的微内核操作系统|
|[x-DelayNoMore](https://github.com/OSH-2022/x-DelayNoMore)|分布式系统|基于ROS|
|[x-TOBEDONE](https://github.com/OSH-2022/x-TOBEDONE)|分布式系统|分布式图文件系统|
|[x_do_our_best](https://github.com/OSH-2022/x_do_our_best)|嵌入式系统|基于ROS|

# 移动操作系统调研（23/03/18）

## Android
[源代码](https://www.androidos.net.cn/sourcecode)

[入门指南](http://gityuan.com/android/)

### 可以做的事
- 优化
- 不同ROM之间的比较
- 摄像头实时动态手势识别
- Android 可使用adb命令的终端

($\downarrow$不开源)
~~Android桌面系统~~

~~[JideOS](http://www.jide.com/m/jideos.html)~~

~~Phoenixos OS~~

~~Chrome OS~~


# ROS具体题目调研（23/03/25）


## OSH-2022-x_do_our_best
> 实时内核RT-Thread+ROS
> stm32
> 小车复杂任务+多车调度

展望：
  - 实时+Linux混合内核+ROS
  - 分布式集群节点

## OSH-2022-x_NooBirds
> 实时Linux + 树莓派
> 多个物理终端实时调度
> 多种调度算法比较

展望：
  - 小车对控制命令响应的延迟
  - 不同终端直接通信
  - 离线调度

## OSH-2022-x_DelayNoMore

> ROS2+Ray 分布式计算


## 官方文档
[Demo](https://github.com/ros2/demos)

## ？？
- 进程通信

- 计算

- 硬件相关