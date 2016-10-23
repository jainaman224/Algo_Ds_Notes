//This file contains an implementation of Dijkstra Algorithm to find shortest path between two elements.
//It contains solution of this codeforces problem. http://codeforces.com/problemset/problem/20/C

//Complexity = O(n log(n))
//Implementation is done using max-heap using STL Priority Queue.


#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX 100010
#define inf 10000000000000ll

std::vector< pair<int,int> > adj[MAX];
ll dist[MAX];
ll parent[MAX];

int main(int argc, char const *argv[])
{
	for (int i = 0; i < MAX; ++i)
	{
		dist[i] = inf;
	}

	int n,m;
	cin>>n>>m;
	int a,b,c;
	for (int i = 0; i < m; ++i)
	{
		cin>>a>>b>>c;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});

	}

	priority_queue< pair<ll,int> > pq;
	dist[1] = 0;
	pq.push({0,1});
	parent[1] = -1;
	int v;
	while(!pq.empty())
	{
		pair<ll, int> p = pq.top();
		pq.pop();
		//p.first *= -1;
		v = p.second;
		for (int i = 0; i < adj[v].size(); ++i)
		{
			int u, c;
			u = adj[v][i].first;
			c = adj[v][i].second;
			if(dist[u] > (dist[v] + c))
			{
				dist[u] = dist[v] + c;
				parent[u] = v;
				pq.push({-dist[u], u});
			}

		}

	}

	if(dist[n] == inf)
		cout<<-1<<endl;
	else
	{
		std::vector<int> v;
		int x = n;
		while(parent[x] != -1)
		{
			v.push_back(x);
			x = parent[x];
		}
		v.push_back(1);

		for (int i = v.size() - 1; i >=0; i--)
		{
			cout<<v[i]<<" ";
		}
		cout<<endl;
	}




	return 0;
}
