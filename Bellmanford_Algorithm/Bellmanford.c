#include <stdio.h>
#include <stdlib.h>

void bellmanford(int graph[5][5] , int vertices, int edges, int edgeSource[5], int edgeDest[5])
{
    int i, j, k, u, v, dist[5], parent[5];
    int isNegative = 1;
    
    
    // initialize distance from source Src = 0 for every vertex to be zero
    // Also the path is empty and hence no vertex a parent, initialise each vertex's parent to be -1
    for(i = 0 ; i < vertices; i++)
    {    
        dist[i] = 1000000;
        parent[i] = -1 ;
    }

    // Initialise distance of the source to be zero
    dist[0] = 0 ;

    for(i = 0;i < vertices-1; i++)
    {
        for(k = 0; k < edges; k++)
        {
            u = edgeSource[k];
            v = edgeDest[k];

            
            // Relax all the edges
            if(dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v] , parent[v] = u;
          
        }
    }

    for(j = 0; j < edges; j++)
        {
            u = edgeSource[j];
            v = edgeDest[j];
        
            if(dist[u] + graph[u][v] < dist[v])
                isNegative = 0;
        }

    // Finally check if the flag -> isNegative is true 
    // for there is no solution if there exists a negative cycle in the graph
    if(isNegative > 0) {
        printf("There is no negative weight cycle in the graph\n");
         for(i = 0; i < vertices; i++)
            printf("%d :: dist = %d : parent = %d\n", i, dist[i], parent[i]);
    }
    
    // else no path exists
    else printf("There is a negative weight cycle in the graph\n");
}

int main()
{
    int vertices = 5;
    
    // storing the vertex pairs containing edges
    int edgeSource[5], edgeDest[5];  
    int i, j, edge = 0;
    
    
    //a graph represented as a 2-D matrix
    int graph[5][5] = {
        {0, 6, 0, 7, 0},
        {0, 0, 5, 8, -4},
        {0, -2, 0, 0, 0},
        {0, 0, -3, 0, 9},
        {2, 0, 7, 0, 0}
    };
    
    for(i = 0; i < vertices; i++)
        for(j=0;j < vertices; j++)
        {
            if(graph[i][j] != 0){
                   edgeSource[edge] = i;
                   edgeDest[edge] = j;
                   edge++;
            }    
        }

  bellmanford(graph, vertices, edge, edgeSource, edgeDest);
  
return 0;
}

/*

      OUTPUT:
      
      There is no negative weight cycle in the graph
        0 :: dist = 0 : parent = -1
        1 :: dist = 5 : parent = 2
        2 :: dist = 7 : parent = 4
        3 :: dist = 13 : parent = 1
        4 :: dist = 0 : parent = 0
        
 */
