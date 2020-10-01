'''
	Dijkstra's algorithm for weighted undirected graph
'''

from collections import deque

class Dijkstra:
    def __init__(self, graph):
        self.vertex_visited = list()
        self.distance = {}
        self.graph = graph
        self.source = None
        self.queue_size = 0
        self.min_queue = deque()

    def initialise(self):
        self.vertex_visited = list()
        self.distance = {}
        #Initialize vertex cost
        for k,v in self.graph.iteritems():
            if k == self.source:
                self.distance.update({k:0})
            else:
                self.distance.update({k:float('inf')})

        #Store source vetex and cost
        for k,v in self.graph[self.source].iteritems():
            self.priorityQueue({k:v})

    def priorityQueue(self,weight):
        self.min_queue.append(weight)
        self.queue_size = self.queue_size + 1
        self.heapify(self.queue_size)


    def heapify(self,i):
        while i/2 > 0:
            if self.min_queue[i].values() <= self.min_queue[i/2].values():
                temp = self.min_queue[i]
                self.min_queue[i] = self.min_queue[i/2]
                self.min_queue[i/2] = temp
            i = i/2

    def del_min(self):
        popped = self.min_queue[1]
        self.min_queue[1] = self.min_queue[self.queue_size] #Assign last element to first
        self.queue_size = self.queue_size - 1;
        self.min_queue.pop()
        self.re_heapify(1)
        return popped

    def re_heapify(self, i):
        while 2 * i <= self.queue_size:
            mc = self.min_node(i)
            if self.min_queue[mc].values() < self.min_queue[i].values():
                temp = self.min_queue[i]
                self.min_queue[i] = self.min_queue[mc]
                self.min_queue[mc] = temp
            i = mc

    def min_node(self, i):
        if (2 * i + 1) > self.queue_size:
            return 2 * i;
        else:
            if self.min_queue[2 * i].values() < self.min_queue[2 * i + 1].values():
                return 2 * i
            else:
                return 2 * i +1

    def minDistance(self, source):
        self.source = source
        self.min_queue.append({self.source:0}) #Insert source vertex into pq and make its distance as 0.
        self.initialise() # Reset values for new source
        while len(self.min_queue) > 1:
            vertex = self.del_min() #Pop out minimum distance vertex from minimum priority queue
            if vertex not in self.vertex_visited:
                self.vertex_visited.append(vertex)
                for parentNode, parentCost in vertex.iteritems():
                    for adjVertex, adjCost in self.graph[parentNode].iteritems():
                        if adjVertex not in self.distance:
                            self.distance.update({adjVertex:adjCost})
                        else:
                            #Compare
                            if self.distance[adjVertex] > (self.distance[parentNode] + adjCost):
                                self.distance[adjVertex] = self.distance[parentNode] + adjCost
                        self.priorityQueue({adjVertex:adjCost}) #Add to minimum priority queue
        return self.distance



#Graph stored as adjacent list
g = { 'A': {'C': 9, 'B': 7, 'F': 14},
      'B': {'A': 7, 'C': 10, 'D': 15},
      'C': {'A': 9, 'B': 10, 'D': 11, 'F': 2},
      'D': {'E': 6, 'B': 15, 'C': 11},
      'E': {'F': 9, 'D': 6},
      'F': {'C': 2, 'A': 14, 'E': 9}
    }

dijkstra = Dijkstra(g)
print dijkstra.minDistance('A')
print dijkstra.minDistance('E')

'''
Output
-------
{'A': 0, 'C': 9, 'B': 7, 'E': 20, 'D': 20, 'F': 11}
{'A': 26, 'C': 17, 'B': 21, 'E': 0, 'D': 6, 'F': 9}

'''
