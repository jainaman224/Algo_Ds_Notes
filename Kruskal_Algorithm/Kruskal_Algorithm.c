// Kruskal's Algorithm in C 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

struct Edge { 
	int src, dest, weight; 
};  
struct Graph { 
	int V, E; // V: Number of vertices, E: Number of Edges
	struct Edge* edge; 
}; 

// Graph with V Vertices and E edges.
struct Graph* makeGraph(int V, int E) { 
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph)); 
	graph->V = V; 
	graph->E = E; 
  graph->edge = (struct Edge*)malloc(sizeof(struct Edge)); 
  return graph; 
} 

// Structure to represent a subset for union-find 
struct subset { 
	int p, z; 
}; 

// A utility function to find set of an element i 
// (uses path compression technique) 
int find(struct subset subsets[], int i) 
{ 
	// find root and make root as parent of i 
	if (subsets[i].p != i) 
		subsets[i].p = find(subsets, subsets[i].p); 
    return subsets[i].p; 
} 

// A function that does union of two sets of x and y  
void Union(struct subset subsets[], int x, int y) { 
	int root1 = find(subsets, x); 
	int root2 = find(subsets, y); 

	// Attach smaller rank tree with higher rank tree 
	if (subsets[root1].z < subsets[root2].z) 
		subsets[root1].p = root2; 
	else if (subsets[root1].z > subsets[root2].z) 
		subsets[root2].p = root1; 
	else{ 
		subsets[root2].p = root1; 
		subsets[root1].z++; 
	} 
} 

int myComp(const void* a, const void* b) { 
	struct Edge* x = (struct Edge*)a; 
	struct Edge* y = (struct Edge*)b; 
	return x->weight > y->weight; 
} 

// The main function to construct MST using Kruskal's algorithm 
void KruskalMST(struct Graph* graph) { 
	int V = graph->V; 
	struct Edge result[V];
	int res = 0; // Used for result[] 
	int k = 0; // Used for sorted edges 

	// Sort all the edges in increasing order
	qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp); 

	// Allocate memory for creating V ssubsets 
	struct subset *subsets = 
		(struct subset*) malloc( V * sizeof(struct subset) ); 

	// Create V subsets with single elements 
	for (int v = 0; v < V; ++v) { 
		subsets[v].p= v; 
		subsets[v].z = 0; 
	} 

	// Number of edges to be taken is equal to V-1 
	while (res < V - 1 && k < graph->E) { 
		// Pick the smallest edge & increment index
		struct Edge next_edge = graph->edge[k++]; 

		int x = find(subsets, next_edge.src); 
		int y = find(subsets, next_edge.dest); 
		if (x != y) 
		{ 
			result[res++] = next_edge; 
			Union(subsets, x, y); 
		} 
		// Else remove next_edge 
	} 
	printf("Edges of Spanning Tree are: \n"); 
	for (k = 0; k < res; ++k) 
		printf("%d -- %d == %d\n", result[k].src, result[k].dest, 
												result[k].weight); 
	return; 
} 

int main() 
{ 
	/* 
			10 
		0--------1 
		| \	 | 
	6| 5\ |15 
		|	 \ | 
		2--------3 
			4	 */
	int V = 4; // Vertices 
	int E = 5; // Edges
	struct Graph* graph = makeGraph(V, E); 


	// add edge 0-1 
	graph->edge[0].src = 0; 
	graph->edge[0].dest = 1; 
	graph->edge[0].weight = 10; 

	// add edge 0-2 
	graph->edge[1].src = 0; 
	graph->edge[1].dest = 2; 
	graph->edge[1].weight = 6; 

	// add edge 0-3 
	graph->edge[2].src = 0; 
	graph->edge[2].dest = 3; 
	graph->edge[2].weight = 5; 

	// add edge 1-3 
	graph->edge[3].src = 1; 
	graph->edge[3].dest = 3; 
	graph->edge[3].weight = 15; 

	// add edge 2-3 
	graph->edge[4].src = 2; 
	graph->edge[4].dest = 3; 
	graph->edge[4].weight = 4; 

	KruskalMST(graph); 

	return 0; 
} 

/*
OUTPUT :
Edges of Spanning Tree are: 
2 -- 3 == 4
0 -- 3 == 5
0 -- 1 == 0
*/
