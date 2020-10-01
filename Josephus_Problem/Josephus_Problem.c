#include<stdio.h>
int josephus(int no,int h)
{
    if(no==1)
        return 1;
    else
        return (josephus(no - 1,h)+ h-1) % no + 1;
}
int main()
{
    int a = 20;
    int b = 5;
    printf("The chosen place is %d",josephus(a,b));
    return 0;
}

