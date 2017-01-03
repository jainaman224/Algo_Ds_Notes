class node:
    def __init__(self,key):
        self.left = None
        self.right = None
        self.val = key

def InOrder(root):
    if root:
        InOrder(root.left)
        print(root.val, end = " ")
        InOrder(root.right)

root = node(1)
root.left = node(2)
root.right = node(3)
root.left.left = node(4)
root.left.right = node(5)
root.right.left = node(6)
root.right.right = node(7)

print("In Order traversal of tree is", end = " ")
InOrder(root)

''' Output

In Order traversal of tree is 4 2 5 1 6 3 7

'''
