// C++ program for Reverse Delete Algorithm to find MST
#include<bits/stdc++.h> 
using namespace std; 

// Creating shortcut for an integer pair 
typedef pair<int, int> iPair; 

// Graph class represents a directed graph using adjacency list representation 
class Graph 
{ 
	int V; // No. of vertices 
	list<int> *adj; 
	vector< pair<int, iPair> > edges; 
	void DFS(int v, bool visited[]); 

public: 
	Graph(int V); // Constructor 

	// function to add an edge to graph 
	void addEdge(int u, int v, int w); 

	// Returns true if graph is connected 
	bool isConnected(); 

	void reverseDeleteMST(); 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int u, int v, int w) 
{ 
	adj[u].push_back(v); // Add w to v’s list. 
	adj[v].push_back(u); // Add w to v’s list. 
	edges.push_back({w, {u, v}}); 
} 

void Graph::DFS(int v, bool visited[]) 
{ 
	// Mark the current node as visited and print it 
	visited[v] = true; 

	// Recur for all the vertices adjacent to 
	// this vertex 
	list<int>::iterator i; 
	for (i = adj[v].begin(); i != adj[v].end(); ++i) 
		if (!visited[*i]) 
			DFS(*i, visited); 
} 

// Returns true if given graph is connected, else false 
bool Graph::isConnected() 
{ 
	bool visited[V]; 
	memset(visited, false, sizeof(visited)); 

	// Find all reachable vertices from first vertex 
	DFS(0, visited); 

	// If set of reachable vertices includes all, 
	// return true. 
	for (int i=1; i<V; i++) 
		if (visited[i] == false) 
			return false; 

	return true; 
} 

// This function assumes that edge (u, v) 
// exists in graph or not, 
void Graph::reverseDeleteMST() 
{ 
	// Sort edges in increasing order on basis of cost 
	sort(edges.begin(), edges.end()); 

	int mst_wt = 0; // Initialize weight of MST 

	cout << "Edges in MST\n"; 

	// Iterate through all sorted edges in 
	// decreasing order of weights 
	for (int i=edges.size()-1; i>=0; i--) 
	{ 
		int u = edges[i].second.first; 
		int v = edges[i].second.second; 

		// Remove edge from undirected graph 
		adj[u].remove(v); 
		adj[v].remove(u); 

		// Adding the edge back if removing it 
		// causes disconnection. In this case this 
		// edge becomes part of MST. 
		if (isConnected() == false) 
		{ 
			adj[u].push_back(v); 
			adj[v].push_back(u); 

			// This edge is part of MST 
			cout << "(" << u << ", " << v << ") \n"; 
			mst_wt += edges[i].first; 
		} 
	} 

	cout << "Total weight of MST is " << mst_wt; 
} 

// Main Function
int main() 
{ 
	// create the graph given in above fugure 
	int V = 9; 
	Graph g(V); 

	// making above shown graph 
	g.addEdge(0, 1, 4); 
	g.addEdge(0, 7, 8); 
	g.addEdge(1, 2, 8); 
	g.addEdge(1, 7, 11); 
	g.addEdge(2, 3, 7); 
	g.addEdge(2, 8, 2); 
	g.addEdge(2, 5, 4); 
	g.addEdge(3, 4, 9); 
	g.addEdge(3, 5, 14); 
	g.addEdge(4, 5, 10); 
	g.addEdge(5, 6, 2); 
	g.addEdge(6, 7, 1); 
	g.addEdge(6, 8, 6); 
	g.addEdge(7, 8, 7); 

	g.reverseDeleteMST(); 
	return 0; 
} 
