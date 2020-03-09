'''
Author: Vedant Wakalkar

Python Program to add two Matrices of size m*n. 
'''

def input_matrix(m,n):
  # m,n -> size of Matrix (m*n)

  mat = []

  for i in range(m):
    # Enter space seperated input for elements of matrix
    # Enter 'n' no. of elemnts row wise and press enter for next row elements
    temp = map(int,input('Elements Row '+str(i+1)+' : ').strip().split(' '))
    mat.append(list(temp))
  return mat

def add_matrices(M1,M2,m,n):
  # parameters: 
  # M1 -> Matrix 1
  # M2 -> Matrix 2
  # m,n -> size of Matrix (m*n)

  mat = []
  for i in range(m):
    tmp = []
    for j in range(n):
      tmp.append([])
    mat.append(tmp)
  for i in range(m):
    for j in range(n):
      mat[i][j] = M1[i][j] + M2[i][j]
  return mat


if __name__ == "__main__":

  # input Matrix of size m*n
  print("\n-- Matrix Size m*n --")
  m = int(input("Enter m : "))
  n = int(input("Enter n : "))
  
  # Input Matrix 1
  print("Input Elements for Matrix1 :")
  M1 = input_matrix(m,n)
  print("Matrix 1:",M1)

  # Input Matrix 2
  print("Input Elements for Matrix2 :")
  M2 = input_matrix(m,n)
  print("Matrix 2:",M2)

  M3 = add_matrices(M1,M2,m,n)
  print("Matrix 1 + Matrix 2 :",M3)

'''
Output: 

  -- Matrix Size m*n --
  Enter m : 2
  Enter n : 2
  
  Input Elements for Matrix1 :
  Elements Row 1 : 1 2
  Elements Row 2 : 3 4
  
  Matrix 1: [[1, 2], [3, 4]]
  
  Input Elements for Matrix2 :
  Elements Row 1 : 4 2
  Elements Row 2 : 3 1
  
  Matrix 2: [[4, 2], [3, 1]]
  
  Matrix 1 + Matrix 2 : [[5, 4], [6, 5]]

'''
