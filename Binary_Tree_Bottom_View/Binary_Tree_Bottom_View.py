'''
    The Bottom View of a Binary Tree depicts the nodes that are visible 
    when the tree is viewed from below. At every horizontal distance 
    there would be exactly one node that will appear in bottom view.
    The horizontal distance is measured with root serving as reference,
    then we measure the left and right deviations of the each node.
'''

import queue

# Node of Binary Tree storing data, horizontal distance from root
# left and right child information
class Node:
    def __init__(self, val): 
        self.data = val
        self.distance = 0
        self.left = None
        self.right = None

# Function to print Bottom View of Binary Tree
def BottomView(root):
    if root is None:
        return

    # initialising variables
    q = queue.Queue()
    q.put(root)
    root.distance = 0
    mp = {}
    # variable to store distance of nodes
    distance = 0

    # asigning horizontal distance to each node of Binary Tree 
    # storing all nodes of same horizontal distance in a map
    # with key as distance
    while (not q.empty()):
        # extract and remove the node from the front of queue
        temp = q.get()
        distance = temp.distance
        # make key as distance and data as value for map
        try: 
            mp[distance].append(temp.data)
        except: 
            mp[distance] = temp.data
        
        # when left child exists, assign horizontal distance to it
        # and push it to the queue
        if temp.left is not None:
            temp.left.distance = distance - 1
            q.put(temp.left)

        # when right child exists, assign horizontal distance to it
        # and push it to the queue
        if temp.right is not None: 
            temp.right.distance = distance + 1
            q.put(temp.right)
    '''
         Map mp contains:
        [-2] -> 4
        [-1] -> 8
        [0] -> 6
        [1] -> 9
        [2] -> 7
    '''

    print("Bottom View of Binary Tree: ")
    # Iterate over the map keys i.e -2, -1, 0, 1, 2
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

# call to BottomView function
BottomView(root)

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
    Bottom View of Binary Tree:
    4 8 6 9 7
'''
