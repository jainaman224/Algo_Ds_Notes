size = 4
front = -1
rear = -1
"""
Uncomment to input size from user and validate it
while (1):
	size = int(raw_input("Enter max input\n> "))
	if size > 0:
		break
"""
queue = [0] * size

#Function to check for empty queue
def isEmpty():
	global front, rear
	if (front == -1 or front > rear):
		return True

#Fuction to insert an element in queue
def enqueue(element):
	global front, rear
	if rear == size - 1:
		print "Queue is Full"
	else:
		if front == -1:
			front = 0
		#Uncomment to get input from user
		#element = int(raw_input("Enter the element to insert\n> "))
		rear = rear + 1
		queue[rear] = element
		print "Item inserted successfully"

#Fuction to delete an element from the queue
def dequeue():
	global front, rear
	if isEmpty():
		print "Queue is Empty"
	else:
		element = queue[front]
		front += 1
		print "Item deleted: " + str(element)

#Fuction to display elements from queue
def display():
	global front, rear
	if isEmpty():
		print "Queue is Empty"
	else:
		temp = front
		while (temp <= rear):
			print queue[temp],
			temp += 1
		print

"""
Code to get choice form the user
while(1):
	print "---Queue Operations---"
	print "1. Insert an element in queue."
	print "2. Delelte an element from queue."
	print "3. Display the current queue."
	print "4. Exit."
	ch = int(raw_input("Enter your choice: "))

	if ch == 1:
		enqueue()
	elif ch == 2:
		dequeue()
	elif ch == 3:
		display()
	else:
		break
"""

enqueue(23)
enqueue(45)
enqueue(65)
enqueue(89)
enqueue(90)
dequeue()
dequeue()


"""
Output
Item inserted successfully
Item inserted successfully
Item inserted successfully
Item inserted successfully
Queue is Full
Item deleted: 23
Item deleted: 45
"""
