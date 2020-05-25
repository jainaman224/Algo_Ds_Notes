'''
Introsort sort is a sorting algorithm that initially uses quicksort, 
but switches to heap sort if the depth of the recursion is too deep,
and uses insertion sort for small cases.
'''

#a function that takes a list as argument.
def introsort(nlist): 
    
    #maxdepth is chosen equal to 2 times floor of log base 2 of the length of the list.
    maxdepth = (len(nlist).bit_length() - 1 ) * 2
    # Call introsort_helper with start = 0 and end = len(alist).
    introsort_helper(nlist, 0, len(nlist), maxdepth)
 
#The function sorts the list from indexes start to end. 
def introsort_helper(nlist, start, end, maxdepth):
    if end - start <= 1:
        return
    elif maxdepth == 0:
        heapsort(alist, start, end)
    else:
        p = partition(nlist, start, end)
        introsort_helper(nlist, start, p + 1, maxdepth - 1)
        introsort_helper(nlist, p + 1, end, maxdepth - 1)
 
#partition function uses Hoare partition scheme to partition the list. 
def partition(nlist, start, end):
    pivot = nlist[start]
    i = start - 1
    j = end
 
    while True:
        i = i + 1
        while nlist[i] < pivot:
            i = i + 1
        j = j - 1
        while nlist[j] > pivot:
            j = j - 1
 
        if i >= j:
            return j
 
        swap(nlist, i, j)

#function for swapping 
def swap(nlist, i, j):
    nlist[i], nlist[j] = nlist[j], nlist[i]

#heapsort from indexes start to end - 1 
def heapsort(alist, start, end):
    build_max_heap(nlist, start, end)
    for i in range(end - 1, start, -1):
        swap(alist, start, i)
        max_heapify(nlist, index = 0, start = start, end = i)
 
#rearrange the list into a list representation of a heap. 
def build_max_heap(nlist, start, end):
    def parent(i):
        return (i - 1) // 2
    length = end - start
    index = parent(length - 1)
    while index >= 0:
        max_heapify(nlist, index, start, end)
        index = index - 1
 
#modifies the heap structure at and below the node at given index to make it satisfy the heap property. 
def max_heapify(nlist, index, start, end):
    def left(i):
        return 2 * i + 1
    def right(i):
        return 2 * i + 2
 
    size = end - start
    l = left(index)
    r = right(index)
    if (l < size and nlist[start + l] > nlist[start + index]):
        largest = l
    else:
        largest = index
    if (r < size and nlist[start + r] > nlist[start + largest]):
        largest = r
    if largest != index:
        swap(alist, start + largest, start + index)
        max_heapify(alist, largest, start, end)
        
#taking list as input from user (dynamic input)
nlist = input('Enter the list of numbers: ').split()
nlist = [int(n) for n in nlist]
introsort(nlist)
print('Sorted list: ', end = '')
#printing sorted list
print(nlist)


'''
Sample input
Enter the list of numbers: 8 4 3 2 1

Sample output
Sorted list: [1, 2, 3, 4, 8]
'''
