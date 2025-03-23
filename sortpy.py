import time
import numpy as np
M=10
N=1000000
with open("test.txt","r")as f:
    datasets=[np.array(list(map(float,line.split())))for line in f]
with open("sortpy_result.txt","w")as f:
    for i in range(M):
        start_time=time.time()
        datasets[i]=np.sort(datasets[i])
        end_time=time.time()
        elapsed_time=(end_time-start_time)*1000
        f.write(f"Time for test {i+1}: {elapsed_time:.3f} ms\n")