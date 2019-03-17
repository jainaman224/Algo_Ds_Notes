# Girlscript Summer Of Code
# 0-1 Knapsack program in Python
"""
What is 0-1 KnapSack program?
Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).
[Refered from www.geeksforgeeks.com]
"""
"""
Variables:
mw-maximum weight
wt[]-Array of weights
val[]-Array of values
n-number of values 
""" 
def knapSack(mw, wt, val, n): 
	K = [[0 for x in range(mw + 1)] for x in range(n + 1)] 

	for i in range(n + 1): 
		for j in range(mw + 1): 
			if i == 0 or j == 0: 
				K[i][j] = 0
			elif wt[i-1] <= j: 
				K[i][j] = max(val[i-1] + K[i-1][j-wt[i-1]], K[i-1][j]) 
			else: 
				K[i][j] = K[i-1][j] 

	return K[n][mw] 

# Test Case for the problem :
# Alter the values to and weights to check the result
# Corresponding Values and Weights
values = [30, 20, 60, 80, 10] 
weights = [10, 20, 30, 40, 50] 
# Maximum Weight
MaxWeight = 80
# Number of Values
n = 5
# Display the Result
print(knapSack(MaxWeight, weights, values, n)) 
# Result is 170 for the test case given initially.

#  Happy Coding!

