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
	printf ("Enter a,b");
	scanf ("%d%d",&a,&b);
	/* Function Calling*/
	hcf = gcd (a,b);
	printf ("GCD = %d", hcf);
	return 0;
}
