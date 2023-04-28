# 论文阅读

## Direct Cache Access for High Bandwidth Network I/O 

* `Abstract`

  * `DCA`显著减少接收密集型网络I/O的**内存延迟和内存带宽**

* `Introduction`

  * I/O对处理器效率的影响可以用10千兆以太网标准和执行TCP/IP协议所涉及的处理来演示。
  * 使用`DCA`尽量减少对内存子系统的依赖，改善处理和I/O能力之间的平衡

* `TCP/IP Example `

* `DCA`在传输密集型工作负载中的适用性有限，只能在传输操作完成后消除处理器对内存的网卡状态的读取

* `Memory Access Profiles of Benchmarks`

  * 测试的一些方法/标准？
    * 磁盘I/O 与 网络I/O？
  * 为了从直接放置在cache中的I/O数据获益，processor必须及时从cache中读取数据。否则，修改后的高速缓存行可能会在被读取之前被驱逐到内存中。In  addition, the cache is subjected to two replacements  instead of one – first, when placing the I/O data in the cache and second, due to untimely placement, when the  processor misses the cache anyway.
  * DCA可以减少很大一部分的cache misses(缓存未命中，explain:当发生缓存未命中时，系统或应用程序会继续在底层数据存储中定位数据，这会增加请求的持续时间。通常，系统可能会将数据写入缓存，再次增加延迟，尽管该延迟会被缓存对其他数据的命中所抵消。)

  ![](https://hazelcast.com/wp-content/uploads/2021/12/7_CacheMiss_1.png)

  

  * 大量传入的网络I/O流量是使用DCA大幅提高性能的前兆,如果I/O的写入数据直接放在处理器的高速缓存中，这一特性可直接减少网络I/O的未命中
  * 处理器数据读取是很重要的带宽组成部分，也是重要的内存延迟停滞来源。DCA可以降低数据读取`Miss`的情况

* `System Considerations `

  * 缓存越小，与I/O相关的cache misses就越小，DCA的好处就越小

  * 缓存空间受限时，DCA可能会因为过早地将数据带入缓存而引起I/O干扰效应。这种影响可通过将与I/O相关的分配限制在一个高速缓存的方式处理
  * **5.4:**`A Reference Model for DCA`
    * `NUMA（非统一内存访问）`

## Using Direct Cache Access Combined With Integrated NIC  Architecture to Accelerate Network Processing 

* `DCA与INIC(集成网络接口卡)`相结合的方式减少与I/O相关的数据传输延迟

* `Network Processing Flow `
  * 网络处理的时间成本：**中断处理、网卡驱动、堆栈处理、内核程序**(数据包成本)、数据复制、校验计算等(数据触摸成本，与I/O数据大小成比例)

* **改进的DCA**
* 修改缓存策略和系统结构，将DCA请求和非DCA请求分开

* 在系统中建立特定内存地址空间接收DCA传输的数据

* DCA method is more promising in reducing memory accessing cost than improving the I/O  transfer. 

* 结论：只有DCA不能大幅减少I/O和内存的流量，在现有的缓存策略下仍然会在缓存和内存系统之间产生数据传输。INIC有助于数据传输(减少数据传输延迟和穿越I/O桥的I/O流量)。使用DCA发送至缓存的数据不应大于缓存大小的1/4 ，否则会产生大量的cache pollution，导致系统性能下降。DCA在减少内存访问延迟方面比减少I/O延迟更有希望。