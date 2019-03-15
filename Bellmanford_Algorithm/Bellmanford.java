 
import java.util.*; 
import java.lang.*; 
import java.io.*; 

class Graph 
{ 
	// to represent a weighted edge in graph 
	class Edge { 
		int src, dest, weight; 
		Edge() { 
			src = 0;
      			dest = 0;
      			weight = 0; 
		} 
	}; 

	int V, E; 
	Edge edge[]; 

	// Creates a graph with V vertices and E edges 
	Graph(int vertices, int edges) 
	{ 
		V = vertices; 
		E = edges; 
		edge = new Edge[edges]; 
		for (int i=0; i<edges; ++i) 
			edge[i] = new Edge(); 
	} 

	// finds shortest distances from source
	void BellmanFord(Graph graph,int src) 
	{ 
		int V = graph.V, E = graph.E; 
		int dist[] = new int[V]; 
    
		// Initialising vertices as INFINITE    
		for (int i=0; i<V; ++i) 
			dist[i] = Integer.MAX_VALUE; 
		dist[src] = 0; 

		for (int i=1; i<V; ++i) 
		{ 
			for (int j=0; j<E; ++j) 
			{ 
				int u = graph.edge[j].src; 
				int v = graph.edge[j].dest; 
				int weight = graph.edge[j].weight; 
				if (dist[u]!=Integer.MAX_VALUE && 
					dist[u]+weight<dist[v]) 
					dist[v]=dist[u]+weight; 
			} 
		} 

		// check for negative-weight cycles.
		for (int j=0; j<E; ++j) 
		{ 
			int u = graph.edge[j].src; 
			int v = graph.edge[j].dest; 
			int weight = graph.edge[j].weight; 
			if (dist[u] != Integer.MAX_VALUE && 
				dist[u]+weight < dist[v]) 
			System.out.println("Graph contains negative weight cycle"); 
		} 
		printArray(dist, V); 
	} 

	// A utility function used to print the solution 
	void printArray(int dist[], int V) 
	{ 
		System.out.println("Vertex    Distance from Source"); 
		for (int i=0; i<V; ++i) 
			System.out.println(i+"\t\t"+dist[i]); 
	} 

	// An example 
	public static void main(String[] args) 
	{ 
		int V = 5; // Number of vertices
		int E = 8; // Number of edges

		Graph graph = new Graph(V, E); 

		graph.edge[0].src = 0; 
		graph.edge[0].dest = 1; 
		graph.edge[0].weight = -1; 

		graph.edge[1].src = 0; 
		graph.edge[1].dest = 2; 
		graph.edge[1].weight = 4; 

		graph.edge[2].src = 1; 
		graph.edge[2].dest = 2; 
		graph.edge[2].weight = 3; 

		graph.edge[3].src = 1; 
		graph.edge[3].dest = 3; 
		graph.edge[3].weight = 2; 

		graph.edge[4].src = 1; 
		graph.edge[4].dest = 4; 
		graph.edge[4].weight = 2; 

		graph.edge[5].src = 3; 
		graph.edge[5].dest = 2; 
		graph.edge[5].weight = 5; 

		graph.edge[6].src = 3; 
		graph.edge[6].dest = 1; 
		graph.edge[6].weight = 1; 

		graph.edge[7].src = 4; 
		graph.edge[7].dest = 3; 
		graph.edge[7].weight = -3; 

		graph.BellmanFord(graph, 0); 
	} 
} 

/*  
	OUTPUT :
	Vertex   Distance from Source
	0                0
	1                -1
	2                2
	3                -2
	4                1
*/
