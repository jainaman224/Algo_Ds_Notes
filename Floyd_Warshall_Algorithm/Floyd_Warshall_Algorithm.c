    #include <stdio.h>
    #include <stdlib.h>
    #define n 4  // Number of vertices in the graph 
    #define INFINITY 9999    // Define Infinite as a large enough value. This value will be used for vertices not connected to each other 
    void display(int mat[n][n]);  // A function to print the solution matrix 
    int main()         // driver program to test above function 
  {
      int adj[n][n] =  { {0,   5,  INFINITY, 10},
                        {INFINITY, 0,   3, INFINITY},
                        {INFINITY, INFINITY, 0,   1},
                        {INFINITY, INFINITY, INFINITY, 0}
                      };
      int Q[n][n], i, j, k;
      printf("\n The adjacency matrix is : ");
      display(adj);
     // Initialize the solution matrix same as input graph matrix. Or  we can say the initial values of shortest distances are based on shortest paths considering no intermediate vertex. 
   for(i=0;i<n;i++)
   {
     for(j=0;j<n;j++)
      {
       if(adj[i][j] == 0)
       Q[i][j] = INFINITY;
       else
       Q[i][j] = adj[i][j];
      }
   }
    for(k=0; k<n;k++)           // Add all vertices one by one to the set of intermediate vertices. Before start of an iteration, we have shortest distances between all pairs of vertices such that the shortest distances consider only the vertices in set {0, 1, 2, .. k-1} as intermediate vertices. 
     // After the end of an iteration, vertex no. k is added to the set of intermediate vertices and the set becomes {0, 1, 2, .. k} 
    {
             // Pick all vertices as source one by one 
     for(i=0;i<n;i++)
          {
             // Pick all vertices as destination for the 
            // above picked source 

      for(j=0;j<n;j++)               
       {
         if(Q[i][j] <= Q[i][k] + Q[k][j])               // If vertex k is on the shortest path from 
          Q[i][j] = Q[i][j];                            // i to j, then update the value of dist[i][j] 
          else
          Q[i][j] = Q[i][k] + Q[k][j];
       }
    }
          printf("\n\n");
          display(Q);
    }
      return 0;
 }
        void display(int mat[n][n])
  {
        int i, j;
     for(i=0;i<n;i++)
     {
      printf("\n");
     for(j=0;j<n;j++)
      printf("%d\t", mat[i][j]);
     }
  }
/* INPUT  0       5       9999    10                                                                                                                      
          9999    0       3       9999                                                                                                                    
          9999    9999    0       1                                                                                                                       
          9999    9999    9999    0   */
/* OUTPUT  The adjacency matrix is :                                                                                                                      
0       5       9999    10                                                                                                                      
9999    0       3       9999                                                                                                                    
9999    9999    0       1                                                                                                                       
9999    9999    9999    0                                                                                                                       
                                                                                                                                                
                                                                                                                                                
9999    5       9999    10                                                                                                                      
9999    9999    3       9999                                                                                                                    
9999    9999    9999    1                                                                                                                       
9999    9999    9999    9999                                                                                                                    
                                                                                                                                                
                                                                                                                                                
9999    5       8       10                                                                                                                      
9999    9999    3       9999                                                                                                                    
9999    9999    9999    1                                                                                                                       
9999    9999    9999    9999                                                                                                                    
                                                                                                                                                
                                                                                                                                                
9999    5       8       9                                                                                                                       
9999    9999    3       4                                                                                                                       
9999    9999    9999    1                                                                                                                       
9999    9999    9999    9999                                                                                                                    
                                                                                                                                                
                                                                                                                                                
9999    5       8       9                                                                                                                       
9999    9999    3       4                                                                                                                       
9999    9999    9999    1                                                                                                                       
9999    9999    9999    9999  */                                                                                                           
                                          
