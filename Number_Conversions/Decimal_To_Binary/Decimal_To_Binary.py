# Python3 program to convert a decimal number to binary number 

# Function to convert decimal to binary 
def decimalToBinary(number): 
	
	# array to store binary number 
	binaryNumber = [0] * number; 

	# counter for binary array
	i = 0; 
	while (number > 0): 

		# storing remainder in binary array 
		binaryNumber[i] = number % 2; 
		number = int(number / 2); 
		i += 1; 

	# printing binary array in reverse order 
	for j in range(i - 1, -1, -1): 
		print(binaryNumber[j], end = ""); 

# The main Code
n = 29; 
decimalToBinary(n); 

#OUTPUT
#11101
