## This is our report of osh-lab4

## 代码部分

* 我们的测试任务选择的是计算矩阵的行列式

```python
def matrix_multiply1():
    A = np.random.randint(0,1000,1000000)
    A = A.reshape(1000, 1000)
    a = np.linalg.det(A)
    return 0
```

> 这段代码是随机生成矩阵元素为0-1000的数，矩阵大小为1000*1000。
>
> 特点是计算量大，可以明显体现出优化后的结果

* 带ray的代码版本

```python
import numpy as np
import time
iimport ray

ray.init()

def matrix_multiply1():
    A = np.random.randint(0,1000,1000000)
    A = A.reshape(1000, 1000)
    a = np.linalg.det(A)
    return 0


@ray.remote(num_cpus=16)
def matrix_multiply2():
    A = np.random.randint(0,1000,1000000)
    A = A.reshape(1000, 1000)
    a = np.linalg.det(A)
    return 0

#使用远程函数计算矩阵乘积
start_time = time.time()
results = [matrix_multiply1() for _ in range(100)]

end_time = time.time()
print("Time taken: {:.2f} seconds".format(end_time - start_time),"\n")


###################
start_time = time.time()
results = ray.get([matrix_multiply2.remote() for _ in range(100)])

end_time = time.time()
print("Time taken: {:.2f} seconds".format(end_time - start_time),"\n")

```

> 运行该程序，可以先后得到不带ray和带ray的运行时间，计算次数选择100次。