/**
 *    Topological Sort implementation in Dart
 * -------------------------------------------------------
 * 
 * In a directed acyclic graph, if there is an edge from u to v. Then, u comes before v.
 * This observation has many real life application like scheduling tasks, ordering things etc.,.
 * 
 * Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that 
 * for every directed edge uv, vertex u comes before v in the ordering.
 * 
 * Topological sorting is an application of Depth First Search.
 * 
 */


// Importing required libraries
import 'dart:io';
import 'dart:core';

// Class for a graph
class Graph{

    // Number of vertices in a graph.
    int vertices;
    
    // Adjacency list to store the graph.
    List< List< int > > adjlist;
    
    // Constructor
    Graph(int v){

        // Assigning number of vertices
        this.vertices = v;

        // Initializing the graph
        this.adjlist = new List< List< int > >(vertices);
    
        for (int i = 0 ; i < vertices ; i ++){
            
            this.adjlist[i] = new List< int >();
        
        }

    }

    // Method to add an edge
    void add_edge(int source , int destination){
        
        this.adjlist[source].add(destination);
    
    }


    // Utility method for Topological Sort
    void topologicalSortUtil(int source , List< int > stack , List< bool > visited){

        // Marking source vertex visited
        visited[source] = true;

        int len = this.adjlist[source].length;

        // Recursively visiting it's neighbours
        for (int i = 0 ; i < len ; i ++){

            if (visited[adjlist[source][i]] == false){

                // Recursive call
                topologicalSortUtil(adjlist[source][i] , stack , visited);
            
            }
        }

        // Adding to stack
        stack.add(source);

    }

    // Method to find the topological sort
    void topologicalSort(){
        
        // Stack required to print the topological sort
        List< int > stack = new List< int >();
        
        // Initializing the visited list.
        List< bool > visited = new List< bool >.generate(this.vertices , ( i ) => false);
        
        // Running the utility on all vertices to cover the entire graph.
        for (int i = 0 ; i < this.vertices ; i ++){
            
            if (visited[i] == false){

                topologicalSortUtil(i , stack , visited);
            
            }

        }

        // Converting the elements in the stack into a string and printing them.
        String s;
        
        List temp = new List< int >();
        
        while ( ! stack.isEmpty ){
            
            temp.add(stack.removeLast());
        
        }
        
        s = temp.join(" ");
        
        // Printing the result
        print(s);

    }

}

// Driver function of the program
void main(){

    // Taking input of number of vertices
    print("Enter number of vertices:");
    
    var input = stdin.readLineSync();
    
    int n = int.parse(input);
    
    Graph g = new Graph(n);

    // Taking input of number of edges
    print("Enter number of edges:");
    
    input = stdin.readLineSync();
    
    int m = int.parse(input);

    // Taking input of edges
    print("Enter edges for vertices in 0 - n range:");
    
    for(int i = 0 ; i < m ; i ++){

        input = stdin.readLineSync();
        
        var lis = input.split(" ");
        
        List list1 = lis.map(int.parse).toList();
        
        g.add_edge(list1[0] , list1[1]);

    }

    // Printing the result
    print("Following is the topological sort of the input graph: ");
    
    g.topologicalSort();

}

/*

      Sample Input
  ----------------------
  Enter number of vertices:
  8
  Enter number of edges:
  7
  Enter edges for vertices in 0 - n range:
  0 1
  0 4
  1 7
  1 2
  2 3
  4 5
  5 6

      Sample Output
  -----------------------
  Following is the topological sort of the input graph:
  0 4 5 6 1 2 3 7

*/
