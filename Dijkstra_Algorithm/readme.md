# Dijkstra Algorithm

Dijkstra's algorithm is used to find the shortest paths from the source vertex to all other vertices in the graph. 

## Example

Let's find shortest distance of all the vertices from the vertex 0 in the graph given below.

![Screenshot from 2020-05-27 01-01-28](https://user-images.githubusercontent.com/43384092/82946882-c0785100-9fbc-11ea-8726-688335180c17.png)

- The set sptSet is initially empty and distances assigned to vertices are {0, INF, INF, INF} where INF indicates infinite. Now pick the vertex with minimum distance value. The vertex 0 is picked, include it in sptSet. So sptSet becomes {0}. After including 0 to sptSet, update distance values of its adjacent vertices. Adjacent vertices of 0 are 1 and 3. The distance values of 1 and 3 are updated as 1 and 2. 

- Pick the vertex with minimum distance value and not already included in sptSet. The vertex 1 is picked and added to sptSet. So sptSet now becomes {0, 1}. Update the distance values of adjacent vertices of 1. The distance value of vertex 2 becomes 4.

- Pick the vertex with minimum distance value and not already included in sptSet. Vertex 3 is picked. So sptSet now becomes {0, 1, 3}. Update the distance values of adjacent vertices of 3. The adjacent vertices of 3 are 0 and 2 which already have a minimum value so they will not be updated.

- Pick the vertex with minimum distance value and not already included in sptSet. Vertex 2 is picked. So sptSet now becomes {0, 1, 3, 2}. The adjacent vertices of 2 are 1 and 3 which already have a minimum value so they will not be updated.

- Now we stop the process as sptSet does include all vertices of given graph. Finally, we get the shortest distances of all the vertices from the vertex 0.

## Algorithm

1) Create an array dist. The size of the array is equal to the number of vertices V in the graph. Initialise all the elements of the array with INFINITE.

2) Create an empty set s of type pair(weight, vertex).

3) Insert source vertex into the set and its distance as 0.
   Update dist[src] = 0.

4) Repeat the below steps while set is not empty<br>
       a) Extract the minimum distance vertex from the set s i.e. the top element from the set as the set is sorted in ascending order on the basis of distance from the source. Let it be u.<br>
       b) Loop through all the adjacent vertices of u. Let the adjacent vertex be labelled as v. For every v,<br>
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if dist[v] > dist[u] + weight(u, v)<br>
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;(i)   dist[v] = dist[u] + weight(u, v)<br>
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;(ii)  If v is in set, remove it.<br>
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;(iii) Insert v in the set with updated distance.<br>

5) Print distance array dist[ ] along with the vertex number.

## Pseudocode
```
minDistance(dist[], sptSet[])
    min = INT_MAX
        for(v = 0; v < V; v++)
            if (sptSet[v] == false and dist[v] <= min) 
                min = dist[v], min_index = v
        return min_index

dijkstra(int graph[V][V], int src)
    for(i = 0; i < V; i++)
        dist[i] = INT_MAX
        sptSet[i] = false
    dist[src] = 0
    for(count = 0; count < V - 1; count++)
        u = minDistance(dist, sptSet)
        sptSet[u] = true
        for(v = 0; v < V; v++)
            if(not(sptSet[v]) && graph[u][v] && dist[u] not equal to INT_MAX && dist[u] + graph[u][v] < dist[v]) 
                dist[v] = dist[u] + graph[u][v]
    for(i = 0; i < V; i++)
        display i, dist[i]
```
## Complexity 

    Time Complexity: O(V * V)
    Space Complexity: O(V)

where
>V = number of vertices<br/>
      
## Implementation
 * [C Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Dijkstra_Algorithm/Dijkstra_Algorithm.c)
 * [C++ Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Dijkstra_Algorithm/Dijkstra_Algorithm.cpp)
 * [Java Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Dijkstra_Algorithm/Dijkstra_Algorithm.java)
 * [Python Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Dijkstra_Algorithm/Dijkstra_Algorithm.py)
 * [JS Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Dijkstra_Algorithm/Dijkstra_Algorithm.js)
 * [Ruby Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Dijkstra_Algorithm/Dijkstra_Algorithm.rb)
 * [C++ STL Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Dijkstra_Algorithm/Dijkstra_Algorithm_STL.cpp)
 * [C++ Efficient Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Dijkstra_Algorithm/Dijkstra_Efficient.cpp)

## References

* [Tutorial - GeeksforGeeks](https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/)
* [Wikipedia](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm)

