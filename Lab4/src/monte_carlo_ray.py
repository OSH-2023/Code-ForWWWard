import ray
import time
import random

start = time.time()

# 初始化Ray
ray.init(num_cpus=2)

# 定义一个在Ray上运行的并行函数
@ray.remote
def monte_carlo():

    x = random.random()
    y = random.random()

    return x*x+y*y<=1

if __name__ == "__main__":
    
    #取点个数
    n=1000

    results = ray.get([monte_carlo.remote() for x in range(1,n)])

    result = sum(results)/n*4
    print("duration =", time.time() - start, "\nresult = ", result)
    # 关闭Ray
    ray.shutdown()