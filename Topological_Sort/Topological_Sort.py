class Graph:
    """
    * Creates a adjaceny list for a graph
    * Implements a function for topological sorting
    """

    def __init__(self, no_vertices):
        """
        Initialises an empty adjaceny list (list of lists)
        """

        self.vertices = no_vertices
        self.adjlist = [[] for i in xrange(0, no_vertices)]

    def add_edge(self, vert1, vert2):
        """
        Creates an edge between two vertices
        """

        self.adjlist[vert1].append(vert2)

    def topological_sort_util(self, i, stack, visited):
        """
        Utility function for topological sort
        """

        visited[i] = True
        for node in self.adjlist[i]:
            if not visited[node]:
                self.topological_sort_util(node, stack, visited)

        stack.append(i)

    def topological_sort(self):
        """
        Implements topological sort (DFS based approach)
        """

        stack = []
        visited = [False for i in xrange(0, self.vertices)]

        for i in xrange(0, self.vertices):
            if not visited[i]:
                self.topological_sort_util(i, stack, visited)

        print "Topological Sort : ",
        while len(stack) > 0:
            print stack.pop(),

def main():
    graph = Graph(6)
    graph.add_edge(5, 2);
    graph.add_edge(5, 0);
    graph.add_edge(4, 0);
    graph.add_edge(4, 1);
    graph.add_edge(2, 3);
    graph.add_edge(3, 1);

    graph.topological_sort()

if __name__ == "__main__":
    main()

#OUTPUT
#Topological Sort :  5 4 2 3 1 0
