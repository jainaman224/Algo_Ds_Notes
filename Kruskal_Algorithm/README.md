# Kruskal's Algorithm

Before going towards Kruskal's Algorithm let's first understand about Spanning Tree and Minimum Spanning Tree(MST).

**Spanning Tree** - Spanning tree is the sum of weights of all the edges in a tree.

**Minimum Spanning Tree**- A minimum spanning tree (MST) is one which costs the least among all spanning trees.

An example is given below

![Spanning Tree](<https://i.imgur.com/E1AHgqc.jpg>)

Fig- Spanning and Minimum Spanning Tree

Kruskal's algorithm is a minimum-spanning-tree algorithm which finds an edge of the least possible weight that connects any two trees in the forest. It is a *greedy algorithm* in graph theory as it finds a minimum spanning tree for a connected weighted graph adding increasing cost arcs at each step. This means it finds a subset of the edges that forms a tree that includes every vertex, where the total weight of all the edges in the tree is minimized. If the graph is not connected, then it finds a minimum spanning forest (a minimum spanning tree for each connected component). It treats every node as an independent tree and connects one with another only if it has the lowest cost compared to all other options available.

This algorithm first appeared in Proceedings of the American Mathematical Society, pp. 48–50 in 1956, and was written by Joseph Kruskal.

### Steps for Kruskal’s Algorithm:

- Sort the graph edges with respect to their weights in increasing order.
- Start adding edges to the minimum spanning tree from the edge with the smallest weight until the edge of the largest weight.
- Only add edges which don’t form a cycle—edges which connect only disconnected components.

In simple language we can say,

- Remove all loops and parallel edges.
- Arrange all the edges in ascending order of cost.
- Add edges with least weight.

### Pseudocode

 ```
  MST- KRUSKAL (G, w)
   1. A ← ∅
   2. for each vertex v ∈ V [G]
   3.     do MAKE - SET (v)
   4.     sort the edges of E into non decreasing order by weight w
   5. for each edge (u, v) ∈ E, taken in non decreasing order by weight
   6.     do if FIND-SET (μ) ≠ if FIND-SET (v)
   7.     then A  ←  A ∪ {(u, v)}
   8.     UNION (u, v)
   9. return A
 ```

### Analysis

Kruskal's Algorithm can be shown to run in `O (E log E)` time, or simply, `O (E log V)` time, all with simple data structures where E is the number of edges in the graph and V is the number of vertices. These running times are equivalent because:
- E is at most V2 and `log V2= 2 x log V` is `O (log V)`.
- If we ignore isolated vertices, which will each their components of the minimum spanning tree, `V ≤ 2 E`, so log V is `O (log E)`.

Thus the total time is `O (E log E) = O (E log V)`.

### Example
Let's take an example. Derive the Minimum Spanning Tree for the following graph using Kruskal's Algorithm
![Question](https://static.javatpoint.com/tutorial/daa/images/methods-of-minimum-spanning-tree.png)
#### Step-1
Initialize the set `A` to the empty set and create `|v|` trees, one containing each vertex with `MAKE-SET` procedure. Then sort the edges in `E` into order by non-decreasing weight.There are 9 vertices and 12 edges. So MST formed (9-1) = 8 edges
![Img](https://static.javatpoint.com/tutorial/daa/images/methods-of-minimum-spanning-tree2.png)

Now, Check for each edge `(u, v)` whether the endpoints `u` and `v` belong to the same tree. If they do then the edge `(u, v)` cannot be supplementary. Otherwise, the two vertices belong to different trees, and the edge `(u, v)` is added to `A`, and the vertices in two trees are merged in by union procedure.
#### Step-2
So, first take `(h, g)` edge 

![Img](https://static.javatpoint.com/tutorial/daa/images/methods-of-minimum-spanning-tree-step1.png)
#### Step-3
Then `(g, f)` edge. 

![Img](https://static.javatpoint.com/tutorial/daa/images/methods-of-minimum-spanning-tree-step2.png)
#### Step-4
Then `(a, b)` and `(i, g)` edges are considered, and the forest becomes

![Img](https://static.javatpoint.com/tutorial/daa/images/methods-of-minimum-spanning-tree-step3.png)
#### Step-5
Now, edge `(h, i)`. Both `h` and `i` vertices are in the same set. Thus it creates a cycle. So this edge is discarded.Then edge `(c, d)`, `(b, c)`, `(a, h)`, `(d, e)`, `(e, f)` are considered, and the forest becomes.

![Img](https://static.javatpoint.com/tutorial/daa/images/methods-of-minimum-spanning-tree-step4.png)
#### Step-6
In `(e, f)` edge both endpoints `e` and `f` exist in the same tree so discarded this edge. Then `(b, h)` edge, it also creates a cycle. After that edge `(d, f)` and the final spanning tree is shown as in dark lines.

![Img](https://static.javatpoint.com/tutorial/daa/images/methods-of-minimum-spanning-tree-step6.png)
#### Step-7
This step will be required Minimum Spanning Tree because it contains all the 9 vertices and (9 - 1) = 8 edges `e → f,  b → h,  d → f [cycle will be formed]`

![Img](https://static.javatpoint.com/tutorial/daa/images/methods-of-minimum-spanning-tree-step7.png)

### Implementation

- [C++ Code](<https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Kruskal_Algorithm/Kruskal_Algorithm.cpp>)

> 🚀 [Compile Online](https://repl.it/@gauravburjwal/Kruskal-Algorithm-CPP) 🚀

- [Java Code](<https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Kruskal_Algorithm/Kruskal_Algorithm.java>)

> 🚀 [Compile Online](https://repl.it/@gauravburjwal/Kruskal-Algorithm-JAVA) 🚀