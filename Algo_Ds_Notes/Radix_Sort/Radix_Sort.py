def Counting_Sort(list, exp):
    size = len(list)
    output = [0] * size
    count = [0] * 10

    for i in range(0, size):
        count[int(list[i] / exp) % 10] += 1

    for i in range(1, 10):
        count[i] += count[i - 1]

    for i in range(size - 1, -1, -1):
        output[count[int(list[i] / exp) % 10] - 1] = list[i]
        count[int(list[i] / exp) % 10] -= 1

    for i in range(0, size):
        list[i] = output[i]

def Radix_Sort(list):
    maximum = max(list)

    exp = 1
    while int(maximum / exp) > 0:
        Counting_Sort(list, exp)
        exp *= 10

def Print_list(list):
    for i in range(len(list)):
        print(list[i], end = " ")

    print()

list = [170, 45, 75, 90, 802, 24, 2, 66]

Radix_Sort(list)
Print_list(list)


''' Output

2 24 45 66 75 90 170 802

'''
