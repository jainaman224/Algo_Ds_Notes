/* Babylonian method for square root
  1. Start with an arbitrary positive start value x (the closer to the 
     root, the better).
  2. Initialize y = 1.
  3. Do following until desired approximation is achieved.
      a) Get the next approximation for root using average of x and y
      b) Set y = n/x */
      
#include <stdio.h>   

float squareRoot(float num) 
{ 
    float number = num; 
    float guess = 1; 
    float accuracy = 0.000001; /* it decides the accuracy level*/
    while (number - guess > accuracy)
    { 
        number = (number + guess) / 2; 
        guess = num / number; //to get next approximation
    } 
    return number; 
}   

int main() 
{ 
    int num ;
    printf("Enter a number :\n");
    scanf("%d",&num); 
    printf("Square root of %d is %f", num, squareRoot(num));     
}

/*Enter a number :
2
Square root of 2 is 1.414214 */
