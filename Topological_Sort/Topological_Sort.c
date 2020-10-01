//Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of
//vertices such that for every directed edge uv, vertex u comes before v in the ordering.

#include<stdio.h>
#include<stdlib.h>

#define MAX 50

void create_graph();
void add(int);
int delete();
int isEmpty();
int find_indegree(int);

int total_vertices;
int adj_matrix[MAX][MAX];
int queue[MAX];
int front = -1;
int rear = -1;

int main()
{
    int i, vertex, count, topological_sort[MAX], indegree[MAX];
    create_graph();//To create the graph
    for(i = 0; i < total_vertices; i++)
    {
        indegree[i] = find_indegree(i);
        if(indegree[i] == 0)
        {
            add(i);
        }
    }
    count = 0;
    while(!isEmpty() && count < total_vertices)
    {
        vertex = delete();
        topological_sort[++count] = vertex;
        for(i = 0; i < total_vertices; i++)
        {
            if(adj_matrix[vertex][i] == 1)
            {
                adj_matrix[vertex][i] = 0;
                indegree[i] = indegree[i] - 1;
                if(indegree[i] == 0)
                {
                    add(i);
                }
            }
        }
    }
    if(count < total_vertices)
    {
        printf("Graph is Cyclic. Therefore, Topological Ordering Not Possible\n");
        exit(1);
    }
    
    printf("Topological Sort \n");
    for(i = 1; i <= count; i++)
    {
        printf("%2d", topological_sort[i]);
    }
    printf("\n");
    return 0;
}

void create_graph()
{
    int count, edges, origin_vertex, destination_vertex;
    printf("Enter number of vertices ");
    scanf("%d", &total_vertices);
      
    printf("Enter the number of edges ");
    scanf("%d",&edges);
    for(count = 1; count <= edges; count++)
    {
        printf("Enter Edge [%d] co-ordinates (Origin Vertex and Destination vertex)  ", count);
        scanf("%d", &origin_vertex);
        scanf("%d", &destination_vertex);
        adj_matrix[origin_vertex][destination_vertex] = 1;//Assigning the value in adjacent matrix
    }
}

void add(int vertex)
{
    if(rear == MAX - 1)
    {
        printf("Queue Overflow\n");//No more vertex can be added i.e. array is completely filled
    }
    else
    {
        if(front == -1) 
        {
            front = 0;
        }
        rear = rear + 1;
        queue[rear] = vertex ;
    }
}

int isEmpty()
{
    if(front == -1 || front > rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int delete()
{
    int element;
    if(front == -1 || front > rear)
    {
        printf("Queue Underflow\n");//No element present
        exit(1);
    }
    else
    {
        element = queue[front];
        front = front + 1;
        return element;
    }
}

//to find sum of indegree
int find_indegree(int vertex)
{   
    int count, total_indegree = 0;
    for(count = 0; count < total_vertices; count++)
    {
        if(adj_matrix[count][vertex] == 1)
        {
            total_indegree++;
        }
    }
    return total_indegree;
}

/* Enter number of vertices 6
Enter the number of edges 6
Enter Edge [1] co-ordinates (Origin Vertex and Destination vertex)  5
2
Enter Edge [2] co-ordinates (Origin Vertex and Destination vertex)  2
3
Enter Edge [3] co-ordinates (Origin Vertex and Destination vertex)  3
1
Enter Edge [4] co-ordinates (Origin Vertex and Destination vertex)  4
1
Enter Edge [5] co-ordinates (Origin Vertex and Destination vertex)  4
0
Enter Edge [6] co-ordinates (Origin Vertex and Destination vertex)  2
0
Topological Sort 
 4 5 2 0 3 1   */
