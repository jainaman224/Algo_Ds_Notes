// C++ program to convert a decimal number to binary number 
#include <iostream> 
using namespace std; 

// Function to convert decimal to binary 
void decimalToBinary(int number) 
{ 
	// array to store binary number 
	int binaryNumber[1000]; 
	// counter for binary array 
	int i = 0; 
	while (number > 0) { 
		// storing remainder in binary array 
		binaryNumber[i] = number % 2; 
		number = number / 2; 
		i++; 
	} 
	// printing binary array in reverse order 
	for (int j = i - 1; j >= 0; j--) 
		cout << binaryNumber[j]; 
} 

// The main Function
int main() 
{ 
	int n = 29; 
	decimalToBinary(n); 
	return 0; 
} 

//OUTPUT
//11101
