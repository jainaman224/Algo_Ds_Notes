import numpy as np

def beadsort(series, max_num=10):
    len_series = len(series)
    array = np.array([[True]*num + [False]*(max_num-num) for num in series])
    array = np.array([[True]*sum(array[:,idx]) + [False]*(len_series-sum(array[:,idx])) for idx in range(max_num)])
    return [sum(array[:,idx]) for idx in range(len_series)]

a = [2,4,1,3,3]
print(beadsort(a))

#[4, 3, 3, 2, 1]

