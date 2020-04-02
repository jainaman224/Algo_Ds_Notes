/*
Johnson’s algorithm for All-pairs shortest paths

Given a weighted Directed Graph where the weights may be negative,
find the shortest path between every pair of vertices in the Graph using
Johnson’s Algorithm.
 */

int MAX_INT = 9223372036854775807;

int minDistance(distance, visited)
{
    var minimum  = MAX_INT;
    var minVertex = 0;

    var v = distance.length;

    for(var vertex = 0; vertex < v; vertex++)
    {
        if( (minimum > distance[vertex]) && (visited[vertex] == false) )
        {
            minimum = distance[vertex];
            minVertex = vertex;
        }
    }
    return minVertex;
}

void Dijkstra(graph, modified, src)
{
    var num_vertices = graph.length;
    var distance = new List(num_vertices);

    var visited = new List(num_vertices);

    for (var i = 0; i < num_vertices; i++)
    {
        distance[i] = MAX_INT;
        visited[i] = false;
    }

    distance[src] = 0;

    for(var count = 0; count < num_vertices; count++)
    {
        var curVertex = minDistance(distance, visited);
        visited[curVertex] = true;
        for(var vertex = 0; vertex < num_vertices; vertex++)
        {
            if ((visited[vertex] == false) && (distance[vertex] > (distance[curVertex] +
            modified[curVertex][vertex])) && (graph[curVertex][vertex] != 0))
            {
               distance[vertex] = (distance[curVertex] + modified[curVertex][vertex]);
            }
        }
    }

    for(var vertex = 0; vertex < num_vertices; vertex++)
    {
        print('Vertex   ${vertex} :  ${distance[vertex]}');
    }
}

List BellmanFord(edges, graph, num_vertices)
{
    var distance = new List(num_vertices+1);

    for(var i = 0; i <= num_vertices; i++)
    {
        distance[i]=MAX_INT;
    }

    distance[num_vertices] = 0;

    for(var i = 0; i < num_vertices; i++)
    {
        edges.add([num_vertices, i, 0]);
    }

    for(var i = 0; i < num_vertices; i++)
    {
        for(var j in edges)
        {

            if((distance[j[0]] != MAX_INT) && (distance[j[0]] + j[2] < distance[j[1]]) )
            {
                distance[j[1]] = distance[j[0]] + j[2];
            }
        }
    }

    return distance;
}


void JohnsonAlgorithm(graph)
{
    var edges = new List();

    for(var i = 0; i < graph.length ; i++)
    {
        for(var j = 0; j < graph[i].length; j++)
        {
          if(graph[i][j] != 0)
          {
              edges.add([i, j, graph[i][j]]);
          }
        }
    }

    var modifiedwei = BellmanFord(edges, graph, graph.length);

    var modified = [[0,0,0,0],
                        [0,0,0,0],
                        [0,0,0,0],
                        [0,0,0,0]];

    for(var i = 0; i < graph.length; i++)
    {
        for(var j = 0; j < graph[i].length; j++)
        {
            if(graph[i][j] != 0)
            {
                modified[i][j] = (graph[i][j] +
                modifiedwei[i] - modifiedwei[j]);
            }
        }
    }

    print ('Modified Graph: ${modified}');

    for(var src = 0; src < graph.length; src++)
    {
        print ('\nShortest Distance with vertex ${src} as the source:\n');
        Dijkstra(graph, modified, src);
    }
}

void main() {

    var graph = [[0, -8, 2, 4],
                  [0, 0, 2, 6],
                  [0, 0, 0, 2],
                  [0, 0, 0, 0]];

    JohnsonAlgorithm(graph);
}

/*
Modified Graph: [[0, 0, 8, 8], [0, 0, 0, 2], [0, 0, 0, 0], [0, 0, 0, 0]]

Shortest Distance with vertex 0 as the source:

Vertex   0 :  0
Vertex   1 :  0
Vertex   2 :  0
Vertex   3 :  0

Shortest Distance with vertex 1 as the source:

Vertex   0 :  9223372036854775807
Vertex   1 :  0
Vertex   2 :  0
Vertex   3 :  0

Shortest Distance with vertex 2 as the source:

Vertex   0 :  9223372036854775807
Vertex   1 :  9223372036854775807
Vertex   2 :  0
Vertex   3 :  0

Shortest Distance with vertex 3 as the source:

Vertex   0 :  9223372036854775807
Vertex   1 :  9223372036854775807
Vertex   2 :  -9223372036854775801
Vertex   3 :  0

 */
