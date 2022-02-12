#include<bits/stdc++.h>
using namespace std;

int binarysearch(int *a,int last,int s,int e,int n,int minm)
{

	if(e<s)
		return s;
	int mid=(s+e)>>1;
	if(a[mid]-last==minm)
		return mid;
	else if(a[mid]-last<minm)
		return binarysearch(a,last,mid+1,e,n,minm);
	else
		return binarysearch(a,last,s,mid-1,n,minm);
}

bool check(int mid,int *a,int n,int c)
{
	int lastpos=0,till=1,i=1;
	while(i<n)
	{
		int j=binarysearch(a,a[lastpos],i,n-c+till+1,n,mid);
		if(a[j]-a[lastpos]<mid)
			j++;
		if(n-j-1<c-till-1)
			return false;
		lastpos=j;
		++till;
		if(till==c)
			return true;
		i=j+1;
	}
	return false;
}
/*
bool checkit(int mid,int *a,int n,int c)
{
	int lastpos=0,till=1,i=1;
	while(i<n)
	{
		if(a[i]-a[lastpos]>=mid)
		{
			lastpos=i;
			if(++till==c)
				return true;	
		}
		i++;
	}
	if(till==c)
		return true;
	return false;
}
*/
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,c;
		scanf("%d%d",&n,&c);
		int i,a[n];
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		int start=0,end=a[n-1]-a[0]+1,mid;
		while(end-start>1)
		{
			mid=(start+end)>>1;
		//	cout<<"start"<<start<<"mid"<<mid<<"end"<<end<<endl;
			if(check(mid,a,n,c))
				start=mid;
			else
				end=mid;
		}
		printf("%d\n",start);
	}
	return 0;
}
