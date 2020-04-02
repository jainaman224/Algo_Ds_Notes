
/*This is a C++ Program to implement Johnson’s Algorithm.
Johnson's algorithm helps to find shortest path between given source and destination nodes.
Here is source code of the C++ Program to Implement Johnson’s Algorithm.
The C++ program is successfully compiled and run on a Linux system. The program output is also shown below.*/

#include<iostream>
#define INF 9999
using namespace std;
int min(int a, int b);
int cost[10][10], adj[10][10];
inline int min(int a, int b)
{
   return (a<b)?a:b;
}
main()
{
   int vert, edge, i, j, k, c;

   cout << "Enter no of vertices: ";
   cin >> vert;
   cout << "Enter no of edges: ";
   cin >> edge;
   cout << "Enter the EDGE Costs:\n";

   for (k = 1; k <= edge; k++) //take the input and store it into adj and cost matrix
   {
       cin >> i >> j >> c;
       adj[i][j] = cost[i][j] = c;
   }

   for (i = 1; i <= vert; i++)
      for (j = 1; j <= vert; j++) {
         if (adj[i][j] == 0 && i != j)
            adj[i][j] = INF; //if there is no edge, put infinity
      }

   for (k = 1; k <= vert; k++)
      for (i = 1; i <= vert; i++)
         for (j = 1; j <= vert; j++)
            adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]); //find minimum path from i to j through k
   cout << "Resultant adj matrix\n";

   for (i = 1; i <= vert; i++) {
      for (j = 1; j <= vert; j++) {
            if (adj[i][j] != INF)
               cout << adj[i][j] << " ";
      }
      cout << "\n";
   }
}

/*   INPUT
Enter no of vertices: 3
Enter no of edges: 5
Enter the EDGE Costs:
1 2 8
2 1 12
1 3 22
3 1 6
2 3 4
     OUTPUT
Resultant adj matrix
0 8 12
10 0 4
6 14 0*/
