
class Graph:

    # class init function 
    def __init__(self,nodes):
        self.Nodes = nodes
        self.adj = [[] for i in range(nodes)]

    # function to add Edge in the graph
    def addEdge(self, u, v):
        # as it is a undirected graph
        self.adj[u].append(v)
        self.adj[v].append(u)
		
    # Recursive function to perform DFS on graph using adjacency list
    def DFS(self, vertex, visited):
        # mark the vertex and print it.
        visited[vertex] = True
        print(vertex,end=" ")

        for i in range(len(self.adj[vertex])):
            if not visited[ self.adj[vertex][i] ]:
                self.DFS(self.adj[vertex][i], visited)
				
    # function to find number of connected Components in graph
    def connectedComponents(self):
        connected_components = 1
        visited = [False for i in range(self.Nodes)]

        for vertex in range(self.Nodes):
            # if vertex is not visited perform DFS
            # if vertex is already visited, then it must be part of already visited connected component
            if visited[vertex] == False:
                print("Connected Commponent:",connected_components)
                self.DFS(vertex, visited)
                print()
                connected_components += 1
				
def main():
    # create a graph with 6 nodes vertices numbered from 
    # 0 to 5
    # 	
    # 	0---3  1--4
    # 	|	   |
    # 	2 	   5

    nodes = 6
    graph = Graph(nodes)
    graph.addEdge(0,2)
    graph.addEdge(3,0)
    graph.addEdge(1,4)
    graph.addEdge(5,1)
    graph.connectedComponents()

if __name__ == "__main__":
    main()
	
'''

Output:

    Connected Commponent: 1
    0 2 3 
    Connected Commponent: 2
    1 4 5

'''
