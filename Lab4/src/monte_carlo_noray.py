import time
import random

start = time.time()


def monte_carlo():

    x = random.random()
    y = random.random()

    return x*x+y*y<=1
    # time.sleep(1)
    # return 0

if __name__ == "__main__":
    #取点个数
    n=10000

    results = [monte_carlo() for x in range(1,n)]

    result = sum(results)/n*4
    print("duration =", time.time() - start, "\nresult = ", result)
