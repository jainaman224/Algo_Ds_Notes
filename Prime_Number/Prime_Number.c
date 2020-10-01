#include<stdio.h>
#include<stdbool.h>
#include<math.h>
 
bool Prime (int num, int i) 
{ 
    if (num == 1)
        return false;

    // Base case
    if (i <= 1) 
        return true;

    // Checking if i is a divisor of num or not
    if (num % i == 0) 
        return false; 

    // Calling recursive function
    return Prime(num, i - 2); 
} 
  
// Driver Program 
int main() 
{ 
    int num;    
    scanf("%d", &num);
 
    if (num == 2)
        printf("It is a prime number");
    else if (num % 2 == 0)
        printf("It is not a prime number");
    else
        if (Prime(num, sqrt(num))) 
            printf("It is a prime number"); 
        else
            printf("It is not a prime number"); 
  
    return 0; 
}

// Input: 29
// Output: It is a prime number
