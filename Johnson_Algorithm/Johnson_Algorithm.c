// Implementation of Johnson's algorithm in C

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent Edge of graph
struct Edge {
    // Edge with a source and destination and weight as distance between source and destination
    int source, destination, weight;
};

// Structure to represent a connected, weighted and directed graph
struct Graph {
    // V is number of vertices
    // E is Number of Edges
    int V, E;
    
    // Array of Edge structure
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E)
{
    // Allocate memory to V vertices of graph
    struct Graph* graph = malloc(V * sizeof(int));
    graph -> V = V;
    graph -> E = E;
    
    // Allocate memory to E Edges of graph
    graph -> edge = malloc(E * sizeof(int));
    
    // Information Message
    // printf("The graph is created with %d vertices and %d edges.\n", V, E);
    return graph;
}

struct Graph* addEdge(struct Graph* graph, int src, int des, int wt, int i)
{
    graph -> edge[i].source = src;
    graph -> edge[i].destination = des;
    graph -> edge[i].weight = wt;
    
    return graph;
}

void printGraph(struct Graph* graph)
{
    int E = graph -> E;
    
    for(int i = 0; i < E; i++)
    {
        printf("The distance from %d to %d is: %d\n", graph -> edge[i].source, graph -> edge[i].destination, graph -> edge[i].weight);
    }
    printf("\n");
}

int* BellmanFord(struct Graph* graph, int extra, int* dist)
{
    int V = graph -> V;
    int E = graph -> E;
    
    // Initialize distance from extra vertex to all vertices as Infinite(INT_MAX)
    for(int i = 0; i < V + 1; i++)
    {
        dist[i] = INT_MAX;
    }
    
    // Distance from extra vertex to itself is zero
    dist[extra] = 0;
    
    // Shortest path from any vertex can have atmost V-1 edges
    for(int i = 1; i <= V; i++)
    {
        for(int j = 0; j < E + V; j++)
        {
            int u = graph -> edge[j].source;
            int v = graph -> edge[j].destination;
            int w = graph -> edge[j].weight;
            
            // Check if old distance is greater than new distance
            if(dist[u] != INT_MAX && dist[v] > dist[u] + w)
            {
                // Update old distance with new distance
                dist[v] = dist[u] + w;
            }
        }
    }
    
    return dist;
}

struct Graph* updateEdge(struct Graph* graph, int dist[], int E)
{
    // Update Edge after getting distance from extra vertex to each original vertex
    // To make distance between all vertices poitive
    for(int i = 0; i < E; i++)
    {
        int u = graph -> edge[i].source;
        int v = graph -> edge[i].destination;
        
        // Update distance between from vertex u to v as => distance of u from extra vertex - distance of v from extra vertex + original distance from u to v
        graph -> edge[i].weight = dist[u] - dist[v] + graph -> edge[i].weight;
    }
    
    return graph;
}

