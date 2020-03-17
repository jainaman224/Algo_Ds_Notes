# Python implementation of Kosaraju's Algorithm 
# Kosaraju's Algorithm is used to print all Strongly Connected Components (SCCs) in a directed graph
# A component is said to be strongly connected if there is a path between all pairs of vertices in it.

# Kosaraju’s Algorithm involves two passes of Depth First Search in order to find the number of SCCs

# defaultdict is a useful technique for building graphs.
from collections import defaultdict 

# Function for first DFS pass and to fill vertices in finishStack
def firstDFS(g, v, visited, finishStack): 
    visited[v] = True
    for i in g[v]: 
        if visited[i] == False: 
            firstDFS(g, i, visited, finishStack) 
    finishStack = finishStack.append(v) 

# Function for second DFS pass
def secondDFS(gt, v, visited): 
    visited[v] = True
    print(v, end = " ")
    for i in gt[v]: 
        if visited[i] == False: 
            secondDFS(gt, i, visited) 

# Create Graph
v = int(input("Enter number of vertices in the graph: "))

# g represents original graph 
g = defaultdict(list)

# gt represents transpose of original graph
gt = defaultdict(list)

e = int(input("Enter number of edges in the graph: "))
for i in range(1 , e + 1):
    print("Edge no. %d - "%(i), end = "")
    num = list(map(int, input(' ').split()))
    g[num[0]].append(num[1])
    gt[num[1]].append(num[0])

# Stack to be filled according to finishing time
finishStack = []

# Maintaining visited array of size v
# All vertices are marked False for first DFS pass
visited = [False] * v

# First DFS on g
for i in range(v): 
    if visited[i] == False: 
        firstDFS(g, i, visited, finishStack)
	
print ("Strongly connected components(SCCs) in the graph are: ") 
	
# Maintaining visited array of size v
# All vertices are marked False for second DFS pass
visited = [False] * v

# Second DFS on gt
while finishStack: 
    i = finishStack.pop() 
    if visited[i] == False: 
        secondDFS(gt, i, visited) 
        print() 
		
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
Strongly connected components(SCCs) in the graph are:
0 2 1
3 5 4
'''
