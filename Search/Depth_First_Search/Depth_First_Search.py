class graph:
  def __init__(self, num_vertices):
    self.num_vertices = num_vertices
    self.adj_list = [[] for _ in xrange(num_vertices)]

  def add_edge(self, source, destination):
    self.adj_list[source].append(destination)

  def dfs(self, start):
    visited = [False] * self.num_vertices

    stack_vertex = []

    visited[start] = True
    stack_vertex.append(start)

    while len(stack_vertex) != 0:
      current = stack_vertex.pop()
      print current,

      for vertex in self.adj_list[current]:
        if (not visited[vertex]):
          visited[vertex] = True
          stack_vertex.append(vertex)


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

print "Depth First Traversal is:",
graph.dfs(0)
print ""

# Expected Output
# Depth First Traversal is: 0 2 3 6 1 4 5 7 
