// C# Program Implementing Jhonson Algorithm.

using System;

namespace ConsoleApp1
{
    class Jhonson_Algorithm
    {
        public static void Main(String[] args)
        {
            int vert, edge, i, j, k, c;
            int INF = 999999;
            int[,] cost = new int[10, 10];
            int[,] adj = new int[10, 10];
            Console.WriteLine("Enter no of vertices: ");
            vert = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Enter no of Edges: ");
            edge = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Enter the EDGE cost: ");
            for (k = 1; k <= edge; k++)
            {
                //take the input and store it into adj and cost matrix
                i = Convert.ToInt32(Console.ReadLine());
                j = Convert.ToInt32(Console.ReadLine());
                c = Convert.ToInt32(Console.ReadLine());
                adj[i, j] = cost[i, j] = c;
            }
            for (i = 1; i <= vert; i++)
                for (j = 1; j <= vert; j++)
                {
                    if (adj[i, j] == 0 && i != j)
                        adj[i, j] = INF; //If its not a edge put infinity
                }
            for (k = 1; k <= vert; k++)
                for (i = 1; i <= vert; i++)
                    for (j = 1; j <= vert; j++)
                        //Finding the minimum
                        adj[i, j] = (adj[i, k] + adj[k, j]) > adj[i, j] ? adj[i, j] : (adj[i, k] + adj[k, j]) ; //find minimum path from i to j through k
            Console.WriteLine("The distance matrix of the graph.\n");
            // Output the resultant matrix
            for (i = 1; i <= vert; i++)
            {
                for (j = 1; j <= vert; j++)
                {
                    if (adj[i, j] != INF)
                        Console.Write("{0}  ", adj[i,j]);
                }
                Console.WriteLine(" ");
            }
        }
    }
}
/*Enter no of vertices:
3
Enter no of Edges:
5
Enter the EDGE cost:
1 2 8

2 1 12

1 3 22

3 1 6

2 3 4
The distance matrix of the graph.

0  8  12
10  0  4
6  14  0*/
