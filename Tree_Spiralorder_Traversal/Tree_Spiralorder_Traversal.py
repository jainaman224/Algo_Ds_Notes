'''
 Spiral Order Traversal of a tree is level order traversal where levels are explored in zig-zag manner i.e. all nodes present at level 1 should be printed first from left to right, followed by nodes of level 2 right to left, followed by nodes of level 3 from left to right and so on.
'''

import queue

# Node of Binary Tree storing data, level, left and right child information
class Node:
	def __init__(self, val): 
        self.data = val
        self.level = 0
        self.left = None
        self.right = None

# Function to print Binary Tree in Spiral Order
def SpiralOrderTraversal(root):
    if root is None:
        return

    # initialising variables
    q = queue.Queue()
    q.put(root)
    root.distance = 0;
    mp = {}

    # asigning level to each node of Binary Tree 
    # storing all nodes of same level in a map with key as distance
    while (not q.empty()):
        # extract and remove the node from the front of queue
        temp = q.get()

        # make key as level and data as value for map
        try: 
            mp[temp.level].append(temp.data)
        except: 
            mp[temp.level] = [temp.data] 
        
        # when left child exists, assign level to it, and push it to the queue
        if temp.left is not None:
            temp.left.level = temp.level + 1
            q.put(temp.left)
        # when right child exists, assign level to it, and push it to the queue
        if temp.right is not None: 
            temp.right.level = temp.level + 1
            q.put(temp.right)
    '''
    Map mp contains:
    [0] -> 1
    [1] -> 2, 3
    [2] -> 4, 5, 6, 7
    [3] -> 8, 9
    '''

    print("Spiral Order Traversal of Tree: ")
    # Iterate over the map keys i.e 0, 1, 2, 3
    level = 0
    for key, value in enumerate(sorted(mp)):
	# when level is even, print elements of list from left to right
        if level%2==0:
            for i in mp[value]: 
                print(i,end=" ")
            print()
        else:
	# when level is odd, print elements of list in from right to left
            for i in range(len(mp[value])-1, -1, -1): 
                print(mp[value][i],end=" ")
            print()
		# increment level value
        level =  level + 1
        
# Driver Function
# Creating and Inserting nodes in Binary Tree
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
root.right.left = Node(6)
root.right.right = Node(7)
root.left.right.left = Node(8)
root.left.right.right = Node(9)
# call to SpiralOrderTraversal function
SpiralOrderTraversal(root)

'''
Input Graph:
            1
         /     \
        2       3
      /   \   /   \
    4      5 6     7
         /   \
        /      \
       8        9
Output:
Spiral Order Traversal of Tree: 
1 
3 2 
4 5 6 7 
9 8 
'''
