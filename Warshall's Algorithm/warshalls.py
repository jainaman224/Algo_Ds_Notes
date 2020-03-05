# Python Program for Floyd Warshall Algorithm 
# Number of vertices in the graph 
V = 4
# Define infinity as the large enough value. This value will be 
# used for vertices not connected to each other 
INF = 99999
def floydWarshall(graph): 
	dist = map(lambda i : map(lambda j : j , i) , graph) 
	for k in range(V): 
  # pick all vertices as source one by one 
		for i in range(V): 
    # Pick all vertices as destination for the 
			# above picked source 
			for j in range(V): 

				# If vertex k is on the shortest path from 
				# i to j, then update the value of dist[i][j] 
				dist[i][j] = min(dist[i][j] , 
								dist[i][k]+ dist[k][j] 
								) 
	printSolution(dist) 
# A utility function to print the solution 
def printSolution(dist): 
	print "Following matrix shows the shortest distances\ 
between every pair of vertices" 
	for i in range(V): 
		for j in range(V): 
			if(dist[i][j] == INF): 
				print "%7s" %("INF"), 
			else: 
				print "%7d\t" %(dist[i][j]), 
			if j == V-1: 
				print "" 
graph = [[0,5,INF,10], 
			[INF,0,3,INF], 
			[INF, INF, 0, 1], 
			[INF, INF, INF, 0] 
		]  
floydWarshall(graph); 

