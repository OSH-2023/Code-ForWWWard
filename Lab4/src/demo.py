import ray

# 初始化Ray
ray.init()

# 定义一个在Ray上运行的并行函数
@ray.remote
def compute_sum(num_list):
    return sum(num_list)

if __name__ == "__main__":
    # 创建一个包含多个整数的列表
    num_list = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

    # 在Ray上并行调用compute_sum函数，将列表分割为两部分进行计算
    result_ids = [compute_sum.remote(num_list[:5]), compute_sum.remote(num_list[5:])]

    # 获取并打印计算结果
    results = ray.get(result_ids)
    total_sum = sum(results)
    print("Total sum:", total_sum)

    # 关闭Ray
    ray.shutdown()