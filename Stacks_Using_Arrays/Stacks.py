class Stacks:
    def __init__(self):
        self.size = 10
        self.tos = -1
        self.array = [0] * self.size

    def __init__(self, size):
        self.size = size
        self.tos = -1
        self.array = [0] * size

    def push(self, value):
        if self.tos == self.size - 1:
            print("Stack is full")
        else:
            self.tos += 1
            self.array[self.tos] = value

    def pop(self):
        if self.tos == -1:
            print("Stack is empty")
        else:
            self.tos -= 1

    def traverse(self):
        temp = self.tos - 1

        if self.tos == -1:
            print("Stack is empty")
        else:
            print("Top of stack is : " + str(self.array[self.tos]))

            if temp > -1:
                print("Other :", end = " ")

            while temp > -1:
                print(self.array[temp], end = " ")
                temp -= 1

            print()


st = Stacks(5)

for i in range(0, 6):
    st.push(i)

st.traverse()

for i in range(0, 6):
    st.pop()

'''
    Output

    Stack is full
    Top of stack is : 4
    Other : 3 2 1 0
    Stack is empty
'''
