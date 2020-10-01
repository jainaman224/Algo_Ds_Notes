# Prim's Algorithm

Prim's algorithm is a greedy algorithm that finds a minimum spanning tree for a weighted undirected graph. 
A minimum spanning tree of a weighted, connected graph is a subgraph that is a tree and connects all the vertices together and has weight less than or equal to the weight of every other spanning tree.

## EXAMPLE

![Prim's Algorithm](https://cdn.programiz.com/sites/tutorial2program/files/Prim%27s-algorithm.jpg)

[Courtesy: Programiz](https://www.programiz.com/dsa/prim-algorithm)

## ALGORITHM

1. Mark all vertices as not visited
2. Select an edge with minimum weight and add it to the tree, mark the start and end vertices of that edge as visited
3. Select edge emanating from the vertices that are now visited and has least weight, add it to the tree and mark the new vertex as visited
4. Repeat 3 until all vertices are visited

## PSEUDOCODE

```
Input - Weighted, connected Graph G, set v for vertices, set e for edges, starting vertex s
Output - Minimum Spanning Tree 

Prims(G, v, e, s) {
    for i = 0 to v
        visited[i] = false
        
    visited[start] = true
      
    count = 0   // counts vertices visited
    int min = 9999  //to get minimum edge
    for (int i = 0; i < v; i++) {
      if(visited[i]) {
            for (int j = 0; j < v; j++) {
              if (edge between i and j exists and visited[j] is false) {
                  if (min > G[i][j]) {
                      min = G[i][j];
                      x = i;
                      y = j;
                      add edge to Minimum Spanning Tree
                  }
              }
         }
     }
 }

```

## COMPLEXITY

**Time complexity**  - О(v^2), where v is the number of vertices in the graph. 

## See Also 

- [Prim's Algorithm](https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/)
- [Prim's Algorithm Visualization](https://www.cs.usfca.edu/~galles/visualization/Prim.html)


## Implementation

- [C Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Prims_Algorithm/Prims_Algorithm.c)
> :rocket: [Compile Online](https://repl.it/repls/LargeAngelicTrace) :rocket:

- [C++ Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Prims_Algorithm/Prims_Algorithm.cpp)
> :rocket: [Compile Online](https://repl.it/repls/MortifiedHilariousPixels) :rocket:

- [Java Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Prims_Algorithm/Prims_Algorithm.java)
> :rocket: [Compile Online](https://repl.it/repls/HoneydewInfiniteTechnician) :rocket:

- [Python Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Prims_Algorithm/Prims_Algorithm.py)
> :rocket: [Compile Online](https://repl.it/repls/FrontArtisticWebmaster) :rocket:
