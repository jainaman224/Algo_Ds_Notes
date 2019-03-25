#include<stdio.h>

int max(int ans,int sum)
{
	return (ans>sum?ans:sum);
	
}

int max_sum_negative_array(int a[],int n)
{//since in  an array containing only negative elments only no non neagative element maximum sum will be the smallest number
	int ans=a[0],i;
	
	for(i=0;i<n;i++)
	{
		if(a[i]>ans)
			ans=a[i];
	}		
	return ans;
	
	
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
	int n,i,k,flag=0;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		if(a[i]>=0)
		{
			flag=1;
			break;
		}	
	}
	
	
	if(flag==1)
	{
		k=max_sum(a,n);
		printf("Maximum sum of sub-array %d",k);	
	}
	else
	{
			k=max_sum_negative_array(a,n);
		printf("Maximum sum of sub-array %d",k);
		
	}
		
	return 0;
}


/*1.input :3
	 -1 -2 -3
   output :-1
  2.input :3
	 -1 2 3
   output :5
  3input :3
	 -1 0 -3
   output :0
  */
