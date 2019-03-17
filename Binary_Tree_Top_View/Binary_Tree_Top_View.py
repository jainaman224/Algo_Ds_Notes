class newNode:

# Construct to create a newNode
def __init__(self, key):
self.data = key
self.left = None
self.right = None
self.hd = 0

# function should print the topView
# of the binary tree
def topview(root) :

if(root == None) :
return
q = []
m = dict()
hd = 0
root.hd = hd

# push node and horizontal
# distance to queue
q.append(root)

while(len(q)) :
root = q[0]
hd = root.hd

# count function returns 1 if the
# container contains an element
# whose key is equivalent to hd,
# or returns zero otherwise.
if hd not in m:
m[hd] = root.data
if(root.left) :
root.left.hd = hd – 1
q.append(root.left)

if(root.right):
root.right.hd = hd + 1
q.append(root.right)

q.pop(0)
for i in sorted (m):
print(m[i], end = “”)

# Driver Code
if __name__ == ‘__main__’:


root = newNode(1)
root.left = newNode(2)
root.right = newNode(3)
root.left.right = newNode(4)
root.left.right.right = newNode(5)
root.left.right.right.right = newNode(6)
print(“Following are nodes in top”,“view of Binary Tree”)
topview(root)
