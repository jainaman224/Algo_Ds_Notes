#include<stdio.h>
#include<stdlib.h>
void swap(int* a,int* b)
{
	int temp;
	temp=(*a);
	(*a)=(*b);
	(*b)=temp;
}
int partition(int* a,int start,int end)
{
	
	int x=a[start];
	
	int i=start;
	int temp;
	int j;
	for(j=start+1;j<=end;j++)
	{
		if(a[j]<x)
		{
			i++;
			swap(&a[j],&a[i]);
					
		}
		
	}
	swap(&a[start],&a[i]);
	return i;
}
void rand_quicksort(int* a,int start,int end,int kth)
{
	if(start>=end)
	{
		printf("%dth element is %d\n",kth,a[kth]);
	
		return;
	}
	int k=rand()%(end-start+1)+start;
	swap(&a[start],&a[k]);
	int r=partition(a,start,end);
	if((r+1)==kth)
	{
		printf("%dth element is %d\n",r+1,a[r]);
		return;
	}
	else if(r>kth)
	{
		rand_quicksort(a,start,r-1,kth);
	}
	else
	{
		rand_quicksort(a,r+1,end,kth);
	}
	
	
	
}
int main()
{
	
	
	int i,t,n,kth;
	int* arr1;
	//int arr1[6]={0,8,7,4,6,1};
	printf("Enter no of test cases:\t"); 
	scanf("%d",&t);
	
	while(t--){
		printf("No of elements in the array:");
		scanf("%d",&n);
		arr1=(int*)malloc((n)*sizeof(int));
		
		printf("Enter the elements:");
		for(i=1;i<=n;i++){
			scanf("%d",&arr1[i]);
			
		}
		printf("Enter the value of k"); 
		scanf("%d",&kth);
		rand_quicksort(arr1,0,n-1,n-kth+1);
		//printf("%d",arr1[kth]);
		
		/*for(i=0;i<n;i++)
		{
			printf("%d\t",arr1[i]);
		}
		*/
	}
	return 0;
	
}



