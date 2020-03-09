// C program for array implementation of queue
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// A structure to represent a queue
typedef struct Queue
{
	int front, rear, size;
	unsigned capacity;
	int* array;
}Queue;


Queue* createQueue(unsigned capacity)
{
	Queue* queue = (Queue*) malloc(sizeof(Queue));
	queue->capacity = capacity;
	queue->front = queue->size = 0;
	queue->rear = capacity - 1; // This is important, see the enqueue
	queue->array = (int*) malloc(queue->capacity * sizeof(int));
	return queue;
}


int isFull(Queue* queue)
{ return (queue->size == queue->capacity); }

int isEmpty(Queue* queue)
{ return (queue->size == 0); }

void enqueue(Queue* queue, int item)
{
	if (isFull(queue))
		return;
	queue->rear = (queue->rear + 1)%queue->capacity;
	queue->array[queue->rear] = item;
	queue->size = queue->size + 1;
	printf("%d enqueued to queue\n", item);
}
int dequeue(Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	int item = queue->array[queue->front];
	queue->front = (queue->front + 1)%queue->capacity;
	queue->size = queue->size - 1;
	return item;
}

int front(Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	return queue->array[queue->front];
}
int rear(Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	return queue->array[queue->rear];
}

int main()
{
	 Queue* queue = createQueue(1000);

	enqueue(queue, 5);
	enqueue(queue, 7);
	enqueue(queue, 23);
	enqueue(queue, 67);

	printf("%d dequeued from queue\n", dequeue(queue));

	printf("Front item is %d\n", front(queue));
	printf("Rear item is %d\n", rear(queue));

	return 0;
}
//output
/*
5 enqueued to queue
7 enqueued to queue
23 enqueued to queue
67 enqueued to queue
5 dequeued from queue
Front item is 7
Rear item is 67
*/
