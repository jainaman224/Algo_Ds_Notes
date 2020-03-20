// Required library to use inbuilt queue in LIFO manner in Dart
import 'dart:collection';
// Required library to use standard output facility of dart
import 'dart:io';

// Function to find the depth first search of a graph
void Depth_First_Search ( var graph, int source, int no_vertices ) {
    // Queue is used in LIFO manner to obtain stack functionality.
    var queue = Queue();
    // A list to keep track of visited nodes
    var visited = new List(no_vertices);
    // Initializing the list
    for(int i = 0; i < no_vertices; i ++ ) {
        visited[i] = 0;
    }
    // Adding the source node to LIFO queue ( stack )
    queue.add(source);
    // Marking the node visited
    visited[source] = 1;
    int val;

    while(queue.isNotEmpty){
        val = queue.removeLast();
        stdout.write("$val ");
        
        //Visiting neighbours of the popped node  
        for(int i = 0; i < no_vertices; i ++ ){
            if(graph[val][i] == 1 && visited[i] == 0){
                queue.add(i);
                visited[i] = 1;
            }
        }
    } 
}

// Driver method of the program
void main(){

    // Reading from the standard input
    print("Which graph do you want to enter ( directed/ undirected ):");
    String mode = stdin.readLineSync().toString();

    print("Enter number of vertices:");
    var input = stdin.readLineSync();
    int no_vertices = int.parse(input);
    
    // Graph is implemented as adjacency matrix.
    var graph = new List.generate(no_vertices, (_) => new List(no_vertices));
    for(int i = 0; i < no_vertices; i++){
        for(int j = 0; j < no_vertices; j++){
            graph[i][j] = 0;
        }
    }
  
    print("Enter number of edges:");
    var input1 = stdin.readLineSync();
    int no_edges = int.parse(input);
    print("Enter source and destination vertices of edges:\n");
    print("Note: Enter source and destination vertices as 0,1,2,...");
    
    for(int i = 1; i <= no_edges; i++){
      
        print("Edge #$i:");
        
        print("Enter source vertex:");
        int source = int.parse(stdin.readLineSync());

        print("Enter destination vertex:");
        int destination = int.parse(stdin.readLineSync());

        if(mode == "undirected"){
            graph[source][destination] = 1;
            graph[destination][source] = 1;
        }
        else{
            graph[source][destination] = 1;
        }

    }

    print("Enter the source vertex from which DFS should begin:");
    int source1 = int.parse(stdin.readLineSync());

    // Sample input graph
    // 0 - 1 - 2
    // |     /
    // 3 - 4

    print("Vertices in Depth First Search of the graph in sample input is: ");

    // Depth First Search of the above graph
    Depth_First_Search(graph,source1,no_vertices);

    // Sample Output
    // Vertices in Depth First Search of the graph in sample input is:
    // 0 3 4 2 1

}


