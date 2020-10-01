""" STRASSEN"S MATRIX MULTIPLICATION ALGORITHM
Strassen's algorithm implements Matrix Multiplication for a NxN  matrix with a Time complexity of T(n) = O(n^2.81).Hence this algorithm
works faster than other conventional algorithm(Naive matrix multiplication method and Divide and conquer method) having a complexity
of T(n) = O(n^3) """

#Strassen's matrix multiplication Algorithm for NxN matrix
"""Sample Input : 
size: 2
enter elements of first matrix:
1 3
7 5
enter elements of second matrix:
6 8
4 2
"""

#Function to form sub matrices
def split_matrix(a):
    matrix_length = len(a)
    mid = matrix_length // 2
    A00 = [[a[i][j] for j in range(mid)] for i in range(mid)]
    A01 = [[a[i][j] for j in range(mid, matrix_length)] for i in range(mid)]
    A10 = [[a[i][j] for j in range(mid)] for i in range(mid, matrix_length)]
    A11 = [[a[i][j] for j in range(mid, matrix_length)] for i in range(mid, matrix_length)]
    return A00,A01,A10,A11

#Add submatrices
def add_matrix(a, b):
    return [[a[i][j] + b[i][j]
             for j in range(len(a))] for i in range(len(a))]

#Subtract submatrices
def sub_matrix(a, b):
    return [[a[i][j] - b[i][j]
             for j in range(len(a))] for i in range(len(a))]

#Function that implements Strassen's algorithm 
def Strassen(a,b):
    c = []
    if len(a) == 1 :
        c.append([])
        c[0].append(a[0][0] * b[0][0])
    else :
        A00,A01,A10,A11 = split_matrix(a)
        B00,B01,B10,B11 = split_matrix(b)
        p1 = Strassen(add_matrix(A00, A11), add_matrix(B00, B11))
        p2 = Strassen(add_matrix(A10,A11 ), B00)
        p3 = Strassen(A00,sub_matrix(B01,B11))
        p4 = Strassen(A11,sub_matrix(B10,B00))
        p5 = Strassen(add_matrix(A00,A01),B11)
        p6 = Strassen(sub_matrix(A10, A00), add_matrix(B00, B01))
        p7 = Strassen(sub_matrix(A01, A11), add_matrix(B10, B11))
        #form final matrix
        c00 = add_matrix(sub_matrix(add_matrix(p1 , p4), p5), p7)
        c01 = add_matrix(p3, p5)
        c10 = add_matrix(p2, p4)
        c11 = add_matrix(add_matrix(sub_matrix(p1,p2),p3),p6) 

        for i in range(len(c01)):
            c.append(c00[i] + c01[i])
        for i in range(len(c11)):
            c.append(c10[i] + c11[i])
    return c

#Read size
s = int(input("Size"))
#Read elements of first matrix
a = [] 
print("enter elements of first matrix:")
for i in range(s): 
    a.append([]) 
    for j in range(s):
        n =int(input())
        a[i].append(n) 
print(a)
#Read elements of second matrix
b = [] 
print("enter elements of second matrix:")
for i in range(s): 
    b.append([]) 
    for j in range(s):
        n = int(input())        
        b[i].append(n) 
print(b)
print( " Product is ")
print(Strassen(a,b))
      
""" Sample Output:
Product is
18 14
62 66
"""
