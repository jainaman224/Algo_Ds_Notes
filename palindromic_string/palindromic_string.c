/*
C Programme to check palindromic string.
A Palindromic String is a sequence of characters which is
the same when read both forward and backward.
*/

#include <stdio.h>
#include <string.h>

// Driver function
int main()
{
    char string1[20];
    int i, length;
    bool flag = false;
    
    printf("Enter a string: ");
    scanf("%s", string1);
    
    length = strlen(string1);
    
    for(i = 0; i < length/2; i++)
    {
        if(string1[i] != string1[length - i - 1])
        {
            flag = true;
            break;
        }
    }
    
    if (flag) 
    {
        printf("%s is not a palindrome", string1);
    }    
    else 
    {
        printf("%s is a palindrome", string1);
    }
    return 0;
}

/*
Input:
radar

Output:
radar is a palindrome

Input:
Enter a string: india

Output:
india is not a palindrome
*/
