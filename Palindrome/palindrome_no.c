/*
This program checks whether the enterd number is palindrome or not and generates output according to input provided.
*/

#include<stdio.h>
int main()
{
    int n,rem,temp,rev = 0;
    printf("\nEnter a number: ");
    scanf("%d",&n);
    temp = n;
    while(temp != 0)
    {
        rem = temp % 10;
        temp = temp / 10;
        rev = (rev * 10) + rem;
    }
    if(rev != n)
    {
        printf("\nEntered number is not palindrome.\n");
    }
    else
    {
        printf("\nEntered number is palindrome.\n");
    }
    return 0;
}



/*
  INPUT:
	n=12456
  OUTPUT:
  	Entered no. is not palindrome.
  
  INPUT:
  	n=12821
  OUTPUT:
  	Entered no. is palindrome.
*/
