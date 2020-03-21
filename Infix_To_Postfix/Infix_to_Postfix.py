# A program to convert infix expression to postfix expression and then evaluate its value.

postfix_list = [] # to hold result of postfix expression
stack = [] # helps in converting exp to postfix
stack2 = [] # helps in evaluating postfix expression

#function to check for operand 
def is_operand(a):
    if a == '+' or a == '-' or a == '/' or a == '*' or a == '^':
        return False
    return True

# function to check if precedence of 1st arg is more than the 2nd arg
def precedence(b, c):
    if (c == "+" or c == "-") and (b == "*" or b == "/"):
        return True
    elif b == "^":
        return True

# function to help evalute expression by performing different operations
def perform(c, b, a):
    d = 0
    if b == "+":
        d = int(a) + int(c)
    elif b == "-":
        d = int(a) - int(c)
    elif b == "*":
        d = int(a) * int(c)
    elif b == "/":
        d = int(a) / int(c)
    elif b == "^":
        d = int(a) ** int(c)
    return d

#function to convert exp to postfix
def postfix(list1):
    for _ in list1:
        if is_operand(_) and _ != ")" and _ != "(":  # checks for true operand
            postfix_list.append(_)
        elif _ is not is_operand(_) and _ != ")" and _ != "(":
            # if len(stack) and stack[-1] == "(":
            #     stack.append(_)
            # else:
            while len(stack) and stack[-1] != "(" and precedence(stack[-1], _):
                postfix_list.append(stack.pop())
            stack.append(_)    
        elif _ == '(':
            stack.append(_)
        elif _ == ")":
            while len(stack) and stack[-1] != "(":
                postfix_list.append(stack.pop())
            stack.pop()
    while len(stack):
            postfix_list.append(stack.pop())

#function to evalute postfix expression 
def evaluate(list2):
    stack2 = []
    for _ in list2:
        if is_operand(_):
            stack2.append(_)
        else:
            if len(stack2)>=2:
                stack2.append(perform(stack2.pop(), _, stack2.pop()))
    result = stack2.pop()
    print(result)

# Driver Code
number = []
number = input().split()
postfix(number)
print("The Postfix of the given expression is ")
print(postfix_list)
evaluate(postfix_list)

#Sample Test Cases
# Input : ( 12 + 45 ) * 5 ^ 2
# Output: The Postfix of the given expression is 
#         12 45 + 5 2 ^ *
#         1425
# Input : ( 12 + 4 ) * 5 - 8 * 9 - 5 ^ 2
# Output: The Postfix of the given expression is 
#         12 4 + 5 * 8 9 * 5 2 ^ - -
#         33

