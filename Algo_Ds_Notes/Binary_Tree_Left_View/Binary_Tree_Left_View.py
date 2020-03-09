'''
    The Left View of a Binary Tree depicts the nodes that are visible 
    when the tree is viewed from the left side of it. At every level 
    there would be exactly one node that will appear in left view which
    would be the first node of that level.
'''

import queue

# Node of Binary Tree storing data, level,
# left and right child information
class Node:
    def __init__(self, val): 
        self.data = val
        self.level = 0
        self.left = None
        self.right = None

# Function to print Left View of Binary Tree
def leftView(root):
    if root is None:
        return

    # initialising variables
    q = queue.Queue()
    q.put(root)
    root.level = 0
    mp = {}

    # variable to store level of nodes
    level = 0

    # asigning level to each node of Binary Tree 
    # storing first node of same level in a map
    # with key as level
    while (not q.empty()):
        # extract and remove the node from the front of queue
        temp = q.get()
        level = temp.level

        # make key as level and data as value for map
        if level not in mp:
            mp[level] = temp.data
        
        # when left child exists, assign level to it
        # and push it to the queue
        if temp.left is not None:
            temp.left.level = level + 1
            q.put(temp.left)

        # when right child exists, assign level to it
        # and push it to the queue
        if temp.right is not None: 
            temp.right.level = level + 1
            q.put(temp.right)
    '''
        Map mp contains:
        [0] -> 1
        [1] -> 2
        [2] -> 4
        [3] -> 8
    '''

    print("Left View of Binary Tree: ")
    # Iterate over the map keys i.e 0, 1, 2, 3
    for key, value in enumerate(sorted(mp)):
        print(mp[value], end = " ")

# Driver Code
m = {}
# Input number of edges
n = int(input())
root = None

''' 
    The input format is that we get node1 which is the parent,
    node2 which is the child, and then direction 'L' or 'R' which
    tells us whether it is a left or right child of node1. Example:
    Input:
    3
    1 2 L
    1 3 R
    2 4 L
    This means there are 3 edges
    2 is the left child of 1,
    3 is the right child of 1,
    4 is the left child of 2.
'''
for i in range(0, n):
    node1, node2, direction = input().split(' ')
    node1 = int(node1)
    node2 = int(node2)
         
    if node1 not in m:
        parent = Node(node1)
        m[node1] = parent
        if root == None:  
            root = parent
    else:
        parent = m[node1]
    child = Node(node2)
    if direction == 'L':
        parent.left = child
    else:
        parent.right = child
    m[node2]  = child

# call to leftView function
leftView(root)

'''
    Input:
    8
    1 2 L 
    1 3 R
    2 4 L 
    2 5 R
    3 6 L
    3 7 R
    5 8 L
    6 9 R
    
            1
         /     \
        2       3
      /   \   /   \
    4      5 6     7
         /   \
        /      \
       8        9

    Output:
    Left View of Binary Tree:
    1 2 4 8
'''
