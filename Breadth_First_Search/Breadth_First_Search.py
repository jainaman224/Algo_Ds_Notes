from collections import deque

class graph:
  def __init__(self, num_vertices):
    self.num_vertices = num_vertices
    self.adj_list = [[] for _ in xrange(num_vertices)]

  def add_edge(self, source, destination):
    self.adj_list[source].append(destination)

  def bfs(self, start):
    visited = [False] * self.num_vertices

    queue_vertex = deque([])

    visited[start] = True
    queue_vertex.append(start)

    while len(queue_vertex) != 0:
      current = queue_vertex.popleft()
      print current,

      for vertex in self.adj_list[current]:
        if (not visited[vertex]):
          visited[vertex] = True
          queue_vertex.append(vertex)


# Create a graph with 8 vertices
graph = graph(8)

# Create arcs
graph.add_edge(0, 1)
graph.add_edge(0, 2)
graph.add_edge(1, 2)
graph.add_edge(1, 4)
graph.add_edge(2, 0)
graph.add_edge(2, 3)
graph.add_edge(3, 3)
graph.add_edge(3, 6)
graph.add_edge(4, 0)
graph.add_edge(4, 5)
graph.add_edge(5, 6)
graph.add_edge(5, 7)
graph.add_edge(6, 2)
graph.add_edge(7, 3)

print "Breadth First Traversal is:",
graph.bfs(0)
print ""

# Expected Output
# Breadth First Traversal is: 0 1 2 4 3 5 6 7
