/**
 *   Bellman Ford Algorithm
 * ----------------------------------------------
 * This algorithm is used to find shortest distances of all vertices from 
 * a source vertex in a graph. It is a DP algorithm unlike Dijkstra which is a greedy one.
 * This algorithm has O(m*n) time complexity where Dijkstra has O(n*log(n)).
 * Bellman ford is suitable for distributed systems and works well on negative edges unline
 * Dijkstra.
 * 
 */

// Importing required libraries
import 'dart:io';

// Class to define an edge
class Edge{
    int source;
    int destination;
    int weight;
    // Constructor
    Edge(int source, int destination, int weight){
        this.source = source;
        this.destination = destination;
        this.weight = weight;
    }
}

// Class to define a graph
class Graph{
    int numVertices;
    int numEdges;
    var edges;

    // Constructor
    Graph(int n, int m){
        this.numVertices = n;
        this.numEdges = m;
        edges = List<Edge>();
    }

    // Method to add an edge to the graph
    void add_edge(int src, int dest, int wt){
        Edge edge = Edge(src, dest, wt);
        this.edges.add(edge);
    }

    /* Method to find shortest distances of all vertices from a source vertex
     using Bellman Ford algorithm */
    void bellmanFordShortestDistances(int src){
        // Using maximum int value as infinity
        const int int64MaxValue = 9223372036854775807;
        var distances = List(this.numVertices);

        // Initializing the distances array
        for(int i = 0; i < this.numVertices; i ++){
            distances[i] = int64MaxValue;
        }
        distances[src] = 0;

        // Finding shortest distances
        for(int i = 0; i < this.numVertices - 1; i ++){
            for(int j = 0; j < this.numEdges; j ++){
                int srce = this.edges[j].source;
                int desti = this.edges[j].destination;
                int wt = this.edges[j].weight;
                if(distances[srce] != int64MaxValue && distances[desti] > distances[srce] + wt){
                    distances[desti] = distances[srce] + wt;
                }
            }
        }

        // Checking for a negative cycle.
        int flag = 0;
        for(int j = 0; j < this.numEdges; j ++){
            int srce = this.edges[j].source;
            int desti = this.edges[j].destination;
            int wt = this.edges[j].weight;
            if(distances[srce] != int64MaxValue && distances[desti] > distances[srce] + wt){
                print("Negative cycle found!!");
                flag = 1;
                break;
            }
        }

        // Printing shortest distances if negative cycle is not found
        if(flag == 0){
            print("The shortest distances of all vertices from src vertex are in the following order:");
            print(distances.join(" "));
        } 
    }
}

// Driver method of the program
void main(){

    // Input of number of vertices
    print("Enter number of vertices:");
    var input = stdin.readLineSync();
    int n = int.parse(input);

    // Input of number of edges
    print("Enter number of edges:");
    input = stdin.readLineSync();
    int m = int.parse(input);

    // Creating the graph
    Graph g = Graph(n, m);

    // Input of edges
    print("Enter edges:");
    for(int i = 0; i < m; i ++){
        print("Enter edge ${i + 1}");
        print("Enter source vertex:");
        int src = int.parse(stdin.readLineSync());
        print("Enter destination vertex:");
        int dest = int.parse(stdin.readLineSync());
        print("Enter weight of the edge:");
        int wt = int.parse(stdin.readLineSync());
        g.add_edge(src, dest, wt);
    }

    // Input of source vertex for Bellman Ford
    print("Enter the source vertex to find shortest distances:");
    int src = int.parse(stdin.readLineSync());

    // Printing output of Bellman Ford
    g.bellmanFordShortestDistances(src);

}

/**
 *   Sample Input and Output
 * -----------------------------
 *   Sample 1
 * -----------------------------
 * Enter number of vertices:
 * 5
 * Enter number of edges:
 * 8
 * Enter edges:
 * Enter edge 1
 * Enter source vertex:
 * 0
 * Enter destination vertex:
 * 1
 * Enter weight of the edge:
 * -1
 * Enter edge 2
 * Enter source vertex:
 * 0
 * Enter destination vertex:
 * 2
 * Enter weight of the edge:
 * 4
 * Enter edge 3
 * Enter source vertex:
 * 1
 * Enter destination vertex:
 * 2
 * Enter weight of the edge:
 * 3
 * Enter edge 4
 * Enter source vertex:
 * 3
 * Enter destination vertex:
 * 1
 * Enter weight of the edge:
 * 1
 * Enter edge 5
 * Enter source vertex:
 * 1
 * Enter destination vertex:
 * 3
 * Enter weight of the edge:
 * 2
 * Enter edge 6
 * Enter source vertex:
 * 3
 * Enter destination vertex:
 * 2
 * Enter weight of the edge:
 * 5
 * Enter edge 7
 * Enter source vertex:
 * 1
 * Enter destination vertex:
 * 4
 * Enter weight of the edge:
 * 2
 * Enter edge 8
 * Enter source vertex:
 * 4
 * Enter destination vertex:
 * 3
 * Enter weight of the edge:
 * -3
 * Enter the source vertex to find shortest distances:
 * 0
 * The shortest distances of all vertices from src vertex are in the following order:
 * 0 -1 2 -2 1
 * ------------------------
 *  Sample 2
 * ------------------------
 * Enter number of vertices:
 * 4
 * Enter number of edges:
 * 5
 * Enter edges:
 * Enter edge 1
 * Enter source vertex:
 * 0
 * Enter destination vertex:
 * 1
 * Enter weight of the edge:
 * 5
 * Enter edge 2
 * Enter source vertex:
 * 0
 * Enter destination vertex:
 * 2
 * Enter weight of the edge:
 * 4
 * Enter edge 3
 * Enter source vertex:
 * 2
 * Enter destination vertex:
 * 1
 * Enter weight of the edge:
 * -6
 * Enter edge 4
 * Enter source vertex:
 * 1
 * Enter destination vertex:
 * 3
 * Enter weight of the edge:
 * 3
 * Enter edge 5
 * Enter source vertex:
 * 3
 * Enter destination vertex:
 * 2
 * Enter weight of the edge:
 * 2
 * Enter the source vertex to find shortest distances:
 * 0
 * Negative cycle found!!
 * 
 */
