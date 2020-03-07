#include<stdio.h>
int main()
{
	int a[10][10],i,j,k=1,t;
	int r1,r2,c2,c1,n;
	printf("\nEnter the limit ");
	scanf("%d",&n);
	t=n*n;
	r1=0;r2=n-1,c1=0,c2=n-1;
	while(k<=t)
	{
		for(j=c1;j<=c2;j++)
			a[r1][j]=k++;
		  
		for(i=r1+1;i<=r2;i++)
			a[i][c2]=k++;
		 
		for(j=c2-1;j>=c1;j--)
			a[r2][j]=k++; 
		 
		for(i=r2-1;i>r1;i--)
			a[i][c1]=k++;
		 
		r1++;
		r2--;
		c1++;
		c2--;
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
}
