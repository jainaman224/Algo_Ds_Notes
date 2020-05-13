# Kosaraju Algorithm

Kosaraju Algorithm is used to find strongly connected components in a directed graph. A directed graph is strongly connected if there is a path between all pairs of vertices.

## Example

Let's find strongly connected components in the directed graph given below.

![Screenshot from 2020-05-13 18-30-06](https://user-images.githubusercontent.com/43384092/81815746-00185500-9548-11ea-961a-0d5a4506dd20.png)
- Create an empty stack 's'. Push the vertex in the stack only after all its neighbours are visited.

- Create a boolean array 'visited' to keep track of all the vertices which are visited.

- Let's start the DFS from vertex 0. Mark 0 as visited. Mark the neighbour of vertex 0 i.e. 2 as visited. Now mark the neighbour of 2 i.e. 1 as visited. There is only one neighbour of 1 i.e. 0 which is already visited. So, no neighbours of 1 are left to be traversed therefore push vertex 1 into the stack. Now, backtrack. There is no neighbour of vertex 2 left to be traversed. Push 2 into the stack.<br/>
Stack: 1, 2<br/>

- Now mark the another neighbour of 0 i.e. 3 as visited. Mark the neighbour of 3 i.e. 4 as visited. There is no neighbour of 4 left to be visited. Push 4 into the stack. Similarly, push 3 into the stack.<br/>
Stack: 1, 2, 4, 3<br/>

- All neighbours of vertex 0 are marked visited. Push 0 into the stack<br/>
Stack: 1, 2, 4, 3, 0<br/>

![a1](https://user-images.githubusercontent.com/43384092/81813457-18d33b80-9545-11ea-9324-ef0c72cb65b4.png)

- Reverse directions of all arcs to obtain the transpose graph. Also, initialise the boolean array 'visited' as false.

- Pop a vertex from stack 's' i.e. 0. Take vertex 0 as source and do DFS. Now, DFS will print the strongly connected component of vertex 0.<br/>
Print: 0, 1, 2<br/>
Stack: 1, 2, 4, 3<br/>

- Pop again from the stack i.e. 3. Take vertex 3 as source and do DFS. Now, DFS will print the strongly connected component of vertex 3.<br/>
Print: 0, 1, 2<br/>
       &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;3<br/>
Stack: 1, 2, 4<br/>

- Repeat the above step with vertex 4.<br/>
Print: 0, 1, 2<br/>
       &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;3<br/>
       &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;4<br/>
Stack: 1, 2<br/>

- Now pop 2 from the stack. It is already marked as visited so no DFS will be performed. Similar case with vertex 1.<br/>
Print: 0, 1, 2<br/>
       &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;3<br/>
       &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;4<br/>

## Algorithm

1. Create an empty stack ‘S’ and do DFS traversal of a graph. In DFS traversal, after calling recursive DFS for adjacent vertices of a vertex, push the vertex to stack.<br/>

2. Reverse directions of all arcs to obtain the transpose graph.<br/>

3. One by one pop a vertex from S while S is not empty. Let the popped vertex be ‘v’. Take v as source and do DFS (call DFSUtil(v)). The DFS starting from v prints strongly connected component of v.<br/>

## Pseudocode
```
Declare array of vectors adj and transpose, stack st and a boolean array visited.
Initialise all the elements of array visited with false.
dfs(s)
    visited[s] = true
    for(i = 0; i < adj[s].size; i++)
        if(visited[adj[s][i]] == false)
            dfs(adj[s][i])
    st.push(s)

dfsUtil(s)
    visited[s] = true
    print(s)
    for(i = 0; i < transpose[s].size; i++)
        if(visited[transpose[s][i]] == false)
            dfsUtil(transpose[s][i])

Kosaraju_Algorithm(nodes, edges, adj, src)
    dfs(0)
    Initialise all the elements of array visited with false.
    for(i = 0; i < stack.size; i++)
        top = stack.top
        stack.pop
        if(visited[top] is false):
            dfsUtil(top)
            print new line
```

## Complexity 

    Time Complexity = O(V + E)
    Space Complexity = O(V)

where
>V = number of vertices<br/>
>E = number of edges<br/>
      
## Implementation

* [C# Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Kosaraju_Algorithm/Kosaraju_Algorithm.cs)
* [Python Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Kosaraju_Algorithm/Kosaraju_Algorithm.py)
* [C++ Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Kosaraju_Algorithm/Kosaraju_Algorithm.cpp)

## References

* [Tutorial - GeeksforGeeks](https://www.geeksforgeeks.org/strongly-connected-components/)
* [Tutorial - OpenGenus](https://iq.opengenus.org/kosarajus-algorithm-for-strongly-connected-components/)
* [Wikipedia](http://en.wikipedia.org/wiki/Kosaraju%27s_algorithm)

