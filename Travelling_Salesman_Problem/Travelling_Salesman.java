//Travelling Salesman Problem

import java.util.*;
class TSP
{
    // Function to find the minimum weight Hamiltonian Cycle
    
    static int tspfn( int[][] graph, boolean[] visited, int currPosition, int n, int count, int cost, int answer)
     {
        //If last node is reached and it has a link to the starting node i.e the source then
       //keep the minimum value out of the total cost of traversal and "answer"
      //Finally return to check for more possible values
      
      if( count == n && graph[currPosition][0] > 0 )
      {
        answer = Math.min( answer, cost + graph[currPosition][0]);
        return answer;
      }

      //BACKTRACKING STEP
     //Loop to traverse the adjacency list of currPos node and increasing the count  by 1 and cost by graph[currPos,i] value
     
     for( int i = 0; i < n; i++)
     { 
      if( visited[i] == false && graph[currPosition][i] > 0)
      {
       //Mark as visited
       visited[i] = true;
       answer = tspfn( graph, visited, i, n, count + 1, cost + graph[currPosition][i], answer);
       //Mark ith node as unvisited
       visited[i] = false;
      }
    }
     return answer;
   }
   
    public static void main( String[] args)
    {
       //n is the number of nodes i.e. V
       int n;
       System.out.println(" Enter the number of villages: ");
       Scanner in = new Scanner( System.in );
       n = in.nextInt();
       int graph[][] = new int[n][n];
       System.out.println( "Enter the cost matrix " );
       for( int i=0; i < n; i++)
       {
         System.out.println( "Enter the cost matrix for village " + i+1 );
         for( int j=0; j<n; j++)
         graph[i][j] = in.nextInt();
       }
       
       //Boolean array to check if a node has been visited or not
       boolean[] visited = new boolean[n];

      //Mark 0th node as visited
      visited[0] = true;
      int answer = Integer.MAX_VALUE;

     //Find the minimum weight Hamiltonian Cycle
     answer = tspfn( graph, visited, 0, n, 1, 0, answer);
     
     //answer is the minimum weight Hamiltonian Cycle
     System.out.println(" The minimum cost is " +answer);
  }
}

/* Sample input
Enter the number of villages:
0
Enter the cost matrix
Enter the cost matrix for village 1
0 10 15 20
Enter the cost matrix for village 2
10 0 35 25
Enter the cost matrix for village 3
15 35 0 30
Enter the cost matrix for village 4
20 25 30 0

Sample Output
The minimum cost is 80 */
