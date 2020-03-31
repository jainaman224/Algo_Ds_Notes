// C++ program to find GCD of two numbers using modulo operator in Euclidean Algorithm
#include <stdio.h> 

// Recursive function to return gcd of a and b 
int gcd(int a, int b) 
{ 
	// Everything divides 0 
	if (a == 0) 
	return b; 
	if (b == 0) 
	return a; 

	// base case 
	if (a == b) 
		return a; 

	// a is greater 
	if (a > b) 
		return gcd(a-b, b); 
	return gcd(a, b-a); 
} 

// Main Program
int main() 
{ 
    int a,b;
    printf("Enter Two Numbers : ");
    scanf("%d %d",&a ,&b);
    printf("GCD of %d and %d is : %d",a,b,gcd(a,b)); 
    return 0; 
} 

//OUTPUT:
//Let a=78 , b=56
//GCD of 78 and 56 is 2.