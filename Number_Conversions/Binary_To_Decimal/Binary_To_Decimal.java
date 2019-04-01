// Java program to convert binary to decimal 

// Function to convert binary to decimal 
class Binary_To_Decimal 
{ 
	static int binaryToDecimal(int n) 
	{ 
		int decimal_value = 0; 
		// Initializing base value to 1, i.e 2^0 
		int base = 1; 
		int temp = n;

		while (temp > 0) { 
			int last_digit = temp % 10; 
			temp = temp / 10; 
			decimal_value += last_digit * base; 
			base = base * 2; 
		} 
		return decimal_value; 
	} 
	
	// The main Function
	public static void main(String[] args) 
	{ 
		int num = 101011101; 
		System.out.println(binaryToDecimal(num)); 
	} 
} 

//OUTPUT
//349
