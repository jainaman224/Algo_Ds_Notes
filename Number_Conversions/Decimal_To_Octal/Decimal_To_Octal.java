// Java program to convert a decimal number to octal number
import java.io.*; 

class  number
{ 
	// Function to convert decimal to octal 
	static void decimalToBinary(int number) 
	{ 
		// array to store octal number 
		int[] octalNumber = new int[1000]; 
		// counter for binary array 
		int i = 0; 
		while (number > 0) 
		{ 
			// storing remainder in octal array 
			octalNumber[i] = number % 8; 
			number = number / 8; 
			i++; 
		} 

		// printing octal array in reverse order 
		for (int j = i - 1; j >= 0; j--) 
			System.out.print(octalNumber[j]); 
	} 
	
	//The main Function 
	public static void main (String[] args) 
	{ 
		int n = 29; 
		decimalToBinary(n); 
	} 
}

//OUTPUT
//35
