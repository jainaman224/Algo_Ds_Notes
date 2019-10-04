N = 3

# A function to rotate N x N matrix by 90 degrees in anti-clockwise direction 
def Rotate(Matrix): 
    
    a = int(N/2)
    for x in range(0, a): 
        
    # elements in group of 4 in square 
        for y in range(x, N-x-1): 
        
            t = Matrix[x][y] 
            Matrix[x][y] = Matrix[y][N-1-x] 
            Matrix[y][N-1-x] = Matrix[N-1-x][N-1-y] 
            Matrix[N-1-x][N-1-y] = Matrix[N-1-y][x] 
            Matrix[N-1-y][x] = t 
            
# Sample Input
Matrix = [ [1, 2, 3], [5, 6, 7], [9, 10, 11 ] ] 

Rotate(Matrix) 

for i in range(0, N): 
    
    for j in range(0, N): 
        print (Matrix[i][j]) 

    print ("") 

'''
    Sample output :

    3
    7
    11

    2
    6
    10

    1
    5
    9
'''
