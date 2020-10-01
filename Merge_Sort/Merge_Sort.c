#include<stdio.h>

void merge(int lf[], int rt[], int a[], int m, int n)
{
	int i,j,k;
	i = j = k = 0;

	while(i<m && j<n)
	{
		if(lf[i]<rt[j])
			a[k++]=lf[i++];
		else
			a[k++]=rt[j++];
	}

	while(i<m)
		a[k++]=lf[i++];

	while(j<n)
		a[k++]=rt[j++];
}

void divide(int a[], int n)
{
	int i, lf[n/2], rt[n-n/2];
	if(n<=1)
		return ;

	for(i=0;i<n/2;i++)
		lf[i]=a[i];

	for(i=n/2;i<n;i++)
		rt[i-n/2]=a[i];

	divide(lf, n/2);
	divide(rt, n-n/2);
	merge(lf, rt, a, n/2, n-n/2);
}


int main()
{
	int n,i;

	//scanf("%d",&n);
	n=7;
	int a[7]={3, 1, 6, 2, 8, 7, 9};
	// for(i=0;i<n;i++)
	// scanf("%d",&a[i]);

	divide(a,n);


	for(i=0;i<n;i++)
	printf("%d ",a[i]);

	printf("\n");
	return 0;
}

// Output :
// 1 2 3 6 7 8 9
