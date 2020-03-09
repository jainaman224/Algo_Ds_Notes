class BellmanFord:
    """
    Input  : Directed Graph
    Output : Minimum distance from provided source

    Requirements
    ==========================================================
    * Adjency List in the form of a dictionary
         * Note : Each node should have a corresponding key (even if empty)
    * A source
    """

    def __init__(self, adjList, source):
        """
        * Converts the adjlist into tuples with source, destination and weight triplets
        * Intialisses distance
        """

        self.no_vertices = len(adjList.keys())
        self.source = source
        self.edge_list = []
        self.dist = {}
        for node in adjList.keys():
            self.dist[node] = float('inf')           # Sets all distances to inf
            for connected_node in adjList[node].keys():
                self.edge_list.append((node, connected_node, adjList[node][connected_node]))
        self.dist[source] = 0                        # Makes source distance as 0
        self.no_of_edges = len(self.edge_list)

    def run(self):
        """
        Bellmanford Implementation
        """

        for i in xrange(0, self.no_vertices - 1):
            for j in xrange(0, self.no_of_edges):
                start = self.edge_list[j][0]
                end = self.edge_list[j][1]
                weight = self.edge_list[j][2]
                if self.dist[start] + weight < self.dist[end]:
                    self.dist[end] = self.dist[start] + weight

    def get_dist(self):
        """
        Returns distance dictionary
        """

        return self.dist

    def print_dist(self):
        print "Node", "\t\tDistance"
        for each in self.dist.keys():
            print each, "\t\t", self.dist[each]


g = { 'A': {'B': -1, 'C': 4},
      'B': {'C': 3, 'D': 2, 'E': 2},
      'C': {}, 
      'D': {'B': 1, 'C': 5},
      'E': {'D': -3}, 
    }

bellmanford = BellmanFord(g, 'A')
bellmanford.run()
bellmanford.print_dist()

#OUTPUT
#Node 		Distance
#A 		0
#C 		2
#B 		-1
#E 		1
#D 		-2
