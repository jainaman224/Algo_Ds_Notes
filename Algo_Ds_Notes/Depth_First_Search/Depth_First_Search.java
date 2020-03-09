
import java.util.Hashtable;
import java.util.List;
import java.util.LinkedList;
import java.util.Stack;


/*
  Instructions to run the program:
    javac Depth_First_Search.java
    java Graph
*/


// The Graph class represents a directed graph
// Constructor template: new Graph(integer)
// Argument: (integer) represents the number of vertices that the graph will possess
// Example: Graph graph = new Graph(10);
class Graph
{
  int numberOfVertices;
  Hashtable<Integer,List<Integer>> adj;

  // Constructor which initializes 'numberOfVertices' and a Hashtable 'adj' which
  // represents an adjacency list which contains a mapping between a vertex and
  // it's adjacent vertices or neighbors
  Graph(int numberOfVertices)
  {
    this.numberOfVertices = numberOfVertices;
    this.adj = new Hashtable<Integer,List<Integer>>();
  }

  // Function to add an edge between the source and destination
  // GIVEN: a source and a destination node
  // EFFECT: adds an edge between the source and destination which is reflected
  //         in the 'adj' adjacency list
  private void addEdge(int source, int destination)
  {
    // if the source node is not already present in the Hashtable 'adj' we create
    // an entry with the given destination node
    if(adj.get(source) == null)
    {
      LinkedList<Integer> neighbours = new LinkedList<Integer>();
      neighbours.add(destination);

      adj.put(source,neighbours);
    }
    // if the source node is already present in the Hashtable 'adj' we update
    // the entry by adding destination node to the list of neighboring nodes
    else
    {
      List<Integer> neighbours  = adj.get(source);
      neighbours.add(destination);
      adj.put(source,neighbours);
    }
  }

  // GIVEN: a start nodes
  // EFFECT: prints out the sequence of Depth First Search in the preorder fashion
  //         (natural order in which the nodes are visited)
  private void dfs(int start)
  {
    // maintains a record of visited nodes
    boolean[] visited = new boolean[numberOfVertices];

    // initially no nodes are visited
    for(int i=0;i<numberOfVertices;i++)
    {
      visited[i] = false;
    }

    // maintain a recursionStack to avoid repetition of same recursive calls
    // which might happen due to cycles (in DFS cycles are caused by
    // back edges - an edge connecting a vertex u to it's ancestor v)
    Stack<Integer> recursionStack = new Stack<Integer>();

    visited[start] = true;
    recursionStack.push(start);


    while(!recursionStack.empty())
    {
      start = recursionStack.pop();
      System.out.print(start+" ");

      // for each adjacent node check if it's visited
      // if visited is true - skip
      // else - mark as visited and add it to recursion stack so that this node
      //        is processed next (in LIFO fashion)
      for(Integer neighbor : adj.get(start))
      {
        if(!visited[neighbor])
        {
          visited[neighbor] = true;
          recursionStack.push(neighbor);
        }
      }
    }
  }


  public static void main(String args[])
  {
    // create new graph with 8 vertices
    Graph graph = new Graph(8);

    // Create edges between vertices
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(1, 4);
    graph.addEdge(2, 0);
    graph.addEdge(2, 3);
    graph.addEdge(3, 3);
    graph.addEdge(3, 6);
    graph.addEdge(4, 0);
    graph.addEdge(4, 5);
    graph.addEdge(5, 6);
    graph.addEdge(5, 7);
    graph.addEdge(6, 2);
    graph.addEdge(7, 3);

    // Output the DFS traversal
    System.out.print("Depth First Traversal is: ");
    graph.dfs(0);
  }

  /* Output

  Depth First Traversal is : 0 2 3 6 1 4 5 7

  */
}
