#include<stdio.h>

//recursive mechanism 
long long int power(long int base,long int exponent)
{
	 if ( exponent == 0)
        return 1;
    long long holder = power(base,  exponent / 2);//r is the placeholder
    if (exponent % 2)
        return holder * holder * base;
    else
        return holder * holder;
	
}

int main()
{
	long int base,exponent;
	scanf("%ld %ld",&base,&exponent);
	printf("The value of given expression is %ld",power(base,exponent));	
	return 0;
	
}

/*
output:
base : 2
exponent:10
output :The result of given expression is 1024
*/
