//counting sort

#include<stdio.h>
#include<stdlib.h>
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
void countsort(int* a,int n)
{
    int k=findmax(a,n);
    printf("%d\n",k);
    int i;
    int *c,*b;
    c=(int*)malloc(sizeof(int)*(k+1));
    b=(int*)malloc(sizeof(int)*n);
    for(i=0;i<=k;i++)
    {
        c[i]=0;
    }
    
    for(i=0;i<n;i++)
    {
        c[a[i]]++;
    }
    
    for(i=2;i<=k;i++)
    {
        c[i]+=c[i-1];
    }
    
    for(i=n-1;i>=0;i--)
    {
        b[c[a[i]]-1]=a[i];
        
        c[a[i]]--;
    }
    
    for(i=0;i<n;i++)
    {
        printf("%d\t",b[i]);
    }

}


int main()
{
    
    int n;
    
    int i;
    
    printf("enter no. of elements\n");
    scanf("%d",&n);
    int *a=(int*)malloc(sizeof(int)*n);
    printf("enter the integers to be sorted\n");
    
    for(i=0;i<n;i++)
    {
    	scanf("%d",&a[i]);
    }
    countsort(a,n);

    return 0;
}
