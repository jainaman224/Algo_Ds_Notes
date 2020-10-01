#include<stdio.h>

int main() 
{ 
    int num;
    scanf("%d", &num); 
  
    // To store octal number 
    int octal[100]; 
  
    int i = 0, j; 
    while (num != 0) 
    {   
        octal[i] = num % 8; 
        num = num / 8; 
        i++; 
    } 
  
    for (j = i - 1; j >= 0; j--) 
        printf("%d", octal[j]);
  
    return 0; 
} 

/*
Input:
20
Output:
24
*/
