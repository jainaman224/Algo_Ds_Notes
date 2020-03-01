/* This code is used to find factorial 
of large numbers*/
#include<stdio.h>
int main()
{
    int n,a[200000],i,j,k,l,m;
    printf("ENTER THE NUMBER\n");
	scanf("%d",&n);
        m=1;
        a[0]=1;
        for(j=2;j<=n;j++)
        {
            l=0;
            for(k=0;k<m;k++)
            {
                a[k]=a[k]*j+l;
                l=a[k]/10;
                a[k]=a[k]%10;
            }
            while(l)
            {
	            a[k]=l%10;
                k++;
                m++;
                l=l/10;
            }
        }
        printf("Answer is : ");
        for(i=m-1;i>=0;i--)
            printf("%d",a[i]);
        printf("\n");
    return 0;
}
/*ENTER THE NUMBER
5
Answer is : 120*/
