// C++ program to convert binary to decimal 
#include <iostream> 
using namespace std; 

// Function to convert binary to decimal 
int binaryToDecimal(int n) 
{ 
    int decimal_value = 0; 

    // Initializing base value to 1, i.e 2^0 
    int base = 1; 
    int temp = n; 
    while (temp) 
	{ 
	    int last_digit = temp % 10; 
	    temp = temp / 10; 
	    decimal_value += last_digit * base; 
	    base = base * 2; 
    } 
    return decimal_value; 
} 

//The main function 
int main() 
{ 
	int num;
    cin>>num;
    cout << binaryToDecimal(num) << endl; 
}

//OUTPUT for  101011101
//349
