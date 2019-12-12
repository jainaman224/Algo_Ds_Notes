//radix sort
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int findmax(int* a,int n)
{
    int  max=a[0];
    int i;
    for(i=1;i<n;i++)
    {
        if(max<a[i])
        {
            max=a[i];
        }
    }
    return max;
}
void radixsort(int* arr,int n)
{
    int kk,ten;
    int i,j,count=0;

    int max=findmax(arr,n);
    for(kk=max;kk>0;kk=kk/10)
        count++;
    int *c,*b,*a;
    c=(int*)malloc(sizeof(int)*10);
    b=(int*)malloc(sizeof(int)*n);
    a=(int*)malloc(sizeof(int)*n);
    for(j=0,ten=1;j<count;j++,ten=ten*10)
    {
        for(i=0;i<n;i++)
        {
            a[i]=(arr[i]/ten)%10;

        }

       // printf("%d\n",k);

        for(i=0;i<10;i++)
        {
            c[i]=0;
        }
       // printf("111111\n");
        for(i=0;i<n;i++)
        {
            c[a[i]]++;
        }
       // printf("2222222\n");
        for(i=1;i<10;i++)
        {
            c[i]+=c[i-1];
        }
       // printf("333333\n");
        for(i=n-1;i>=0;i--)
        {
            b[c[a[i]]-1]=arr[i];
            //printf("%d\n",b[c[a[i]]]);
            c[a[i]]--;
        }
       // printf("444444\n");
       for(i=0;i<n;i++)
    {
        //printf("%d\t",b[i]);
        arr[i]=b[i];
    }
    //printf("\n");

    }
    for(i=0;i<n;i++)
    {
        printf("%d\t",b[i]);
    }

}


int main()
{
    //int a[]={895,697,733,245,911,500};
    int n;
    
    int i;
    //int *b;
    printf("enter no. of elements\n");
    scanf("%d",&n);
    int *a=(int*)malloc(sizeof(int)*n);
    printf("enter the integers to be sorted\n");
    
    for(i=0;i<n;i++)
    {
    	scanf("%d",&a[i]);
    }
    radixsort(a,n);

    return 0;
}
