// C++ program to convert hexadecimal to decimal 
#include <stdio.h>
#include <string.h> 
using namespace std; 

// Function to convert hexadecimal to decimal 
int hexadecToDecimal(char hexVal[]) 
{ 
	int len = strlen(hexVal); 
	// Initializing base value to 1, i.e 16^0 
	int base = 1; 
	int decimal_value = 0; 
	
	// Extracting characters as digits from last character 
	for (int i=len-1; i>=0; i--) 
	{ 
		// if character lies in '0'-'9', converting it to integral 0-9 by subtracting 48 from ASCII value. 
		if (hexVal[i]>='0' && hexVal[i]<='9') 
		{ 
			decimal_value += (hexVal[i] - 48)*base; 
		    // incrementing base by power 
			base = base * 16; 
		} 

		// if character lies in 'A'-'F' , converting it to integral 10 - 15 by subtracting 55 from ASCII value 
		else if (hexVal[i]>='A' && hexVal[i]<='F') 
		{ 
			decimal_value += (hexVal[i] - 55)*base; 
	        // incrementing base by power 
			base = base*16; 
		} 
	}
	return decimal_value; 
} 

//The main Function 
int main() 
{ 
	char hexNum[] = "34FA";	 
	int decimal_number=hexadecToDecimal(hexNum) ;
    printf("%d",decimal_number);
	return 0; 
} 

//OUTPUT
//13562
