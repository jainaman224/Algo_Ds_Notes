#include<stdio.h>
int main()
{
	int i,n,m,c=0,j,temp,num;
	printf("Enter the sizeof the array\n");
	scanf("%d",&n);
	int a[n],mid,start,end;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("enter the number to be searched\n");
	scanf("%d",&num);
				for(i=0;i<n;i++)
				for(j=0;j<n-1;j++)
					if(a[j]>a[j+1])
						{temp=a[j+1];a[j+1]=a[j];a[j]=temp;}
			printf("Your array sorted	\n");
			for(i=0;i<n;i++)
				printf("%d  ",a[i]);
			start=0;end=n-1;
			while(start<=end)
			{
				mid=(start+end)/2;
				if(a[mid]==num)
				{  printf("\nNUmber found at %d Position\n",mid+1);c++;break;	 }
				else if(a[mid]<num)
					start=mid+1;
				else if(a[mid]>num)
					end=mid-1;
			}
			if(c==0)printf("\nNumber not found\n");
			
		return 0;
}
