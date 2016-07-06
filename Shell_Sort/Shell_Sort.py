def Shell_Sort(array):
    size = len(array)
    gap = int(size / 2)

    while gap > 0:
        for i in range(gap, size):
            temp = array[i]

            j = i
            while  j >= gap and array[j - gap] > temp:
                array[j] = array[j - gap]
                j -= gap

            array[j] = temp
        gap = int(gap / 2)

def Print_Array(array):
    for i in range(len(array)):
        print(array[i], end = " ")

    print()

array = [12, 34, 54, 2, 3]

Shell_Sort(array)
Print_Array(array)


''' Output

2 3 12 34 54

'''
