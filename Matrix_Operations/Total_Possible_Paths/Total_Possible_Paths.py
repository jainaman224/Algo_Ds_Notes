'''
TOTAL PATHS FROM (0, 0) to (m, n)

The task is to calculate total possible moves we can make to reach
(m, n) in a matrix, starting from origin, given that we can only take
1 step towards right or up in a single move.
'''

def totalPaths(m, n):
    total = []
    for i in range(0, m):
        temp = []
        for j in range(0, n):
            temp.append(0)
        total.append(temp)
    for i in range(0, max(m, n)):
        if i < m:
            total[i][0] = 1
        if i < n:
            total[0][i] = 1
    for i in range(1, m):
        for j in range(1, n):
            total[i][j] = total[i - 1][j] + total[i][j - 1]
    return total[m-1][n-1]

m = int(input())
n = int(input())
print("The total paths are", totalPaths(m, n))

'''
INPUT :
n = 6
m = 5
OUTPUT :
The total paths are 126
'''
