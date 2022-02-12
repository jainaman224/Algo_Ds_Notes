#include <stdio.h>
#include <stdlib.h>
// we are implementing tree with the help of queue 
// for performing BFS we need a queue data structure // and this queue is using linkedlist 
struct Node
{
	int data;
	struct Node* next;
}*front = NULL, * rear = NULL;										//front and rear pointer to help in insertion and deletion of nodes in Queue

void enqueue(int x)
{
	struct Node* t;
	t = (struct Node*)malloc(sizeof(struct Node));					//Node is created in Heap

	if (t == NULL)													//if node was not created due to insufficient space in the HEAP
		printf("Queue is Full\n");
	else
	{
		t->data = x;
		t->next = NULL;

		if (front == NULL)											//if front is NULL it means it is the first node of the queue //first node condition
			front = rear = t;										//if it is the first node make front and rear both point on the first node
		else														//if it is not the first node
		{
			rear->next = t;											//last node which is rear //rear->next points on the new node
			rear = t;												//the new node is updated as the rear 
		}
	}
}

int dequeue()
{
	int x = -1;												//If Queue is empty the function will return -1 
	struct Node* t;											//temporary pointer to hold the address of the node that is to be deleted

	if (front == NULL)										//If front is NULL there is no nodes in the Queue
		printf("Queue is Empty\n");
	else
	{
		t = front;											//temp pointer is made to point on the front node
		front = front->next;								//front node is updated to its next node
		x = t->data;										//x assigns the data value of t node
		free(t);											//t node is deleted
	}
	return x;												//x is returned as the deleted element
}
int isEmpty() 
{
	return front == NULL;
}
void BFS(int G[][7], int start, int n) // it sud take matrix i.e G 1st dimension is not require // starting point // and the order of the matrix i.e 7x7 
{
	int i = start, j; // for start of a ttaversal we need a variable 
	int visited[7] = { 0 }; // we need an array i.e visited array size of 7 intialized with zero 

	printf("%d ", i); //1st of all print the starting vertex  taked vertex in i 
	visited[i] = 1; // mark the starting vertex as visited 
	enqueue(i); // then push i in the queue 
	// then i sud perform a repeting task 
	while (!isEmpty()) // while there is vertex 
	{
		i = dequeue(); // everytime i will get a vertex 
		for (j = 1; j < n; j++) // as long as j is less then n i.e 7 
		{
			if (G[i][j] == 1 && visited[j] == 0) // everytime check either edge or vertex is visited or not ==1 means there is an edge // and it is not yet visited 
			{
				printf("%d ", j); // print j 
				visited[j] = 1; // mark visited of j as 1 
				enqueue(j); // push j in queue 
			}
		}
	}


}
void DFS(int G[][7], int start, int n)// it sud take matrix i.e G 1st dimension is not require // starting point // and the order of the matrix i.e 7x7 
{
	static int visited[7] = { 0 }; // declear it as static array so that it can be accsessible to every call // intialized it as zero 
	int j;

	if (visited[start] == 0) // if it is not yet visited 
	{
		printf("%d ", start); // print that vertex 
		visited[start] = 1; // mark it as visited  else it will go infite loop 

		for (j = 1; j < n; j++) // we have to explore vertes so go through loop 
		{
			if (G[start][j] == 1 && visited[j] == 0) // everytime we check that if it is an edge from i i.e starting vertex // if it is not yet visited 
				DFS(G, j, n); // recursion call 
		}
	}
}
int main()
{
	int G[7][7] = { {0,0,0,0,0,0,0}, // 1st row and 1st col is zero 
	{0,0,1,1,0,0,0},
	{0,1,0,0,1,0,0},
	{0,1,0,0,1,0,0},
	{0,0,1,1,0,1,1},
	{0,0,0,0,1,0,0},
	{0,0,0,0,1,0,0} };
	DFS(G, 3, 7); // graph // staring index // order of matrix 

	return 0;
}

