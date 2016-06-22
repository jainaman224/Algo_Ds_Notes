class node:
    def __init__(self, value):
        self.data = value
        self.next = None

class Stacks:
    def __init__(self):
        self.TOS = None

    def Push(self, value):
        new_node = node(value)
        new_node.next = self.TOS
        self.TOS = new_node

    def Pop(self):
        if self.TOS == None:
            print("Stack is empty")
        else:
            self.TOS = self.TOS.next

    def Print_Stack(self):
        if self.TOS == None:
            print("Stack is empty")
        else:
            print("Top of stack is " + str(self.TOS.data))

            if self.TOS.next != None:
                print("Other elements are :", end = " ")
                current = self.TOS.next

                while current != None:
                    print(current.data, end = " ")
                    current = current.next

                print()

Stack = Stacks()

for i in range(0, 5):
    Stack.Push(i)

Stack.Print_Stack()

for i in range(0, 6):
    Stack.Pop()

Stack.Print_Stack()


''' Output

Top of stack is 4
Other elements are : 3 2 1 0
Stack is empty
Stack is empty

'''
