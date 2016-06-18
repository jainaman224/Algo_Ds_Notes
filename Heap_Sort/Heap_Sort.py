def Heapify(array, root, size):
    left = 2 * root + 1
    right = left + 1
    if left < size and array[left] > array[root]:
        largest = left
    else:
        largest = root
    if right < size and array[right] > array[largest]:
        largest = right
    if largest != root:
        array[root], array[largest] = array[largest], array[root]
        Heapify(array, largest, size)


def Build_Heap(array):
    for i in range(int((len(array) - 1) / 2), -1, -1):
        Heapify(array, i, len(array))

def Heap_Sort(array):
    Build_Heap(array)
    for i in range(len(array) - 1, 0, -1):
        array[0], array[i] = array[i], array[0]
        Heapify(array, 0, i)

# function to print array
def Print_Array(array):
    for i in range(0, len(array)):
        print(array[i],end=" ")
    print()

array = [2, 4, 3, 1, 6, 8, 4]

Heap_Sort(array)

Print_Array(array)

# Output
# 1 2 3 4 4 6 8
