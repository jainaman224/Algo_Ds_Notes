#include <bits/stdc++.h>
using namespace std;
#define MAX 9999

int ST[4*MAX];
int A[MAX];
void build(int v, int l, int r)
{

	if(l == r)
	{
		ST[v] = A[l];
		return;
	}

	int mid = (l+r)/2;
	build(2*v, l, mid);
	build(2*v + 1, mid + 1, r);
	ST[v] = ST[2*v] + ST[2*v+1];

}

int query(int v, int l, int r, int ql, int qr)
{
	if(qr < l or ql > r )
		return 0;
	if(ql <= l and qr >= r)
		return ST[v];
	int m = (l+r)/2;
	int left = query(2*v, l,m,ql,qr);
	int right =  query(2*v + 1, m+1,r,ql,qr);
	return left + right;
}

void pointupdate(int v, int l, int r, int p, int val)
{

	if(l == r)
	{
		ST[v] = val;
		return; 
	}

	int mid = (l+r)/2;
	if(p <= mid)
		pointupdate(2*v,l, mid,p,val );
	else
		pointupdate(2*v+1, mid+1, r,p,val);

	ST[v] = ST[2*v]+ ST[2*v + 1];
}

void debugtree(int v, int l, int r)
{
		if(l == r)
	{
		cout<<v<<" -> "<<"("<<l<<","<<r<<")"<<ST[v]<<endl;
		return;
	}

	int mid = (l+r)/2;
	debugtree(2*v, l, mid);
	debugtree(2*v + 1, mid + 1, r);
	cout<<v<<" -> "<<"("<<l<<","<<r<<")"<<ST[v]<<endl;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		cin>>A[i];
	}
	build(1,0,n-1);
	debugtree(1,0,n-1);
	int q;
	cin>>q;
	int a,b,c;
	while(q--)
	{
		cin>>c>>a>>b;
		if(c == 1)	
			cout<<query(1,0,n-1,a,b)<<endl;
		else
			pointupdate(1,0,n-1,a,b);
	}


	return 0;
}

