# Topological Sort

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge uv, vertex u comes before v in the ordering. 
Topological Sorting for a graph is not possible if the graph is not a DAG.


## Algorithm

1. Find any vertex v with in-degree zero
2. Add v in sorted array
3. Remove vertex v and all edges emanating from it from the directed graph
4. Repeat from Step 1, until all vertices have been added to sorted array


## Example:

![Topological Sort](https://he-s3.s3.amazonaws.com/media/uploads/0c3320c.png)
![Topological Sort](https://he-s3.s3.amazonaws.com/media/uploads/401c3c4.png)
![Topological Sort](https://he-s3.s3.amazonaws.com/media/uploads/4aed1a4.png)
![Topological Sort](https://he-s3.s3.amazonaws.com/media/uploads/54d23c8.png)
![Topological Sort](https://he-s3.s3.amazonaws.com/media/uploads/ccb8663.png)

[Courtesy: HackerEarth](https://www.hackerearth.com/practice/algorithms/graphs/topological-sort/tutorial/)


## Time Complexity

Total Time = O(|V|^2 + |E|)
Here, O(|V|^2) is the time complexity for finding a vertex with in-degree zero, and O(|E|) is the time complexity for reducing in-degree of all the adjacent vertices by one on deletion of the vertex.


## See also

- [Topological Sort](https://www.geeksforgeeks.org/topological-sorting/)
- [Topological Sort Interactive Visualisations](https://www.cs.usfca.edu/~galles/visualization/TopoSortDFS.html)
