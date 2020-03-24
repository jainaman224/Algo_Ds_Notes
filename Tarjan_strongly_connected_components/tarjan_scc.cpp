#include<bits/stdc++.h>
int NIL = -1;
using namespace std; 

void addEdge(list<int> *adj,int v, int w) 
{ 
    adj[v].push_back(w); 
} 

void DFS(int V, list<int>*adj,int u, int dis[], int low[], stack<int> *s, bool visited[]) 
{ 
    static int time = 0; 
	//updating the low value , discovery time of vertex
    dis[u] = low[u] = ++time; 
    s->push(u); 
    visited[u] = true; 

    list<int>::iterator i; 
    for (i = adj[u].begin(); i != adj[u].end(); ++i) 
    { 
        int v = *i;  
        if (dis[v] == -1) 
        { 
            DFS(V,adj,v, dis, low, s, visited); 
            low[u]  = min(low[u], low[v]); 
        } 
 
        else if (visited[v] == true) 
            low[u]  = min(low[u], dis[v]); 
    } 
  
    
    if (low[u] == dis[u]) // head node found, pop the stack and print the SCC 
    { 
    	int w = 0;  // To store the extracted vertices 
        while (s->top() != u) 
        { 
            w = (int) s->top(); 
            cout << w << " ";          
            s->pop(); 
        } 
        w = (int) s->top(); 
        cout << w << "\n";        
        s->pop(); 
    } 
}
 
int main() 
{ 
	int V; //the number of vertices present in graph
	cout<<"Enter no.of vertices: ";
	cin>>V; 
	list<int> *adj;    
    adj = new list<int>[V]; //adj is array of adjacency lists of vertices
	int E; //No.of edges in graph
	cout<<"Enter the no.of edges: ";
	cin>>E;
	cout<<"Enter the edges: \n";
	int u,v;
	for(int i=0;i<E;i++)
	{
		cin>>u>>v;
		addEdge(adj,u,v); //adding edges to graph
	}	
    
	//printing the adjacency list to check if it is created correctly
	cout<<"Adjacency list : \n";
    for(auto i=0;i<V;i++)
    {
    	for(auto j=adj[i].begin();j!=adj[i].end();j++)
    	cout<<*j<<" ";
    	cout<<endl;
    }
 	
	int *dis = new int[V]; //array to store discovery times
    int *low = new int[V]; //array to store low value of vertices
    stack<int> *s = new stack<int>(); //creating a stack 
  	bool *visited = new bool[V]; //an array to know if a vertex is already visited or not
 
    // Initializing dis and low, and visited arrays 
    for (int i = 0; i < V; i++) 
    { 
        dis[i] = NIL; 
        low[i] = NIL; 
        visited[i] = false; 
    } 
  
    // Call the DFS function to find strongly connected components in DFS tree with vertex 'i' 
    cout<<"The Strongly connected Components are : \n";
    for (int i = 0; i < V; i++) 
        if (dis[i] == NIL) 
            DFS(V, adj,i, dis, low, s, visited); 

	/*
	Example :
	For V=5,E=5
    addEdge(adj,1, 0); 
    addEdge(adj,0,2); 
    addEdge(adj,2,1); 
    addEdge(adj,0,3); 
    addEdge(adj,3, 4);
    The Strongly Connected Components are : 
    4
    3
    1 2 0  
    */ 

    return 0; 
} 
