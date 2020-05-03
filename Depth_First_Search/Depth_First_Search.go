package main
import "fmt"
type set map[int]bool

// Define Graph structure
type Graph struct {
    adjList map[int]set
}

// Create a graph and initialize its adjacency list, and return a pointer to it.
func createGraph() *Graph {
    var g = Graph{}
    g.adjList = make(map[int]set)
    return &g
}

// Add an edge between the two given nodes.If a node does not exist in the graph yet, add it.
func (g *Graph) addEdge(node1 int, node2 int) {
    // Check if node1 is already in the graph
    if g.adjList[node1] == nil {
        g.adjList[node1] = make(set)
    }
	
    g.adjList[node1][node2] = true
    // Check if node2 is already in the graph
    if g.adjList[node2] == nil {
        g.adjList[node2] = make(set)
    }
	
    g.adjList[node2][node1] = true
}

// Perform a depth first search from the given node and apply the given function to each node.
func dfs(g *Graph, current int, visited set, visitFunction func(int)) {
    if _, seen := visited[current]; seen {
        return
    }

    visited[current] = true
    visitFunction(current)
    for neighbour := range g.adjList[current] {
        dfs(g, neighbour, visited, visitFunction)
    }
}

func main() {
    graph := createGraph()
    var n int
    fmt.Println("Enter the number of vertices : ")
    fmt.Scan(&n)
    for i := 0; i < n; i++ {
	  var a int
	  var b int
	  fmt.Println("Enter the source vertex : ")
	  fmt.Scan(&a)
	  fmt.Println("Enter the destination vertex : ")
	  fmt.Scan(&b)
	  graph.addEdge(a, b)
    }
    fmt.Println("\nThe DFS Traversal of the graph is : ")
    visited := make(set)
    dfs(graph, 1, visited, func(node int) {
    fmt.Print(node, " ")
    })
}


/*
	
	The sample input is given in the form of the following graph :
		 1
		/ \
             /   \
	      2     5
	     / \   / \
	    3 - 4 6   7

	Sample Input :
	Enter the number of vertices :                                                                                               
	7
	Enter the source vertex :                                                                                                    
	1                                                                                                                            
	Enter the destination vertex :                                                                                               
	2 
	Enter the source vertex :                                                                                                    
	2                                                                                                                            
	Enter the destination vertex :                                                                                               
	3                                                                                                                            
	Enter the source vertex :                                                                                                    
	2 
	Enter the destination vertex :                                                                                               
	4                                                                                                                            
	Enter the source vertex :                                                                                                    
	3                                                                                                                            
	Enter the destination vertex :                                                                                               
	4  
	Enter the source vertex :                                                                                                    
	1                                                                                                                            
	Enter the destination vertex :                                                                                               
	5                                                                                                                            
	Enter the source vertex :                                                                                                    
	5   
	Enter the destination vertex :                                                                                               
	6                                                                                                                            
	Enter the source vertex :                                                                                                    
	5                                                                                                                            
	Enter the destination vertex :                                                                                               
	7    

	The DFS Traversal of the graph is :                                                                                          
	1 2 3 4 5 6 7     
	
*/

