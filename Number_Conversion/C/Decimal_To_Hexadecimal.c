#include<stdio.h>

int main() 
{ 
    int num;
    scanf("%d", &num);
    
    // To store hexadecimal number 
    char hexa[100]; 
      
    int i = 0, j; 
    while (num != 0) 
    {    
        int temp  = 0;         
        temp = num % 16;         
         
        // Checking if temp < 10; if it then it is a letter
        if (temp < 10) 
        { 
            hexa[i] = temp + 48; 
            i++; 
        } 
        else
        { 
            hexa[i] = temp + 55; 
            i++; 
        } 
          
        num = num / 16;
    }
    
    for (j = i - 1; j >= 0; j--) 
        printf("%c", hexa[j]);       
         
    return 0; 
} 

/*
Input:
1234
Output:
4D2
*/
