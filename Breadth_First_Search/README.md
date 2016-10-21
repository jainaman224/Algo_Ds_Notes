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
| 3.  | ![Breadth First Traversal](https://www.tutorialspoint.com/data_structures_algorithms/images/bfs_three.jpg)   | We then see an unvisited adjacent node from **S**. In this example, we have three nodes but alphabetically we choose **A**, mark it as visited and enqueue it.    |
| 4.  | ![Breadth First Traversal](https://www.tutorialspoint.com/data_structures_algorithms/images/bfs_four.jpg)   | Next, the unvisited adjacent node from **S** is **B**. We mark it as visited and enqueue it.    |
| 5.  | ![Breadth First Traversal](https://www.tutorialspoint.com/data_structures_algorithms/images/bfs_five.jpg)   | Next, the unvisited adjacent node from **S** is **C**. We mark it as visited and enqueue it.    |
| 6.  | ![Breadth First Traversal](https://www.tutorialspoint.com/data_structures_algorithms/images/bfs_six.jpg)   | Now, **S** is left with no unvisited adjacent nodes. So, we dequeue and find **A**.    |
| 7.  | ![Breadth First Traversal](https://www.tutorialspoint.com/data_structures_algorithms/images/bfs_seven.jpg)   | From **A** we have **D** as unvisited adjacent node. We mark it as visited and enqueue it.    |
