def matrix_product(p):
    """Return m and s.
 
    m[i][j] is the minimum number of scalar multiplications needed to compute the
    product of matrices A(i), A(i + 1), ..., A(j).
 
    s[i][j] is the index of the matrix after which the product is split in an
    optimal parenthesization of the matrix product.
 
    p[0... n] is a list such that matrix A(i) has dimensions p[i - 1] x p[i].
    """
    length = len(p) # len(p) = number of matrices + 1
 
    # m[i][j] is the minimum number of multiplications needed to compute the
    # product of matrices A(i), A(i+1), ..., A(j)
    # s[i][j] is a matrix after which the product is split in the minimum
    # number of multiplications needed
    m = [[-1]*length for _ in range(length)]
    s = [[-1]*length for _ in range(length)]
 
    matrix_product_helper(p, 1, length - 1, m, s)
 
    return m, s
 
 
def matrix_product_helper(p, start, end, m, s):
    """Return minimum number of scalar multiplications needed to compute the
    product of matrices A(start), A(start + 1), ..., A(end).
 
    The minimum number of scalar multiplications needed to compute the
    product of matrices A(i), A(i + 1), ..., A(j) is stored in m[i][j].
 
    The index of the matrix after which the above product is split in an optimal
    parenthesization is stored in s[i][j].
 
    p[0... n] is a list such that matrix A(i) has dimensions p[i - 1] x p[i].
    """
    if m[start][end] >= 0:
        return m[start][end]
 
    if start == end:
        q = 0
    else:
        q = float('inf')
        for k in range(start, end):
            temp = matrix_product_helper(p, start, k, m, s) \
                   + matrix_product_helper(p, k + 1, end, m, s) \
                   + p[start - 1]*p[k]*p[end]
            if q > temp:
                q = temp
                s[start][end] = k
 
    m[start][end] = q
    return q
 
 
def print_parenthesization(s, start, end):
    """Print the optimal parenthesization of the matrix product A(start) x
    A(start + 1) x ... x A(end).
 
    s[i][j] is the index of the matrix after which the product is split in an
    optimal parenthesization of the matrix product.
    """
    if start == end:
        print('A[{}]'.format(start), end='')
        return
 
    k = s[start][end]
 
    print('(', end='')
    print_parenthesization(s, start, k)
    print_parenthesization(s, k + 1, end)
    print(')', end='')
 
 
n = int(input('Enter number of matrices: '))
p = []
for i in range(n):
    temp = int(input('Enter number of rows in matrix {}: '.format(i + 1)))
    p.append(temp)
temp = int(input('Enter number of columns in matrix {}: '.format(n)))
p.append(temp)
 
m, s = matrix_product(p)
print('The number of scalar multiplications needed:', m[1][n])
print('Optimal parenthesization: ', end='')
print_parenthesization(s, 1, n)


#Output- 
 
# Case 1:
# Enter number of matrices: 3
# Enter number of rows in matrix 1: 10
# Enter number of rows in matrix 2: 100
# Enter number of rows in matrix 3: 5
# Enter number of columns in matrix 3: 50
# The number of scalar multiplications needed: 7500
# Optimal parenthesization: ((A[1]A[2])A[3])
 
# Case 2:
# Enter number of matrices: 5
# Enter number of rows in matrix 1: 5
# Enter number of rows in matrix 2: 10
# Enter number of rows in matrix 3: 8
# Enter number of rows in matrix 4: 15
# Enter number of rows in matrix 5: 20
# Enter number of columns in matrix 5: 4
# The number of scalar multiplications needed: 2200
# Optimal parenthesization: (A[1](A[2](A[3](A[4]A[5]))))
 
