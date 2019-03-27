'''
Author: Vedant Wakalkar

Python Program to multipy two Matrices of size m*n and n*o. 
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

def multipy_matrices(M1,M2,m,n,o):
  # parameters: 
  # M1 -> Matrix 1
  # M2 -> Matrix 2
  # m,n -> size of Matrix1 (m*n)
  # n,o -> size of Matrix2 (n*o)

  mat = []
  for i in range(m):
    tmp = []
    for j in range(o):
      tmp.append(0)
    mat.append(tmp)
  for i in range(m):
    for j in range(o):
      for k in range(n):
        mat[i][j] += M1[i][k] * M2[k][j]
  return mat


if __name__ == "__main__":

  # input Matrix of size m*n
  print("\n-- Matrix1 Size m*n  Matrix2 Size n*o --")
  m = int(input("Enter m : "))
  n = int(input("Enter n : "))
  o = int(input("Enter o : "))

  # Input Matrix 1
  print("\nInput Elements for Matrix1 :")
  M1 = input_matrix(m,n)
  print("Matrix 1:",M1)

  # Input Matrix 2
  print("\nInput Elements for Matrix2 :")
  M2 = input_matrix(n,o)
  print("Matrix 2:",M2)

  M3 = multipy_matrices(M1,M2,m,n,o)
  print("\nMatrix 1 * Matrix 2 :",M3)

'''
Output: 

  -- Matrix1 Size m*n  Matrix2 Size n*o --
  Enter m : 3
  Enter n : 3
  Enter o : 4

  Input Elements for Matrix1 :
  Elements Row 1 : 12 7 3
  Elements Row 2 : 4 5 6
  Elements Row 3 : 7 8 9
  Matrix 1: [[12, 7, 3], [4, 5, 6], [7, 8, 9]]

  Input Elements for Matrix2 :
  Elements Row 1 : 5 8 1 2
  Elements Row 2 : 6 7 3 0
  Elements Row 3 : 4 5 9 1
  Matrix 2: [[5, 8, 1, 2], [6, 7, 3, 0], [4, 5, 9, 1]]

  Matrix 1 * Matrix 2 : [[114, 160, 60, 27], [74, 97, 73, 14], [119, 157, 112, 23]]

'''
