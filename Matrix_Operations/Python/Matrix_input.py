'''
Author: Vedant Wakalkar

Python Program to take Matrix Input of size m*n. 
'''

def input_matrix():
  # input Matrix of size m*n
  print("-- Matrix Size m*n --")
  m = int(input("Enter m : "))
  n = int(input("Enter n : "))

  mat = []

  for i in range(m):
    # Enter space seperated input for elements of matrix
    # Enter 'n' no. of elemnts row wise and press enter for next row elements
    temp = map(int,input('Elements Row '+str(i+1)+' : ').strip().split(' '))
    mat.append(list(temp))
  return mat

if __name__ == "__main__":

  M1 = input_matrix()
  print("Matrix :",M1)


'''
Output: 

  -- Matrix Size m*n --
  Enter m : 2
  Enter n : 2
  Elements Row 1 : 1 2
  Elements Row 2 : 3 4
  Matrix : [[1, 2], [3, 4]]

'''
