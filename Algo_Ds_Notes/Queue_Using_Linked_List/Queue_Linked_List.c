#include <stdio.h>
#include <stdlib.h>

//A structure having data and link representing a node in linked list
typedef struct node
{
	int data;
	struct node *link;
}node;

node *front=NULL,*rear=NULL;

//A fuction to check for empty queue
int isEmpty()
{
	if (front == NULL)
		return 1;
	else
		return 0;
}

//Fuction to insert node in queue
void enqueue(int elt)
{
	node *newNode;
	newNode = (node *)malloc(sizeof(node));
	newNode->data = elt;
	newNode->link = NULL;
	if (newNode == NULL)
	{
		printf("Memory is not allocated\n");
		return;
	}
	if (front == NULL)
	{
		front = newNode;
		rear = newNode;
	}
	else
	{
		rear->link = newNode;
		rear = newNode;
	}
	printf("%d inserted in the queue\n", elt);
}

//Function to delete a node from queue
void dequeue()
{
	int data;
	if (isEmpty())
	{
		printf("Queue is empty\n");
		return;
	}
	data = front->data;
	printf("Element deleted is %d\n", data);
	front = front->link;
}

//Fucntion to display the queue
void display()
{
	node *ptr;
	if (isEmpty())
	{
		printf("Queue is empty\n");
		return;
	}
	printf("The queue is\n");
	for (ptr = front; ptr != NULL; ptr = ptr->link)
		printf("%d\t", ptr->data);
	printf("\n");
}


int main()
{
	dequeue();
	enqueue(15);
	enqueue(49);
	enqueue(54);
	enqueue(2);
	enqueue(97);
	display();
	dequeue();
	dequeue();
	display();
	return 0;
}

/* Output
Queue is empty
15 inserted in the queue
49 inserted in the queue
54 inserted in the queue
2 inserted in the queue
97 inserted in the queue
The queue is
15	49	54	2	97
Element deleted is 15
Element deleted is 49
The queue is
54	2	97
*/
