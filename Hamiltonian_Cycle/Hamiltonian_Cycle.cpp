#include<stdio.h> 

// Number of vertices in the graph 
#define vertices 5 

// Check if the vertex can be added at index in the Hamiltonian Cycle
bool isPathSafe(int v, bool graph[vertices][vertices], int path[], int position) 
{ 
    if (graph[path[position - 1]][v] == 0) 
        return false; 

    for (int i = 0; i < position; i++) 
        if (path[i] == v) 
            return false;  
    return true; 
} 

// A recursive function to solve hamiltonian cycle problem
bool helper(bool graph[vertices][vertices], int path[], int index) 
{ 
    if (index == vertices) 
    { 
        if (graph[path[index - 1]][path[0]] == 1) 
           return true; 
        else
           return false; 
    } 

    for (int v = 1; v < vertices; v++) 
    { 
        if (isPathSafe(v, graph, path, index)) 
        { 
            path[index] = v; 

            if (helper (graph, path, index + 1) == true) 
                return true; 
            path[index] = -1; 
        } 
    } 

    return false; 
} 

 // Solving the Hamiltonian Cycle problem using Backtracking. 
bool Hamiltonian_Cycle(bool graph[vertices][vertices]) 
{ 
    int *path = new int[vertices]; 

    for (int i = 0; i < vertices; i++) 
        path[i] = -1; 

    path[0] = 0; 
    if (helper(graph, path, 1) == false) 
    { 
        printf("\nSolution does not exist"); 
        return false; 
    }

    // Print the solution if it exists
    for (int i = 0; i < vertices; i++) 
        printf(" %d ", path[i]);  
    printf(" %d ", path[0]); 
    printf("\n"); 

  return true; 
} 

// sample input
int main() 
{ 
    bool graph[vertices][vertices] = {{0, 1, 0, 1, 0}, 
                         {1, 0, 1, 1, 1}, 
                         {0, 1, 0, 0, 1}, 
                         {1, 1, 0, 0, 1}, 
                         {0, 1, 1, 1, 0}, 
                        }; 

    Hamiltonian_Cycle(graph); 

    return 0; 
}

// Sample Output
//  0  1  2  4  3  0
