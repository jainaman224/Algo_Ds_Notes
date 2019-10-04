'''
    Number of Islands Problem is a problem to compute the count
    of number of disconnected islands present in the sea i.e
    Given an adjacency matrix, it is count of number of connected
    components in that graph.
'''

# Function to perform DFS from a cell
def dfs(i, j, adj, N, M, visited):
    # perform DFS when all the values of i and j
    # fall within the matrix
    if i >= 0 and i < N and j >= 0 and j < M:
        '''
            Check for an edge of the current cell with
            all the neighbouring 8 cells in the matrix 
            and it is not visited, perform DFS from that cell, 
            and mark the cell as visited.
        '''
        if adj[i][j] == '1' and visited[i][j] == 0:
            visited[i][j] = 1

            # Cell to the upper left diagonal of current cell
            dfs(i - 1, j - 1, adj, N, M, visited);
            # Cell to the upper right diagonal of current cell
            dfs(i - 1, j + 1, adj, N, M, visited);
            # Cell to the up of current cell
            dfs(i - 1, j, adj, N, M, visited);
            # Cell to the down of current cell
            dfs(i + 1, j, adj, N, M, visited);
            # Cell to the left of current cell 
            dfs(i, j - 1, adj, N, M, visited);
            # Cell to the right of current cell
            dfs(i, j + 1, adj, N, M, visited);
            # Cell to the lower left diagonal of current cell
            dfs(i + 1, j - 1, adj, N, M, visited);
            # Cell to the lower right diagonal of current cell
            dfs(i + 1, j + 1, adj, N, M, visited);
        
# Function to compute number of connected components 
# using Adjacency Matrix Representation of Graph
def numberOfIslands(adj, N, M):
    # A 2D Matrix to keep track of visited cells
    # Initialising all cells with false initially
    visited = [ [0] * M for i in range(0, N)]

    # Variable for storing count of components of Graphs
    components = 0;
    for i in range(0, N):
        for j in range(0, M):
            '''
                if there is an edge between i - j and it is
                not visited, perform DFS from that cell, then
                increase the number of connected components by 1.
            '''
            if adj[i][j] == '1' and visited[i][j] == 0: 
                dfs(i, j, adj, N, M, visited)
                components = components + 1
    return components

# Driver Code
# N is the number of rows
# M is the numbers of columns
N, M = input().split()
N = int(N)
M = int(M)

# Adjacency Matrix representation of Graph in adj
adj = [ [ j for j in input().split(' ')] for i in range(0, N)] 

# Call to compute the number of Islands
print("Number Of Islands: ")
print(numberOfIslands(adj, N, M))

'''
    Input:
    4 6
    1 1 0 0 0 0
    0 1 0 0 1 1
    0 0 0 0 1 1
    1 1 0 0 0 0

    Output:
    Number Of Islands: 3
'''
