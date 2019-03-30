// C++ program to convert binary to decimal 
#include <iostream> 
using namespace std; 

// Function to convert binary to decimal 
int binaryToDecimal(int n) 
{ 
	int num = n; 
	int decimal_value = 0; 

	// Initializing base value to 1, i.e 2^0 
	int base = 1; 

	int temp = num; 
	while (temp) { 
		int last_digit = temp % 10; 
		temp = temp / 10; 
		decimal_value += last_digit * base; 
		base = base * 2; 
	} 
	return decimal_value; 
} 
// The main function 
int main() 
{ 
	int num = 101011101; 
	cout << binaryToDecimal(num) << endl; 
}

//OUTPUT
//349
