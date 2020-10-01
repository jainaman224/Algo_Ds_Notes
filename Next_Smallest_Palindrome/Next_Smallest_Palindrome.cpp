#include <stdio.h> 

// This function is for when -> 
// 1.The input number is not palindrome. 
// 2.number is palindrome but not all digits as nine

void helper(int num[], int n) 
{ 
    int middle = n/2, i = middle - 1;    

    // handling middle for odd and even lengths
    int j = 0;
    if(n % 2 == 0)
        j = middle;
    else
        j = middle + 1;
  
    // ignore the middle same digits  
    while (i >= 0 && num[i] == num[j]) 
    {        
        i--;
        j++; 
    }

    bool isLeftSmaller = false;
    // if the middle digits need to be incremented or not.
    if (i < 0 || num[i] < num[j]) 
        isLeftSmaller = true; 
  
    while (i >= 0) 
    { 
        num[j] = num[i]; 
        j++; 
        i--; 
    } 
  
    // the case where middle digit must be incremented.  
    if (isLeftSmaller) 
    { 
        int cflag = 1; 
        i = middle - 1; 
        if (n % 2 == 1) 
        { 
            num[middle] += cflag; 
            cflag = num[middle] / 10; 
            num[middle] %= 10; 
            j = middle + 1; 
        } 
        else
            j = middle; 

        // copy same left to right
        while (i >= 0) 
        { 
            num[i] += cflag; 
            cflag = num[i] / 10; 
            num[i] %= 10; 
            num[j] = num[i]; 
            j++;
            i--;
        } 
    } 
} 

void next_smallest_palindrome(int num[], int n) 
{
    //if All the digits are 9, o/p 1 followed by n-1 0's followed by 1. 
    int b = 1;
    for (int i = 0; i < n; ++i) 
        if (num[i] != 9) 
            b = 0;  

    printf("Next palindrome is:");
    if (b) 
    { 
        printf("1 "); 
        for(int i = 0; i < n - 1; i++) 
            printf("0 "); 
        printf("1"); 
    } 
  
    // for other input cases 
    else
    { 
        helper(num, n); 
        for (int i = 0; i < n; i++) 
            printf("%d ", num[i]); 

        printf("\n"); 
    } 
} 

int main() 
{ 
    // Sample input
    int num[] = {9, 4, 1, 8, 7, 9, 7}; 
  
    int n = sizeof (num)/ sizeof(num[0]); 
  
    next_smallest_palindrome(num, n); 
  
    return 0; 
} 

// Sample Output
// Next palindrome is:9 4 1 9 1 4 9
