#include<stdio.h>

//calculation of modular exponentiation using iterative approach
long long power(long long base, long long exp) {
    long long holder = 1;
    while (exp > 0) {
        if (exp & 1)
            holder = holder * base;
        base = base * base;
        exp >>= 1;
    }
    return holder;
}
int main()
{
	long long base,exponent ;
    
	scanf("%lli %lli",&base,&exponent);
	//taking input for base and exponent ;

	printf("The result of given expression is id %lli",power(base,exponent));
	
	return 0;
}
/*
output:
base : 2
exponent:10
output :The result of given expression is1024



*/
