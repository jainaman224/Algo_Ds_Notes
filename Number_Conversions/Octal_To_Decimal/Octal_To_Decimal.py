# Python3 program to convert octal to decimal number

# Function to convert octal to decimal 
def octalToDecimal(number): 
	
	num = number; 
	decimal_value = 0; 

	# Initializing base value to 1, i.e 8^0 
	base = 1; 
	temp = num; 
	while (temp): 

		# Extracting last digit 
		last_digit = temp % 10; 
		temp = int(temp / 10); 

		#Multiplying last digit with appropriate base value and adding it to decimal value 
		decimal_value += last_digit * base;
		base = base * 8; 

	return decimal_value; 

# The main code 
num = 167; 
print(octalToDecimal(num)); 

#OUTPUT
#119
