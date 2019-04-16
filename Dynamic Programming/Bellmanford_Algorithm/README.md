## Bellmanford Algorithm

The Bellman–Ford algorithm is an algorithm that computes shortest paths from a single source vertex 
to all of the other vertices in a weighted digraph. It is slower than Dijkstra's algorithm for the 
same problem, but more versatile, as it is capable of handling graphs in which some of the edge
weights are negative numbers.



## Algorithm

#### Input 
Graph and a source vertex src

#### Output
Shortest distance to all vertices from src. If there is a negative weight cycle, then shortest distances are not calculated, negative weight cycle is reported.

#### Following are the detailed steps.

* This step initializes distances from source to all vertices as infinite and distance to source itself as 0. 
Create an array dist[] of size |V| with all values as infinite except dist[src] where src is source vertex.

* This step calculates shortest distances. Do following |V|-1 times where |V| is the number of vertices in given graph.
  
  a) Do following for each edge u-v
  
      If dist[v] > dist[u] + weight of edge uv, then update dist[v]
  
      dist[v] = dist[u] + weight of edge uv

* This step reports if there is a negative weight cycle in graph. Do following for each edge u-v
    
       If dist[v] > dist[u] + weight of edge uv, 
      
      then “Graph contains negative weight cycle”

The idea of step 3 is, step 2 guarantees shortest distances if graph doesn’t contain negative weight cycle. If we iterate through all edges one more time and get a shorter path for any vertex, then there is a negative weight cycle

## Pseudocode

```
function BellmanFord(list vertices, list edges, vertex source)
 ::distance[],predecessor[]

 // This implementation takes in a graph, represented as
 // lists of vertices and edges, and fills two arrays
 // (distance and predecessor) about the shortest path
 // from the source to each vertex

 // Step 1: initialize graph
 for each vertex v in vertices:
     distance[v] := inf             // Initialize the distance to all vertices to infinity
     predecessor[v] := null         // And having a null predecessor

 distance[source] := 0              // The distance from the source to itself is, of course, zero

 // Step 2: relax edges repeatedly
 for i from 1 to size(vertices)-1:
     for each edge (u, v) with weight w in edges:
         if distance[u] + w < distance[v]:
             distance[v] := distance[u] + w
             predecessor[v] := u

 // Step 3: check for negative-weight cycles
 for each edge (u, v) with weight w in edges:
     if distance[u] + w < distance[v]:
         error "Graph contains a negative-weight cycle"

 return distance[], predecessor[]
 ```

## Time Complexity
Bellman-Ford makes |E| relaxations for every |V|-1 iteration, and there are  iterations. Therefore, the worst-case scenario is that Bellman-Ford runs in O(|V|.|E|) time.

However, in some scenarios, the number of iterations can be much lower. For certain graphs, only one iteration is needed, and hence in the best case scenario, only O(|E|) time is needed

## Implementation
- [C Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Bellmanford_Algorithm/Bellmanford.c)
> :rocket: [Compile Online](https://repl.it/repls/UntrueMediumLoop) :rocket:

- [C++ Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Bellmanford_Algorithm/Bellmanford.cpp)
> :rocket: [Compile Online](https://repl.it/repls/AccomplishedLightpinkMapping) :rocket:

- [C# Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Bellmanford_Algorithm/Bellmanford.cs)
> :rocket: [Compile Online](https://repl.it/repls/BrilliantFabulousBytecode) :rocket:

- [Java Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Bellmanford_Algorithm/Bellmanford.java)
> :rocket: [Compile Online](https://repl.it/repls/DefenselessSpotlessFibonacci) :rocket:

- [Python Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Bellmanford_Algorithm/Bellmanford.py)
> :rocket: [Compile Online](https://repl.it/repls/MortifiedBothKnowledge) :rocket:

## References
* [geeksforgeeks](https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/)
* [wikipedia](https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm/)
* [Lecture notes](http://faculty.ycp.edu/~dbabcock/PastCourses/cs360/lectures/lecture21.html/)
