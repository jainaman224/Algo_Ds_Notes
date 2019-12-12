#include<stdio.h>
#include<stdlib.h>
int insert=0,merge=0;
void insertsort(int *arr,int n)
{
	int i,key,j;
	for(i=1;i<n;i++)
	{
		key=arr[i];
		j=i-1;
		while(key<arr[j]&&j>=0)
		{
			arr[j+1]=arr[j];
			j--;
			insert++;
		}
		arr[j+1]=key;
		
	}
}

void mergesort(int *arr,int start,int end)
{
	int mid=(start+end)/2;
	int *a,*b,*c;
	int i=0,j=0,k=0;
	if(start>=end)
	{
		return;
	}
	a=(int*)malloc(sizeof(int)*(mid-start+1));
	b=(int*)malloc(sizeof(int)*(end-mid));
	
	c=(int*)malloc(sizeof(int)*(end-start+1));
	
	mergesort(arr,start,mid);
	mergesort(arr,mid+1,end);
	for(i=start;i<=mid;i++)
	{
		a[i-start]=arr[i];
	}
	for(i=mid+1;i<=end;i++)
	{
		b[i-mid-1]=arr[i];
	}
	
	for(k=0,i=0,j=0;k<(end-start+1);k++)
	{
		if(i>mid-start)
		{
			c[k]=b[j];
			j++;
		}
		else if(j>end-mid-1)
		{
			c[k]=a[i];
			i++;
		}
		else if(a[i]<b[j])
		{
			merge++;
			c[k]=a[i];
			i++;
		}
		else if(b[j]<a[i])
		{
			merge++;
			c[k]=b[j];
			j++;
		}
	}
	for(i=start;i<=end;i++)
	{
		arr[i]=c[i-start];
	}
	
	
	
}
int main()
{
	int arr1[]={4,6,2,7,8,2,10};
	int arr2[]={4,6,2,7,8,2,10};
	int i;
	int size=7;
	
	insertsort(arr1,7);
	printf("Insert sort comparisions:%d\n",insert);
	for(i=0;i<size;i++)
	{
		printf("%d\t",arr1[i]);
	}
	printf("\nMerge sort comparisions:%d\n",merge);
	mergesort(arr2,0,6);
	for(i=0;i<size;i++)
	{
		printf("%d\t",arr2[i]);
	}
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

