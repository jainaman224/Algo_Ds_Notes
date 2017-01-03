// C++ implementation of Kruskal's Algorithm to find the Minimum Spanning tree for a weighted, connected and undirected graph.

#include <iostream>
#include <climits>
#define n 6
int parent[n]; // Parent array to hold the parent nodes of each node in the graph

using namespace std;

void printMST(int a[n], int b[n], int weight[n]) // Printing the MST
{
    int Minweight = 0; // Weight of Minimum spanning tree
    for (int i = 0; i < n - 1; i++)
    {
        cout << "Edge: " << a[i] << "-" << b[i] << " "
             << "cost: " << weight[i] << endl;
        Minweight += weight[i];
    }
    cout << "Minimum Weight is " << Minweight << endl; // Printing the weight of MINIMUM SPANNING TREE
}

int findParent(int node) // Function to determine the parent node
{
    while(parent[node] >= 0)
        node = parent[node];

    return node;
}

/* "findParentPathCompression" is an alternative for "findParent" which is more efficient.
 * We use a technique called "path compression" here.
 * With path compression, we destroy the structure of the tree, and only focus on which group a node is in.
 */

int findParentPathCompression(int node)
{
    if(node == parent[node]) return node;
    return parent[node] = findParentPathCompression(parent[node]);
}


void kruskal(int cost[n][n]) // Function performing Kruskal's algorithm
{
    fill_n(parent, n, -1);
    int u, v, k = 0, count = 0;
    int firstNode, secondNode;
    int a[n]; // Array containing the first nodes of all the edges present in MST
    int b[n]; // Array containing the second nodes of all the edges present in MST
    int weight[n]; // Array containing the weights of the edges present in MST
    int minimum;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (cost[i][j] == 0) //  If i and j nodes are not adjacent
                cost[i][j] = INT_MAX; // Then, initialize their weight as INFINITE

    while(count < n-1)
    {
        minimum = INT_MAX; // Initializing minimum as INFINITE

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (cost[i][j] < minimum)
                {
                    minimum = cost[i][j]; // find the minimum cost edge
                    firstNode = i; // First node of determined edge
                    secondNode = j; // Second node of determined edge
                }
            }
        }

        u = findParent(firstNode);
        v = findParent(secondNode);


        if (u != v) // If parents of both the nodes are different, no circuit is being formed
        {
            parent[v] = u;
            a[k] = firstNode; // Store first node in array
            b[k] = secondNode; // Store second node in array
            weight[k] = cost[firstNode][secondNode]; // Store the determined edge's weight in array
            count++;
            k++;
        }

        cost[firstNode][secondNode] = cost[secondNode][firstNode] = INT_MAX; // Edges getting included in MST will be given the weight of INFINITE
    }

    printMST(a, b, weight); // Printing the MST
}

// Driver program to test above function
int main()
{

/* Let the given graph is :

     (1)____1___(2)
    /  \       /  \
   3    4     4    6
  /      \   /      \
 /        \ /        \
(0)___5___(5)____5___(3)
 \         |         /
  \        |        /
   \       |       /
    \      2      /
     6     |     8
      \    |    /
       \   |   /
        \  |  /
         \ | /
          (4)
*/

    int cost[n][n] = {
        { 0, 3, 0, 0, 6, 5 },
        { 3, 0, 1, 0, 0, 4 },
        { 0, 1, 0, 6, 0, 4 },
        { 0, 0, 6, 0, 8, 5 },
        { 6, 0, 0, 8, 0, 2 },
        { 5, 4, 4, 5, 2, 0 }
    };

    kruskal(cost);
    return 0;
}

/*
Output :
 Edge: 0-1 cost: 3
 Edge: 1-2 cost: 1
 Edge: 1-5 cost: 4
 Edge: 5-4 cost: 2
 Edge: 5-3 cost: 5
 Minimum Weight is 15
*/
