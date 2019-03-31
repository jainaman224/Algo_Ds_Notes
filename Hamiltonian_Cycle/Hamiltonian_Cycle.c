#include<stdio.h> 
  
// Number of vertices in the graph 
#define V 5 
  
void printSolution(int path[]); 
  
// Check if the vertex v can be added at index 'pos' in the Hamiltonian Cycle
bool isSafe(int v, bool graph[V][V], int path[], int pos) 
{ 
    if (graph [ path[pos-1] ][ v ] == 0) 
        return false; 
  
    for (int i = 0; i < pos; i++) 
        if (path[i] == v) 
            return false;  
    return true; 
} 
  
// A recursive function to solve hamiltonian cycle problem
bool hamCycleUtil(bool graph[V][V], int path[], int pos) 
{ 
    if (pos == V) 
    { 
        if ( graph[ path[pos-1] ][ path[0] ] == 1 ) 
           return true; 
        else
          return false; 
    } 
  
    for (int v = 1; v < V; v++) 
    { 
        if (isSafe(v, graph, path, pos)) 
        { 
            path[pos] = v; 
  
            if (hamCycleUtil (graph, path, pos+1) == true) 
                return true; 
            path[pos] = -1; 
        } 
    } 
  
    return false; 
} 
  
// Solving the Hamiltonian Cycle problem using Backtracking. 
bool hamCycle(bool graph[V][V]) 
{ 
    int *path = new int[V]; 
    for (int i = 0; i < V; i++) 
        path[i] = -1; 
        path[0] = 0; 
    if ( hamCycleUtil(graph, path, 1) == false ) 
    { 
        printf("\nSolution does not exist"); 
        return false; 
    }
      
    printSolution(path); 
  return true; 
} 
  
// Print the solution
void printSolution(int path[]) 
{ 
    printf ("Solution Exists:"
            " Following is one Hamiltonian Cycle \n"); 
    for (int i = 0; i < V; i++) 
        printf(" %d ", path[i]);  
    printf(" %d ", path[0]); 
    printf("\n"); 
} 
  
// Testing the above function with sample input
int main() 
{ 
    bool graph1[V][V] = {{0, 1, 0, 1, 0}, 
                         {1, 0, 1, 1, 1}, 
                         {0, 1, 0, 0, 1}, 
                         {1, 1, 0, 0, 1}, 
                         {0, 1, 1, 1, 0}, 
                        }; hamCycle(graph1); 

    bool graph2[V][V] = {{0, 1, 0, 1, 0}, 
                         {1, 0, 1, 1, 1}, 
                         {0, 1, 0, 0, 1}, 
                         {1, 1, 0, 0, 0}, 
                         {0, 1, 1, 0, 0}, 
                        }; hamCycle(graph2); 
  
    return 0; 
}

// Solution Exists: Following is one Hamiltonian Cycle
//  0  1  2  4  3  0

