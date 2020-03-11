class Graph:
    def __init__(self):
        # Dictionary with keys mapping to respective vertex object
        self.vertices = {}
 
    def add_v(self, k):
        # Adding a vertex with the given key to the graph
        vertex = Vertex(k)
        self.vertices[k] = vertex
 
    def get_v(self, k):
        # Returns vertex object with respective key
        return self.vertices[k]
 
    def __contains__(self, k):
        return k in self.vertices
 
    def add_e(self, source_k, destination_k, w=1):
        # Adding edge from source to destination key with given weight
        self.vertices[source_k].add_n(self.vertices[destination_k], w)
 
    def does_e(self, source_k, destination_k):
        #Returns True if there is an edge from source to destination key
        return self.vertices[source_k].does_point(self.vertices[destination_k])
 
    def __len__(self):
        return len(self.vertices)
 
    def __iter__(self):
        return iter(self.vertices.values())

class Vertex:
    def __init__(self, k):
        self.k = k
        self.points = {}
 
    def get_k(self):
        # Returns key corresponding to this vertex object
        return self.k
 
    def add_n(self, destination, w):
        # Making this vertex point to destination with given edge weight
        self.points[destination] = w
 
    def get_n(self):
        # Returns all vertices pointed to by this vertex
        return self.points.keys()
 
    def get_w(self, destination):
        # Getting weight of edge from this vertex to destination vertex
        return self.points[destination]
 
    def set_w(self, destination, w):
        # Setting weight of edge from this vertex to destination vertex
        self.points[destination] = w
 
    def does_point(self, destination):
        # Returns True if this vertex points to destination vertex
        return destination in self.points
 
 def johnson(g):
    # Returns distance where d[u][v] is the min distance from u to v
    # Adding new vertex q
    g.add_v('q')
    # Making q point to all other vertices with zero-weight edges
    for v in g:
        g.add_e('q', v.get_k(), 0)
    # Shortest distance from q to other vertices
    bell_dist = bellman_ford(g, g.get_v('q'))
    # Setting weight of u, v = weight of (u, v) + bell_dist of (u) - bell_dist of (v) for each edge
    for v in g:
        for n in v.get_n():
            z = v.get_w(n)
            v.set_w(n, z + bell_dist[v] - bell_dist[n])
    # Deleting vertex q
    del g.vertices['q']
    # d[u][v] has the minimum distance from u to v
    d = {}
    # Applying dijktra's algorithm on all vertices
    for v in g:
        d[v] = dijkstra(g, v)
    # Correcting the distances
    for v in g:
        for z in g:
            d[v][z] += bell_dist[z] - bell_dist[v]
    # Correcting weights in original graph
    for v in g:
        for n in v.get_n():
            z = v.get_w(n)
            v.set_w(n, w + bell_dist[n] - bell_dist[v])
     return d
 
 def bellman_ford(g, source):
    # Returns d where d[v] is minimum distance from source to v
    d = dict.fromkeys(g, float('inf'))
    d[source] = 0
    for _ in range(len(g) - 1):
        for v in g:
            for n in v.get_n():
                d[n] = min(d[n], d[v] + v.get_w(n))
    return d
 
def dijkstra(g, source):
    # Returns d where d[v] is minimum distance from source to v
    unvisited = set(g)
    d = dict.fromkeys(g, float('inf'))
    d[source] = 0
    while unvisited != set():
        # Finding vertex with minimum distance
        closest = min(unvisited, key=lambda v: d[v])
        # Marking as visited
        unvisited.remove(closest)
        # Updating distances
        for neighbour in closest.get_n():
            if neighbour in unvisited:
                new_d = d[closest] + closest.get_w(neighbour)
                if d[neighbour] > new_d:
                    d[neighbour] = new_d
    return d
 
g = Graph()
print('To add vertex, enter: add vertex <key>')
print('To add edge, enter: add edge <source key> <destination key> <weight>')
print('To apply Johnson algorithm, enter: johnson')
print('To quit, enter: quit')
while True:
    do = input('What would you like to do? ').split()
    operation = do[0]
    if operation == 'add':
        suboperation = do[1]
        if suboperation == 'vertex':
            k = int(do[2])
            if k not in g:
                g.add_v(k)
            else:
                print('Vertex already exists.')
        elif suboperation == 'edge':
            source = int(do[2])
            destination = int(do[3])
            w = int(do[4])
            if source not in g:
                print('Vertex {} does not exist.'.format(source))
            elif destination not in g:
                print('Vertex {} does not exist.'.format(destination))
            else:
                if not g.does_e(source, destination):
                    g.add_e(source, destination, w)
                else:
                    print('Edge already exists.')
    elif operation == 'johnson':
        d = johnson(g)
        print('Shortest distances:')
        for start in g:
            for end in g:
                print('{} to {}'.format(start.get_k(), end.get_k()), end=' ')
                print('distance {}'.format(d[start][end]))
    elif operation == 'display':
        print('Vertices: ', end='')
        for v in g:
            print(v.get_k(), end=' ')
        print()
        print('Edges: ')
        for v in g:
            for destination in v.get_n():
                z = v.get_w(destination)
                print('(source={}, destination={}, w={}) '.format(v.get_k(),destination.get_k(), z))
                print()
    elif operation == 'quit':
        break

""" Sample Input and Output:
To add vertex, enter: add vertex <key>
To add edge, enter: add edge <source key> <destination key> <weight>
To apply Johnson algorithm, enter: johnson
To quit, enter: quit

What would you like to do? add vertex 1
What would you like to do? add vertex 2
What would you like to do? add vertex 3
What would you like to do? add edge 1 2 20
What would you like to do? add edge 2 3 70
What would you like to do? add edge 3 1 10
What would you like to do? johnson
Shortest distances:
1 to 1 distance 0
1 to 2 distance 20
1 to 3 distance 90
2 to 1 distance 80
2 to 2 distance 0
2 to 3 distance 70
3 to 1 distance 10
3 to 2 distance 30
3 to 3 distance 0 """
