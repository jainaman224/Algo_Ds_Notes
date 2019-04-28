'''A positive integer of n digits is called an Armstrong number of order n (order is number of digits) if
abcd... = pow(a,n) + pow(b,n) + pow(c,n) + pow(d,n) + .... '''

#To calculate the order of the number
def order(num): 
	# variable to store of the number 
	count = 0
	while (num != 0): 
		count = count + 1
		num = num / 10
	return count 

# Function to check whether the given number is 
# Armstrong number or not 
def Armstrong (num): 
	count = order(num) 
	temp = num 
	sum1 = 0
	while (temp != 0): 
		d = temp % 10
		sum1 = sum1 + pow(d, count) 
		temp = temp / 10

	# If condition satisfies 
	return (sum1 == num) 


# Driver Program 
num = 153
print(Armstrong(num))

#True
