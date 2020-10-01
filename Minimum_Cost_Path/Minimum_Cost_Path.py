'''
Finding minimum cost path in 2-D array "array[][]" to reach a position (left, right)
in array[][] from (0, 0).
Total cost of a path to reach (left, right) is sum of all the costs on that 
path (including both source and destination).
'''

import sys 

#  Finding minimum cost path in 2-D array
def minimumCost(array, left, right): 
    # For invalid left and right query
    if (left < 0 or right < 0):
        return sys.maxsize
    elif (left == 0 and right == 0):
        return array[left][right] 
    else:
        # Finding path with minimum cost i.e. which way to move down, right and diagonally lower cells
        x = minimumCost(array, left - 1, right - 1)
        y = minimumCost(array, left - 1, right)
        z = minimumCost(array, left, right - 1)
        if (x < y): 
            minimum = x if (x < z) else z 
        else: 
            minimum = y if (y < z) else z
        return array[left][right] + minimum 
  
# Driver program 
row = int(input())
col = int(input())
array = []
for i in range(row):  
    a = [] 
    for j in range(col):     
         a.append(int(input())) 
    array.append(a) 
left = int(input())
right = int(input())
print(minimumCost(array, left, right)) 

'''
Input:
row = 3
col = 3
array = {{1, 2, 3},
         {4, 5, 6},
         {7, 8, 9}}
left = 2
right = 2
Output:
15
Because to reach from (0, 0) to (2, 2)
the cost for minimum path is (0, 0) –> (1, 1) –> (2, 2); 1 + 5 + 9 = 15
'''
