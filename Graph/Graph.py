class Graph:
    def __init__(self, nodesCount):
        self.numberOfNodes = nodesCount
        self.adjacencyList = []

        for i in range(self.numberOfNodes):
            self.adjacencyList.append([])

    def addEdge(self, a, b):
        if a >= self.numberOfNodes and b >= self.numberOfNodes:
            raise Exception('Invalid node provided')

        self.adjacencyList[a].append(b)
        self.adjacencyList[b].append(a)
    
    def showConnections(self):
        for i in range(self.numberOfNodes):
            print(i, '--> ', sep='', end='')
            for j in range(len(self.adjacencyList[i])):
                print(self.adjacencyList[i][j], ' ', sep='', end='')
            print()


if __name__ == '__main__':
    graph1 = Graph(7)

    graph1.addEdge(3, 1)
    graph1.addEdge(3, 4)
    graph1.addEdge(4, 2)
    graph1.addEdge(4, 5)
    graph1.addEdge(1, 2)
    graph1.addEdge(1, 0)
    graph1.addEdge(0, 2)
    graph1.addEdge(6, 5)

    graph1.showConnections()


'''
OUTPUT
0--> 1 2 
1--> 3 2 0 
2--> 4 1 0 
3--> 1 4 
4--> 3 2 5 
5--> 4 6 
6--> 5 
'''
