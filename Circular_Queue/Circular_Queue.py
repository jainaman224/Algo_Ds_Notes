class CircularQueue(object):
	'''Simple Circular Queue'''
	
	def __init__(self, size):
		'''
		Intializing the data structure here. Maximum size of the queue is "size".
		'''
		self.Max = size
		self._size = 0
		self.queue = [None] * size
		self._front = self._rear = -1

	def Enqueue(self, key):
		'''
		Insert element key into the queue.
		'''
		if ((self._rear + 1) % self.Max == self._front):
			return False 

		elif (self._front == -1):
			self._front = 0
			self._rear = 0
			self.queue[self._rear] = key


		else:
			self._rear = (self._rear + 1) % self.Max
			self.queue[self._rear] = key
			self._size +=1

		return True

	def Dequeue(self):
		'''
		Delete an element from the queue.
		'''
		if (self._front == -1):
			return False 

		else:
			self._front = (self._front + 1) % self.Max
			self._size -= 1

		if (self._front == -1):
			self._front = -1
			self._rear = -1

		return True
	def Front(self):
		'''
		Get the front item from the queue.
		''' 
		if (self._front == -1):
			return -1

		return self.queue[self._front]
	def Rear(self):
		'''
		Get the last item from the queue.
		'''
		if (self._front == -1):
			return -1

		return self.queue[self._rear]
	def PrintQueue(self):
		'''
		Printing the queue
		'''
		if(self._front == -1):
			print ("Queue is Empty")

		elif (self._rear >= self._front):
			print("Elements in the circular queue are:",end = " ")
			for i in range(self._front, self._rear + 1):
				print(self.queue[i], end = " ")
			print ()
		else:
			print ("Elements in Circular Queue are:",end = " ")
			for i in range(self._front, self.Max):
				print(self.queue[i], end = " ")
			for i in range(0, self.rear + 1):
				print(self.queue[i], end = " ")
			print ()
		if ((self._rear + 1) % self.Max == self._front):
			print("Queue is Full") 

# Sample Input / Output
obj = CircularQueue(6)
p1 = obj.Enqueue(5)
p6 = obj.Enqueue(7)
p7 = obj.Enqueue(8)
p8 = obj.Enqueue(9)
p2 = obj.Dequeue()
p3 = obj.Dequeue()
p8 = obj.Enqueue(10)
p5 = obj.PrintQueue()
