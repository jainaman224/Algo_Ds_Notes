import math

def log(x, base):
    return int( math.log(x) / math.log(base))

def main():

    print("Enter number of elements")
    n = int(input())
    print("Enter the elements")
    arr = list(map(int, input().split()))

    # Building the sparse table
    sparseTable = [[0]*n for i in range(n)]
    # Transferring value from array to sparse table
    for i in range(n):
        sparseTable[i][0] = arr[i]

    j = 1
    while (1 << j) <= n:
        # Compute minimum value for all intervals with size 2^j
        i = 0
        while (i + (1 << j) - 1) < n:
            if sparseTable[i][j-1] < sparseTable[i + (1 << (j-1))][j-1]:
                sparseTable[i][j] = sparseTable[i][j-1]
            else:
                sparseTable[i][j] = sparseTable[i + (1 << (j-1))][j-1]

            i+=1
        j+=1

    # Range Min Query 
    # To find min between L(query start) to R (query end) where 0 <= L <= R <= n-1
    print("Enter the query start")
    L = int(input())
    print("Enter the query end")
    R = int(input())

    j = log(R - L + 1, 2)
    print("The element is: ", end="")

    if sparseTable[L][j] <= sparseTable[R - (1 << j) + 1][j]:
        print(sparseTable[L][j])
    else:
        print(sparseTable[R - (1 << j) + 1][j])
    
if __name__ == '__main__':
    main()

'''
Sample Input:
    Enter the number of elements:
    9
    Enter the elements:
    1 2 3 4 5 6 7 8 9
    Enter the query start 
    2
    Enter the query end 
    7

Sample Output:
    The element is: 3

'''
