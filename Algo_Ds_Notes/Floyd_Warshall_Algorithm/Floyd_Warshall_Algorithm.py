class FloydWarshall:
    """
    Implements : Floyd Warshall Algorithm
    Inputs     : Adjaceny Matrix (list of lists)
    Outputs    : Shortest distance between all pairs
    """

    def __init__(self, adj_matrix):
        """
        Initialises distance matrix (list of lists)
        """

        self.adj_matrix = adj_matrix
        self.distance = adj_matrix
        self.num_vertices = len(adj_matrix)

    def run(self):
        """"
        Implements Floyd Warshall Algorithm
        """

        for k in xrange(0, self.num_vertices):
            for i in xrange(0, self.num_vertices):
                for j in xrange(0, self.num_vertices):
                    if self.distance[i][k] + self.distance[k][j] < self.distance[i][j]:
                        self.distance[i][j] = self.distance[i][k] + self.distance[k][j]

    def get_distance(self):
        """
        Returns the distance list
        """

        return self.distance

    def print_distance(self):
        for node in self.distance:
            for each in node:
                print each,
            print

def main():
    graph = [[0, 5, float('inf'), 10],
             [float('inf'), 0, 3, float('inf')],
             [float('inf'), float('inf'), 0, 1],
             [float('inf'), float('inf'), float('inf'), 0]]


    floyd = FloydWarshall(graph)
    floyd.run()
    floyd.print_distance()

if __name__ == '__main__':
    main()

#OUTPUT
#0 5 8 9
#inf 0 3 4
#inf inf 0 1
#inf inf inf 0
