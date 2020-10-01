'''
Compute the shortest distance between two cells in a matrix namely the source and destination cells, where only certain moves like up, down, left and right are allowed. 
The cell marked as '2' is the source
The cell marked as '3' is the destination
The cells marked as '1', where a move is allowed.
The cells marked as '0' are forbidden, hence move is not allowed
'''
import queue
INF = 10000

class Node:
    def __init__(self, i, j): 
        self.row_num = i
        self.col_num = j


# Function to compute minimum distance between source and destination using BFS
def findDistance(row, col, mat):
    # Variable to store the information about source and destination
    source_i = 0
    source_j = 0
    destination_i = 0
    destination_j = 0
    # Loop to find out the source and destination
    for i in range(0, row):
        for j in range(0, col):
            # Cell marked as 2 is the source
            if mat[i][j] == 2 :
                source_i = i
                source_j = j
            # cell marked as 3 is the destination
            if mat[i][j] == 3 :
                destination_i = i
                destination_j = j

    # dist matrix will store information about the distance of a cell from source
    # initialising dist matrix as some large value
    dist = []
    for i in range(0, row):
        sublist = []
        for j in range(0, col):
            sublist.append(INF)
        dist.append(sublist)

    # initialise queue to start BFS on matrix
    q = queue.Queue()
    source = Node(source_i, source_j)
    q.put(source)
    dist[source_i][source_j] = 0

    # modified BFS by add constraint checks
    while (not q.empty()):
         # extract and remove the node from the front of queue
        temp = q.get()
        x = temp.row_num
        y = temp.col_num

        # If move towards left is allowed or it is the destnation cell
        if y - 1 >= 0 and (mat[x][y - 1] == 1 or mat[x][y - 1] == 3) :
	    # if distance to reach the cell to the left is less than the computed previous path distance, update it
            if dist[x][y] + 1 < dist[x][y - 1] :
                dist[x][y - 1] = dist[x][y] + 1
                next = Node(x, y - 1)
                q.put(next)

        # If move towards right is allowed or it is the destination cell
        if y + 1 < col and (mat[x][y + 1] == 1 or mat[x][y + 1] == 3) :
            # if distance to reach the cell to the right is less than the computed previous path distance, update it
            if dist[x][y] + 1 < dist[x][y + 1] :
                dist[x][y + 1] = dist[x][y] + 1
                next = Node(x, y + 1)
                q.put(next);

        # If move towards up is allowed or it is the destination cell
        if x - 1 >= 0 and (mat[x - 1][y] == 1 or mat[x-1][y] == 3) :
            # if distance to reach the cell to the up is less than the computed previous path distance, update it
            if dist[x][y] + 1 < dist[x - 1][y] :
                dist[x - 1][y] = dist[x][y] + 1
                next = Node(x - 1, y)
                q.put(next)

        # If move towards down is allowed or it is the destination cell
        if x + 1 < row and (mat[x + 1][y] == 1 or mat[x+1][y] == 3) :
            # if distance to reach the cell to the down is less than the computed previous path distance, update it
            if dist[x][y] + 1 < dist[x + 1][y] :
                dist[x + 1][y] = dist[x][y] + 1
                next = Node(x + 1, y)
                q.put(next)
    return dist[destination_i][destination_j]

# initialising number of rows and columns
row = 5
col = 5
# initialising matrix 
mat = [ [1, 0, 0, 2, 1],
        [1, 0, 1, 1, 1],
        [0, 1, 1, 1, 0],
        [3, 1, 0, 0, 1],
        [1, 1, 0, 0, 1] ]

# Call to function to compute distance between source and destination
answer = findDistance(row, col, mat);
# When source and destination are unreachable
if answer == INF :
    print("No Path present between source and destination")
else:
    # When source and destination are reachable, print shortest distance between them
    print("The Shortest Distance between Source and Destination is:")
    print(answer)
    
'''
Input:
[1, 0, 0, 2, 1]
[1, 0, 1, 1, 1]
[0, 1, 1, 1, 0]
[3, 1, 0, 0, 1]
[1, 1, 0, 0, 1]

Output:
The Shortest Distance between Source and Destination is:
6
'''
