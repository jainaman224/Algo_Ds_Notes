#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

vector<ll> parent, size;

void make_set(ll n)
{
    parent.resize(n);
    size.resize(n);
    for(ll i=0; i<n; i++)
    {
        parent[i]=i;
        size[i]=1;
    }
}

ll find(ll x)
{
    if(parent[x]==x)
        return x;
    return parent[x]=find(parent[x]);
}

void union_sets(ll x, ll y)
{
    ll a=find(x), b=find(y);
    if(a!=b)
    {
        if(size[a]<size[b])
            swap(a, b);
        parent[b]=a;
        size[a]+=size[b];
    }
}

void print(ll n)
{
    unordered_map<ll, vector<ll>> m;
    for(ll i=0; i<n; i++)
        m[parent[i]].pb(i);
    for(auto y:m)
    {
        for(auto x:y.second)
            cout<<x<<" ";
        cout<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n=5;
    make_set(n);
    union_sets(0, 1);
    union_sets(2, 3);
    union_sets(4, 3);
    union_sets(2, 3);
    print(n);
    return 0;
}
