from collections import deque

class Graph:
    def __init__(self, num_vertices):
        self.num_vertices = num_vertices
        self.adj_list = [[] for _ in xrange(num_vertices)]

    def addEdge(self, source, destination):
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


def main():
    # Create a graph with 8 vertices
    nodes = int(input())
    graph = Graph(nodes)

    # Create arcs
    edges = int(input())

    for i in range(edges):
        u, v = map(int, raw_input().split())
        graph.addEdge(u, v)

    print "Breadth First Traversal is:",
    graph.bfs(0)
    print ""

if __name__ == '__main__':
    main()

"""
Input:
8
14
0 1
0 2
1 2
1 4
2 0
2 3
3 3
3 6
4 0
4 5
5 6
5 7
6 2
7 3

Output:

Breadth First Traversal is: 0 1 2 4 3 5 6 7
"""
