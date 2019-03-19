
def Edit_Distance(a, b, m , n): 

	# If first string is empty, the only option is to insert all characters of second string into first 
	if m == 0: 
		return n 

	# If second string is empty, remove all characters of first string 
	if n == 0: 
		return m 

	# If last characters of two strings are same, nothing much to do.
	if a[m-1]==b[n-1]: 
		return Edit_Distance(a,b,m-1,n-1) 

	# If last characters are not same, consider all three operations on last character of first string, recursively 
	# compute minimum cost for all three operations and take minimum of three values. 
	return 1 + min(Edit_Distance(a, b, m, n-1), # Insert 
				Edit_Distance(a, b, m-1, n), # Remove 
				Edit_Distance(a, b, m-1, n-1) # Replace 
				) 

a = "kanchan"
b = "thareja"

print Edit_Distance(a, b, len(a), len(b)) 

# OUTPUT :
#   6
