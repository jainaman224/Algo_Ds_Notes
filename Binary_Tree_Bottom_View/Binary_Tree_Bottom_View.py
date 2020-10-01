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
m = {}
# Input number of edges
n = int(input())
root = None

''' 
    Input Format :
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

# call to BottomView function
BottomView(root)

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
    Bottom View of Binary Tree:
    4 8 6 9 7
'''
