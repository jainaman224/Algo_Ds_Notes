# Ford-Fulkerson Algorithm

The Ford-Fulkerson algorithm is an algorithm that tackles the max-flow min-cut problem. That is, given a network with vertices and edges between those vertices that have certain weights, how much "flow" can the network process at a time? Flow can mean anything, but typically it means data through a computer network.

It was discovered in 1956 by Ford and Fulkerson. This algorithm is sometimes referred to as a method because parts of its protocol are not fully specified and can vary from implementation to implementation. An algorithm typically refers to a specific protocol for solving a problem, whereas a method is a more general approach to a problem.

The Ford-Fulkerson algorithm assumes that the input will be a graph, GG, along with a source vertex, ss, and a sink vertex, tt. The graph is any representation of a weighted graph where vertices are connected by edges of specified weights. There must also be a source vertex and sink vertex to understand the beginning and end of the flow network.

Ford-Fulkerson has a complexity of O\big(|E| \cdot f^{*}\big),O(∣E∣⋅f 
∗
 ), where f^{*}f 
∗
  is the maximum flow of the network. The Ford-Fulkerson algorithm was eventually improved upon by the Edmonds-Karp algorithm, which does the same thing in O\big(V^2 \cdot E\big)O(V 
2
 ⋅E) time, independent of the maximum flow value.

# Time Complexity
O(max_flow * E)
Time complexity of the above algorithm is O(max_flow * E). We run a loop while there is an augmenting path. In worst case, we may add 1 unit flow in every iteration. Therefore the time complexity becomes O(max_flow * E)

# Implementation

 - # [c code]
 - # [coffee code]
 - # [cpp code]
 - # [c# code]
 - # [go code]
 - # [java code]
 - # [javaScript code]
 - # [kotlin code]
 - # [python code]
 - # [ruby code]
 - # [dart code]



   [c code]: https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Ford_Fulkerson_Method/Ford_Fulkerson_Method.c
   [cpp code]: https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Ford_Fulkerson_Method/Ford-Fulkerson.cpp
   [java code]: https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Ford_Fulkerson_Method/Ford_Fulkerson_Method.java
   [python code]: https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Ford_Fulkerson_Method/Ford_Fulkerson_Method.java
   
  
## PSEUDOCODE

The pseudo-code for this method is quite short; however, there are some functions that bear further discussion. The simple pseudo-code is below.

This pseudo-code is not written in any specific computer language. Instead, it is an informal, high-level description of the algorithm.

Ford-Fulkerson Algorithm ((Graph GG, source ss, sink t):t):
```
initialize flow to 0
path = findAugmentingPath(G, s, t)
while path exists:
    augment flow along path                 #This is purposefully ambiguous for now
    G_f = createResidualGraph()
    path = findAugmentingPath(G_f, s, t)
return flow
```

## ALGORITHM
This algorithm is more well-defined. The only ambiguous point is the 'foward edge' terminology on line 8. When a residual graph, G_fG 
f
​	
 , is created, edges can be created that go in the opposite direction when compared to the original graph. An edge is a 'forward edge' if the edge existed in the original graph, GG. If it is a reversal of an original edge, it is called a 'backwards edge.'
```
flow = 0
for each edge (u, v) in G:
    flow(u, v) = 0
while there is a path, p, from s -> t in residual network G_f:
    residual_capacity(p) = min(residual_capacity(u, v) : for (u, v) in p)
    flow = flow + residual_capacity(p)
    for each edge (u, v) in p:
        if (u, v) is a forward edge:
            flow(u, v) = flow(u, v) + residual_capacity(p)
        else:
            flow(u, v) = flow(u, v) - residual_capacity(p)
return flow
```



python implementation:

```
class Vertex:
    def __init__(self, name, source=False, sink=False):
        self.name = name
        self.source = source
        self.sink = sink

class Edge:
    def __init__(self, start, end, capacity):
        self.start = start
        self.end = end
        self.capacity = capacity
        self.flow = 0
        self.returnEdge = None

class FlowNetwork:
    def __init__(self):
        self.vertices = []
        self.network = {}

    def getSource(self):
        for vertex in self.vertices:
            if vertex.source == True:
                return vertex
        return None

    def getSink(self):
        for vertex in self.vertices:
            if vertex.sink == True:
                return vertex
        return None

    def getVertex(self, name):
        for vertex in self.vertices:
            if name == vertex.name:
                return vertex

    def vertexInNetwork(self, name):
        for vertex in self.vertices:
            if vertex.name == name:
                return True
        return False

    def getEdges(self):
        allEdges = []
        for vertex in self.network:
            for edge in self.network[vertex]:
                allEdges.append(edge)
        return allEdges

    def addVertex(self, name, source=False, sink=False):
        if source == True and sink == True:
            return "Vertex cannot be source and sink"
        if self.vertexInNetwork(name):
            return "Duplicate vertex"
        if source == True:
            if self.getSource() != None:
                return "Source already Exists"
        if sink == True:
            if self.getSink() != None:
                return "Sink already Exists"
        newVertex = Vertex(name, source, sink)
        self.vertices.append(newVertex)
        self.network[newVertex.name] = []

    def addEdge(self, start, end, capacity):
        if start == end:
            return "Cannot have same start and end"
        if self.vertexInNetwork(start) == False:
            return "Start vertex has not been added yet"
        if self.vertexInNetwork(end) == False:
            return "End vertex has not been added yet"
        newEdge = Edge(start, end, capacity)
        returnEdge = Edge(end, start, 0)
        newEdge.returnEdge = returnEdge
        returnEdge.returnEdge = newEdge
        vertex = self.getVertex(start)
        self.network[vertex.name].append(newEdge)
        returnVertex = self.getVertex(end)
        self.network[returnVertex.name].append(returnEdge)

    def getPath(self, start, end, path):
        if start == end:
            return path
        for edge in self.network[start]:
            residualCapacity = edge.capacity - edge.flow
            if residualCapacity > 0 and not (edge, residualCapacity) in path:
                result = self.getPath(edge.end, end, path + [(edge, residualCapacity)])
                if result != None:
                    return result

    def calculateMaxFlow(self):
        source = self.getSource()
        sink = self.getSink()
        if source == None or sink == None:
            return "Network does not have source and sink"
        path = self.getPath(source.name, sink.name, [])
        while path != None:
            flow = min(edge[1] for edge in path)
            for edge, res in path:
                edge.flow += flow
                edge.returnEdge.flow -= flow
            path = self.getPath(source.name, sink.name, [])
        return sum(edge.flow for edge in self.network[source.name])
```
