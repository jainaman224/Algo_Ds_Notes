import sys

Infinity = sys.maxint
graph = [[0, 8, Infinity, 15],[Infinity, 0, 7, Infinity],[Infinity, Infinity, 0, 7],[Infinity, Infinity, Infinity, 0]];
def floydWarshallAlgorithm():
    for k in range(0,4):
        for i in range(0,4):
            for j in range(0,4):
                if graph[i][k] != Infinity and graph[k][j] != Infinity and graph[i][j] > graph[i][k] + graph[k][j]:
                    graph[i][j] = graph[i][k] + graph[k][j]

    displayOutput()
    return
def displayOutput():
    print("The matrix below shows the shortest distances between each pair of vertices");
    for i in range(0,4):
        for j in range(0,4):
            if(graph[i][j] == Infinity):
                print("INFINITY\t")
            else:
                print(str(graph[i][j])+" ")
        print("\n")
    return
floydWarshallAlgorithm()


// Output
//        The matrix below shows the shortest distances between each pair of vertices
//        0           8          15          15
//        INFINITY           0           7          14
//        INFINITY    INFINITY           0           7
//        INFINITY    INFINITY    INFINITY           0
//
//

