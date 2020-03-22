
#OPTIMAL STRATEGY FOR A GAME SET - 1
#Given Problem Statement : Problem statement: Consider a row of n coins of values v1 . . . vn, where n is even.
#We play a game against an opponent by alternating turns. In each turn,
#a player selects either the first or last coin from the row,
#removes it from the row permanently and receives the value of the coin.
#Determine the maximum possible amount of money we can definitely win if we move first.
#Note - Note: The opponent is as clever as the user.

# Returns optimal value possible that 
# a player can collect from an array 
# of coins of size n. Note than n 
# must be even 
def optimalStrategyOfGame(arr, n): 
	
	# Create a table to store 
	# solutions of subproblems 
	table = [[0 for i in range(n)] 
				for i in range(n)] 

	# Fill table using above recursive 
	# formula. Note that the table is 
	# filled in diagonal fashion 
	# (similar to http://goo.gl/PQqoS), 
	# from diagonal elements to 
	# table[0][n-1] which is the result. 
	for gap in range(n): 
		for j in range(gap, n): 
			i = j - gap 
			
			# Here x is value of F(i+2, j), 
			# y is F(i+1, j-1) and z is 
			# F(i, j-2) in above recursive 
			# formula 
			x = 0
			if((i + 2) <= j): 
				x = table[i + 2][j] 
			y = 0
			if((i + 1) <= (j - 1)): 
				y = table[i + 1][j - 1] 
			z = 0
			if(i <= (j - 2)): 
				z = table[i][j - 2] 
			table[i][j] = max(arr[i] + min(x, y), 
							arr[j] + min(y, z)) 
	return table[0][n - 1] 

# Driver Code 
# Enter array
arr = list( map( int , input().split() ) ) 
n = len(arr1) 
print( optimalStrategyOfGame( arr1, n ) ) 

"""
Input for test case 1:
8 15 3 7     //input taken in array
Output for test case 1:
22
"""

"""
Input for test case 2:
2 2 2 2    //input taken in array
Output for test case 2:
4
"""

"""
Input for test case 3:
20 30 2 2 2 10    //input taken in array
Output for test case 3:
42
"""

 
