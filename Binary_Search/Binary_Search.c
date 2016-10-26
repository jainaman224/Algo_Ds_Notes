//Program for Binary Seach implemented in C
#include<stdio.h>

int main()
{
	int n,a[11],i,ele;
	printf("\nEnter the number of elements you want to be in the array,should be less than or equal to 10\n");
	scanf("%d",&n);
	printf("\nStart entering the elements in increasing order,as binary search will only work if the elements are sorted\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("\nEnter the element that you want to be searched\n");
	scanf("%d",&ele);
	int mid,first,last,flag=0;
	first=0;
	last=n-1;
	while(first<last)
	{
		mid=(first+last)/2;
		if(a[mid]==ele)
		{
			flag=1;
			break;
		}
		else if(a[mid]>ele)
			last=mid-1;
		else
			first=mid+1;
	}
	if(flag==1)
	printf("\nThe element %d was found at position %d",ele,mid+1);
	else
		printf("The element %d was not found in the array you entered",ele);
}