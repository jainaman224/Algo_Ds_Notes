#include <bits/stdc++.h>
using namespace std;

class Graph
{

  int V;			// Number of vertices 
    list < int >*adj;		// An array of adjacency lists 

  void fillOrder (int v, bool visited[], stack < int >&Stack);	//Fills Stack with vertices in increasing order of finishing times

  void DFSUtil (int v, bool visited[]);	// A recursive function to print DFS
public:
    Graph (int V);
  void addEdge (int v, int w);

  void KasurajaAlgorithm ();	// Finds and prints strongly connected components 

  Graph getTranspose ();	// Function that returns transpose of graph 
};

Graph::Graph (int V)
{
  this->V = V;
  adj = new list < int >[V];
}


void
Graph::DFSUtil (int v, bool visited[])
{
  // Mark the current node as visited and print it 
  visited[v] = true;
  cout << v << " ";


  list < int >::iterator i;
  for (i = adj[v].begin (); i != adj[v].end (); ++i)
    if (!visited[*i])
      DFSUtil (*i, visited);
}

Graph
Graph::getTranspose ()
{
  Graph g (V);
  for (int v = 0; v < V; v++)
    {
      // Recur for all the adjacent vertices 
      list < int >::iterator i;
      for (i = adj[v].begin (); i != adj[v].end (); ++i)
	{
	  g.adj[*i].push_back (v);
	}
    }
  return g;
}

void
Graph::addEdge (int v, int w)
{
  //Adding edge is equivalent to pushing corresponding vertices in adjacency list
  adj[v].push_back (w);
}

void
Graph::fillOrder (int v, bool visited[], stack < int >&Stack)
{
  // Mark the current node as visited
  visited[v] = true;

  // Recur for all the adjacent vertices
  list < int >::iterator i;
  for (i = adj[v].begin (); i != adj[v].end (); ++i)
    if (!visited[*i])
      fillOrder (*i, visited, Stack);

  // All vertices reachable from v are processed , push v 
  Stack.push (v);
}

void
Graph::KasurajaAlgorithm ()
{
  stack < int >Stack;

  // Mark all the vertices as not visited - first DFS
  bool *visited = new bool[V];
  for (int i = 0; i < V; i++)
    visited[i] = false;

  // Fill vertices in stack according to their finishing times 
  for (int i = 0; i < V; i++)
    if (visited[i] == false)
      fillOrder (i, visited, Stack);

  // Create a reversed graph 
  Graph gr = getTranspose ();

  // Mark all the vertices as not visited -second DFS
  for (int i = 0; i < V; i++)
    visited[i] = false;

  while (Stack.empty () == false)
    {
      int v = Stack.top ();
      Stack.pop ();

      // Print Strongly connected components
      if (visited[v] == false)
	{
	  gr.DFSUtil (v, visited);
	  cout << endl;
	}
    }
}

int
main ()
{
  int V, n, v1, v2;
  cout << "Enter number of vertices" << endl;
  cin >> V;
  Graph g (V);			//Create a graph with V number of vertices
  cout << "Enter number of edges" << endl;
  cin >> n;
  for (int i = 0; i < n; i++)
    {
      cout << "Enter the vertices forming this edge" << endl;
      cin >> v1 >> v2;
      g.addEdge (v1, v2);
    }

  cout <<
    "The strongly connected components in given graph are using Kasuraja Algorithm are"
    << endl;
  g.KasurajaAlgorithm ();

  /* Sample Input:
    8
    8
    2 1
    2 3
    1 0
    0 2
    0 4
    4 2
    3 4
    0 3

    Sample Output:
    The strongly connected components in given graph are using Kasuraja Algorithm are
    7 
    6 
    5 
    0 1 2 4 3 */

  return 0;
}
