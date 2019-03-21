

def Edit_Distance(first_str, second_str, size1 , size2): 

	# If first string is empty, the only option is to insert all characters of second string into first 
	if size1 == 0: 
		return size2 

	# If second string is empty, remove all characters of first string 
	if n == 0: 
		return size1 

	# If last characters of two strings are same, nothing much to do.
	if first_str[size1-1] == second_str[size2-1]: 
		return Edit_Distance(first_str,second_str,size1-1,size2-1) 

	# If last characters are not same, consider all three operations on last character of first string, recursively 
	# compute minimum cost for all three operations and take minimum of three values. 
	return 1 + min(Edit_Distance(first_str, second_str, size1, size2-1), # Insert 
				Edit_Distance(first_str, second_str, size1-1, size2), # Remove 
				Edit_Distance(first_str, second_str, size1-1, size2-1) # Replace 
				) 

a = "kanchan"
b = "thareja"

print Edit_Distance(a, b, len(a), len(b)) 

# OUTPUT :
#   6


