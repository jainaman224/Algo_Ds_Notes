# Dijkstra Algorithm

Dijkstra's algorithm is used to find the shortest paths from the source vertex to all other vertices in the graph. 

## Algorithm

1) Create a array sptSet which will keep the track of all the vertices whose minimum distance is calculated from the source vertex. Initially all vertices are marked as false.

2) Create an array dist whose size is equal to number of vertices V. Initialize all dist values as INFINITE.

3) dist[src] = 0
   sptSet[src] = true

4) Repeat the below steps while sptSet doesn't include all vertices

       a) Pick a vertex u which is not there in sptSet and has minimum distance value.
       
       b) Insert u in sptSet.
       
       c) Iterate through all the adjacent vertices of u. Let the adjacent vertex be v.For every vertex v,
       
              if(dist[u] + weight(u,v) < dist[v]):
              
                  dist[v] = dist[u] +  weight(u, v)

5) Print distance array dist[ ] along with the vertex number.

**We can also use C++ STL. The algorithm below uses STL to implement dijkstra algorithm.**

1. Create an array dist. The size of the array is equal to the number of vertices V in the graph.Initialise all the elements of the array with INFINITE.
 
2. Create an empty set s of type pair(weight, vertex).

3. Insert source vertex into the set and its distance as 0.
   Update dist[src] = 0.

4. Repeat the below steps while set is not empty
       a. Extract the minimum distance vertex from the set s i.e. the top element from the set as the set is sorted in ascendng orer on the basis of distance from the source. Let it be u.
       b. Loop through all the adjacent vertices of u. Let the adjacent vertex be labelled as v. For every v, 
       
              if dist[v] > dist[u] + weight(u, v) 
              
                  (i)   dist[v] = dist[u] + weight(u, v)
                  
                  (ii)  If v is in set, remove it.
                  
                  (iii) Insert v in the set with updated distance.

5.  Print distance array dist[ ] along with the vertex number.

## Pseudo Code

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
        for(count = 0; count < V-1; count++)
            u = minDistance(dist, sptSet)
            sptSet[u] = true
            for(v = 0; v < V; v++)
                if(not(sptSet[v]) && graph[u][v] && dist[u] not equal to INT_MAX && dist[u] + graph[u][v] < dist[v]) 
                     dist[v] = dist[u] + graph[u][v]
        for(i = 0; i < V; i++)
            display i, dist[i]
```

**Using C++ STL**

```  
        
       dijkstra(src)
           set< pair<int,int> > s
           dist[V] = {INF}
           s.insert(0, src)
           dist[src] = 0
           while(s is not empty):
               temp = *(s.begin())
               delete s.begin
               u = temp.second
               for(i = adj[u].begin(); i != adj[u].end(); i++)
                   v = (*i).first
                   weight = (*i).second
                   if dist[v] != INF
                       delete(dist[v], v)
                   s.insert(dist[v], v)
           for(i = 0; i < V; i++)
               display i, dist[i]
```
       
## Complexity
       Time Complexity: O(V * V)
       Space Complexity: O(V)
       
 **Using C++ STL:**
 
       Time Complexity: O(V + ElogV)
       Space Complexity: O(V)

 ## Implementation
 * [C Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Dijkstra_Algorithm/Dijkstra_Algorithm.c)
 * [C++ Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Dijkstra_Algorithm/Dijkstra_Algorithm.cpp)
 * [Java Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Dijkstra_Algorithm/Dijkstra_Algorithm.java)
 * [Python Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Dijkstra_Algorithm/Dijkstra_Algorithm.py)
 * [JS Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Dijkstra_Algorithm/Dijkstra_Algorithm.js)
 * [Ruby Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Dijkstra_Algorithm/Dijkstra_Algorithm.rb)
 * [C++ STL Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Dijkstra_Algorithm/Dijkstra_Algorithm_STL.cpp)
 * [C++ Efficient Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Dijkstra_Algorithm/Dijkstra_Efficient.cpp)
 
