// C++program to check if a connected 
// graph is bipartite or not suing DFS 
#include<bits/stdc++.h>
using namespace std;

// to keep a check whether a node is discovered or not
unordered_map<int,bool> visited;

// to color the vertices of graph with 2 color
unordered_map<int,int> color;

// function to store the connected nodes
void add_edge(vector<int> adj[],int u,int v,bool flag=true)
{
	adj[u].push_back(v);
	if(flag){
		adj[v].push_back(u);
	}
}

// function to check whether a graph is bipartite or not 
bool isBipartite(vector<int> adj[],int src)
{
	// mark present vertic as visited 
	visited[src]=true;

	for(int i=0;i<adj[src].size();i++)
	{
		int u=adj[src][i];

		// if vertex u is not explored before
		if(!visited[u])
		{
			// mark its color opposite to its parent
			color[u]=!color[src];
			
			// if the subtree rooted at vertex src is not bipartite 
			if(!isBipartite(adj,u))
			{
				return false;
			}
		
		}
		// if two adjacent are colored with same color then 
        	// the graph is not bipartite 
		else if(color[u]==color[src])
		{
			return false;
		}
	}
	return true;
}

int main(){

	int n=6;
	vector<int> adj[n+1];

	// adding edges to the graph 
	add_edge(adj,1,2);
	add_edge(adj,2,3);
	add_edge(adj,3,4);
	add_edge(adj,4,5);
	add_edge(adj,5,6);
	add_edge(adj,6,4);

	

	for(int i=1;i<=n;i++)
	{
		if(!visited[i])
		{
			//give color of start node as 1
			color[i]=1;
			if(isBipartite(adj,i)){
				cout<<"Graph is bipartite\n";
			}
			else{
				cout<<"Graph not bipartite\n";
			}	
		}
	}

	return 0;
}





