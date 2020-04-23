/*
Kruskal's algorithm is a minimum spanning tree algorithm that takes a graph a
s input and finds the subset of the edges of that graph which

(1) form a tree that includes every vertex
(2) has the minimum sum of weights among all the trees that can be
    formed from the graph
 */

import 'dart:io';

var INT_MAX = 9223372036854775807;

int find(i, parent)
{
    while (parent[i] != i) {
        i = parent[i];
    }
    return i;
}

void union1(i, j, parent)
{
    var a = find(i, parent);
    var b = find(j, parent);

    parent[a] = b;
}

void kruskal_mst(adjmat, V)
{
    var mincost = 0;

    var parent = new List(V);

    for (var i = 0; i < V; i++)
    {
        parent[i] = i;
    }

    var edge_count = 0;
    while (edge_count < V - 1)
    {
        var min = INT_MAX, a = -1, b = -1;

        for (var i = 0; i < V; i++)
        {
            for (var j = 0; j < V; j++)
            {
                if (find(i, parent) != find(j, parent) && adjmat[i][j] < min)
                {
                    min = adjmat[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        union1(a, b, parent);
        print('Edge ${edge_count++}:(${a}, ${b}) cost:${min} \n');

        mincost += min;
    }

    print('\n Minimum cost= ${mincost} \n');
}

int main()
{
    print('Enter number of nodes 0 to ?');

    var n = int.parse(stdin.readLineSync());
    var max_edges = (n + 1) * (n);
    var adjmat = new List.generate(n+1, (_) => new List(n + 1));

    for(var i = 0; i <= n; i++)
    {
        for(var j = 0; j <= n; j++)
        {
            adjmat[i][j] = INT_MAX;
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

    kruskal_mst(adjmat , n + 1);
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

 Let the given graph is :

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

 Edge: 0-1 cost: 3
 Edge: 1-2 cost: 1
 Edge: 1-5 cost: 4
 Edge: 5-4 cost: 2
 Edge: 5-3 cost: 5
 Minimum Weight is 15
 */

