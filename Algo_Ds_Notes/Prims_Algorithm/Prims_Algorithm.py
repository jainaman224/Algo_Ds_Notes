# Prim's algorithm is a greedy algorithm that
# finds a minimum spanning tree
# for a weighted undirected graph.
#
# Time complexity: O(m * n)

# Input Format:
# First line has two integers, denoting the number of nodes in the graph and
# denoting the number of edges in the graph.
# The next  lines each consist of three space separated integers,
# where  and  denote the two nodes between which the undirected edge
# exists, denotes the length of edge between the corresponding nodes.

# Output Format:
# Single integer denoting the weight of MST

def popmin(pqueue):
    lowest = 1000
    keylowest = None
    for key in pqueue:
        if pqueue[key] < lowest:
            lowest = pqueue[key]
            keylowest = key
    del pqueue[keylowest]
    return keylowest

def prim(graph, root):
    pred = {} # pair {vertex: predecesor in MST}
    key = {}  # keep track of minimum weight for each vertex
    pqueue = {} # priority queue implemented as dictionary

    for v in graph:
        pred[v] = -1
        key[v] = 1000
    key[root] = 0
    for v in graph:
        pqueue[v] = key[v]

    while pqueue:
        u = popmin(pqueue)
        for v in graph[u]: # all neighbors of v
            if v in pqueue and graph[u][v] < key[v]:
                pred[v] = u
                key[v] = graph[u][v]
                pqueue[v] = graph[u][v]
    return pred

graph = {
            0 : {1:6, 2:8},
            1 : {4:11},
            2 : {3:9},
            3 : {},
            4 : {5:3},
            5 : {2:7, 3:4}
        }

pred = prim(graph, 0)
for v in pred: print (v, pred[v])

# Output format:
# 0: -1
# 1: 0
# 2: 0
# 3: 2
# 4: 1
# 5: 4
