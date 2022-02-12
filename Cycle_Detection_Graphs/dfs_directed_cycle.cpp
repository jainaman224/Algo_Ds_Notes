#include<bits/stdc++.h>
using namespace std;
int N=4;
vector<int> vis(5);
vector<vector<int> > G(N+1);
bool temp;
bool dfs(int root){
	vis[root]=1;
	for(int i=0;i<G[root].size();i++){
		if(vis[G[root][i]]==0)
		  temp=dfs(G[root][i]);
		else if(vis[G[root][i]]==1)
		   return 1;
		if(temp)
		   return 1;   
	}
	vis[root]=2;
	return 0;
}
int main(){
	G[1].push_back(2);
	G[1].push_back(3);
	G[2].push_back(3);
	G[3].push_back(4);
	G[4].push_back(1);
	vector<bool> v;
	for(int i=1;i<=N;i++){
		if(!vis[i]){
			v.push_back(dfs(i));
		}
	}
	int i;
	for(i=0;i<v.size();i++){
		if(v[i]){
			cout<<"cycle exists"<<endl;
			break;
		}
	}
	if(i==v.size())
	  cout<<"cycle does not exist"<<endl;
}
