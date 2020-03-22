#include <stdio.h>
#include <string.h>    /*used string library header file for string functions.*/

main()
{          
    char str[200], rev[200];
    printf ("Enter a string : ");
    gets (str);   /*This function is used to read multiword string (one line) from keyboard*/
    strcpy (rev, str);   /*This function is used to copy one string into another*/
    strrev (rev);   /*This function is used to reverse the giveen string*/
    if (strcmp (str, rev) == 0)   /*To compare two strings.*/
        printf ("\nThe Given string is Palindrome");
    else
        printf ("\nThe Given string is NOT Palindrome");
    return 0;
}

/* Sample Input 1 :-
    Enter a String : racecar
Output:
    The Given string is Palindrome  */
	
/* Sample input 2 :-
	Enter a String : madam
Output:
	The Given string is Palindrome */    
