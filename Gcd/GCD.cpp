// C++ program to find GCD of two numbers using modulo operator in Euclidean Algorithm
#include <bits/stdc++.h>
using namespace std;

// Recursive function to return gcd of a and b 
int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 
   
// Main Program 
int main() 
{ 
    int a,b;
    cout<<"Enter Two Numbers : ";
    cin>>a>>b;
    cout<<"GCD of "<<a<<" and "<<b<<" is "<<gcd(a, b); 
    return 0; 
} 

//OUTPUT:
//Let a=78 , b=56
//GCD of 78 and 56 is 2.