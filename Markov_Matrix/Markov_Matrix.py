'''
Markov Matrix is a matrix in which the sum of each row is equal to 1.
'''

def markovMatrix(matrix, row, col):       
    count = 0 
    for i in range(0, row):           
        # Calculating sum of each row
        sum1 = 0
        for j in range(0, col): 
            sum1 = sum1 + matrix[i][j] 
        if (sum1 != 1):
            count = count + 1
    if (count == 0):
        print("YES")
    else: 
        print("NO") 

# Driver program 
row = int(input())
col = int(input())
matrix = []
for i in range(row):  
    a = [] 
    for j in range(col):     
        a.append(float(input())) 
    matrix.append(a) 
markovMatrix(matrix, row, col) 

'''
Input:
row = 2
col = 2
Matrix = {{1, 0},
          {0.5, 0.5}}
Output:
YES
'''
