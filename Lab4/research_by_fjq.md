## 计算类可测试的性能指标

- 延迟
- 并行度
- 可伸缩性（Scalability）
  - 衡量系统在处理大规模数据和负载时的能力
  - 通过增加数据量或任务数量，并观察系统的响应时间来评估可伸缩性

## init参数

num_cpus: 设置用于Ray worker的CPU核心数。
num_gpus: 设置用于Ray worker的GPU数量。
object_store_memory: 设置对象存储的内存限制。
redis_max_memory: 设置Redis服务器的内存限制。
object_manager_port: 设置对象管理器使用的端口号。
node_manager_port: 设置节点管理器使用的端口号。
redis_address: 设置Redis服务器的地址。
temp_dir: 设置临时文件的存储路径。
raylet_socket_name: 设置Raylet服务器使用的套接字名称。
raylet_socket_name: 设置Raylet服务器使用的套接字名称。
raylet_heartbeat_timeout_milliseconds: 设置Raylet心跳超时的时间。
plasma_directory: 设置Plasma对象存储的目录。
num_workers: 设置启动的Ray worker的数量。
object_timeout_milliseconds: 设置对象的超时时间。


# 程序中可能影响性能的误区

[误区](https://blog.csdn.net/zkh880loLh3h21AJTH/article/details/91410217)

## 关于ray.get()

阻塞地，直到括号中任务结束

- 不使用ray.get(),则只能测试启动任务所花时间，而非执行任务所花时间
- 正确使用ray.get(),才能实现并行：尽可能晚的调用ray.get()

## 单个任务所花时间较少时，ray效果不如不用

大规模简单任务中执行时间小于进程调度时间