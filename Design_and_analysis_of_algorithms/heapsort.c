#include<stdio.h>
#include<stdlib.h>
void swap(int* a,int* b)
{
	int temp;
	temp=(*a);
	(*a)=(*b);
	(*b)=temp;
}
void max_heapify(int* a,int i,int n)
{
	//printf("In max heapify");
	if(2*i>=n)
	{
		return;
	}
	
	if(a[2*i]>a[2*i+1])
	{
		if(a[2*i]>a[i])
		{
			swap(&a[2*i],&a[i]);
			max_heapify(a,2*i,n);
		}
	}
	else
	{
		if(a[2*i+1]>a[i])
		{
			swap(&a[2*i+1],&a[i]);
			max_heapify(a,2*i+1,n);
		}
		
	}
	
	
}



void build_max_heap(int* a,int n)
{
	//printf("In build max heap");
	int i;
	for(i=n/2;i>=1;i--)
	{
		max_heapify(a,i,n);
		
	}
}
void heapsort(int* a,int start,int end)
{
	//printf("In heap sort");
	 build_max_heap(a,end-start+1);
	 int size = end-start+1;
	 while(size!=1)
	 {
	 	swap(&a[start],&a[size]);
	 	size--;
	 	max_heapify(a,1,size);
	 }
	
}

int main()
{
	
	
	int i,t,n;
	//int arr1[6]={0,8,7,4,6,1};
	printf("Enter no of test cases:"); 
	scanf("%d",&t);
	
	while(t--){
		printf("No of elements in the array:");
		scanf("%d",&n);
		arr1=(int*)malloc((n+1)*sizeof(int));
		
		printf("Enter the elements:");
		for(i=1;i<=n;i++){
			scanf("%d",&arr1[i]);
			
		}
		heapsort(arr1,1,n);
		
		for(i=1;i<=n;i++)
		{
			printf("%d\t",arr1[i]);
		}
		
	}
	return 0;
	
}
