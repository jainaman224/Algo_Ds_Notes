'''
Vertical Order Traversal of Binary Tree is a traversal in which all nodes that fall in the same vertical line are visited together, starting from the leftmost vertical line and ending at the rightmost vertical line. The horizontal distance is measured with root serving as reference, then we measure the left and right deviations of the each node.
'''

import queue

# Node of Binary Tree storing data, horizontal distance from root, left and right child information
class Node:
    def __init__(self, val): 
        self.data = val
        self.distance = 0
        self.left = None
        self.right = None

# Function to print Binary Tree in Vertical Order
def VerticalOrderTraversal(root):
    if root is None:
        return

    # initialising variables
    q = queue.Queue()
    q.put(root)
    root.distance = 0;
    mp = {}
    # variable to store distance of nodes
    distance = 0

    # asigning horizontal distance to each node of Binary Tree 
    # storing all nodes of same horizontal distance in a map with key as distance
    while (not q.empty()):
        # extract and remove the node from the front of queue
        temp = q.get()
        distance = temp.distance
        # make key as distance and data as value for map
        try: 
            mp[distance].append(temp.data)
        except: 
            mp[distance] = [temp.data] 
        
        # when left child exists, assign horizontal distance to it, and push it to the queue
        if temp.left is not None:
            temp.left.distance = distance - 1
            q.put(temp.left)
        # when right child exists, assign horizontal distance to it, and push it to the queue
        if temp.right is not None: 
            temp.right.distance = distance + 1
            q.put(temp.right)
    '''
    Map mp contains:
    [-2] -> {4}
    [-1] -> {2, 8}
    [0] -> {1, 5, 6}
    [1] -> {3, 9}
    [2] -> {7}
    '''

    print("Vertical Order Traversal of Tree: ")
    # Iterate over the map keys i.e -2, -1, 0, 1, 2
    for key, value in enumerate(sorted(mp)): 
        for i in mp[value]: 
            print(i,end=" ")
        print()

# Driver Code
'''
Contructing Binary Tree as:
            1
         /     \
        2       3
      /   \   /   \
    4      5 6     7
         /   \
        /      \
       8        9
'''
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
root.right.left = Node(6)
root.right.right = Node(7)
root.left.right.left = Node(8)
root.left.right.right = Node(9)
# call to VerticalOrderTraversal function
VerticalOrderTraversal(root)

'''
Output:
Vertical Order Traversal of Tree: 
4 
2 8 
1 5 6 
3 9 
7 
'''
