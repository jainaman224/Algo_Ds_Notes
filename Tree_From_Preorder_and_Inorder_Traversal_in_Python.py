
#constructing a node class for tree

class Node:
    def __init__(self):
        self.data=None
        self.left=None
        self.right=None

#constructing a binary tree class

class BinaryTree:
    def __init__(self,preorder,ion) :
        self.root = constructPre(preorder, 0, len(preorder) - 1, ino, 0, len(ino) - 1)

#function for constructing the tree from given inorder and preorder traversal

def constructPre(pre,plo,phi,ino,ilo,ihi):
    root=Node()
    if (plo > phi or ilo > ihi):
        return None
    root.data = pre[plo]
    si=-1
    for i in range(ilo,ihi+1):
        if (ino[i] == pre[plo]):
            si = i
            break
    nel = si - ilo
    
    #constructing left subtree with help of recursion
    
    root.left = constructPre(pre, plo + 1, plo + nel, ino, ilo, si - 1)
    root.right = constructPre(pre, plo + nel + 1, phi, ino, si + 1, ihi)
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

pre = [20, 10, 5, 15, 30, 25, 35]
ino = [5, 10, 15, 20, 25, 30, 35]
bt=BinaryTree(pre, ino)
display(bt.root)

#output
#10 -> 20 <- 30
#5 -> 10 <- 15
#. -> 5 <- .
#. -> 15 <- .
#25 -> 30 <- 35
#. -> 25 <- .
#. -> 35 <- .

