def Shell_Sort(list):
    size = len(list)
    gap = int(size / 2)

    while gap > 0:
        for i in range(gap, size):
            temp = list[i]

            j = i
            while  j >= gap and list[j - gap] > temp:
                list[j] = list[j - gap]
                j -= gap

            list[j] = temp
        gap = int(gap / 2)

def Print_list(list):
    for i in range(len(list)):
        print(list[i], end = " ")

    print()

list = [12, 34, 54, 2, 3]

Shell_Sort(list)
Print_list(list)


''' Output

2 3 12 34 54

'''
