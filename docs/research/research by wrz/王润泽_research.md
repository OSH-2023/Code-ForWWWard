# 王润泽_research

​                                                                                                                                           

## ROS调研（23/4/4）

#### 理论知识

- **[DMA技术](https://zhuanlan.zhihu.com/p/138573828?utm_campaign=&utm_medium=social&utm_oi=1261794022705479680&utm_psn=1626592645932834816&utm_source=qq)**

  - **基本定义**：DMA，全称Direct Memory Access，即直接存储器访问。DMA技术通过直接访问系统内存，实现设备和系统之间的数据传输，可以减轻CPU的负担，提高数据传输的效率。

    > DMA传输将数据从一个地址空间复制到另一个地址空间，提供在外设和存储器之间或者存储器和存储器之间的高速数据传输。当CPU初始化这个传输动作，传输动作本身是由DMA控制器来实现和完成的。DMA传输方式无需CPU直接控制传输，也没有中断处理方式那样保留现场和恢复现场过程，通过硬件为RAM和IO设备开辟一条直接传输数据的通道，使得CPU的效率大大提高。

  - **总线控制**：CPU和外设再写入系统内存时，可能发生总线争用，有以下三种方式处理冲突

    - **突发模式（Burst mode）**：在突发模式下，整个数据块以一个连续的序列传输。一旦 DMA 控制器被 CPU 授予对系统总线的访问权限，它就会在将系统总线的控制权交还给 CPU 之前传输数据块中的所有字节数据，但会使 CPU 在相对较长的时间内处于非活动状态。
    - **循环窃取模式（Cycle stealing mode）**：循环窃取模式用于 CPU 不应在突发传输模式所需的时间长度内被禁用的系统。在循环窃取模式下，DMA 控制器使用与突发模式相同的方式获取对系统总线的访问权限，使用*BR（[总线请求](https://en.wikipedia.org/wiki/Bus_Request)）*和*BG（[总线授权](https://en.wikipedia.org/wiki/Bus_Grant)）*信号，这是控制 CPU 和 DMA 控制器之间接口的两个信号。然而，在循环窃取模式下，在一个单元（例如字节）的数据传输之后，系统总线的控制权通过 BG 被取消赋予给 CPU。然后通过 BR 再次连续请求它，每次请求传输一个数据单元（例如字节），直到整个数据块已传输。通过不断获得和释放对系统总线的控制，DMA 控制器实质上交织了指令和数据传输。CPU 处理一条指令，然后 DMA 控制器传输一个数据值，依此类推。数据传输速度没有那么快，但 CPU 的空闲时间没有突发模式那么长。循环窃取模式对于实时监控数据的控制器很有用。**（可以理解成ics课第九章学的io算法）**
    - **透明模式（Transparent mode）**：透明模式需要最多的时间来传输数据块，但就整体系统性能而言，它也是最有效的模式。在透明模式下，DMA 控制器仅在 CPU 执行不使用系统总线的操作时传输数据。透明模式的主要优点是 CPU 永远不会停止执行其程序并且 DMA 传输在时间上是免费的，而缺点是硬件需要确定 CPU 何时不使用系统总线，这可能很复杂. 

  - **缓存一致性（Cache coherency）**

    ![DMA 导致缓存不一致](https://upload.wikimedia.org/wikipedia/commons/thumb/4/49/Cache_incoherence_write.svg/559px-Cache_incoherence_write.svg.png)

    > 当设备向内存写入数据时，由于CPU可能会将数据缓存在L1、L2、L3缓存中，设备无法直接访问缓存，因此会向内存中写入数据，但是缓存中的数据可能已经发生了改变。同样地，当设备从内存中读取数据时，由于CPU可能将数据缓存在缓存中，设备读取的数据可能是缓存中的数据，而不是最新的数据。这就是所谓的缓存一致性问题。
    >
    > 为了解决缓存一致性问题，现代的CPU和设备通常采用了一些技术来保证缓存一致性。例如，CPU可以使用cache一致性协议（如MESI）来保证多个缓存之间的一致性。当设备向内存写入数据时，缓存中对应的数据会被标记为“失效”，即无效状态，这样在其他缓存中的数据就会被清除。当CPU访问该内存地址时，会从内存中重新读取最新的数据，从而保证缓存一致性。
    >
    > DMA控制器通常也采用类似的机制来保证缓存一致性。在进行DMA数据传输时，DMA控制器会通知CPU缓存该内存地址中的数据已经失效，以便CPU在下次访问该内存地址时能够从内存中读取最新的数据，而不是从缓存中读取旧数据。一些现代的DMA控制器甚至支持cache一致性协议，从而可以直接与CPU的缓存进行通信，提高了系统的性能和可靠性。

  - **DMA传输模式**

    - 外设到存储器
    - 存储器到外设
    - 存储器到存储器

  - **IO加速技术（I/O Acceleration Technology）**

    IOAT（I/O Acceleration Technology）是英特尔开发的一种数据传输加速技术，主要用于优化服务器等高性能计算机系统中的数据传输速度。IOAT技术利用DMA技术，通过硬件直接传输数据，避免了CPU介入，可以大幅提高数据传输速度。

  - **RDMA技术（Remote Direct Memory Access）**

    - RDMA（Remote Direct Memory Access，远程直接内存访问）是一种网络通信技术，它可以让网络中的两个节点之间直接访问彼此的内存，而无需操作系统或者CPU的干预，从而大幅提高网络传输的速度和效率。
    - 传统的网络通信模式中，数据传输需要经过多次复制和处理，包括应用程序将数据从内存中复制到内核缓冲区、网卡从内核缓冲区复制数据到自己的缓存区、然后再从网卡缓存区复制到目标主机的内核缓冲区、最后再从内核缓冲区复制到目标应用程序的内存中。这个过程需要经过多次CPU的干预和数据复制，导致网络传输的速度和效率较低。
    - RDMA技术则可以实现直接从源主机的内存中将数据传输到目标主机的内存中，避免了多次数据复制和CPU的干预，从而可以大幅提高网络传输的速度和效率。RDMA技术主要有两种实现方式，一种是InfiniBand，另一种是RoCE（RDMA over Converged Ethernet）。

- **[ROS2的优势](https://zhuanlan.zhihu.com/p/477126847?utm_campaign=&utm_medium=social&utm_oi=1261794022705479680&utm_psn=1626594507587358720&utm_source=qq)**

  - ROS通讯机制：点对点的分布式通信机制是ROS的核心，使用了基于TCP/IP的通信方式，实现模块间点对点的松耦合连接，可以执行若干种类型的通信，包括基于话题（Topic）的异步数据流通信，基于服务（Service）的同步数据流通信，还有参数服务器上的数据存储等。

  - 主要区别

    - 支持多机器人系统（没啥用）
    - 支持微控制器（MCU）
    - **支持实时控制**
    - 支持跨系统平台：增加了对Windows、MacOS、RTOS等系统的支持。
    - 不依赖Master主节点。

  - ROS缺点

    - **实时性差**：时延高达0.01ms量级，难以实现高实时性要求任务。
    - **稳定性差**：一旦ROS Master莫名宕机，整个系统不再受控，难以产品化。

  - **DDS（Data Distribution Service）**

    > ROS2支持数据分发服务（DDS）通信协议，它可以以零拷贝的方式传递消息，节省了CPU和内存资源。在开发方面，他们花了更多的精力来增加测试覆盖率，提供更多更好理解的文档，以及更多持续集成，以便实现软件的认证。

    - DDS（Data Distribution Service）是一种面向实时通信的消息传递中间件技术，它允许不同设备之间进行实时的、可靠的数据交换。DDS旨在解决数据分发和通信问题，它支持多种编程语言和平台，并提供了高效、安全、可靠的数据交换方式。
    - DDS基于发布-订阅模式（Publish-Subscribe），允许多个发送者（Publishers）同时向多个接收者（Subscribers）广播数据，且能够自动进行数据交换的协商和管理。DDS可以提供实时性能，支持大量的数据量，同时具备高可靠性和安全性。
    - DDS与其他通信技术（如消息队列、WebSocket等）相比，具有更高的实时性、更可靠的通信、更强大的管理和更灵活的数据模型等优势，因此被广泛应用于需要高效实时通信的领域，如工业自动化、航空航天、医疗、智能交通等。

    较为复杂，可以作为下一阶段的具体探索方向？

- **[百度Apollo](http://www.uml.org.cn/ai/201805284.asp)**

  **通讯机制优化**思路：

  - **去中心化**，也就是干掉ROS Master，这部分使用了DDS技术。

    ![img](http://www.uml.org.cn/ai/images/2018052844.jpg)

  - 使用**共享内存**的方法，优化大数据传输的瓶颈。

    ![img](http://www.uml.org.cn/ai/images/2018052845.jpg)

  - 使用**Protobuf**优化数据格式的兼容性。

    ![img](http://www.uml.org.cn/ai/images/2018052846.jpg)

  CyberRT是和DDS类似的中间件，都解决了ROS在实时性方面的显著缺点。了解到和ROS2实现实时性思路    差不多？或许可以借鉴一些研究思路。

  > Apollo Cyber RT 是专为自动驾驶场景设计的开源、高性能运行时框架。 基于中心化计算模型，主要价值是提升自动驾驶系统的高并发、低延迟、高吞吐。
  >
  > Apollo 并不是一开始就使用 CyberRT，在 v3.0 之前用的都是基于 ROS 框架进行开发。但在之前的版本中发现了很多问题，随着 Apollo 的发展，对最高水平的稳健性和性能的需求， Apollo Cyber RT 应运而生，它满足了一个面向商业化的自动驾驶解决方案的基础需求。

​		[一篇介绍Apollo Cyber RT的回答](https://zhuanlan.zhihu.com/p/479518561?utm_campaign=&utm_medium=social&utm_oi=1261794022705479680&utm_psn=1626600792936439808&utm_source=qq)

#### 硬件支持&操作系统

**操作系统**

- **Ubuntu**：ROS2官方推荐使用Ubuntu 18.04或更高版本作为操作系统，它是ROS2的主要开发和测试平台。
- **Windows**：ROS2已经支持Windows操作系统，但需要使用Visual Studio 2019或更高版本进行编译和构建。

**硬件支持**

- **个人计算机**

  ROS可以在Linux、Windows和macOS等操作系统上运行。如去年[x-NooBirds](https://github.com/OSH-2022/x-NooBirds)采用改造后的实时linux操作系统，运行小车服务器。

- **树莓派**

  > 树莓派是一种基于ARM架构的单板计算机，它由英国的Raspberry Pi基金会开发和推广。树莓派的外形和尺寸类似于一张信用卡，但它具有强大的计算能力和丰富的扩展接口，可以运行Linux操作系统，广泛应用于各种嵌入式系统和物联网领域。

  [树莓派官方教程](https://www.raspberrypi.com/documentation/)

- **STM32开发板**

  > STM32开发板是一种基于STM32系列微控制器的开发板，具有丰富的外设和接口，可用于各种嵌入式系统开发和应用。

  - **特点**：STM32开发板具有低功耗、高性能、多功能、易于使用和可靠性高等特点。其内置了丰富的外设和接口，包括通用定时器、UART、SPI、I2C、USB、CAN、SDIO、DMA等等。
  - **应用**：STM32开发板广泛应用于各种嵌入式系统开发和应用，包括智能家居、工业自动化、电力电子、智能交通、医疗设备等等。由于STM32开发板具有丰富的外设和接口，可以满足不同应用的需求，并且易于扩展和定制。
  - **开发环境**：STM32开发板可以使用多种软件开发环境，如Keil MDK、IAR Embedded Workbench、GCC等等。同时，STM32开发板也提供了丰富的开发工具和资料，包括代码库、例程、文档等等，方便开发者快速入门和开发。

  去年[x_do_our_best](https://github.com/OSH-2022/x_do_our_best)组使用嵌入式操作系统RT_thread搭配ros的方式，来实现一个兼顾实时性和计算复杂性的嵌入式系统。该系统运行在STM32F407开发板上，完全可以支持RT-thread运行ros。



## 参考资料

- [DMA维基百科](https://en.wikipedia.org/wiki/Direct_memory_access)
- [STM32之深入理解DMA](https://zhuanlan.zhihu.com/p/92678091?utm_campaign=&utm_medium=social&utm_oi=1261794022705479680&utm_psn=1626592585295552512&utm_source=qq)
- [DMA原理介绍](https://zhuanlan.zhihu.com/p/138573828?utm_campaign=&utm_medium=social&utm_oi=1261794022705479680&utm_psn=1626592645932834816&utm_source=qq)
- [STM32手册](https://www.st.com/resource/en/reference_manual/rm0090-stm32f405415-stm32f407417-stm32f427437-and-stm32f429439-advanced-armbased-32bit-mcus-stmicroelectronics.pdf)
- [百度Apollo](http://www.uml.org.cn/ai/201805284.asp)
- [ROS2的优势](https://zhuanlan.zhihu.com/p/477126847?utm_campaign=&utm_medium=social&utm_oi=1261794022705479680&utm_psn=1626594507587358720&utm_source=qq)
- [树莓派官方教程](https://www.raspberrypi.com/documentation/)
- [一篇介绍Apollo Cyber RT的回答](https://zhuanlan.zhihu.com/p/479518561?utm_campaign=&utm_medium=social&utm_oi=1261794022705479680&utm_psn=1626600792936439808&utm_source=qq)
