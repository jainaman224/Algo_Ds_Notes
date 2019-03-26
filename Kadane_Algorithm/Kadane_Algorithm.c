#include<stdio.h>

int max(int ans,int sum)		//function to calculate maximum of two
{
	return (ans>sum?ans:sum);
}

int max_sum(int a[],int size)		//function to calculate max sum	
{
	int ans=0;
	int sum=0,i;
	for(i=0;i<size;i++)
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
	int size,i,k,max;
	scanf("%d",&size);
	int a[size];
	for(i=0;i<size;i++)
		scanf("%d",&a[i]);
	max=a[0];
	for(i=0;i<size;i++)
	{
		if(a[i]>max)		// putting maximum value in 
			max=a[i];
		if(a[i]>=0)
		{
			break;
		}	
	}
	
	if(max>=0)			//if maximum value is positive value than call max_sum(int *,int ) function
	{
		k=max_sum(a,size);
		printf("Maximum sum of sub-array %d",k);	
	}
	else
	{
		printf("%d",max);	//if max element is negative than max  itself is the maximum sum
	}
		
	return 0;
}


/*
output:
5
-8 -7 -2 -13 -74
-2
*/
/*output
5
-1 5 -3 10 -11
Maximum sum of sub-array 12
*/
