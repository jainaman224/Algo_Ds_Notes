/*
    For octal number with n digits:
    dn-1 ... d3 d2 d1 d0
    The decimal number is equal to the sum of octal digits (dn) times their power of 8 (8n):
    decimal = d0×8^0 + d1×8^1 + d2×8^2 + ...
*/

#include<stdio.h> 

int main() 
{ 
    int num;
    scanf("%d", &num);
    int decimal; 
    int base = 1; 
  
    while (num)
    { 
        int x = num % 10; 
        num = num / 10; 
  
        decimal += x * base; 
  
        base = base * 8; 
    }   
    printf("%d", decimal); 
} 

/*
Input:
1000
Output:
512
*/
