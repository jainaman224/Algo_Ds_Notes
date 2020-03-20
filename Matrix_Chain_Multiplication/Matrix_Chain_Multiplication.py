
# Problem Description: Matrix chain multiplication (or Matrix Chain Ordering Problem, MCOP) is an optimization problem 
# to find the most efficient sequence of multiplying a set of 'n' given matrices. 
# e.g. Multiplying 3 matrices can have the following sequences: ((AB)C) or (A(BC)). 
# Both of the sequences can have different computational cost(number of scalar multiplications) based on the dimensions of the matrices.
# Our goal is to find the sequence with the least computational cost.


def MCM(dims, n):
    table = [ [0] * n for i in range(n) ]

    for L in range(2, n):
        for i in range(1, n - L + 1):
            j = i + L - 1
            table[i][j] = float('inf')
            for k in range(i, j):

                # q = cost/scalar multiplications
                q = table[i][k] + table[k + 1][j] + dims[i - 1] * dims[k] * dims[j]
                if q < table[i][j]:
                    table[i][j] = q

    return table[1][n - 1]

def main():
    
    # Input number of matrices
    print ("Enter the number of matrices: ")
    n = int(input().strip())

    # Input the dimensions of the matrices
    dims = list(map(int, input().strip().split()))
    
    print ("The minimum number of scalar multiplications are: " + str(MCM(dims, n + 1)))



if __name__ == "__main__":
    main()



#         OUTPUT DESCRIPTION

#       P = {10, 20, 30, 40, 30},
#       dimensions of matrix [1] = 10X20,
#       dimensions of matrix [2] = 20X30,
#       dimensions of matrix [3] = 30X40,
#       dimensions of matrix [4] = 40X30


#  This is how table[][] matrix will look like

#         0 6000 18000 30000
#         0 0    24000 48000
#         0 0    0     36000
#         0 0    0     0

# where table[1][size-1]=30000 is the answer.

