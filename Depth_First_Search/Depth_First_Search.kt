import java.util.LinkedList

class Dfs(private val vertices: Int) {
    private val adj: List<LinkedList<Int>> = (0 until vertices).map { LinkedList<Int>() }
    fun addEdge(vertex: Int, weight: Int) {
        adj[vertex].add(weight)    // Add weight to vertex's list.
    }

    private fun dfsUtil(vertex: Int, visited: BooleanArray) {
        visited[vertex] = true    // Mark the current node as visited and print it
        print("$vertex ")
        adj[vertex].filter { !visited[it] }.forEach { dfsUtil(it, visited) }
    }

    fun traverse(startVertex: Int) {
        dfsUtil(startVertex, BooleanArray(vertices))    // Call the recursive helper function to print DFS traversal
    }
}

fun main(args: Array<String>) {
    var read = Scanner(System.`in`)
    println("Enter the number of vertices :")
    val arrSize = read.nextLine().toInt()
    val graph = Dfs(arrSize)
    for(i in 0 until arrSize)
        {   
            println("Enter the source vertex :")  
            val a = read.nextLine().toInt()
            println("Enter the destination vertex :")  
            val b = read.nextLine().toInt()
            graph.addEdge(a,b)
        }
    println("\nFollowing is Depth First Traversal :")
    graph.traverse(0)
    println()
}


/*
    
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
	
	Following is Depth First Traversal :                                                                                          
	1 2 3 4 5 6 7     
	
*/

