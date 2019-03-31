class HamiltonianCycle 
{ 
    final int V = 5; 
    int path[]; 
  
    // Checking if the vertex v can be added at index 'pos'in the Hamiltonian Cycle
    boolean isSafe(int v, int graph[][], int path[], int pos) 
    { 
        if (graph[path[pos - 1]][v] == 0) 
            return false; 
  
        for (int i = 0; i < pos; i++) 
            if (path[i] == v) 
                return false;  
        return true; 
    } 
  
    // Function to solve hamiltonian cycle problem
    boolean hamCycleUtil(int graph[][], int path[], int pos) 
    { 
        if (pos == V) 
        { 
            if (graph[path[pos - 1]][path[0]] == 1) 
                return true; 
            else
            return false; 
        } 
  
        // Try different vertices as a next candidate in Hamiltonian Cycle. 
        for (int v = 1; v < V; v++) 
        { 
            if (isSafe(v, graph, path, pos)) 
            { 
                path[pos] = v; 
  
                if (hamCycleUtil(graph, path, pos + 1) == true) 
                    return true;  
                path[pos] = -1; 
            } 
        } 
  
        return false; 
    } 
  
    // This function solves the Hamiltonian Cycle problem using backtracking.
    int hamCycle(int graph[][]) 
    { 
        path = new int[V]; 
        for (int i = 0; i < V; i++) 
            path[i] = -1; p
            path[0] = 0; 
        if (hamCycleUtil(graph, path, 1) == false) 
        { 
            System.out.println("\nSolution does not exist"); 
            return 0; 
        } 
  
        printSolution(path); 
        return 1; 
    } 
  
    // Printing the solution
    void printSolution(int path[]) 
    { 
        System.out.println("Solution Exists: Following" + 
                           " is one Hamiltonian Cycle"); 
        for (int i = 0; i < V; i++) 
            System.out.print(" " + path[i] + " ");   
        System.out.println(" " + path[0] + " "); 
    } 
  
    // Testing the above function with sample input
    public static void main(String args[]) 
    { 
        HamiltonianCycle hamiltonian = new HamiltonianCycle(); 

        int graph1[][] = {{0, 1, 0, 1, 0}, 
                          {1, 0, 1, 1, 1}, 
                          {0, 1, 0, 0, 1}, 
                          {1, 1, 0, 0, 1}, 
                          {0, 1, 1, 1, 0}, 
                        }; hamiltonian.hamCycle(graph1); 
                          
        int graph2[][] = {{0, 1, 0, 1, 0}, 
                          {1, 0, 1, 1, 1}, 
                          {0, 1, 0, 0, 1}, 
                          {1, 1, 0, 0, 0}, 
                          {0, 1, 1, 0, 0}, 
                        }; hamiltonian.hamCycle(graph2); 
    } 
} 

// Solution Exists: Following is one Hamiltonian Cycle
//  0  1  2  4  3  0

