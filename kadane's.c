#include<stdio.h>

int max(int ans,int sum)
{
	return (ans>sum?ans:sum);
	
}
//here ans holds the final largest sum of contiguous array
//sum holds the sum the sum of contiguous array
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
{//here variable i is for loop,k is a variable which will hold maximum sum of contuguous array returned 
	int size,i,k;
	scanf("%d",&size);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	k=max_sum(a,size);
	printf("Maximum sum of sub-array %d",k);
		
	return 0;
}
/*input : 5
	   4 -1 -2 5 -3
 output : 6
 */
/* here largest contiguous array sum is =4+(-1)+(-2)+5=6
 */
