# Breadth First Traversal

[Breadth First Traversal](https://en.wikipedia.org/wiki/Breadth-first_search)  is an algorithm for traversing or searching tree or graph data structures. It starts at the tree root (or some arbitrary node of a graph, sometimes referred to as a 'search key') and explores the neighbor nodes first, before moving to the next level neighbors.

## Example
![Breadth First Traversal](https://www.tutorialspoint.com/data_structures_algorithms/images/breadth_first_traversal.jpg)

As in the example given above, BFS algorithm traverses from A to B to E to F first then to C and G lastly to D.

It employs the following rules.

**Rule 1** − Visit the adjacent unvisited vertex. Mark it as visited. Display it. Insert it in a queue.

**Rule 2** − If no adjacent vertex is found, remove the first vertex from the queue.

**Rule 3** − Repeat Rule 1 and Rule 2 until the queue is empty.

| Step     | Traversal    | Description |
| --------|---------|-------|
| 1.  | ![Breadth First Traversal](https://www.tutorialspoint.com/data_structures_algorithms/images/bfs_one.jpg)   | Initialize the queue.    |
| 2. | ![Breadth First Traversal](https://www.tutorialspoint.com/data_structures_algorithms/images/bfs_two.jpg) | We start from visiting S (starting node), and mark it as visited.    |

