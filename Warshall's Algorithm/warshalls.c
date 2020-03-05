// C Program for Floyd Warshall Algorithm 
#include<stdio.h>  
#define V 4 
#define INF 99999 

// A function to print the solution matrix 
void printSolution(int dist[][V]); 
// Solves the all-pairs shortest path problem using Floyd Warshall algorithm 
void floydWarshall (int graph[][V]) 
{ 
	int dist[V][V], i, j, k; 
  /* Initialize the solution matrix same as input graph matrix. Or 
	we can say the initial values of shortest distances are based 
	on shortest paths considering no intermediate vertex. */
	for (i = 0; i < V; i++) 
		for (j = 0; j < V; j++) 
			dist[i][j] = graph[i][j]; 
	for (k = 0; k < V; k++) 
	{ 
		// Pick all vertices as source one by one 
		for (i = 0; i < V; i++) 
		{ 
			// Pick all vertices as destination for the 
			// above picked source 
			for (j = 0; j < V; j++) 
			{ 
				// If vertex k is on the shortest path from 
				// i to j, then update the value of dist[i][j] 
				if (dist[i][k] + dist[k][j] < dist[i][j]) 
					dist[i][j] = dist[i][k] + dist[k][j]; 
			} 
		} 
	} 

	// Print the shortest distance matrix 
	printSolution(dist); 
} 

/* A utility function to print solution */
void printSolution(int dist[][V]) 
{ 
	printf ("The following matrix shows the shortest distances"
			" between every pair of vertices \n"); 
	for (int i = 0; i < V; i++) 
	{ 
		for (int j = 0; j < V; j++) 
		{ 
			if (dist[i][j] == INF) 
				printf("%7s", "INF"); 
			else
				printf ("%7d", dist[i][j]); 
		} 
		printf("\n"); 
	} 
} 
int main() 
{ 
	int graph[V][V] = { {0, 5, INF, 10}, 
						{INF, 0, 3, INF}, 
						{INF, INF, 0, 1}, 
						{INF, INF, INF, 0} 
					}; 
	floydWarshall(graph); 
	return 0; 
} 
