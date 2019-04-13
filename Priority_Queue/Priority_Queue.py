# A simple implementation of Priority Queue (resembing a max-heap)
# using Queue. 
class PriorityQueue(object): 
	#class initialisation
	def __init__(self): 
		self.queue = [] 

	#prints the priority queue when print function is called
	def __str__(self): 
		return ' '.join([str(i) for i in self.queue]) 

	# for checking if the queue is empty 
	def isEmpty(self): 
		return len(self.queue) == [] 

	# for inserting an element in the queue 
	def insert(self, data): 
		self.queue.append(data) 

	# for popping an element based on Priority 
	def delete(self): 
		try: #checks if it is possible to pop any more elements from the priority queue
			max = 0
			for i in range(len(self.queue)): 
				if self.queue[i] > self.queue[max]: #decides priority
					max = i 
			item = self.queue[max] 
			del self.queue[max] 
			return item 
		except IndexError: #if index out of range it prints "Error!" and exits
			print("Error!") 
			exit() 

if __name__ == '__main__': 
	q1 = PriorityQueue() 
	q1.insert(5) 
	q1.insert(1) 
	q1.insert(3) 
	q1.insert(10) 
	print(q1)			 
	while q1.isEmpty() != 1: 
		print(q1.delete()) 
"""OUTPUT:
5 1 3 10
10
5
3
1
Error!
"""


