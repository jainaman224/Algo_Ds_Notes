#include<stdio.h>

void swap(int *x,int *y)
{
	int temp;

	temp=*x;
	*x=*y;
	*y=temp;
}


int main()
{
	int n,a[10000],i,j,k,temp;

	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=(i+1);j<n;j++)
		{
			if(a[i]>a[j])
				swap(&a[i],&a[j]);
				
				/*			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}*/
		}
	for(k=0;k<n;k++)
		printf("%d",a[k]);
	printf("\n");
	}

	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	printf(" ");
	}
	printf("\n");
	return 0;
}

