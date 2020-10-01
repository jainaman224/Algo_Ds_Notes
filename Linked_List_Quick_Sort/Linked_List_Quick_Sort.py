# node class for singly linked list
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# class for maintaining linked list
class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    # add a node at the last of a linked list
    def addNode(self, data):
        temp_node = Node(data)
        if(self.head == None): # if size of list is 0
            self.head = temp_node
            self.tail = temp_node
        else: # size of list in not zero
            self.tail.next = temp_node
            self.tail = temp_node

    # print the whole linked list
    def print(self):
        temp_node = self.head
        output = ""
        while(temp_node != None):
            output = output + str(temp_node.data) + " "
            temp_node = temp_node.next
        print(output)

    # swap data of two nodes 'node1' and 'node2'
    def swapNodeData(self, node1, node2):
        temp = node1.data
        node1.data = node2.data
        node2.data = temp

    # returns previous node of the node 'n'
    def prevNode(self, start, n):
        # if node 'n' is the start of the linked list
        if start == n:
            return None
        while start.next != n:
            start = start.next
        return start

    ''' create the partition of the list
        all the number less than pivot is on left side of pivot
        all the number greater than pivot is on the right side of pivot
        exapmle : input  : 1,5,4,6,2,3
                  output : 1,2,3,6,5,4 '''
    def divideList(self, start, end):
        pivot = end.data
        i = None
        j = start
        while j != end:
            if j.data <= pivot:
                # increment index of smaller element
                if i == None:
                    i = start
                else:
                    i = i.next
                self.swapNodeData(i, j) # swap current and smaller element
            j = j.next
        # increment index of smaller element
        if i == None:
            i = start
        else:
            i = i.next
        self.swapNodeData(i, j) # place pivot at its correct position
        return i

    def quickSortRec(self, start, end):
        if start != end and start != None and end != None and start != end.next:
            pivot = self.divideList(start, end) # create partition of unsorted list
            self.quickSortRec(start, self.prevNode(start, pivot)) # sort list left of pivot
            self.quickSortRec(pivot.next, end) # sort list right of pivot

    def quickSort(self):
        self.quickSortRec(self.head, self.tail)


l = LinkedList()
l.addNode(5)
l.addNode(2)
l.addNode(1)
l.addNode(8)
l.addNode(3)
l.addNode(6)
l.addNode(-1)
l.print()
l.quickSort()
l.print()

'''
this code is contributed by Raghav
https://github.com/raghav-dalmia
'''

'''
sample input : 5 2 1 8 3 6 -1
ouput : -1 1 2 3 5 6 8
'''

