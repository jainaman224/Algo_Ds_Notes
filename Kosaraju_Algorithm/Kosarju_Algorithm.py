# Python implementation of Kosaraju's Algorithm 
# Kosaraju's Algorithm is used to print all Strongly Connected Components (SCCs) in a directed graph
# A component is said to be strongly connected if there is a path between all pairs of vertices in it.

# Kosaraju’s Algorithm involves two passes of Depth First Search in order to find the number of SCCs

# defaultdict is useful if one tries to access or modify a missing key. In such a case,
# defaultdict will automatically create the key and generate a default value for it. 
# It handles missing keys well.

from collections import defaultdict 

class Graph: 
	def __init__(self,vertices): 
		self.V = vertices 
		self.graph = defaultdict(list) 

	# Function to add edge to graph 
	def add_newEdge(self,u,v): 
		self.graph[u].append(v) 

    	# Function for first DFS pass and to fill vertices in stack 
	def firstDFS(self,v,visited, stack): 
		visited[v] = True
		for i in self.graph[v]: 
			if visited[i] == False: 
				self.firstDFS(i, visited, stack) 
		stack = stack.append(v) 

    	# Function for second DFS pass  
	def secondDFS(self,v,visited): 
		visited[v] = True
		print(v, end = " ")
		for i in self.graph[v]: 
			if visited[i] == False: 
				self.secondDFS(i,visited) 

	# Function to get and print all strongly connected components 
	def get_printSCC(self): 
		stack = [] 

		# First DFS pass
		visited = [False]*(self.V) 
		for i in range(self.V): 
			if visited[i] == False: 
				self.firstDFS(i, visited, stack) 

		# After the first DFS pass reverse the graph
		grev = Graph(self.V) 
		for i in self.graph: 
			for j in self.graph[i]: 
				grev.add_newEdge(j,i) 

		# Second DFS pass
		visited = [False]*(self.V) 
		while stack: 
			i = stack.pop() 
			if visited[i] == False: 
				grev.secondDFS(i, visited) 
				print() 


# Create Graph
v = int(input("Enter number of vertices in the graph: "))
g = Graph(v)
e = int(input("Enter number of edges in the graph: "))
for i in range(1,e+1):
    print("Edge no. %d - "%(i), end = "")
    num = list(map(int, input(' ').split()))
    g.add_newEdge(num[0],num[1])
print ("Strongly connected components in the graph are: ") 
g.get_printSCC() 


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
