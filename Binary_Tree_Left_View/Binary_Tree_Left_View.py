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

# call to leftView function
leftView(root)

'''
    Input:
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
