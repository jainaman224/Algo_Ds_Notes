
N = 4

# An Inplace function to rotate N x N matrix by 90 degrees in anti-clockwise direction 
def rotateMatrix(mat): 
	
    for x in range(0, int(N/2)): 
		
    # Consider elements in group of 4 in current square 
    for y in range(x, N-x-1): 
			
    # store current cell in temp variable 
    temp = mat[x][y] 

    mat[x][y] = mat[y][N-1-x] 
    mat[y][N-1-x] = mat[N-1-x][N-1-y] 

    # move values from left to bottom 
    mat[N-1-x][N-1-y] = mat[N-1-y][x] 
    # assign temp to left 
    mat[N-1-y][x] = temp 


# Function to print the matrix 
def displayMatrix( mat ): 
	
    for i in range(0, N): 
		
    for j in range(0, N): 
    print (mat[i][j], end = ' ') 
    print ("") 
	
	
# Driver Code 
mat = [[0 for x in range(N)] for y in range(N)] 


# Samplle Input
mat = [ [1, 2, 3, 4 ], [5, 6, 7, 8 ], [9, 10, 11, 12 ], [13, 14, 15, 16 ] ] 

rotateMatrix(mat) 

# Print rotated matrix 
displayMatrix(mat) 

'''
    Sample output :

    4  8 12 16 
    3  7 11 15 
    2  6 10 14 
    1  5  9 13 

'''
