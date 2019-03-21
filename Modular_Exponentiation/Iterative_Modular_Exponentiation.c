#include<stdio.h>

//calculation of modular exponentiation using iterative approach
long long power(long long base, long long exp,long long p) {
	long long holder = 1;
	base=base%p;
	while (exp > 0) {
		if (exp & 1)
			holder = (holder * base)%p;
		base = (base * base)%p;
		exp >>= 1;
	}
	return holder;
}

int main()
{
	long long base,exponent ,p;
    
	scanf("%lli %lli %lli",&base,&exponent,&p);
	//taking input for base and exponent ;

	printf("The result of given expression is id %lli",power(base,exponent,p));
	
	return 0;
}

/*
output:
base : 2
exponent:4
output :The result of given expression is1
*/
