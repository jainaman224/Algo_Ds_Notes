// C++ program to convert a decimal number to octal number 
#include <iostream> 
using namespace std; 

// Function to convert decimal to octal 
void decimalToOctal(int number) 
{ 
	// array to store octal number 
	int octalNumber[1000]; 
	// counter for octal array 
	int i = 0; 
	while (number > 0) { 
		// storing remainder in octal array 
		octalNumber[i] = number % 8; 
		number = number / 8; 
		i++; 
	} 
	// printing octal array in reverse order 
	for (int j = i - 1; j >= 0; j--) 
		cout << octalNumber[j]; 
} 

// The main Function
int main() 
{ 
	int n = 29; 
	decimalToOctal(n); 
	return 0; 
} 

//OUTPUT
//35
