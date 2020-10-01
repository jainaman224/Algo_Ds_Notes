'''
One other way to represent a mathematical equation is Expression Tree. It is a binary
tree in which every parent node corresponds to the operator and the leaf nodes correspond
to operands.
Expression Tree of a + b is :

      +
     / \
    a   b
Preorder traversal of expression tree will give us prefix to of the expression and inorder
traversal will results to infix expression.
'''

# stack class
class stack:
    def __init__(self):
        self.arr = []

    def push(self, data):
        self.arr.append(data)

    def pop(self):
        try:
            return self.arr.pop(-1)
        except:
            pass

    def top(self):
        try:
            return self.arr[-1]
        except:
            pass

    def size(self):
        return len(self.arr)

# node class for expression tree
class node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# expression tree class
class exp_tree:
    def __init__(self, postfix_exp):
        self.exp = postfix_exp
        self.root = None
        self.createTree(self.exp)

    def isOperator(self, char):
        optr = ['+', '-', '*', '/', '^']
        if char in optr:  # if given char is operator
            return True  # then return true
        return False  # else return false

    def createTree(self, exp):
        s = stack()  # store those operator node whose any child node is NULL
        self.root = node(exp[-1])
        # last character of postfix expression is always an operator
        s.push(self.root)
        # travel on rest of the postfix expression
        for i in "".join(reversed(exp[:-1])):
            curr_node = s.top()
            if not curr_node.right:  # if right node of current node is NULL
                temp = node(i)
                curr_node.right = temp
                if self.isOperator(i):
                    s.push(temp)
            else:  # if left node of current node is NULL
                temp = node(i)
                curr_node.left = temp
                # if no child node of current node is NULL
                s.pop()  # pop current from stack
                if self.isOperator(i):
                    s.push(temp)

    def inorder(self, head):  # inorder traversal of expression tree
        # inorder traversal => left,root,right
        if head.left:
            self.inorder(head.left)
        print(head.data, end=" ")
        if head.right:
            self.inorder(head.right)

    def infixExp(self):  # inorder traversal of expression tree give infix expression
        self.inorder(self.root)
        print()

if __name__ == "__main__":
    postfixExp = input()
    et = exp_tree(postfixExp)
    et.infixExp()

'''
sample input  : 395+2*+
sample output : 3 + 9 + 5 * 2
'''

'''
This code is contributed by raghav
https://github.com/raghav-dalmia
'''

