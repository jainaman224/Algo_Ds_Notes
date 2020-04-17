using System;

namespace Declaring_Method 
{
    public class Prim_Algorithm 
    {
        public static void Main(string[] args) 
        {
            int a = 0, b = 0, u = 0, v = 0, n, i, j, edge_no = 1;
            int min, mincost = 0;
            int[] visited = new int[100];
            int[, ] cost = new int[10, 10];
            
            Console.WriteLine("Enter the number of Nodes");
            n = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Enter the adjency matrix");

            //Intilize all visited elements to 0
            for (i = 0; i < 100; i++) 
            {
                visited[i] = 0;
            }
            
            //Taking Matrix Input from the User
            for (i = 1; i <= n; i++) 
            {
                for (j = 1; j <= n; j++) 
                {
                    cost[i, j] = Convert.ToInt32(Console.ReadLine());
                    //Initialize Cost Matrix to Infintiy if user input is 0
                    if (cost[i, j] == 0)
                        cost[i, j] = 999;
                }
            }
            visited[1] = 1;
            Console.WriteLine(" ");
            
            while (edge_no < n) 
            {
                for (i = 1, min = 999; i <= n; i++)
                    for (j = 1; j <= n; j++)
                        if (cost[i, j] < min)
                            if (visited[i] != 0) 
                            {
                                min = cost[i, j];
                                //Storing Position
                                a = u = i;
                                b = v = j;
                            }
                // Print the Edge Number with its Cost
                if (visited[u] == 0 || visited[v] == 0) 
                {
                    Console.WriteLine("Edge {0} : ({1} {2}) cost:{3} ", edge_no++, a, b, min);
                    mincost += min; // Calculating minimum Cost
                    visited[b] = 1;
                }
                cost[a, b] = cost[b, a] = 999;
            }
            Console.WriteLine("Minimum Cost : {0}", mincost);
        }
    }
}

/*Enter the number of Nodes
5
Enter the adjency matrix
0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0

Edge 1 : (1 2) cost:2
Edge 2 : (2 3) cost:3
Edge 3 : (2 5) cost:5
Edge 4 : (1 4) cost:6
Minimum Cost : 16 */
