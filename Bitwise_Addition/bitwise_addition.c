#include<stdio.h>

int bitwiseaddition(int a, int b)
{
    while(b != 0)
    {
        int carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}
int main()
{
    int no1,no2,result;
    printf("Enter two numbers: ");
    scanf("%d%d",&no1,&no2);
    result = bitwiseaddition(no1,no2);
    printf("\nusing bitwise addition,\n");
    printf("\n%d + %d = %d",no1,no2,result);
    return 0;
}


/*
INPUT:
    Enter two numbers: 12 30

OUTPUT:
    using bitwise operations,
    
	12+30 = 42
*/
