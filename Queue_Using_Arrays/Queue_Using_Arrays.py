size = -1
front = -1
rear = -1

while (1):
	size = int(raw_input("Enter max input\n> "))
	if size > 0:
		break

queue = [0] * size

def isEmpty():
	global front, rear
	if (front == -1 or front > rear):
		return True

def enqueue():
	global front, rear
	if rear == size - 1:
		print "Queue is Full"
	else:
		if front == -1:
			front = 0
		element = int(raw_input("Enter the element to insert\n> "))
		rear = rear + 1
		queue[rear] = element
		print "Item inserted successfully"

def dequeue():
	global front, rear
	if isEmpty():
		print "Queue is Empty"
	else:
		element = queue[front]
		front += 1
		print "Item deleted: " + str(element)

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
