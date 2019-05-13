#include<stdio.h>

// Function to print nth fibonacci number
int FibonacciNumber (int num) 
{ 
    if (num <= 1) 
        return num; 
    return FibonacciNumber(num - 1) + FibonacciNumber(num - 2); 
} 

// Function to print fibonacci series  
int FibonacciSeries (int num)  
{  
    int a = 0, b = 1, i;  

    if (num < 1)  
        return 0;  

    for (i = 1; i <= num; i++)  
    {  
        printf("%d ", b); 
        int c = a + b;  
        a = b;  
        b = c;         
    }  
} 

int main() 
{ 
    int num; 
    scanf("%d", &num);
    printf("The fibonacci number at position %d is %d ", num, FibonacciNumber(num));
    printf("\nFibonacci series:\n");
    FibonacciSeries(num);
    return 0;
}

/*
Input :
6
Output :
The fibonacci number at position 6 is 8
Fibonacci series:
1 1 2 3 5 8
*/
