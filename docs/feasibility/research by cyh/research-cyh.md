### i/o acceleration tech

- #### 大纲

  - 背景
  - 寻找i/o瓶颈
  - 给出解决方法
  - 优势分析
  - 总结

- #### 背景

  > 大数据时代，数据中心会接受大量数据。为了处理这些数据并能充分发挥互联网高带宽的性能，数据中心需要提高数据处理能力。
  >
  > 这里给出了一种方法，即使用Intel的新一代芯片

  - #### hardware 

    > available in  the new Dual-Core and Quad-Core Intel® Xeon® processor-based server platforms （英特尔 至强 处理器）
    >
    > ![image-20230412081137967](C:\Users\chen\AppData\Roaming\Typora\typora-user-images\image-20230412081137967.png)
    >
    > 找了一个8核的可扩展处理器（这篇文献里面说的两核、四核处理器，可能是上古版本）

- #### 寻找瓶颈

  > 文章分析了信息输入输出要经历的几个步骤（与我们做的无关）
  >
  > 发现了在小文件情况下系统调用占据了大量的实践

- #### 解决方式

  > 1. 并行处理TCP和内存函数（这里面有关于cache的）
  >    - Lowers  system overhead and improves the efficiency of TCP stack  processing by using the abilities of the CPU to execute multiple instructions per clock, **pre-fetch TCP/IP header information into cache,** and perform other data movement operations in parallel
  > 2. 贴合数据流分配CPU使用
  > 3. 异步低成本复制
  > 4. 优化堆栈来加快TCP/IP的处理

- #### 性能提升（减少东西，提高性能）

  ![image-20230412083441393](C:\Users\chen\AppData\Roaming\Typora\typora-user-images\image-20230412083441393.png)

- #### 总结

  > 又快又好，快买（但是没看到关于cache的指令）

------

------（分割线）------

------

### Using Direct Cache Access Combined With Integrated NIC  Architecture to Accelerate Network Processing 

- ### 大纲

  - 背景介绍
  - 设计方法
  - 分析和讨论
  - 总结

- #### 背景

  > 前置的两种加速方法
  >
  > 1. DCA： It  delivers network packets **from Network Interface Card  (NIC) into cache** instead of memory to reduce the data  accessing latency
  > 2. INIC:  INIC is  introduced to **reduce the heavy burden for I/O registers  access in NIC drivers** and interrupt handling
  >
  > 回顾数据传输
  >
  > - At the  beginning, Packets from **physical line** are sampled by NIC  which performs the address filtering and stream control.  Then **the DMA engine in NIC sends the packets to the  socket buffer and notifies OS** to invoke network stackprocessing **by interrupts**. When OS receives the interrupt,  the **stack accesses the data in socket buffer** and calculates  the checksum. Protocol specific operations are executed  layer by layer in stack processing. Finally, **data is  transferred from socket buffer to the user buffer allocated  by applications**. This operation is usually done by a  function called **memcpy** in OS kernel
  >
  >   [memcpy]: https://www.runoob.com/cprogramming/c-function-memcpy.html	"C function， 用于复制数据"
  >
  > - 提出了不同数据延迟
  >
  >   Generally, the kernel routine cost ranges from 10%  - 30% of the total cycles; the driver and interrupt handling  costs range from 15% - 35%; the stack processing cost  ranges from 7% - 15%; and **data touch cost takes up 20% -  35%**.
  >
  > - 实验动机
  >
  >   - CPU和mem速度差异大
  >   - DCA也有点跟不上速度
  >   - major time costs of  network processing mentioned above are associated with  I/O and memory speeds 
  >   - $\Rightarrow$ 结合INIC和DCA

- #### 分析和讨论

  > - DCA 他们的方案考虑了以下几点
  >   1. cache连贯性
  >   2. cache 污染
  >   3. DCA policy（when and which part of the data is  transferred with DCA）
  > - 补充--intel 的 伪DCA实现[*Layout 1 (umn.edu)](https://www.d.umn.edu/~tkwon/course/5315/HW/quadcore/sma.pdf)
  > - ![](D:\OneDrive\图片\屏幕快照\屏幕截图 2023-04-12 142944.png)
  > - the IP prefetcher **builds a history and keeps it in the IP history array** ， tries to **predict the address of the next load** accordingly to a constant stride calculation
  > - 预测失败，从L2cache 中找指令
  >
  > 
  >
  > - 他做了一个很新的东西，把NIC放在一个很神奇的位置
  > - ![image-20230412145816444](C:\Users\chen\AppData\Roaming\Typora\typora-user-images\image-20230412145816444.png)
  > - we attach the NIC to the  nearest place to CPU core **instead of the place below I/O  controller (HT in fig.4**) to **diminish hundreds of cycles**  spent on the data transformation in I/O Bridge. 
  > - 注意这个on-chip network，是用于高速通信的

- #### 他基于高斯3设计了芯片，然后进行了一些测试

- 总结 

  后面全在测试性能。主要就是看了一下关于DCA和INIC的东西。但是有点绕，也没有说DCA具体实现。我顺着注释看了一下后面的文件。