#include<bits/stdc++.h> 
using namespace std; 
  
// Function to rotations of a number 
void rotation(int num) 
{ 
    int temp = num;
    int digits = 0; 
    
    // Finding the number of digits
    while (temp > 0)
    { 
        digits++; 
        temp /= 10; 
    } 
    
    int power = pow(10, digits - 1); 
    
    // Rotations of the number
    for (int i = 0; i < digits - 1; i++) 
    {
        int lastDigit = num % 10; 
        int x = num / 10;
        num = lastDigit * power + x;
        cout<<num<<" "; 
    } 
} 

// Driver Code 
int main() 
{ 
    int num;
    cin>>num;
    rotation(num); 
    return 0; 
} 

/*
Input:
1234
Output:
4123 3412 2341 
*/
