# Python implementation of Kosaraju's algorithm 
# It is used to print all Strongly Connected Components (SCCs) in a directed graph
# A component is said to be strongly connected if there is a path between all pairs of vertices in it
from collections import defaultdict 

# Adjacency list representation of directed graph using class - Graph 
class Graph: 
	def __init__(self,vertices): 
		self.V = vertices 
		self.graph = defaultdict(list) 

	# Function to add edge to graph 
	def addEdge(self,u,v): 
		self.graph[u].append(v) 
				
    # Function to fill vertices in stack 
	def fillStack(self,v,visited, stack): 
		# Mark current vertex as visited 
		visited[v] = True
		# Recur for vertices adjacent to this vertex 
		for i in self.graph[v]: 
			if visited[i] == False: 
				self.fillStack(i, visited, stack) 
		stack = stack.append(v) 
	
	# Function to return reverse of the graph 
	def getReverse(self): 
		g = Graph(self.V) 
		# Recur for all the vertices adjacent to this vertex 
		for i in self.graph: 
			for j in self.graph[i]: 
				g.addEdge(j,i) 
		return g 

    # function for DFS traversal
	def DFS(self,v,visited): 
		# Mark current vertex as visited and print it 
		visited[v] = True
		print(v, end = " ")
		# Recur for all vertices adjacent to this vertex 
		for i in self.graph[v]: 
			if visited[i] == False: 
				self.DFS(i,visited) 

	# Function to print all strongly connected components 
	def printSCC(self): 
		stack = [] 
		# Mark all the vertices as not visited (For first DFS) 
		visited = [False]*(self.V) 
		# Fill vertices in stack according to their finishing times 
		for i in range(self.V): 
			if visited[i] == False: 
				self.fillStack(i, visited, stack) 
		# Create a reversed graph 
		gr = self.getReverse() 
		# Mark all the vertices as not visited (For second DFS) 
		visited = [False]*(self.V) 
		# Process all vertices in order defined by Stack 
		while stack: 
			i = stack.pop() 
			if visited[i] == False: 
				gr.DFS(i, visited) 
				print() 


# Create Graph
v = int(input("Enter number of vertices in the graph: "))
g = Graph(v)
e = int(input("Enter number of edges in the graph: "))
for i in range(1,e+1):
    print("Edge no. %d - "%(i), end = "")
    num = list(map(int, input(' ').split()))
    g.addEdge(num[0],num[1])
print ("Strongly connected components in the graph are: ") 
g.printSCC() 
 

'''
Sample Input:
Enter number of vertices in the graph: 6
Enter number of edges in the graph: 7
Edge no. 1 - 0 1
Edge no. 2 - 1 2
Edge no. 3 - 2 0
Edge no. 4 - 2 3
Edge no. 5 - 3 4
Edge no. 6 - 4 5
Edge no. 7 - 5 3

Sample Output:
Strongly connected components in the graph are:
0 2 1
3 5 4
'''
