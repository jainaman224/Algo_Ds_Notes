def Counting_Sort(array, exp):
    size = len(array)
    output = [0] * size
    count = [0] * 10

    for i in range(0, size):
        count[int(array[i] / exp) % 10] += 1

    for i in range(1, 10):
        count[i] += count[i - 1]

    for i in range(size - 1, -1, -1):
        output[count[int(array[i] / exp) % 10] - 1] = array[i]
        count[int(array[i] / exp) % 10] -= 1

    for i in range(0, size):
        array[i] = output[i]

def Radix_Sort(array):
    maximum = max(array)

    exp = 1
    while int(maximum / exp) > 0:
        Counting_Sort(array, exp)
        exp *= 10

def Print_Array(array):
    for i in range(len(array)):
        print(array[i], end = " ")

    print()

array = [170, 45, 75, 90, 802, 24, 2, 66]

Radix_Sort(array)
Print_Array(array)


''' Output

2 24 45 66 75 90 170 802

'''
