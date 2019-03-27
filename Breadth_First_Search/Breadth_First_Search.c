//BFS on graphs using adjacency matrix
//Expected complexity O(V^2)
//uses 1-based indexing for vertices
#include<stdio.h>
#include<stdlib.h>
int queue[1000];
int front=-1;
int rear=-1;
int graph[1000][1000];//the graph 2-D array
int state[1000]; //stores 1 for visited nodes(black), 0 for unvisited nodes(white)
int n; 
int dequeue(int n);
int front1();
int enqueue(int e);
int isempty();
int printq(int n);
void graph_initiator();
void BFS(int node);
//BFS functions
void BFS_run()//runs BFS on the whole graph starting from vertex 0
{
	for(int i=0; i<n; i++) 
		state[i] = 0;
	int v;
	for (int i=0;i<n;i++)
	{
	if (state[i]!=1)
	BFS(i);
	}
}
 
void BFS(int node)//main function for BFS
{
	enqueue(node);
	state[node]=1;
	while (!isempty())
	{
	int val=front1();
	printf("%d ",val+1);
	dequeue(n);
	for (int i=0;i<n;i++)
	{
		if (graph[val][i]==1){ // checks for neighbours of node to perform BFS on
		if (state[graph[val][i]]!=1)
		{
			enqueue(graph[val][i]);
			state[graph[val][i]]=1;
		}
	}
		else
			continue;
	} 
	}
}
//UTILITY FUNCTIONS FOR QUEUE
int enqueue(int e)
{

	if(front == -1) 
		front = 0;
	rear = rear+1;
	queue[rear] = e ;
	
}
int dequeue(int n)
{
	int elmnt;
	if(front == -1 || front > rear)
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	
	elmnt= queue[front];
	front+=1;
	return elmnt;
}
int front1()//returns queue[front]
{
	if (isempty()){
		printf("Empty queue!!\n");}
	else
	return queue[front];
}

int isempty()
{
	
	if (front == -1 || front > rear)
		return 1;
	else
		return 0;
}
int printq(int n)
{
	int size=(rear-front);
	for (int i=front;i<=size+1;i++)
		printf("%d\n",queue[i]);
}
void graph_initiator()//initiates the graph
{
	n=0;
	printf("Enter number of vertices : \n");
	scanf("%d",&n);
	int e;
	printf("Enter number of edges:\n");
	scanf("%d",&e);
	printf("Enter start and finish vertex for each edge:\n");
	//inputs the edges from start to finish nodes
 	for (int i=0;i<n;i++)
 	{
 		for (int j=0;j<n;j++)
 			graph[i][j]=0;
 	}
	for(int i=1; i<=e; i++)
	{
		int origin,destin;
		scanf("%d %d",&origin,&destin);
		graph[origin-1][destin-1] = 1;
	}
}
int main()
{
	graph_initiator();
	BFS_run();
	printf("\n");
}
