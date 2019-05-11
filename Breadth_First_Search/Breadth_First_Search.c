//BFS on graphs using adjacency matrix
//Expected complexity O(V^2)
//uses 1-based indexing for vertices
#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

//inititation of data structures
int queue[MAX]; //the queue array
int graph[MAX][MAX]; //the graph 2-D array
int state[MAX]; //array that stores 1 for visited nodes(black), 0 for unvisited nodes(white)

int n; //no of vertices in the graph 

//queue pointers:
int front = -1;
int rear = -1;

//function declarations
int dequeue(int n);
int front1();
int enqueue(int e);
int isempty();
void graph_initiator();
void BFS(int node);


//BFS FUNCTIONS:

/*Runs BFS on every vertex of the graph that hasn't been visited(marked black or 1) yet */
void BFS_run()	
{
    for (int i = 0; i < n; i++) // initialising state of each vertex as 0(white)
        state[i] = 0;
    int v;
    for (int i = 0; i < n; i++)
    {
        if (state[i] != 1)
	    BFS(i);
    }
}
 
/*BFS first enqueues each unvisited vertex to the queue,marks it as visited and stores its value in val.
 Then it dequeues the vertex at the front of the queue itself from the queue.
 For the row of val in the adjacency matrix every column that is marked 1 has an edge from the val vertex to that vertex. 
 Hence they form the neighbors of val.Checks if the neighbours have already been visited or not. 
 If not, then it enqueues the neighbour and marks it as visited. Else, it moves on to the next neighbour.
 */
void BFS(int node)
{
    enqueue(node);
    state[node] = 1;
    while (!isempty())
    {
        int val = front1();
	printf("%d ",val + 1);
	dequeue(n);
	for (int i = 0; i < n; i++)
	{
            if (graph[val][i] == 1) // checks for existence of edge between two nodes
	    { 
	        if (state[graph[val][i]] != 1) // checks for neighbours of node to perform BFS on
		{
		    enqueue(graph[val][i]);
		    state[graph[val][i]] = 1;
		}
	    }
	    else
	        continue;
	} 
    }
}

//FUNCTIONS FOR QUEUE

/* Function to enqueue, i.e insert new element at the rear of the queue array, adds 1 to the rear pointer 
after each insertion. Handles isempty case by setting front =0
*/
int enqueue(int e)
{
    if (front == -1) 
    front = 0;
    rear = rear + 1;
    queue[rear] = e ;	
}

/*Function to delete elements from the front of the queue and return them.
 Returns queue underflow while trying to dequeue from an empty queue 
 */
int dequeue(int n)
{
    int elmnt;
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
	exit(1);
    }
    elmnt= queue[front];
    front += 1;
    return elmnt;
}

/*Returns the element at front of the queue*/
int front1()
{
    if ( isempty() ){
        printf( "Empty queue!!\n" );}
    else
	return queue[front];
}

/*Returns 1 if queue is empty,else 0*/
int isempty()
{
	
    if (front == -1 || front > rear)
        return 1;
    else
	return 0;
}

void matrix_initiator(int origin, int destin)
{
    // assigns vertices and edges 
    graph[origin - 1][ destin - 1] = 1;
}

/*Function to initiate the graph from edges input by user*/
void graph_initiator()
{
    n = 4;
    int e = 6;
    for (int i = 0; i < n; i++) //initialise whole graph matrix with 0s
    {
        for (int j = 0;j < n; j++)
            graph[i][j] = 0;
    }
	
    matrix_initiator(1 , 2);
    matrix_initiator(1 , 3);
    matrix_initiator(2 , 3);
    matrix_initiator(3 , 4);
    matrix_initiator(3 , 1);
    matrix_initiator(4 , 4);
}

//main function
int main()
{
    graph_initiator();
    BFS_run();
    printf("\n");
}

/*OUTPUT
1 2 3 4 
*/
