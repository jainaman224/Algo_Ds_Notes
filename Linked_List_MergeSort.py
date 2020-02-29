import atexit
import io
import sys

class Node:
    def __init__(self, data): 
        self.data = data
        self.next = None

# Linked List Class
class LinkedList:
    def __init__(self):
        self.head = None

    # creates a new node with given value and appends it at the end of the linked list
    def append(self, new_value):
        new_node = Node(new_value)
        if self.head is None:
            self.head = new_node
            return
        curr_node = self.head
        while curr_node.next is not None:
            curr_node = curr_node.next
        curr_node.next = new_node


    def merge(self, l1, l2): 
        result = None
          
        # Base cases
        if l1 == None: 
            return l2 

        if l2 == None: 
            return l1
              
        # pick either l1 or l2 and recurse 
        if l1.data <= l2.data: 
            result = l1 
            result.next = self.merge(l1.next, l2) 
        else: 
            result = l2 
            result.next = self.merge(l1, l2.next) 
        return result 


    def mergeSort(self, head):

        if head == None or head.next == None:
            return head

        ptr1 = head
        ptr2 = head.next

        while(ptr2 != None and ptr2.next != None):
            ptr1 = ptr1.next
            if ptr2.next != None:
                ptr2 = ptr2.next.next

        ptr2 = ptr1.next
        ptr1.next = None

        return self.merge(self.mergeSort(head), self.mergeSort(ptr2))


# prints the elements of linked list starting with head
def printList(head):
    if head is None:
        return
        
    temp = head
        
    while temp:
        print(temp.data,end="-->")
        temp = temp.next

    print("NULL")

'''
Sample Input
1 - Test cases
5 - Total number of elements to be inserted in linked list
23 2 34 5 1 - Adding the contents of the linked list

'''

if __name__ == '__main__':
    t=int(input())
        
    for cases in range(t):
        n = int(input())
        li = LinkedList() # create a new linked list 'a'.
        nodes_p = list(map(int, input().strip().split()))
        for x in nodes_p:
            li.append(x)  # add to the end of the list
        
        li.head = li.mergeSort(li.head)
        printList(li.head)
