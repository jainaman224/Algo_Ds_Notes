class node:
    def __init__(self,key):
        self.left = None
        self.right = None
        self.val = key

def PostOrder(root):
    if root:
        PostOrder(root.left)
        PostOrder(root.right)
        print(root.val, end = " ")

root = node(1)
root.left = node(2)
root.right = node(3)
root.left.left = node(4)
root.left.right = node(5)
root.right.left = node(6)
root.right.right = node(7)

print("Post Order traversal of tree is", end = " ")
PostOrder(root)

''' Output

Post Order traversal of tree is 4 5 2 6 7 3 1

'''
