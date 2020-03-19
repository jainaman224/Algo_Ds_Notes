/*
 Djikstra's algorithm (named after its discover, E.W. Dijkstra) solves the
 problem of finding the shortest path from a point in a graph (the source)
 to a destination.
 It turns out that one can find the shortest paths from a given source to all
 points in a graph in the same time, hence this problem is sometimes called
 the single-source shortest paths problem.
*/
int mind(dist, visited , n)
{

int min = 9223372036854775807, min_index;

for (var v = 0; v < n; v++) {
  if ((visited[v] == false) && (dist[v] <= min)) {
    min = dist[v];
    min_index = v;
  }
}

return min_index;
}

void printsol(dist , n)
{
  print('Vertex \t\t Distance from Source\n');

  for (var i = 0; i < n; i++)
    {
      print('${i} \t\t ${dist[i]}\n');
    }
}

void dijkstra(graph, src, n)
{
  var dist = new List(n);

  var visited = new List(n);

  for (var i = 0; i < n; i++) {
    dist[i] = 9223372036854775807;
    visited[i] = false;
  }

  dist[src] = 0;

  for (var count = 0; count < n - 1; count++)
  {

    var u = mind(dist, visited , n);

    visited[u] = true;

    for (var v = 0; v < n; v++)
    {
        if (!visited[v] && graph[u][v]>0 && dist[u] != 9223372036854775807
        && dist[u] + graph[u][v] < dist[v])
        {
          dist[v] = dist[u] + graph[u][v];
        }
    }
  }
    printsol(dist,n);
}

void main()
{

  var adjmat = [[0, 14, 0, 7, 0, 0, 0, 8, 0, 10],
    [14, 0, 8, 0, 0, 0, 0, 11, 0, 0],
    [0, 8, 0, 7, 0, 4, 0, 0, 2, 0],
    [7, 0, 7, 0, 9, 12, 0, 0, 0, 5],
    [0, 0, 0, 9, 0, 0, 0, 0, 0, 0],
    [0, 0, 4, 0, 0, 0, 2, 0, 0, 11],
    [0, 0, 0, 12, 0, 2, 0, 1, 6, 15],
    [8, 11, 0, 0, 0, 0, 1, 0, 7, 0],
    [0, 0, 2, 0, 0, 0, 6, 7, 0, 0],
    [10, 0, 0, 5, 0, 11, 15, 0, 0, 0]];

  dijkstra(adjmat, 0 , 9);

}
/* Output
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