/*
    A decagonal number is a figurate number that extends the concept of 
    triangular and square numbers to the decagon (a ten-sided polygon).
    
    The n-th decagonal number is given by the formula:
    Dn = 4n^2 - 3n.
*/

#include<stdio.h> 
   
// To calculate decagonal number 
int decagonalnumber (int num) 
{ 
    // Using formula  
    return 4 * num * num - 3 * num; 
} 
   
int main() 
{ 
    int num;
    scanf("%d", &num);
    printf("%d decagonal number : %d", num, decagonalnumber(num)); 
    return 0; 
}

/*
Input:
6
output:
6 decagonal number : 126
*/