int minDistance(int dist[], bool visited[], int V)
{
    // Find closest vertex from source vertex that has not been visited
    
    // Initialize as min as INFINITY(INT_MAX)
    int min = INT_MAX, min_index;
    
    for(int v = 0; v < V; v++)
    {
        // If vertex is not visited and is smaller than current min
        if(!visited[v] && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

int askGraph(struct Graph* graph, int u, int v, int E)
{
    // Return distance from vertex u to vertex v
    
    for(int i = 0; i < E; i++)
    {
        if(graph -> edge[i].source == u && graph -> edge[i].destination == v)
        {
            return graph -> edge[i].weight;
        }
    }
    // return INT_MIN if edge from u to v does not exist
    return INT_MIN;
}

int* Dijsktra(struct Graph* graph, int V, int E, int src, int* dist)
{
    // Calculate shortest path from source vertex to all other vertices
    
    // checks if vertex i is visited and is finalized
    bool visited[V]; 
  
    // Initialize all distances as INT_MAX and visited[] as false 
    for(int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    
    // Distance of source vertex from itself is zero
    dist[src] = 0;
    
    // Shortest path from any vertex can have atmost V-1 edges
    for(int i = 0; i < V - 1; i++)
    {
        // Pick the minimum distance vertex from all vertices
        int u = minDistance(dist, visited, V);
        
        // Picked vertex is visited
        visited[u] = true;
        
        // Update distance of adjacent vertices from picked vertex
        for(int v = 0; v < V; v++)
        {
            // Update dist[v] only if it is not in visited, 
            // Distance from src to v is smaller through src to u to v
            
            // Distance from u to v
            int temp = askGraph(graph, u, v, E); 
            
            if(!visited[v] && dist[u] != INT_MAX && temp != INT_MIN && dist[v] > dist[u] + temp)
            {
                // Update old distance
                dist[v] = dist[u] + temp;
            }
        }
        
    }
    
    return dist;
}
         
int main(){
    
    // V is number of vertices and E is number of Edges in graph
    int V, E;
    
    scanf("%d %d", &V, &E);
    
    // Information Message
    // printf("%d\n",V);
    // printf("%d\n",E);
    
    // Declaring source, destination and weight for edges
    int src, des, wt;
    
	// One Extra vertex (V+1) is considered for calculating distance with each vertex present in original graph 
	// Additional V edges (E+V) from extra vertex to all original vertices is considered
	
    struct Graph* graph = createGraph(V + 1, E + V); 
    
    // Add each edge to graph with source, destination and weight
    for(int i = 0; i < E + V; i++)
    {
        if(i < E) // Original E Edges
        {
            scanf("%d %d %d", &src, &des, &wt);
            // printf("%d %d %d %d\n",src,des,wt, i);
            graph = addEdge(graph, src, des, wt, i);
        }
        else // Extra V edges from one extra vertex to original vertices with 0 weight
        {
            // printf("%d %d %d %d\n",V,i-E,0, i);
            graph = addEdge(graph, V, i - E, 0, i);
        }
    }
    
    // printf("\n");
    
    // Print graph
    // printf("Original Graph:\n\n");
    // printGraph(graph);
    
    // Store distance of each original vertex from extra vertex(including itself)
    int _dist[V + 1];
    
    // BellmanFord Algorithm to calculate distance of all original vertices with negative edges from extra vertex
    int* dist = BellmanFord(graph, V, _dist);
    
    // Update new edge weights between vertices
    graph = updateEdge(graph, dist, E);
    
    // Now will consider original E Edges only, rest V will be ignored from extra vertex total of E+V
    // Also extra vertex will be ignored
    // As was required only to convert negative weight distance between vertices to positive weight distance
    
    // New graph with all positive weight distance
    // printf("Updated Graph:\n\n");
    // printGraph(graph);
    
    // Matrix to store distance of every vertex with every other vertex
    int distance[V][V];
    // Running Dijsktra for every vertex as source
    for(int i = 0; i < V; i++)
    {
        int __dist[V];
        
        // Calculating shortest distance from source i to every other vertices using Dijsktra
        int* dist_final = Dijsktra(graph, V, E, i, __dist);
        
        // Update the final matrix distance
        for(int j = 0; j < V; j++)
        {
            distance[i][j] = dist_final[j];
        }
    }
    
    printf("Final Result\n");
    printf("(Value 2147483648 indicates vertex v is not reachable from vertex u)\n\n");
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            if(distance[i][j] == INT_MAX)
            {
                distance[i][j] = INT_MAX;
                // To indicate that j vertex is not reachable from i vertex
                // No Edge from i to j
            }
            printf("Distance from %d to %d is :%d\n", i, j, distance[i][j]);
        }
        printf("\n");
    }
}

/*
      INPUT:
      
      7 9
      0 1 -1
      0 2 0
      3 0 12
      3 2 5
      2 5 -6
      5 4 3
      4 1 4
      6 5 8
      1 6 -7
      
      OUTPUT:
      
      Final Result
(Value -2147483648 indicates vertex v is not reachable from vertex u)

Distance from 0 to 0 is :0
Distance from 0 to 1 is :0
Distance from 0 to 2 is :0
Distance from 0 to 3 is :-2147483648
Distance from 0 to 4 is :0
Distance from 0 to 5 is :0
Distance from 0 to 6 is :0

Distance from 1 to 0 is :-2147483648
Distance from 1 to 1 is :0
Distance from 1 to 2 is :-2147483648
Distance from 1 to 3 is :-2147483648
Distance from 1 to 4 is :6
Distance from 1 to 5 is :6
Distance from 1 to 6 is :0

Distance from 2 to 0 is :-2147483648
Distance from 2 to 1 is :2
Distance from 2 to 2 is :0
Distance from 2 to 3 is :-2147483648
Distance from 2 to 4 is :0
Distance from 2 to 5 is :0
Distance from 2 to 6 is :2

Distance from 3 to 0 is :12
Distance from 3 to 1 is :7
Distance from 3 to 2 is :5
Distance from 3 to 3 is :0
Distance from 3 to 4 is :5
Distance from 3 to 5 is :5
Distance from 3 to 6 is :7

Distance from 4 to 0 is :-2147483648
Distance from 4 to 1 is :2
Distance from 4 to 2 is :-2147483648
Distance from 4 to 3 is :-2147483648
Distance from 4 to 4 is :0
Distance from 4 to 5 is :8
Distance from 4 to 6 is :2

Distance from 5 to 0 is :-2147483648
Distance from 5 to 1 is :2
Distance from 5 to 2 is :-2147483648
Distance from 5 to 3 is :-2147483648
Distance from 5 to 4 is :0
Distance from 5 to 5 is :0
Distance from 5 to 6 is :2

Distance from 6 to 0 is :-2147483648
Distance from 6 to 1 is :8
Distance from 6 to 2 is :-2147483648
Distance from 6 to 3 is :-2147483648
Distance from 6 to 4 is :6
Distance from 6 to 5 is :6
Distance from 6 to 6 is :0
   
 */
