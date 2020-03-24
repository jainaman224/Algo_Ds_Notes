/*
 Djikstra's algorithm (named after its discover, E.W. Dijkstra) solves the
 problem of finding the shortest path from a point in a graph (the source)
 to a destination.
 It turns out that one can find the shortest paths from a given source to all
 points in a graph in the same time, hence this problem is sometimes called
 the single-source shortest paths problem.
*/
import 'dart:io';

var INT_MAX = 9223372036854775807;

int minDistance(dist, visited , n)
{
    int min = INT_MAX, min_index;

    for (var v = 0; v < n + 1; v++)
    {
        if (( visited[v] == false ) && ( dist[v] <= min ))
        {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printsol(dist , n)
{
    print('Vertex \t\t Distance from Source\n');

    for (var i = 0; i < n + 1; i++)
    {
        print('${i} \t\t ${dist[i]}\n');
    }
}

void dijkstra(graph, src, n)
{
    var dist = new List(n + 1);

    var visited = new List(n + 1);

    for (var i = 0; i < n + 1; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;

    for (var count = 0; count < n ; count++)
    {

        var u = minDistance(dist, visited , n);

        visited[u] = true;

        for (var v = 0; v < n + 1; v++)
        {
            if ( !visited[v] && graph[u][v] > 0 && dist[u] != INT_MAX
            && dist[u] + graph[u][v] < dist[v] )
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printsol(dist, n);
}

void main()
{
    print('Enter number of nodes 0 to ?');

    int n = int.parse(stdin.readLineSync());

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

        if( (src == -1) && (dest == -1) )
        {
            break;
        }

        if( src > n || dest > n || src < 0 || dest < 0 )
        {
            print('Invalid edge!\n');
            i--;
        }
        else
        {
            adjmat[src][dest] = weight;
        }
    }

    dijkstra(adjmat, 0 , n);
}

/*
Input:
Enter number of nodes 0 to ?
9
Enter in the following format
Source
Destination
Weight

*******************************************************
The adjacency matrix will look like this

admat=[[0, 14, 0, 7, 0, 0, 0, 8, 0, 10],
    [14, 0, 8, 0, 0, 0, 0, 11, 0, 0],
    [0, 8, 0, 7, 0, 4, 0, 0, 2, 0],
    [7, 0, 7, 0, 9, 12, 0, 0, 0, 5],
    [0, 0, 0, 9, 0, 0, 0, 0, 0, 0],
    [0, 0, 4, 0, 0, 0, 2, 0, 0, 11],
    [0, 0, 0, 12, 0, 2, 0, 1, 6, 15],
    [8, 11, 0, 0, 0, 0, 1, 0, 7, 0],
    [0, 0, 2, 0, 0, 0, 6, 7, 0, 0],
    [10, 0, 0, 5, 0, 11, 15, 0, 0, 0]];

*******************************************************

Output:
Distance from Source:
Vertex		Distance
0		0
1		14
2		14
3		7
4		16
5		11
6		9
7		8
8		15
9		10
*/
