class node:
    def __init__(self,key):
        self.left = None
        self.right = None
        self.val = key

def PreOrder(root):
    if root:
        print(root.val, end = " ")
        PreOrder(root.left)
        PreOrder(root.right)

root = node(1)
root.left = node(2)
root.right = node(3)
root.left.left = node(4)
root.left.right = node(5)
root.right.left = node(6)
root.right.right = node(7)

print("Pre Order traversal of tree is", end = " ")
PreOrder(root)

''' Output

Pre Order traversal of tree is 1 2 4 5 3 6 7

'''
