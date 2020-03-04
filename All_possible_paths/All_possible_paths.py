# Python program to count all possible paths 
# from top left to bottom right 

# I'm using Dynamic Programming approach.

# Returns count of possible paths to reach cell 
# at row number m and column number n from the 
# topmost leftmost cell (cell at 1, 1) 
def numberOfPaths(m, n): 
	# Create a 2D table to store 
	# results of subproblems 
	count = [[0 for x in range(n)] for y in range(m)] 
	
	# Count of paths to reach any 
	# cell in first column is 1 
	for i in range(m): 
		count[i][0] = 1
	
	# Count of paths to reach any 
	# cell in first column is 1 
	for j in range(n): 
		count[0][j] = 1
	
	# Calculate count of paths for other 
	# cells in bottom-up 
	# manner using the recursive solution 
	for i in range(1, m): 
		for j in range(1, n):			 
			count[i][j] = count[i-1][j] + count[i][j-1] 
	return count[m-1][n-1] 

# Driver program to test above function 
m = int(input("Enter the numbers of rows: "))
n = int(input("Enter the number of columns: "))
print(f"The number of unique paths from top left to bottom right of a mXn matrix is {numberOfPaths(m, n)} " ) 



# Output
# Enter the numbers of rows: 3
# Enter the number of columns: 4
# The number of unique paths from top left to bottom right of a mXn matrix is 10