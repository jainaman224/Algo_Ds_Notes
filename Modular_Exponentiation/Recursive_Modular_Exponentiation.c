#include<stdio.h>

//recursive mechanism 
long long power(long int base,long long exponent,long long p)
{
	long long holder;
	if(base==0)
		return 0;
	if ( exponent == 0)
        	return 1;
        
	if(exponent%2==0)
	{
    		holder=power(base,exponent/2,p);
    		holder=(holder*holder)%p;
	}
	else
	{
		holder=base%p;
		holder=(holder*power(base,exponent-1,p)%p)%p;
	}
	return (holder+p)%p;
}

int main()
{
	long long base,exponent,p;
	scanf("%lli %lli %lli",&base,&exponent,&p);
	printf("The value of given expression is %lli",power(base,exponent,p));	
	return 0;
}

/*
output:
base : 2
exponent:4
output :The result of given expression is 1
*/
