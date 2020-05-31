# Floyd Warshall Algorithm

In computer science, the **Floyd–Warshall algorithm** is an algorithm for finding
shortest paths in a weighted graph with positive or negative edge weights (but
with no negative cycles). A single execution of the algorithm will find the 
lengths (summed weights) of shortest paths between all pairs of vertices.

## Algorithm

The Floyd–Warshall algorithm compares all possible paths through the graph between 
each pair of vertices. It is able to do this with `O(|V|^3)` comparisons in a graph.
This is remarkable considering that there may be up to `|V|^2` edges in the graph, 
and every combination of edges is tested. It does so by incrementally improving an 
estimate on the shortest path between two vertices, until the estimate is optimal.

Consider a graph `G` with vertices `V` numbered `1` through `N`. Further consider 
a function `shortestPath(i, j, k)` that returns the shortest possible path 
from `i` to `j` using vertices only from the set `{1, 2, ..., k}` as 
intermediate points along the way. Now, given this function, our goal is to 
find the shortest path from each `i` to each `j` using only vertices 
in `{1, 2, ..., N}`.

![Recursive Formula](https://wikimedia.org/api/rest_v1/media/math/render/svg/f9b75e25063384ccca499c56f9a279abf661ad3b)

![Recursive Formula](https://wikimedia.org/api/rest_v1/media/math/render/svg/34ac7c89bbb18df3fd660225fd38997079e5e513)
![Recursive Formula](https://wikimedia.org/api/rest_v1/media/math/render/svg/0326d6c14def89269c029da59eba012d0f2edc9d)

This formula is the heart of the Floyd–Warshall algorithm.

### Pseudo Code:

```
FLOYD - WARSHALL (W)
 1. n ← rows [W].
 2. D0 ← W
 3. for k ← 1 to n
 4. do for i ← 1 to n     
 5. do for j ← 1 to n     
 6. do d(i, j, k) ← min ( d(i, j, k-1),d(i, k, k-1) + d(k, j, k-1) )
 7. return D(n) 
```

## Time complexity
The strategy adopted by the Floyd-Warshall algorithm is Dynamic Programming. 
The running time of the Floyd-Warshall algorithm is determined by the triply nested for loops of lines 3-6.
Each execution of line 6 takes O (1) time. The algorithm thus runs in time θ(n3 ).

## Example

The algorithm above is executed on the graph on the left below:

![Example](https://upload.wikimedia.org/wikipedia/commons/2/2e/Floyd-Warshall_example.svg)

In the tables below `i` is row numbers and `j` is column numbers.


**k = 0**

|       | 1   | 2   | 3   | 4   |
|:-----:|:---:|:---:|:---:|:---:|
| **1** |	0   |	∞   |	−2  | ∞   |
| **2** |	4   |	0   |	3	  | ∞   |
| **3** |	∞   |	∞   |	0	  | 2   |
| **4** |	∞   |	−1  | ∞   | 0   |


**k = 1**

|       | 1   | 2   | 3   | 4   |
|:-----:|:---:|:---:|:---:|:---:|
| **1** | 0   | ∞   | −2  | ∞   |
| **2** | 4   | 0   |  2  | ∞   |
| **3** | ∞   | ∞   |  0  | 2   |
| **4** | ∞   | −   |  ∞  | 0   |


**k = 2**

|       | 1   | 2   | 3   | 4   |
|:-----:|:---:|:---:|:---:|:---:|
| **1** |	0   |	∞   |	−2  | ∞   |
| **2** |	4   |	0   | 2	  | ∞   |
| **3** |	∞   |	∞	  | 0	  | 2   |
| **4** |	3   |	−1  | 1   | 0   |


**k = 3**

|       | 1   | 2   | 3   | 4   |
|:-----:|:---:|:---:|:---:|:---:|
| **1** |	0   |	∞   |	−2  | 0   |
| **2** |	4   |	0   |	2	  | 4   |
| **3** |	∞   |	∞   |	0	  | 2   |
| **4** |	3   |	−1  | 1   | 0   |


**k = 4**

|       | 1   | 2   | 3   | 4   |
|:-----:|:---:|:---:|:---:|:---:|
| **1** |	0   |	−1  | −2  | 0   |
| **2** |	4   |	0	  | 2	  | 4   |
| **3** |	5   |	1	  | 0	  | 2   |
| **4** |	3   |	−1  | 1   | 0   |


## Implementation
* [CPP Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Floyd_Warshall_Algorithm/Floyd_Warshall_Algorithm.cpp)
* [Go Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Floyd_Warshall_Algorithm/Floyd_Warshall_Algorithm.go)
* [Java Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Floyd_Warshall_Algorithm/Floyd_Warshall_Algorithm.java)
* [Python Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Floyd_Warshall_Algorithm/Floyd_Warshall_Algorithm.py)
