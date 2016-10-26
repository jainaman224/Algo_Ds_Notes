#include<stdio.h>
void swap(int *a,int *b)
{
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}

int divide(int a[],int st,int nd)
{
	int i,p_indx,pivot;
	p_indx=st;
		pivot=a[nd];

	for(i=st;i<nd;i++)
	{
		if(a[i]<=pivot)
		{
			swap(&a[i],&a[p_indx]);
			p_indx++;
		}
	}
	printf("%d\n",p_indx);
	swap(&a[p_indx],&a[nd]);
	return p_indx;
}

int Q_sort(int a[],int start,int end)
{
	int p_index;
	if(start<end)
	{
		p_index=divide(a,start,end);
		Q_sort(a,start,p_index-1);
		Q_sort(a,p_index+1,end);
	}
}

int main()
{
	int i,t,n,k,a[10000];
scanf("%d",&t);
while(t--)
{
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	Q_sort(a,0,n-1);

	printf("%d\n",a[k-1]);
//	for(i=0;i<n;i++)
//	printf("%d ",a[i]);
//	printf("\n");
}
return 0;
}
