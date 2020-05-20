# Johnson's Algorithm

Johnson's algorithm is a method to find the shortest distance between every pair of vertices in a weighted directed graph. The edges weights may be negative, but no negative cycles should be present in the graph.
Johnson's algorithm utilizes both Dijkstra's algorithm and Bellman-Ford's algorithm as subroutines. The algorithm can be applied on sparse graphs, and the time complexity depends on the number of edges.
Johnson's algorithm uses the technique of reweighting, which works as follows:

If all edge weights w in a graph G = (V, E) are nonnegative, we can find shortest paths between all pairs of vertices by running Dijkstra's algorithm once from each vertex.

If G has negative-weight edges but no negative-weight cycles, we simply compute a new set of nonnegative edge weights that allows us to use the same method. The new set of edge weights must satisfy two important properties.
1. For all pairs of vertices u, v V, a path p is the shortest path from u to v using weight function w if and only if p is also the shortest path from u to v using weight function.
2. For all edges (u, v), the new weight is nonnegative.

## Algorithm

### Input:
Graph G

### Output:
List of all pair shortest paths for G

### Pseudocode:
```
Johnson(G)
{

    G'.V = G.V + {n}
    G'.E = G.E + ((s, u) for u in G.V)
    weight(n,u) = 0 in G.V
    
    Dist = BellmanFord(G'.V, G'.E)
    for edge(u, v) in G'.E do
        weight(u, v) += h[u] - h[v]
    end
    
    L = []        /*for storing result*/
    for vertex v in G.V do
        L += Dijkstra(G, G.V)
    end
    
    return L
}
```

## Example
Let us consider the following graph.

![image](https://media.geeksforgeeks.org/wp-content/cdn-uploads/Johnson1.png)

We add a source s and add edges from s to all vertices of the original graph. In the following diagram s is 4.

![image](https://www.geeksforgeeks.org/wp-content/uploads/Johnson2-300x196.png)

We calculate the shortest distances from 4 to all other vertices using Bellman-Ford algorithm. The shortest distances from 4 to 0, 1, 2 and 3 are 0, -5, -1 and 0 respectively, i.e., h[] = {0, -5, -1, 0}. Once we get these distances, we remove the source vertex 4 and reweight the edges using following formula. w(u, v) = w(u, v) + h[u] - h[v].

![image](https://www.geeksforgeeks.org/wp-content/uploads/Johnson3.png)

Since all weights are positive now, we can run Dijkstra's shortest path algorithm for every vertex as source.

## Time Complexity
The main steps involved in this algorithm are
* Bellman-Ford Algorithm, called once. (Time complexity O(VE))
* Dijkstra Algorithm, called V times. (Time complexity  O(VLogV))

Thus the overall time complexity of Johnson's algorithm is O(V^(2)*log V + VE).
Worst Time complexity of above algorithm is O(V^(3) + V*E) as Dijkstra's Algorithm takes O(n^(2)).

## References
* [GeeksforGeeks](https://www.geeksforgeeks.org/johnsons-algorithm/)
* Introduction to Algorithms 3rd Edition by Clifford Stein, Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest.
