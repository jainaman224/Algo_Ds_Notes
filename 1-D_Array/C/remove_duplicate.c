#include<stdio.h>
int main()
{
	int i,n,j,k;
	printf("Enter the size of array : ");
    scanf("%d",&n);
    int a[n];
    printf("The array elements are : ");
    for(i=0;i<n;i++)
    {
    	scanf("%d",&a[i]);
	}
	printf("The array without duplicates : ");
	for(i=0;i<n;i++)
	{
	for(j=i+1;j<n;j++)
	{
	if(a[i]==a[j])
	{
		for(k=j;k<n;k++)
		{
			a[k]=a[k+1];
		}
		n--;
		j--;
	}	
    }
    }
    for (i = 0; i < n; i++) 
	{
        printf("%d ", a[i]);
    }
    
	return 0;
}
