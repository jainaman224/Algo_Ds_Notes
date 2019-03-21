// C++ program for graph coloring algorithm

#include <iostream> 
#include <list> 
using namespace std; 

// A class for an undirected graph 
class Graph 
{ 
	int num_V; // No. of vertices 
	list<int> *adj; // A dynamic array of adjacency lists 
public: 
	// Constructor 
	Graph(int num_V) { 
	    this->num_V = num_V; 
	    adj = new list<int>[num_V];
	} 
	//Destructor 
	~Graph() { 
	    delete [] adj; 
	} 

	// function for adding an edge to graph 
	void addEdge(int a, int b){ 
		adj[a].push_back(b); 
		adj[b].push_back(a); // Note: the graph is undirected 
	}  

	// Displays greedy coloring of the vertices 
	void greedyColoring(){ 
		int res[num_V]; 

		// Assign the 1st color to 1st vertex 
		res[0] = 0; 

		// Initialize remaining num_V-1 vertices as unassigned 
		for (int i = 1; i < num_V; i++) 
			res[i] = -1;                // no color is assigned to u 

		//True value of available[clr] --> the color clr assigned to one of its adjacent vertices 
		bool available[num_V]; 
		for (int clr = 0; clr < num_V; clr++) 
			available[clr] = false; 

		// Assign colors to remaining num_V-1 vertices 
		for (int k = 1; k < num_V; k++) 
		{ 
			// Process all adjacent vertices and flag their colors as unavailable 
			list<int>::iterator i; 
			for (i = adj[k].begin(); i != adj[k].end(); ++i) 
				if (res[*i] != -1) 
					available[res[*i]] = true; 

			// Find the first available color 
			int clr; 
			for (clr = 0; clr < num_V; clr++) 
				if (available[clr] == false) 
					break; 

			res[k] = clr; // Assign the found color 

			// Reset the values back to false for the next iteration 
			for (i = adj[k].begin(); i != adj[k].end(); ++i) 
				if (res[*i] != -1) 
					available[res[*i]] = false; 
		} 

		// print the res
		for (int k = 0;k < num_V; k++) 
			cout << "Vertex " << k << " ---> Color "
				<< res[k] << endl; 
	}
}; 


//Main Function
int main() 
{ 
	Graph g1(5); 
	g1.addEdge(0, 1); 
	g1.addEdge(0, 2); 
	g1.addEdge(1, 2); 
	g1.addEdge(1, 3); 
	g1.addEdge(2, 3); 
	g1.addEdge(3, 4); 
	cout << "Coloring of graph 1 \n"; 
	g1.greedyColoring(); 

	Graph g2(5); 
	g2.addEdge(0, 1); 
	g2.addEdge(0, 2); 
	g2.addEdge(1, 2); 
	g2.addEdge(1, 4); 
	g2.addEdge(2, 4); 
	g2.addEdge(4, 3); 
	cout << "\nColoring of graph 2 \n"; 
	g2.greedyColoring(); 

	return 0; 
} 


/* ------------------------------------------------------------------------------------------------------------------------------- */
//RESULT

/*
Coloring of graph 1
Vertex 0 --->  Color 0
Vertex 1 --->  Color 1
Vertex 2 --->  Color 2
Vertex 3 --->  Color 0
Vertex 4 --->  Color 1

Coloring of graph 2
Vertex 0 --->  Color 0
Vertex 1 --->  Color 1
Vertex 2 --->  Color 2
Vertex 3 --->  Color 0
Vertex 4 --->  Color 3
*/
