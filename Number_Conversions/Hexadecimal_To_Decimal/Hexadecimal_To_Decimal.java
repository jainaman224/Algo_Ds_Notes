// Java program to convert hexadecimal to decimal 
import java.io.*; 
class number
{ 
	// Function to convert hexadecimal to decimal 
	static int hexadecimalToDecimal(String hexVal) 
	{ 
		int len = hexVal.length();
		// Initializing base value to 1, i.e 16^0 
		int base = 1; 
		int decimal_value = 0; 
	
		// Extracting characters as digits from last character 
		for (int i=len-1; i>=0; i--) 
		{ 
			// if character lies in '0'-'9', converting it to integral 0-9 by subtracting 48 from ASCII value 
			if (hexVal.charAt(i) >= '0' && hexVal.charAt(i) <= '9') 
			{ 
				decimal_value += (hexVal.charAt(i) - 48)*base; 
				// incrementing base by power 
				base = base * 16; 
			} 

			// if character lies in 'A'-'F' , converting it to integral 10 - 15 by subtracting 55 from ASCII value 
			else if (hexVal.charAt(i) >= 'A' && hexVal.charAt(i) <= 'F') 
			{ 
				decimal_value += (hexVal.charAt(i) - 55)*base;
				// incrementing base by power 
				base = base*16; 
			} 
		} 
		return decimal_value; 
	} 
	
	// The main Function
	public static void main (String[] args) 
	{ 
		String hexNum = "34FA";	 
		System.out.println(hexadecimalToDecimal(hexNum)); 
	} 
}

//OUTPUT
//13562
