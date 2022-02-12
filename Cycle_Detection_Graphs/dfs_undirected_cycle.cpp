#include<bits/stdc++.h>
using namespace std;
int N=6;
vector<bool> vis(N+1);
vector<vector<int> > G(N+1);
bool dfs(int root,int p){
	vis[root]=1;
	bool temp=false;
	for(int i=0;i<G[root].size();i++){
		if(G[root][i]==p)
		  continue;
		if(vis[G[root][i]]){
			return 1;
		}  
		else{
			temp=(temp||dfs(G[root][i],root));
		}
	}
	return temp;
}
int main(){
	G[1].push_back(2);
	G[2].push_back(3);
	G[2].push_back(1);
	G[2].push_back(6);
	G[3].push_back(4);
	G[3].push_back(5);
	G[3].push_back(2);
	G[4].push_back(3);
	G[5].push_back(3);
	G[5].push_back(6);
	G[6].push_back(2);
	G[6].push_back(5);
	if(dfs(1,-1))
			cout<<"cycle exists"<<endl;
	else
	  cout<<"cycle does not exist"<<endl;
}
	

