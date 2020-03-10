#include <stdio.h>
/* Function for gcd */
int gcd (int a, int b)
{
	if (b==0)
	return a;
	/* Using recursion for checking gcd*/
	else 
	return gcd (b,a%b);
}
main()
{
	int a,b,hcf;
	printf ("Input two numbers : ");
	scanf ("%d%d",&a,&b);
	/* Function Calling*/
	hcf = gcd (a,b);
	printf ("GCD = %d", hcf);
	return 0;
}

/* 
Sample input:-
   input two numbers : 15 45
   GCD = 15
   */
