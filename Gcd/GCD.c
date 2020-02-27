//This code is the implementation of the Euclidean Algorithm in C
#include <stdio.h>

int GCD(int a, int b){
	//base case
	if(b==0)
		return a;
	//recursive case
	return GCD(b,a%b);
}
//here if a becomes less than b than the numbers swap
//for example if we find the gcd of 10 and 14 i.e GCD(10,14), after the recursive case we get GCD(14,10) 

int main(){
	int a,b;
	printf("Please enter two numbers whose gcd you would like to find\n");
	scanf("%d %d",&a,&b);
	printf("The GCD of %d %d is %d\n",a,b,GCD(a,b));
	return 0;
}
// Output
// Enter number 14, 63
// Gcd of 14, 63 = 7
