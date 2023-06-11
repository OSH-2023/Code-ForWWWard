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
