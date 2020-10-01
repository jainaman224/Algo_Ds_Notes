// A Java program to implement greedy algorithm for graph coloring 

import java.io.*; 
import java.util.*; 
import java.util.LinkedList; 

// This class represents an undirected graph using adjacency list 
class Main 
{ 
	private int num_V; // No. of vertices 
	private LinkedList<Integer> adj[]; //Adjacency List 

	//Constructor 
	Main(int a) 
	{ 
		num_V = a; 
		adj = new LinkedList[a]; 
		for (int i=0; i<a; ++i) 
			adj[i] = new LinkedList(); 
	} 

	//Function to add an edge into the graph 
	void addEdge(int a,int b) 
	{ 
		adj[a].add(b); 
		adj[b].add(a); //Graph is undirected 
	} 

	// Assigns colors (starting from 0) to all vertices and prints the assignment of colors 
	void greedyColoring() 
	{ 
		int res[] = new int[num_V]; 

		// Initialize all vertices as unassigned 
		Arrays.fill(res, -1); 

		// Assign the first color to first vertex 
		res[0] = 0; 

		// A temporary array to store the available colors. False value of available[clr] would mean that the color clr is  assigned to one of its adjacent vertices 
		boolean available[] = new boolean[num_V]; 
		
		// Initially, all colors are available 
		Arrays.fill(available, true); 

		// Assign colors to remaining num_V-1 vertices 
		for (int u = 1; u < num_V; u++) 
		{ 
			// Process all adjacent vertices and flag their colors as unavailable 
			Iterator<Integer> it = adj[u].iterator() ; 
			while (it.hasNext()) 
			{ 
				int i = it.next(); 
				if (res[i] != -1) 
					available[res[i]] = false; 
			} 

			// Find the first available color 
			int clr; 
			for (clr = 0; clr < num_V; clr++){ 
				if (available[clr]) 
					break; 
			} 

			res[u] = clr; // Assign the found color 

			// Reset the values back to true for the next iteration 
			Arrays.fill(available, true); 
		} 

		// print the result 
		for (int u = 0; u < num_V; u++) 
			System.out.println("Vertex " + u + " ---> Color "
								+ res[u]); 
	} 

	// Main Function
	public static void main(String args[]) 
	{ 
		Main g1 = new Main(5); 
		g1.addEdge(0, 1); 
		g1.addEdge(0, 2); 
		g1.addEdge(1, 2); 
		g1.addEdge(1, 3); 
		g1.addEdge(2, 3); 
		g1.addEdge(3, 4); 
		System.out.println("Coloring of graph 1"); 
		g1.greedyColoring(); 

		System.out.println(); 
		Main g2 = new Main(5); 
		g2.addEdge(0, 1); 
		g2.addEdge(0, 2); 
		g2.addEdge(1, 2); 
		g2.addEdge(1, 4); 
		g2.addEdge(2, 4); 
		g2.addEdge(4, 3); 
		System.out.println("Coloring of graph 2 "); 
		g2.greedyColoring(); 
	} 
} 


/*------------------------------------------------------------------------------------------------------------------------------*/
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
