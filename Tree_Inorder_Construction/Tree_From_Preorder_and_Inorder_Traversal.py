
#constructing a node class for tree

class Node:
    def __init__(self):
        self.data=None
        self.left=None
        self.right=None
        
#constructing a binary tree class
        
class BinaryTree:
    def __init__(self,preorder,inorder) :
        self.root = constructTree(preorder, 0, len(preorder) - 1, inorder, 0, len(inorder) - 1)
        
#function for constructing the tree from given inorder and preorder traversal
        
def constructTree(preorder,pre_start,pre_end,inorder,in_start,in_end):
    root=Node()
    if (pre_start > pre_end or in_start > in_end):
        return None
    root.data = preorder[pre_start]
    si=-1
    for i in range(in_start,in_end+1):
        if (inorder[i] == preorder[pre_start]):
            si = i
            break
    nel = si - in_start
    
    #constructing left subtree with help of recursion
    
    root.left = constructTree(preorder, pre_start + 1, pre_start + nel, inorder, in_start, si - 1)

    #constructing right subtree with help of recursion
    
    root.right = constructTree(preorder, pre_start + nel + 1, pre_end, inorder, si + 1, in_end)
    return root

#function for displaying the tree

def display(node):
    if (node == None):
        return
    string= ""
    if (node.left == None):
        string+= "."
    else :
        string += str(node.left.data)
    string += " -> " + str(node.data) + " <- "
    if (node.right == None):
        string += "."
    else :
        string += str(node.right.data)
    print(string)
    display(node.left)
    display(node.right)

#main function for test above functions

preorder = [20, 10, 5, 15, 30, 25, 35]
inorder = [5, 10, 15, 20, 25, 30, 35]
binaryTree=BinaryTree(preorder, inorder)
display(binaryTree.root)

#output
#10 -> 20 <- 30
#5 -> 10 <- 15
#. -> 5 <- .
#. -> 15 <- .
#25 -> 30 <- 35
#. -> 25 <- .
#. -> 35 <- .

