/**
 *   Kosaraju's Algorithm
 * ----------------------------------------
 * 
 * This algorithm is used to find the number of strongly connected components
 * in a directed graph. It uses DFS. It performs DFS twice to achieve the goal based on the fact that
 * finishing time of starting vertex will be greater than the finishing times of vertices in other SCCs.
 * 
 */
// Importing required libraries
import 'dart:io';
import 'dart:collection';

// Class definition for a graph
class Graph{

    // Total number of vertices in a graph
    int numVertices;
    // Adjacency list of the graph
    var adj;

    // Constructor
    Graph(int v){
        this.numVertices = v;
        this.adj = List(this.numVertices);
        for(int i = 0; i < this.numVertices; i ++){
            adj[i] = List();
        }
    }

    // Method to add an edge to a graph
    void add_edge(int source, int destination){
        adj[source].add(destination);
    }

    // Utility method to fill the stack through DFS.
    void fillOrder(int v, List visited, Queue stack){
        visited[v] = true;
        var temp = this.adj[v];
        int m = temp.length;
        int i = 0;
        while(i < m){
            if(!visited[this.adj[v][i]]){
                fillOrder(this.adj[v][i], visited, stack);
            }
            i ++;
        }
        stack.add(v);
    }

    // Utility method to find the transpose of the graph
    Graph getTranspose(){

        Graph transpose = Graph(this.numVertices);

        for(int i = 0; i < transpose.numVertices; i ++){
            int destination = i;
            for(int j = 0; j < this.adj[i].length; j ++){
                transpose.adj[this.adj[i][j]].add(destination);
            }
        }

        return transpose;
    }

    // Utility method that performs DFS.
    void DFSUtil(int v, List visited, List result){
        visited[v] = true;
        result.add(v);
        int m = this.adj[v].length;

        for(int i = 0; i < m; i ++){
            if(!visited[this.adj[v][i]]){
                DFSUtil(this.adj[v][i], visited, result);
            }
        }
    }

    // Utility method to print strongly connected components.
    void printStronglyConnectedComponents(){
        // Using a LIFO queue as stack
        Queue stack = Queue();
        var visited = List(this.numVertices);

        // Initializing the visited list.
        for(int i = 0; i < this.numVertices; i ++){
            visited[i] = false;
        }

        // Filling the stack through DFS
        for(int i = 0; i < this.numVertices; i ++){
            if(visited[i] == false){
                fillOrder(i, visited, stack);
            }
        }

        // Finding transpose of the graph
        Graph g = getTranspose();
        for(int i = 0; i < this.numVertices; i ++){
            visited[i] = false;
        }

        
        int count = 0;

        // Finding strongly connected components using DFS on all vertices in stack.
        while(!stack.isEmpty){
            int v = stack.removeLast();

            if(visited[v] == false){
                var result = List();
                g.DFSUtil(v, visited, result);
                print("Strongly Connected Component ${count+1}:");
                print(result.join(" "));
                count += 1;
            }
        }
    }
}

// Driver method of the program
void main(){

    // Input of number of vertices
    print("Enter number of vertices in the graph:");
    var input = stdin.readLineSync();
    int n = int.parse(input);
    Graph g = Graph(n);

    // Input of number of edges
    print("Enter number of edges:");
    input = stdin.readLineSync();
    int m = int.parse(input);

    // Input of edges
    for(int i = 0; i < m; i ++){
        print("Edge ${i+1}:");
        print("Enter source vertex:");
        input = stdin.readLineSync();
        int source = int.parse(input);
        print("Enter destination vertex:");
        input = stdin.readLineSync();
        int destination = int.parse(input);
        g.add_edge(source, destination);
    }

    // Output of Strongly Connected Components.
    g.printStronglyConnectedComponents();

}

/*
 *    Sample Input and Output
 * -----------------------------
 * Enter number of vertices in the graph:
 * 8
 * Enter number of edges:
 * 9
 * Edge 1:
 * Enter source vertex:
 * 0
 * Enter destination vertex:
 * 1
 * Edge 2:
 * Enter source vertex:
 * 3
 * Enter destination vertex:
 * 0
 * Edge 3:
 * Enter source vertex:
 * 1
 * Enter destination vertex:
 * 2
 * Edge 4:
 * Enter source vertex:
 * 2
 * Enter destination vertex:
 * 3
 * Edge 5:
 * Enter source vertex:
 * 2
 * Enter destination vertex:
 * 4
 * Edge 6:
 * Enter source vertex:
 * 4
 * Enter destination vertex:
 * 5
 * Edge 7:
 * Enter source vertex:
 * 5
 * Enter destination vertex:
 * 6
 * Edge 8:
 * Enter source vertex:
 * 6
 * Enter destination vertex:
 * 7
 * Edge 9:
 * Enter source vertex:
 * 6
 * Enter destination vertex:
 * 4
 * Strongly Connected Component 1:
 * 0 3 2 1
 * Strongly Connected Component 1:
 * 4 6 5
 * Strongly Connected Component 1:
 * 7
 * 
 */
