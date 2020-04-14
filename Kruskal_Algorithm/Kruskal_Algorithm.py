#Implementation of Kruskal Algorithm using Disjoint 

graphData = []
vertices = []

class Disjoint:
    def __init__(self):
        self.sets = []

    def createSet(self, val):
        self.sets.append([val])

    def getSets(self):
        return self.sets
    
    def findSet(self, val):
        for oneSet in self.sets:
            if val in oneSet:
                return oneSet

    def mergeSets(self, val1, val2):
        set1 = self.findSet(val1)
        set2 = self.findSet(val2)
        if set1 != set2:
            set1.extend(set2)
            self.sets.remove(set2)

def kruskalAlgorithm(vertices, graphData):
    MST = []
    minimumWeight = 0
    
    adisjointSet = Disjoint()                # Creating object of disjoint set
    for vertex in  vertices:
        adisjointSet.createSet(vertex)
    
    graphData.sort()                         # Sort weights in increasing order
    
    for weight, vertex1, vertex2 in graphData:
        if (adisjointSet.findSet(vertex1) != adisjointSet.findSet(vertex2)):
            minimumWeight += weight
            MST.append((weight, vertex1, vertex2))
            adisjointSet.mergeSets(vertex1, vertex2)
        # To improve efficiency
        # when length of disjoint set becomes 1 we can break loop
        if (len(adisjointSet.sets) == 1):
            break
    
    print("Minimum Weight : ", minimumWeight)    
    # To display in which order edges are added    
    for path in MST:
        print((path[1], path[2]), "=>", path[0])
    
if __name__ == "__main__":
    numberOfVertices = int(input("Enter number of vertices in graph : "))
    print("Enter vertices")
    for _ in range(numberOfVertices):
        vertex = input()
        vertices.append(vertex)

    numberOfEdges = int(input("Enter number of edges in graph : "))
    print("Note :=> Enter graph data in following format weight vertex1 vertex2")
    for _ in range(numberOfEdges):
        weights, vertex1, vertex2 = input().split()
        weights = int(weights)
        graphData.append((weights, vertex1, vertex2))
    
    kruskalAlgorithm(vertices, graphData)
    
"""
Input/Output

Enter number of vertices in graph : 5
Enter vertices
a
b
c
d
e
Enter number of edges in graph : 7
Note :=> Enter graph data in following format weight vertex1 vertex2
1 a c
4 a b
2 c b
3 b d
7 c d
5 c e
6 d e
Minimum Weight :  11
('a', 'c') => 1
('c', 'b') => 2
('b', 'd') => 3
('c', 'e') => 5
"""
