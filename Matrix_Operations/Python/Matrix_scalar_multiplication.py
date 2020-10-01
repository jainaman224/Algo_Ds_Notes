'''
Author: Vedant Wakalkar

Python Program to multiply Matrix (of size m*n) with scalar number. 
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

def scalar_multiply(k,M1,m,n):
  # parameters:
  # k -> scalar multiple 
  # M1 -> Matrix 1
  # m,n -> size of Matrix (m*n)

  mat = []
  for i in range(m):
    tmp = []
    for j in range(n):
      tmp.append([])
    mat.append(tmp)
  for i in range(m):
    for j in range(n):
      mat[i][j] = M1[i][j] * k
  return mat


if __name__ == "__main__":

  # input Matrix of size m*n
  print("\n-- Matrix Size m*n --")
  m = int(input("Enter m : "))
  n = int(input("Enter n : "))
  
  # Input Matrix 1
  print("\nInput Elements for Matrix1 :")
  M1 = input_matrix(m,n)
  print("Matrix 1:",M1)

  k = int(input("\nEnter Scalar Multiple : "))

  M2 = scalar_multiply(k,M1,m,n)
  print("\n",k,"X (Matrix 1) : ",M2)

'''
Output: 

  -- Matrix Size m*n --
  Enter m : 2
  Enter n : 2

  Input Elements for Matrix1 :
  Elements Row 1 : 2 4
  Elements Row 2 : 5 7
  Matrix 1: [[2, 4], [5, 7]]

  Enter Scalar Multiple : 5

  5 X (Matrix 1) :  [[10, 20], [25, 35]]

'''
