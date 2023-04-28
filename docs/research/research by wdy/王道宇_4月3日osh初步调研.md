#### 项目背景

- `ROS`的具体任务
  
  - 树莓派的`ROS`小车：[知乎专栏：搭建Arduino+树莓派ROS的小车](https://zhuanlan.zhihu.com/p/389331316)
  
  - 我觉得不错的`ROS`教程，强烈推荐，感觉很贴近我们的环境，稍微有点老，但是无妨：[Introduction · Autolabor-ROS机器人入门课程《ROS理论与实践》零基础教程](http://www.autolabor.com.cn/book/ROSTutorials/)
  
  - 包括教程中与树莓派的联系：[8.5.1 控制系统实现_树莓派概述 · Autolabor-ROS机器人入门课程《ROS理论与实践》零基础教程](http://www.autolabor.com.cn/book/ROSTutorials/di-8-zhang-gou-jian-lun-shi-cha-fen-ji-qi-ren/87-ji-qi-ren-ping-tai-she-ji-zhi-kong-zhi-xi-tong/871-kong-zhi-xi-tong-shi-xian.html)

#### 理论知识

- cache的简要介绍
  
  - 程序如何运行？
    
    程序是运行在`RAM`中的，`RAM`就是我们常说的`DDR`（`DDR3`、`DDR4`、`DDR5`），我们称之为主存`main memory`。当我们需要运行一个进程的时候，首先会从磁盘设备（例如，`eMMC`、`UFS`、`SSD`等）中将可执行程序`load`到主存中，然后开始执行。在`CPU`内部存在一堆的通用寄存器（`register`）。
    
    大概过程类似这样：
    
    ![](https://github.com/OSH-2023/forwwward/blob/main/docs/research/image/4%E6%9C%883%E6%97%A5%E7%8E%8B%E9%81%93%E5%AE%87_pic/4%E6%9C%883%E6%97%A5%E5%9B%BE%E7%89%871.jpg)
    
    但是由于`CPU`通用寄存器的速度和主存之间存在着太大的差异。两者之间的速度大致如下关系：
    
    ![](https://github.com/OSH-2023/forwwward/blob/main/docs/research/image/4%E6%9C%883%E6%97%A5%E7%8E%8B%E9%81%93%E5%AE%87_pic/4%E6%9C%883%E6%97%A5%E5%9B%BE%E7%89%872.jpg)
    
    在速度差了百倍的情况下，`CPU`对主存的`load/store`操作实际上都非常慢。但是试图提升主存的速度，又要考虑到现今主存动不动几个`GB`的容量，**成本可能过高**。因此产生了一个折中的办法，那就是制作一块速度极快但是容量极小的存储设备。那么其成本也不会太高，我们称之为`cache memory`，在硬件上我们将`cache`放置在`CPU`和主存**之间**，作为**主存数据**的缓存。
    
    当`CPU`试图从主存中`load/store`数据的时候， `CPU`会首先从`cache`中查找对应地址的数据是否缓存在`cache` 中。如果是，直接从`cache`中拿到数据并返回给`CPU`。当存在`cache`的时候，程序运行的流程将会变成如下:
    
    ![](https://github.com/OSH-2023/forwwward/blob/main/docs/research/image/4%E6%9C%883%E6%97%A5%E7%8E%8B%E9%81%93%E5%AE%87_pic/4%E6%9C%883%E6%97%A5%E5%9B%BE%E7%89%873.jpg)
    
    ***CPU和主存之间直接数据传输的方式转变成CPU和cache之间直接数据传输。cache负责和主存之间数据传输。***
  
  - 关于多级`cache`
    
    一级`cache`并没有满足人们对性能的要求，当cache中没有缓存我们想要的数据的时候，依然需要漫长的等待从主存中load数据。所以我们引入了三级`cache`，在刚刚提到的`L1 cache`之后再接上`L2 cache`，在`L2 cache`和主存之间再连接`L3 cache`。等级越高，速度越慢，容量越大。但是速度相比较主存而言，依然很快。不同等级`cache`速度之间关系如下：
    
    ![](https://github.com/OSH-2023/forwwward/blob/main/docs/research/image/4%E6%9C%883%E6%97%A5%E7%8E%8B%E9%81%93%E5%AE%87_pic/4%E6%9C%883%E6%97%A5%E5%9B%BE%E7%89%874.jpg)

- 关于`x86`中的`cache`
  
  ![](https://github.com/OSH-2023/forwwward/blob/main/docs/research/image/4%E6%9C%883%E6%97%A5%E7%8E%8B%E9%81%93%E5%AE%87_pic/4%E6%9C%883%E6%97%A5%E5%9B%BE%E7%89%875.jpg)
  
  - UC，是最容易理解的，就是不用cache机制，读是直接从内存中读，写是直接写到内存里去。对于一些硬件寄存器，通常采用这种配置，因为寄存器的值是可以在CPU控制之外变化的。还有就是用来做DMA传输的内存，也需要是UC的，原因同上，DMA controller会在CPU背后悄悄的修改内存，打开cache的话就会造成cache和内存的不一致。
  
  -  UC-，大致上与UC肯定是相同的。
  
  - WC，这是arm中没有的功能，只有在x86里实现。首先要明确的是，设置成WC之后，就和L1，L2，L3的cache没有任何关系了。在x86里，有另外一块存储区域叫WC buffer（通常是一个buffer是64字节大小，不同平台有不同数量个buffer）。设置成WC的内存，对其进行读操作和UC是一样的，直接从内存里读取，绕过cache。但是当对其进行写操作的时候，区别就来了。新的数据不会被直接写进内存，而是缓存在WC buffer里，等到WC buffer满了或者执行了某些指令后，WC buffer里的数据会一下子被写进内存里去。
  
  - WT，这个是很常见的属性。
    
    读内存的时候：
    
    > 假如cache已经有了这块内存（read hit），则直接从cache里返回数据。
    
    > 假如cache里没有（read miss），则把这块数据从内存中加载到cache中去，再从cache里返回数据。
    
    写内存的时候：
    
    > 假如cache已经有了这块内存（write hit），则更新cache里的数据，并把修改更新到内存。
    
    > 假如cache里没有（write miss）：这里又要出来一个新的概念Write-Allocate和no Write-Allocate。在arm手册里是明确有这两个东西的，但是在x86的文档里我没有找到完全一样的东西，不清楚到底是怎么区分这两个概念的。
    
    > 假如设置成Write-Allocate，就是先把更新写进内存，然后把内存加载到cache。
    
    > 假如设置成no Write-Allocate，就会把更新直接写进内存，然后就结束了。
  
  - 剩余的可以去([x86架构里的cache_潘振杰的博客-CSDN博客](https://blog.csdn.net/panzhenjie/article/details/17589991))直接看，感觉意义不大。

- `cache`的部分操作
  
  [cache操作](https://blog.csdn.net/guyongqiangx/article/details/52045849)

### 参考文献

- [知乎专栏：搭建Arduino+树莓派ROS的小车](https://zhuanlan.zhihu.com/p/389331316)

- https://zhuanlan.zhihu.com/p/102293437

- [Introduction · Autolabor-ROS机器人入门课程《ROS理论与实践》零基础教程](http://www.autolabor.com.cn/book/ROSTutorials/)

- [cache操作](https://blog.csdn.net/guyongqiangx/article/details/52045849)
