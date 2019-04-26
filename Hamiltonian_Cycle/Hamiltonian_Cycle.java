class Hamiltonian_Cycle 
{ 
    int vertices = 5, path[]; 

    // Checking if the vertex v can be added at index 'index'in the Hamiltonian Cycle
    boolean isPathSafe(int v, int graph[][], int path[], int index) 
    { 
        if (graph[path[index - 1]][v] == 0) 
            return false; 

        for (int i = 0; i < index; i++) 
            if (path[i] == v) 
                return false;  

        return true; 
    } 

    // Function to solve hamiltonian cycle problem
    boolean helper(int graph[][], int path[], int index) 
    { 
        if (index == vertices) 
        { 
            if (graph[path[index - 1]][path[0]] == 1) 
                return true; 
            else return false; 
        } 

         // Try different vertices as a next candidate in Hamiltonian Cycle. 
        for (int v = 1; v < vertices; v++) 
        { 
            if (isPathSafe(v, graph, path, index)) 
            { 
                path[index] = v; 

                if (helper(graph, path, index + 1) == true) 
                    return true;  

                path[index] = -1; 
            } 
        } 

        return false; 
    } 

     // This function solves the Hamiltonian Cycle problem using backtracking.
    int hamiltonian_cycle(int graph[][]) 
    { 
        path = new int[vertices]; 
        for (int i = 0; i < vertices; i++) 
            path[i] = -1;

        path[0] = 0; 
        if (helper(graph, path, 1) == false) 
        { 
            System.out.println("Solution does not exist"); 
            return 0; 
        } 

        // Printing the solution if sol exists
        for (int i = 0; i < vertices; i++) 
            System.out.print(" " + path[i] + " ");  

        System.out.println(" " + path[0] + " "); 

        return 1; 
    } 

    // Sample input
    public static void main(String args[]) 
    { 
        Hamiltonian_Cycle h = new Hamiltonian_Cycle(); 

        int graph[][] = {{0, 1, 0, 1, 0}, 
                          {1, 0, 1, 1, 1}, 
                          {0, 1, 0, 0, 1}, 
                          {1, 1, 0, 0, 1}, 
                          {0, 1, 1, 1, 0}, 
                        }; 
        
        h.hamiltonian_cycle(graph); 
    } 
} 

// Sample output
//  0  1  2  4  3  0
