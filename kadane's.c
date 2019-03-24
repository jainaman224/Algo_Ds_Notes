#include<stdio.h>

int max(int ans,int sum)
{
	return (ans>sum?ans:sum);
	
}

int max_sum(int a[],int n)
{
	int ans=0;
	int sum=0,i;
	for(i=0;i<n;i++)
	{
		if(sum+a[i]>0)
			sum+=a[i];
		else
			sum=0;
		ans=max(ans,sum);
		
	}
	
	return ans;
}
int main()
{
	int n,i,k;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	k=max_sum(a,n);
	printf("Maximum sum of sub-array %d",k);
		
	return 0;
}
