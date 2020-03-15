/*ASCII SUBSEQUENCES PROBLEM
This problem is same as the "Subsequences" question just instead of two function calls, three function calls will be made :
- One with the same string.
- One with a letter added.
- One with the ASCII code of the letter added to the string.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char str[100];

void subseq(char s[], int i, char str[])
{
    if(i == strlen(str))
    {
        printf("%s\n", s);
        return;
    }

    // The 3 function calls in the same order as explained above.
    // First function call
    subseq(s, i + 1, str);  

    int i1;
    char s2[strlen(s) + 2];

    for(i1 = 0; i1 < strlen(s); i1++)
    {
        // Copy string from s to s2
        s2[i1] = s[i1]; 
    }
    
    // Concatinate ith character of string str to s2
    s2[i1++] = str[i]; 
    s2[i1] = '\0';
    
    // Second function call
    subseq(s2, i + 1, str); 
    
    // Integer n stores the ASCII value of the ith character of string str
    int i2, n = (int)str[i]; 
    char s3[strlen(s) + 2];

    // Create AsciiString to store the ASCII value of the ith character of string str
    char AsciiString[5];

    if(n < 10)
    {
        AsciiString[0] = (char)(n + 48);
        AsciiString[1] = '\0';
    }
    else if(n<100)
    {
        AsciiString[0] = (char)(((n - (n % 10)) / 10) + 48);
        AsciiString[1] = (char)((n % 10) + 48);
        AsciiString[2] = '\0';
    }
    else
    {
        AsciiString[0] = (char)(((n - (n % 100)) / 100) + 48);
        AsciiString[1] = (char)((((n - (n % 10)) / 10) % 10) + 48);
        AsciiString[2] = (char)((n % 10) + 48);
        AsciiString[3] = '\0';
    }

    for(i2 = 0; i2 < strlen(s); i2++)
    {
        // Copy string from s to s3
        s3[i2] = s[i2]; 
    }

    int i3 = i2;

    for(; i2 < strlen(AsciiString) + strlen(s); i2++)
    {
       // Concatinate AsciiString into s3
       s3[i2] = AsciiString[i2 - i3]; 
    }

    s3[i2] = '\0';
    // Third function call
    subseq(s3, i + 1, str); 
}

int main()
{
    printf("Enter the string\n");
    scanf("%s", str);
    printf("Number of Subsequences : %d\n", (int)pow(3, strlen(str)));
    subseq("", 0, str);
    return 0;
}

/*Sample Input: Enter the string:
ab
Sample Output:
Number of Subsequences : 9

b
98
a
ab
a98
97
97b
9798
*/
