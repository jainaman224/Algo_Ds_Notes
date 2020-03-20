def introsort(list):
    #Here maxdepth is chosen equal to 2 times floor of log base 2 of the length of the list
    depth = (len(list).bit_length() - 1)
    #calls helper function
    helper(list, 0, len(list), depth) 

def helper(list, start, end, depth):
    if end - start <= 1:
        #if there is only one element, just return
        return   
    elif depth == 0:
        heapsort(list, start, end)
        #if depth comes out to be 0, perform heapsort
    else:
        #else partition the list and call introsort on both lists
        part = partition(list, start, end)
        helper(list, start, part + 1, depth - 1)
        helper(list, part + 1, end, depth - 1)
    
def partition(list, start, end):
    #uses Hoare’s partition scheme to partition the list
    pivot = list[start]
    i = start - 1
    j = end
    while True:
        i = i + 1
        while list[i] < pivot:
            i = i+1
        j = j - 1
        while list[j] > pivot:
            j = j - 1
        if i >= j:
            return j
        swap(list, i, j)

def swap(list, i, j):
    #swaps the elements
    list[i], list[j] = list[j], list[i]
 
def heapsort(list, start, end):
    #build max heap from the list
    build_max_heap(list, start, end)
    for i in range(end - 1, start, -1):
        #swap first and last element in heap
        swap(list, start, i)
        max_heapify(list, index = 0, start = start, end = i)
        #max heapify the remaining heap of size one less than previous
 
def build_max_heap(list, start, end):
    def parent(i):
        return (i - 1)//2
    length = end - start
    index = parent(length - 1)
    while index >= 0:
        max_heapify(list, index, start, end)
        index = index - 1

def max_heapify(list, index, start, end):
    def left(i):
        return 2 * i + 1
    def right(i):
        return 2 * i + 2
    size = end - start
    l = left(index)
    r = right(index)
    if (l < size and list[start + l] > list[start + index]):
        largest = l
    else:
        largest = index
    if (r < size and list[start + r] > list[start + largest]):
        largest = r
    if largest != index:
        swap(list, start + largest, start + index)
        max_heapify(list, largest, start, end)

list = input('Enter the list of numbers: ').split() #take input
#perform introsort
list = [int(x) for x in list]
introsort(list)
#print sorted list
print('Sorted list: ', end = '')
print(list)

#Input : 8 7 5 4 6
#Output : [4, 5, 6, 7, 8]
