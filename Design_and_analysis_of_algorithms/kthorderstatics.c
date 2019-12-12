#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
	int temp=(*a);
	(*a)=(*b);
	(*b)=temp;
}

int sort(int *arr,int start,int end)
{
	int i,j;
	for(i=start;i<end;i++)
	{
		for(j=i+1;j<=end;j++)
		{
			if(arr[i]>arr[j])
			{
				swap(&arr[i],&arr[j]);
			}
		}
	}
}

int partition(int* a,int start,int end,int pivot)
{


	swap(&a[start],&a[pivot]);
	int x=a[start];
	int i=start;
	//int temp;
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
int indexOf(int *arr,int start,int end,int value)
{
	int i;
	for(i=start;i<=end;i++)
	{
		if(arr[i]==value)
		{
			return i;
		}
	}
}

//kth order statistics
int selectk(int *arr,int start,int end,int index,int group_size)
{
	//-------sort each group size--------------
	int i,j,val,median;
	int sizex,sizearr=end-start+1;
	//int *brr=(int*)malloc(sizeof(int)*(end+1));
	/*for(i=start;i<=end;i++)
	{
	    brr[i]=arr[i];
	}*/
	int ii;
	for(i=0,j=0;j<sizearr/group_size;j++,i+=group_size)
	{
		sort(arr,start+i,start+i+group_size-1);
	}
	ii=i;
	if(sizearr%group_size!=0)
        sort(arr,start+ii,end);

	//------------create array of medians------------

    int *x;
	if(sizearr%group_size==0)
	{
		sizex=sizearr/group_size;
		x=(int *)malloc(sizeof(int)*sizex);
        for(i=0;i<sizex;i++)
        {
            x[i]=arr[start+group_size*i+(group_size-1)/2];
        }

	}
	else
	{
		sizex=(sizearr/group_size)+1;
		x=(int *)malloc(sizeof(int)*sizex);
        for(i=0;i<sizex-1;i++)
        {
            x[i]=arr[start+group_size*i+(group_size-1)/2];
        }
        x[sizex-1]=arr[(start+ii+end)/2];
	}
	//sizex=(sizearr/group_size);
	/*int *x=(int *)malloc(sizeof(int)*sizex);
	for(i=0;i<sizex;i++)
	{
		x[i]=brr[start+group_size*i+(group_size-1)/2];
	}*/


	//----------choose a good pivot-----------
	if(sizex<=group_size)
    {
        sort(x,0,sizex-1);
        median = x[sizex/2];
    }
    else
    {
        median = selectk(x,0,sizex-1,sizex/2+1,group_size);
    }

	//free(brr);

    free(x);
	int r=partition(arr,start,end,indexOf(arr,start,end,median));
	//printf("r value:%d\n",r);

	if((r+1)==index)
	{

		return median;
	}
	else if((r+1)>index)
	{
		return selectk(arr,start,r-1,index,group_size);
	}
	else
	{
		return selectk(arr,r+1,end,index,group_size);
	}
}


int main()
{
	int i,t,n,kth,grpsize;
	int *arr1;
	//int arr1[6]={0,8,7,4,6,1};

    printf("enter no. of test cases:\t");
    scanf("%d",&t);
	int elem;

	while(t--){
		printf("\nNo of elements in the array:\t");
		scanf("%d",&n);
		arr1=(int*)malloc((n)*sizeof(int));
        printf("enter group size:\t");
        scanf("%d",&grpsize);
		printf("Enter the elements:\n");
		for(i=0;i<n;i++)
			scanf("%d",&arr1[i]);
        printf("Enter value of k[1-based index]:\t");
        scanf("%d",&kth);
        elem=selectk(arr1,0,n-1,kth,grpsize);
		printf("%d smallest element is %d\n",kth,elem);

		}

		/*for(i=0;i<6;i++)
		{
			printf("%d\t",arr1[i]);
		}*/
	return 0;

}
//changed
//partition:i=start
//sort:brr<-arr
//median array:x[i]=brr<-arr
//changed median base case
