# Kosaraju's Algorithm

Kosaraju's algorithm (also known as Kosaraju–Sharir algorithm) is a linear time algorithm to find the strongly connected components of a directed graph. Aho, Hopcroft and Ullman credit it to S. Rao Kosaraju and Micha Sharir. Kosaraju suggested it in 1978 but did not publish it, while Sharir independently discovered it and published it in 1981. It makes use of the fact that the transpose graph (the same graph with the direction of every edge reversed) has exactly the same strongly connected components as the original graph.

## Strongly Connected Components

A graph can be said strongly connected if every vertex can be reached by every other vertex. The strongly connected components of an arbitrary directed graph form a partition into subgraphs that are themselves strongly connected. 

## Uses of SCC algorithms

In case of social network ( like a group of students or any other community) there are common pages which people like, common games they play or common places they visit. These can be considered as strongly connected communities. The SCC algorithms can be of use here. By using them websites can suggest the commonly liked pages,games,places etc. to people who have not liked them yet but are part of the group.

## Implementation

    Step 1. - Create an empty stack and do DFS traversal of a graph.
    
    Step 2. - In DFS traversal, after calling recursive DFS for adjacent vertices of a vertex, push the vertex to stack.

    Step 3. - Find the transpose of the graph by reversing all arcs.

    Step 4. - One by one pop a vertex from stack while stack is not empty.  

    Step 5. - Let the popped vertex be ‘v’. Take v as source and do DFS (call DFSUtil(v)).\

    Step 6. - The DFS starting from v prints strongly connected component of v. 



### Time Complexity

    O(V + E) - This algorithm uses DFS for a graph represented using adjacency list O(V + E) and reversing a graph also takes O(V + E). This algorithm is asymptotically best algorithm.


## Implementation

- [Python Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Kosaraju_Algorithm/Kosaraju_Algorithm.py)

## References 
- Wikipedia and GeeksforGeeks.

