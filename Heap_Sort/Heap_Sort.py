def Heapify(list, root, size):
    left = 2 * root + 1
    right = left + 1
    if left < size and list[left] > list[root]:
        largest = left
    else:
        largest = root

    if right < size and list[right] > list[largest]:
        largest = right

    if largest != root:
        list[root], list[largest] = list[largest], list[root]
        Heapify(list, largest, size)


def Build_Heap(list):
    for i in range(int((len(list) - 1) / 2), -1, -1):
        Heapify(list, i, len(list))

def Heap_Sort(list):
    Build_Heap(list)

    for i in range(len(list) - 1, 0, -1):
        list[0], list[i] = list[i], list[0]
        Heapify(list, 0, i)

# function to print list
def Print_list(list):
    for i in range(0, len(list)):
        print(list[i],end=" ")

    print()

list = [2, 4, 3, 1, 6, 8, 4]

Heap_Sort(list)

Print_list(list)

# Output
# 1 2 3 4 4 6 8
