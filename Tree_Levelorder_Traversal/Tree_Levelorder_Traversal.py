class node:
    def __init__(self,key):
        self.left = None
        self.right = None
        self.val = key

def LevelOrder(root):
    if root:
        queue = []
        queue.append(root)
        while(len(queue) > 0):
            if(queue[0].left!=None):
                queue.append(queue[0].left)
            if(queue[0].right!=None):
                queue.append(queue[0].right)
            print(queue[0].val, end = " ")
            queue.pop(0)

root = node(1)
root.left = node(2)
root.right = node(3)
root.left.left = node(4)
root.left.right = node(5)
root.right.left = node(6)
root.right.right = node(7)

print("Level Order traversal of tree is", end = " ")
LevelOrder(root)

''' Output

Level Order traversal of tree is 1 2 3 4 5 6 7

'''
