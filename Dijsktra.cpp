//g++  5.4.0

#include <bits/stdc++.h>
#define ll long long 
#define mod 1000000007
#define INF mod*mod
using namespace std;
vector<pair<ll,ll>>g[100001];
ll n;
void dij(ll s)
{
    //ll i;
    vector<ll>dis(100001,INT_MAX);
    //cout<<INF<<endl;
    dis[s]=0;
    set<pair<ll,ll>>st;
    st.insert(make_pair(0,s));
    while(!st.empty())
    {
        pair<ll,ll>tmp=*(st.begin());
        ll u=tmp.second;
        st.erase(st.begin());
        for(auto i:g[u])
        {
            ll v=i.first;
            ll w=i.second;
            if(dis[v]>dis[u]+w)
            {
                /*if(dis[v]!=INF)
                {
                    st.erase(st.find(make_pair(dis[v],v)));
                }*/
                dis[v]=dis[u]+w;
                st.insert(make_pair(dis[v],v));
            }
                
        }
    }
    for(ll i=1;i<=n;i++)
    {
        cout<<dis[i]<<" ";
    }
    return ;
}
int main()
{
    ll t,i,j,m,u,v,w,s;
    cin>>n>>m;
    while(m--)
    {
        cin>>u>>v>>w;
        g[u].push_back(make_pair(v,w));
        g[v].push_back(make_pair(u,w));
    }
    cin>>s;
    dij(s);
}