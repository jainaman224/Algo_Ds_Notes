from __future__ import print_function #used for modifying how print works

class Node(object):
    def __init__(self, data=None, next_node=None):
        self.data =data
        self.next_node = next_node

    def reverse_iterative(self,n):
        last = None
        current = n

        while(current is not None):
            next_node = current.next_node
            current.next_node = last
            last = current
            current = next_node

        return last

#chain together the node.  n3 will be head while n0 the tail
n0 = Node(4,None)
n1 = Node(3,n0)
n2 = Node(2,n1)
n3 = Node(1,n2)

head = n3 # the head of the nodes
print("Before Reverse", end=" ")
while head:
    print(head.data ,end=" ")
    head = head.next_node

print("\nAfter Reverse", end=" ")
head = n3  # the head of the nodes
n = Node() # will contain reverse linked_list
n = head.reverse_iterative(head)
while n:
    print(n.data ,end=" ")
    n = n.next_node
