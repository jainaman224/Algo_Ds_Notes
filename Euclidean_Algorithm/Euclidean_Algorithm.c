// Program to demonstrate Basic Euclidean Algorithm 

#include <stdio.h> 

// Function to return gcd of x and y
int gcd_algorithm (int x, int y)
{
   // if the remainder is 0, return second number
    if (x == 0)
    {
        return y;
    } 
     return gcd_algorithm( (y % x) , x ); // recursive call to the function     
}
 
// Driver program 
int main()
{
    int num1, num2, gcd;
    printf("\nEnter two numbers to find gcd using Euclidean algorithm: ");
    scanf("%d %d", &num1, &num2);
    gcd = gcd_algorithm(num1, num2); 
    printf("\nThe GCD of %d and %d is %d\n", num1, num2, gcd);
    return 0;
}

/*
Output-
Enter two numbers to fing gcd using Euclidean algorithm:
12 16
The GCD of 12 and 16 is 4
*/
