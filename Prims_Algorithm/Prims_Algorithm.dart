/*
Prim's algorithm is to find minimum cost spanning tree (as Kruskal's algorithm)
uses the greedy approach. Prim's algorithm shares a similarity with the
shortest path first algorithms.

Prim's algorithm, in contrast with Kruskal's algorithm, treats the nodes as a
single tree and keeps on adding new nodes to the spanning tree from the
given graph.
 */

import 'dart:io';
import 'dart:svg';

var INT_MAX = 9223372036854775807;

int minnode(dist, fingraph, V)
{
    var min = INT_MAX;
    var min_index = 0;

    for (var v = 0; v < V; v++) {
        if (fingraph[v] == false && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printMST(parent, graph, V)
{
    print("Edge \tWeight\n");
    for (var i = 1; i < V; i++) {
        print('${parent[i]} - ${i} \t ${graph[i][parent[i]]} \n');
    }
}

void prim_mst(graph, V)
{
    var parent = new List(V);
    var dist = new List(V);
    var fingraph = new List(V);

    for (var i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        fingraph[i] = false;
    }

    dist[0] = 0;
    parent[0] = -1;

    for (var count = 0; count < V - 1; count++)
    {
        var u = minnode(dist, fingraph, V);
        fingraph[u] = true;

        for (var v = 0; v < V; v++)
        {
            if (graph[u][v] > 0 && fingraph[v] == false && graph[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, V);
}

int main()
{
    print('Enter number of nodes 0 to ?');

    var n = int.parse(stdin.readLineSync());
    var max_edges = (n + 1) * (n);
    var adjmat = new List.generate(n + 1, (_) => new List(n + 1));

    for(var i = 0; i <= n; i++)
    {
        for(var j = 0; j <= n; j++)
        {
            adjmat[i][j] = 0;
        }
    }

    print('Enter in the following format\nsrc\ndest\nweight\n');
    for(var i = 0; i < max_edges; i++)
    {
        var src = int.parse(stdin.readLineSync());
        var dest = int.parse(stdin.readLineSync());
        var weight = int.parse(stdin.readLineSync());

        print('*' * 20);

        if((src == -1) && (dest == -1))
        {
            break;
        }

        if(src > n || dest > n || src < 0 || dest < 0)
        {
            print('Invalid edge!\n');
            i--;
        }

        else
        {
            adjmat[src][dest] = weight;
        }
    }

    prim_mst(adjmat, n + 1);
    return 0;
}

/*
Input:
Enter number of nodes 0 to ?
4
Enter in the following format
Source
Destination
Weight

Let us create the following graph

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

   adjmat = [
        [ 0, 3, 0, 0, 6, 5 ],
        [ 3, 0, 1, 0, 0, 4 ],
        [ 0, 1, 0, 6, 0, 4 ],
        [ 0, 0, 6, 0, 8, 5 ],
        [ 6, 0, 0, 8, 0, 2 ],
        [ 5, 4, 4, 5, 2, 0 ]
    ];

Output:

Edge Weight

0 - 1   3
1 - 2   1
1 - 5   4
5 - 4   2
5 - 3   5
Minimum Weight is 15
 */

