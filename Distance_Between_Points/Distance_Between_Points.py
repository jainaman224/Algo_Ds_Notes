'''
DISTANCE BETWEEN COORDINATES

Suppose you are given n co-ordinate points in a 2D plane. The task
is to find the total sum of distance between all those points.
Basically it is computing the perimeter of the complete polygon 
formed by those n co-ordinate points. 

For calculating the distance between two points (x1, y1) & (x2, y2),
we calculate -> sqrt((x1 - x2)^2 + (y1 - y2)^2)
'''

import math

n = int(input())
x = []
y = []
for i in range(0, n):
    x.append(int(input()))
for i in range(0, n):
    y.append(int(input()))
distance = 0
for i in range(0, n):
    for j in range(i + 1, n):
        sq_x = abs(x[i] - x[j])
        sq_y = abs(y[i] - y[j])
        distance = distance + math.sqrt(sq_x * sq_x + sq_y * sq_y)
print(distance)

'''
INPUT :
n = 4
x = [1, 4, 3, 2]
y = [2, 5, 4, 1]
OUTPUT :
17.5339
'''
