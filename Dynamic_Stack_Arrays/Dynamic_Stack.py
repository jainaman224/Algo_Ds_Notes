class Dynamic_Stack:
	capacity = 0
	stack = []

	def __init__(self, capacity):
		self.capacity = capacity
		self.stack = []

	def isFull(self):
		return len(self.stack) == self.capacity

	def isEmpty(self):
		return len(self.stack) == 0

	def push(self, element):
		if(self.isFull()):
			return
		else:
			self.stack.append(element)

	def pop(self):
		if(self.isEmpty()):
			return -1
		else:
			temp = self.stack[-1]
			self.stack[:-2]
			return temp

	def peek(self):
		if(self.isEmpty()):
			return -1
		else:
			return self.stack[-1]

# Example
a = Dynamic_Stack(4)

print(a.isEmpty())
a.push(1)
print(a.isEmpty())
a.push(2)
a.push(3)
print(a.isFull())
a.push(4)
print(a.isFull())
print(a.peek())
print(a.pop())
print(a.peek())
