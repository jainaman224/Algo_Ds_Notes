# Python3 program to convert a decimal number to  octal number 

# function to convert decimal to octal 
def decimalToOctal(number): 
	
	# array to store octal number 
	octalNumber = [0] * 100; 

	# counter for octal number array 
	i = 0; 
	while (number != 0): 

		# storing remainder in octal array 
		octalNumber[i] = number % 8; 
		number = int(number / 8); 
		i += 1; 

	# printing octal number array in reverse order 
	for j in range(i - 1, -1, -1): 
		print(octalNumber[j], end = ""); 

#The main Code
n = 29; 

decimalToOctal(n); 

#OUTPUT
#35
