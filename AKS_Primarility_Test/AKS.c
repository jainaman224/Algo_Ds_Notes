#include <stdio.h>
/*

Check if n is a perfect power: if n = ab for integers a > 1 and b > 1, output composite.


Find the smallest r such that ordr(n) > (log2 n)2. (if r and n are not coprime, then skip this r)


For all 2 ≤ a ≤ min(r, n−1), check that a does not divide n: If a|n for some 2 ≤ a ≤ min(r, n−1), output composite.


If n ≤ r, output prime.


For a = 2 to sqrt(phi (r))*log(2)(n)  
	if (X+a)n≠ Xn+a (mod Xr − 1,n), output composite;


Output prime.

*/
int isprm(long long n)
{
	long long i = 5, w = 2;
	if (n == 2 || n==3)
		return 1;
	if(n%2 == 0 || n%3 == 0 || n == 1)
		return 0;
	while(i*i <= n)
	{
		if(n%i == 0)
			return 0;
		i += w;
		w = 6 - w;
	}
	return 1;
}

int main()
{
	// Prints all prime less than 100000000
	for (int i = 1; i <= 100000000; i++)
	{
		if(isprm(i) == 1)
			printf("%d\n",i);
	}
	return 0;
}
