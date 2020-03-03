#include<stdio.h>

int bitwiseAdditionRecursive(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    else
    {
        int carry = a & b;
        return bitwiseAdditionRecursive(a^b, carry<<1);
    }
}
int main()
{
    int no1,no2,result;
    printf("Enter two numbers: ");
    scanf("%d%d",&no1,&no2);
	result = bitwiseAdditionRecursive(no1, no2);
	printf("\nby using recursive bitwise addition method,\n");
    printf("\n%d + %d = %d",no1,no2,result);
    return 0;
}






/*
INPUT:
    Enter two numbers: 12 30

OUTPUT:
    byusing recursive bitwise addition method,
    12+30 = 42
*/
