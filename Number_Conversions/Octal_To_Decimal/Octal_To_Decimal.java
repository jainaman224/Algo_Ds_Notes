// Java program to convert octal to decimal
import java.io.*; 
class number { 

	// Function to convert octal to decimal 
	static int octalToDecimal(int number) 
	{ 
		int num = number; 
		int decimal_value = 0; 

		// Initializing base value to 1, i.e 8^0 
		int base = 1; 

		int temp = num; 
		while (temp > 0) { 
			// Extracting last digit 
			int last_digit = temp % 10; 
			temp = temp / 10; 

			// Multiplying last digit with appropriate base value and adding it to decimal value 
			decimal_value += last_digit * base;
			base = base * 8; 
		} 
		return decimal_value; 
	} 

	//The main Function
	public static void main(String[] args) 
	{ 
		int num = 167; 
		System.out.println(octalToDecimal(num)); 
	} 
} 

//OUTPUT
//119
