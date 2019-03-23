'''
Author: Vedant Wakalkar

Python Program to find Determinant of Square Matrix of size m*m. 
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

def get_cofactor(M,a,b,m):
  co_factor = []
  # temporary co_factor matrix

  for i in range(m):
    tmp = []
    for j in range(m):
      tmp.append(0)
    co_factor.append(tmp)

  i = j = 0 

  # Looping for each element of the matrix 
  for row in range(m): 
    for col in range(m): 
      #  Copying into temporary matrix only those element 
      #  which are not in given row and column 
      if (row != a and col != b): 
        co_factor[i][j] = M[row][col]
        j += 1
        # Row is filled, so increase row index and 
        # reset col index 
        if (j == m - 1): 
          j = 0
          i += 1 
  return co_factor          


def determinant_matrix(M,m):
  # parameters: 
  # M -> Matrix 
  # m -> size of Matrix1 (m*m)
  
  det = 0

  if(m==1):
    return M[0][0]

  sign = 1

  for i in range(m):
    co_factor = get_cofactor(M,0,i,m)
    det += sign * M[0][i] * determinant_matrix(co_factor,m-1) 
    sign *= -1 
  return det


if __name__ == "__main__":

  # input Matrix of size m*n
  print("\n-- Matrix Size m*m --")
  m = int(input("Enter m : "))

  # Input Matrix 1
  print("\nInput Elements for Matrix :")
  M = input_matrix(m,m)
  print("Matrix :",M)

  det = determinant_matrix(M,m)
  print("\nDeterminant of Matrix :",det)

'''
Output: 

  -- Matrix Size m*m --
  Enter m : 2

  Input Elements for Matrix :
  Elements Row 1 : 3 8
  Elements Row 2 : 4 6
  Matrix : [[3, 8], [4, 6]]

  Determinant of Matrix : -14

'''
