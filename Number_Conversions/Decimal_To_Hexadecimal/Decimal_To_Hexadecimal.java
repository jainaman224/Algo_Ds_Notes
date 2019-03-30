// Java program to convert a decimal number to hexadecimal number 
import java.io.*; 

class number
{ 
	// function to convert decimal to hexadecimal 
	static void decimalToHexa(int number) 
	{ 
		// char array to store hexadecimal number 
		char[] hexaDeciNum = new char[100]; 
	
		// counter for hexadecimal number array 
		int i = 0; 
		while(number!=0) 
		{ 
			// temporary variable to store remainder 
			int temp = 0; 
			// storing remainder in temp variable. 
			temp = number % 16; 
			// check if temp < 10 
			if(temp < 10) 
			{ 
				hexaDeciNum[i] = (char)(temp + 48); 
				i++; 
			} 
			else
			{ 
				hexaDeciNum[i] = (char)(temp + 55); 
				i++; 
			} 
			number = number/16; 
		} 
		// printing hexadecimal number array in reverse order 
		for(int j=i-1; j>=0; j--) 
			System.out.print(hexaDeciNum[j]); 
	} 
	
	//The main function 
	public static void main (String[] args) 
	{ 
		int n = 27463; 
		decimalToHexa(n); 
	} 
} 

//OUTPUT
//6B47
