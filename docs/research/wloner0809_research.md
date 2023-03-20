> ROS并不是一个操作系统，而是编写机器人软件程序的一种具有高度灵活性的软件架构。它的实时性全部由它运行在其上的操作系统实现。$\rightarrow$ 可以搭载一个实时性的操作系统

* (`Wikipedia`)	ROS是是一种分布式处理框架。这使可执行文件能被单独设计，并且在运行时松散耦合。这些过程可以封装到**数据包（Packages）和堆栈（Stacks）**中，以便于共享和分发。ROS还支持代码库的联合系统。使得协作亦能被分发。这种从文件系统级别到社区一级的设计让独立地决定发展和实施工作成为可能。上述所有功能都能由ROS的基础工具实现。

> ROS可以分成**两层**，低层是上面描述的操作系统层，高层则是广大用户群贡献的实现不同功能的各种**软件包**，例如定位绘图，行动规划，感知，模拟等等



* `ROS`的主要特点
  * 点对点设计
    * `ROS`通过点对点设计以及服务和节点管理器等机制可以分散实时计算压力
  * 不依赖编程语言
    * `ROS`支持多种现代高级编程语言
  * 精简、模块化、容易集成
  * 便于测试
  * 强大的库



![img](https://img-blog.csdnimg.cn/d4b624e0b6604662810c037ace6eaa11.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2dlem9uZ2Jv,size_16,color_FFFFFF,t_70#pic_center)





> 问`gpt4`基于`ROS`的操作系统项目，如下：

![](image/wloner0809_graph1.png)



[可供参考的blog](https://blog.csdn.net/gezongbo/article/details/119790219)