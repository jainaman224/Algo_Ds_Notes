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
void quicksort(int* a,int start,int end)
{
	if(start>=end)
	{
		return;
	}
	int r=partition(a,start,end);
	quicksort(a,start,r-1);
	quicksort(a,r+1,end);
	
}


int main()
{
	int *arr1;
	int *arr2;
	int i,t,n;
	printf("Enter no of test cases:"); 
	scanf("%d",&t);
	while(t--){
		printf("No of elements in the array:");
		scanf("%d",&n);
		arr1=(int*)malloc(n*sizeof(int));
		
		printf("Enter the elements:");
		for(i=0;i<n;i++){
			scanf("%d",&arr1[i]);
			
		}
		quicksort(arr1,0,n-1);
		
		for(i=0;i<n;i++)
		{
			printf("%d\t",arr1[i]);
		}
		
	}
	return 0;
	
}
