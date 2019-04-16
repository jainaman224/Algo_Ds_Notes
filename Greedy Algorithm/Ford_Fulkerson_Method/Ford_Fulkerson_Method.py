# Ford Fulkerson MAx Flow Python Implementation
# Referred from: Wikipiedia

class Edge(object):
    def __init__(self, u, v, w):
        self.source = u
        self.sink = v
        self.capacity = w
    def __repr__(self):
        return "%s->%s:%s" % (self.source, self.sink, self.capacity)

class FlowNetwork(object):
    def __init__(self):
        self.adj = {}
        self.flow = {}

    def add_vertex(self, vertex):
        self.adj[vertex] = []

    def get_edges(self, v):
        return self.adj[v]

    def add_edge(self, u, v, w=0):
        if u == v:
            raise ValueError("u == v")
        edge = Edge(u,v,w)
        redge = Edge(v,u,0)
        edge.redge = redge
        redge.redge = edge
        self.adj[u].append(edge)
        self.adj[v].append(redge)
        self.flow[edge] = 0
        self.flow[redge] = 0

    def find_path(self, source, sink, path):
        if source == sink:
            return path
        for edge in self.get_edges(source):
            residual = edge.capacity - self.flow[edge]
            if residual > 0 and edge not in path:
                result = self.find_path( edge.sink, sink, path + [edge])
                if result != None:
                    return result

    def max_flow(self, source, sink):
        path = self.find_path(source, sink, [])
        while path != None:
            residuals = [edge.capacity - self.flow[edge] for edge in path]
            flow = min(residuals)
            for edge in path:
                self.flow[edge] += flow
                self.flow[edge.redge] -= flow
            path = self.find_path(source, sink, [])
        return sum(self.flow[edge] for edge in self.get_edges(source))

if __name__ != "":
    g = FlowNetwork()
    [g.add_vertex(v) for v in "sopqrt"]
    g.add_edge('s','o',3)
    g.add_edge('s','p',3)
    g.add_edge('o','p',2)
    g.add_edge('o','q',3)
    g.add_edge('p','r',2)
    g.add_edge('r','t',3)
    g.add_edge('q','r',4)
    g.add_edge('q','t',2)
    print "The maximum possible flow is: " + str(g.max_flow('s','t'))

# Output For Given Graph: The maximum possible flow is: 5
#
#               +------+                           +------+
#      3/3      |      |           3/3             |      |     2/2
#    +---------->  o   +--------------------------->  q   +--------+
#    |          |      |                           |      |        |
#    |          +------+                           +------+        |
# +-----+           |                                  |        +--v--+
# |     |           |                                  |        |     |
# |  s  |           |0/2                             1/4        |  t  |
# |     |           |                                  |        |     |
# +-----+           |                                  |        +-----+
#    |              |                                  |           ^
#    |          +---v--+                           +---v--+        |
#    |          |      |                           |      |        |
#    +---------->   p  +--------------------------->   r  +--------+
#       2/3     |      |           2/2             |      |      3/3
#               +------+                           +------+
