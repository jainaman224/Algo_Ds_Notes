# Python3 program to convert a decimal number to hexadecimal number 

# function to convert decimal to hexadecimal 
def decimalToHexa(number): 
	
	# char array to store hexadecimal number 
	hexaDeciNum = ['0'] * 100; 
	
	# counter for hexadecimal number array 
	i = 0; 
	while(number != 0): 
		
		# temporary variable to store remainder 
		temp = 0; 
		
		# storing remainder in temp variable. 
		temp = number % 16; 
		
		# check if temp < 10 
		if(temp < 10): 
			hexaDeciNum[i] = chr(temp + 48); 
			i = i + 1; 
		else: 
			hexaDeciNum[i] = chr(temp + 55); 
			i = i + 1; 
		number = int(number / 16); 
		
	# printing hexadecimal number array in reverse order 
	for j in range(i - 1, -1, -1):
		print((hexaDeciNum[j]), end = ""); 

# The main code 
n = 27463; 
decimalToHexa(n); 

#OUTPUT
#6B47
