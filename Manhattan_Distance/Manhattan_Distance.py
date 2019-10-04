'''
MANHATTAN DISTANCE

In a 2D plane, the manhattan distance is equal to the distance needed
to be covered using only vertical and horizontal steps.

M(p1, p2) = |p1.x - p2.x| + |p1.y - p2.y|

Given an array of co-ordinates. find the sum of manhattan distances 
of all the coordinates with each other.
'''

def Manhattan(x, y, i, j):
    return int((abs(x[i] - x[j]) + abs(y[i] - y[j])))

def ManhattanSum(x, y, n):
    ans = 0
    for i in range(0, n):
        for j in range(i + 1, n):
            ans = ans + Manhattan(x, y, i, j)
    return ans

n = int(input())
x = []
y = []
for i in range(0, n):
    x.append(int(input()))
for i in range(0, n):
    y.append(int(input()))

print(ManhattanSum(x, y, n))

'''
INPUT
x = [3, 3, 2, -2]
y = [6, -5, 0, 2]
OUTPUT
51
'''
