class BinaryHeap():
    def __init__(self):

        # To enable 1-index based array operations
        self.heapData = [0]
        self.currentSize = 0

    # If the min value is down in the tree, it needs to be bubbled up
    # to the proper position within the tree

    def bubbleUp(self, i):

        # check that i is not at the root index
        while i // 2 > 0:
            if self.heapData[i] < self.heapData[i // 2]:

                # swap the values so the lower value will get bubbled up
                self.heapData[i //  2], self.heapData[i] = \
                    self.heapData[i], self.heapData[i // 2]

            i = i // 2

    # Append the value to the list, then bubble up values based on
    # minimum heap property
    def insert(self, k):
        self.heapData.append(k)
        self.currentSize += 1
        self.bubbleUp(self.currentSize)

    # Delete the minimum value (present at the root index)

    def deleteMin(self):

        if self.currentSize == 0:
            return 'Binary Heap is empty'

        # Minimum value is present at index[1] in the heapData list
        min_val = self.heapData[1]

        # Take the last element and move it to first position in the list
        self.heapData[1] = self.heapData[self.currentSize]

        self.currentSize -= 1

        # Remove the last element in the list
        self.heapData.pop()

        # bubble down values as required based on minimum heap property from
        # the root index
        self.bubbleDown(1)

        return min_val

    # Check the smallest child - left child or right child, return its index
    def minChildIdx(self, i):

        if i * 2 + 1 > self.currentSize:
            return i * 2
        else:

            # Check if left-child value is less than right-child value
            if self.heapData[i * 2] < self.heapData[i * 2 + 1]:
                return i * 2
            else:
                return i * 2 + 1

    # If a larger value is up in the tree, it needs to be bubbled down
    # to the proper position within the tree
    def bubbleDown(self, i):

        while (i * 2) <= self.currentSize:

            # From the left or right child - get the index of the minimum value
            min_child_idx = self.minChildIdx(i)

            # if parent value is greater than child value - swap them
            if self.heapData[i] > self.heapData[min_child_idx]:

                self.heapData[i], self.heapData[min_child_idx] = \
                    self.heapData[min_child_idx], self.heapData[i]

            # Repeat from index of the minimum child value
            i = min_child_idx

    # Build minimum heap from given numbers - can be represented in an array
    def minHeapify(self, newlist):

        i = len(newlist) // 2
        self.currentSize = len(newlist)
        self.heapData = [0] + newlist[:]

        # Bubble down as required so that minimum heap property is maintained
        while i > 0:
            self.bubbleDown(i)
            i -= 1

    def printData(self):
        return self.heapData[1::]


if __name__ == '__main__':

    # Empty binary heap
    binary_heap = BinaryHeap()

    # Build minimum heap - using static input
    binary_heap.minHeapify([2, 17, 12, 35, 59])

    # Insert values into the heap
    binary_heap.insert(23)
    binary_heap.insert(89)
    binary_heap.insert(46)
    binary_heap.insert(55)

    # Expected - [2, 17, 12, 35, 59, 23, 89, 46, 55]
    print('Binary Heap Array representation - Static input')        
    print(binary_heap.printData())

    print('Priority Queue - mininum value')        
    # Expected - 2
    print(binary_heap.deleteMin())

    # Expected - 12
    print(binary_heap.deleteMin())

    # Expected - 17
    print(binary_heap.deleteMin())

    # Expected - 23
    print(binary_heap.deleteMin())

    # Expected - 35
    print(binary_heap.deleteMin())

    # Expected - 46
    print(binary_heap.deleteMin())

    # Expected - 55
    print(binary_heap.deleteMin())

    # Expected - 59
    print(binary_heap.deleteMin())

    # Expected - 89
    print(binary_heap.deleteMin())

    # Expected - Binary Heap is empty
    print(binary_heap.deleteMin())


    # Using Dynamic input    
    len_binary_heap = int(input('Enter total number of elements in Binary Heap - '))
    print(len_binary_heap)
    
    binary_heap_dyn = BinaryHeap()

    for _ in range(len_binary_heap):
        binary_heap_dyn.insert(int(input('Enter binary heap value - ')))    

    print('Binary Heap Array representation - Dynamic input')        
    print(binary_heap_dyn.printData())        

    print('Priority Queue - mininum value')               
    for _ in range(len_binary_heap + 1):
        print(binary_heap_dyn.deleteMin())

    '''
    
    Sample Input : [2,5,1,3,6]
    Sample Output : 1, 3, 2, 5, 6 
        
    Deletion Order - 1, 2, 3, 5, 6
    
    '''
