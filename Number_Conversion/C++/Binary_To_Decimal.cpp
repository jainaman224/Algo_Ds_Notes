/*
    For binary number with n digits:
    dn-1 ... d3 d2 d1 d0
    The decimal number is equal to the sum of binary digits (dn) times their power of 2 (2n):
    decimal = d0×2^0 + d1×2^1 + d2×2^2 + ...
*/

#include<iostream> 
using namespace std; 

int main() 
{ 
    int num;
    cin>>num;
    int decimal; 
    int base = 1; 
  
    while (num)
    { 
        int x = num % 10; 
        num = num / 10; 
  
        decimal += x * base; 
  
        base = base * 2; 
    }   
    cout<<decimal; 
} 

/*
Input:
100
Output:
4
*/
