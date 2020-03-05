// Kruskal Algorithm in C
#include <stdio.h>
#define NUM 20

// Creating the edge
typedef struct edge 
{
    int p;    // Variable to contain all the first node of the edge
    int q;    // Variable to contain all the second node of the edge  
    int weight;    // Variable to contain the weight of the edge
} edge;
 
// Creating the Edgelist
typedef struct edgelist 
{
    edge data[NUM];
    int n;
} edgelist;
 
edgelist list;
int weights[NUM][NUM];    // Array for weights in the graph
int n;
edgelist listSpan;
 
void kruskal_algo();
void print();
int find(int contain[], int vertexno);
void union1(int contain[], int c1, int c2);
void sort();

// Driver Program
int main() 
{
    int total_cost;
    printf("\nEnter number of vertices : ");
    scanf("%d", &n);    // Number of Vertices
	
    printf("\nEnter the adjacency matrix : \n");
	
    for(int i = 0; i < n; i++)    // Enter the Adjacency Matrix
    for(int j = 0; j < n; j++)
    scanf("%d", &weights[i][j]);
			
    kruskal_algo();
    print();
    return 0;
}

// Function performing Kruskal's algorithm
void kruskal_algo() 
{
    int contain[NUM], x, y;
    list.n = 0;
 
    for(int i = 1; i < n; i++)
    for(int j = 0; j < i; j++) 
    {
        if(weights[i][j] != 0) 
        {
            // Containing all the first node of the edges
            list.data[list.n].p = i;
            // Containing all the second node of the edges
            list.data[list.n].q = j;
            // Containing the weight of the edges
            list.data[list.n].weight = weights[i][j];
            list.n++;
        }
    }

    // Sorting the edges according to their weight.
    sort();
	
    for(int i = 0; i < n; i++)
    contain[i] = i;    // Intializing the array with first node
	
    listSpan.n = 0;
	
    for(int i = 0; i < list.n; i++) 
    {
        x = find(contain, list.data[i].p);     // x is the first node of the edge
        y = find(contain, list.data[i].q);     // y is the second node of the edge
        if(x != y) 
        {
            listSpan.data[listSpan.n] = list.data[i];
            listSpan.n = listSpan.n+1;
            union1(contain, x, y);
        }
    }
}
 
// Returns the value present at k[vertex_number]
int find(int contain[], int vertex_number) 
{
    return(contain[vertex_number]);
}
 
void union1(int contain[], int c1, int c2) 
{
    for(int i = 0; i < n; i++)
    if(contain[i] == c2)
        contain[i] = c1;
}
 
// Sorting all the edges in increasing order
// according to their weight.
void sort() 
{
    edge temp;
    for(int i = 1; i < list.n; i++) 
    {
        for(int j = 0; j < list.n-1; j++) 
        {
            if(list.data[j].weight > list.data[j+1].weight) 
            {
                temp = list.data[j];
                list.data[j] = list.data[j+1];
                list.data[j+1] = temp;
            }
        }
    }
}

// Printing the Output
void print() 
{
    int cost = 0;
    for(int i = 0; i < listSpan.n; i++) 
    {
        printf("\n%d\t%d\t%d", listSpan.data[i].p, listSpan.data[i].q, listSpan.data[i].weight);
        cost = cost + listSpan.data[i].weight;
    }
    printf("\nCost of the spanning tree = %d\n", cost);
}

/*
INPUT :
Enter number of vertices : 6
Enter the Adjacency Matrix :
    0  3  0  0  6  5    
    3  0  1  0  0  4 
    0  1  0  6  0  4
    0  0  6  0  8  5 
    6  0  0  8  0  2 
    5  4  4  5  2  0 

OUTPUT :

    2     1     1
    5     4     2
    1     0     3
    5     1     4
Cost of the spanning tree = 15
*/
