//A connected component of an undirected graph is a subgraph in which any two vertices are connected to each other by paths, and which is connected to no additional vertices in the supergraph. 

#include<bits/stdc++.h>
using namespace std;

// Recursive Function to perform DFS on graph using adjacency list
void dfs(vector<int> adj[], bool visited[], int s)
{
    visited[s] = true;
    cout<<s<<" ";
    for(int i = 0;i < adj[s].size(); i++) 
    {
        // if vertex is unvisited, start DFS from that vertex
        if(!visited[adj[s][i]])
            dfs(adj, visited, adj[s][i]);
    }
}

// Function to add edge to an undirected graph
void addEdge(vector<int> adj[], int x, int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}

// Driver Function
int main()
{
    // Initialise number of nodes
    int nodes = 7;
    // Initialise number of edges
    int edges = 6;
    // Initialise Adjacency List for graph
    vector<int> adj[nodes+1];
    // Visited array to keep track of visited nodes
    bool visited[nodes+1];
    /*  Input Graph:
          1----6     4
        /   \   \     \
       2 --- 3   7     5    
    */
    // call to function addEdge
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 6);
    addEdge(adj, 6, 7);
    addEdge(adj, 4, 5);

    // initialise visited array with false
    for (int i = 1; i <= nodes; ++i)
      visited[i] = false;
    
    // variable to count the number of connected components
    int connectedComponents=0;
    // Loop to iterate over all nodes
    for(int i = 1; i <= nodes; i++)
    {
        // if vertex is unvisited, perform DFS
        // If vertex is already visited, the vertex must be a part of already visited connected component
        if(!visited[i])
        {
            cout << "Connected Component " << (connectedComponents+1) << ":"<<endl;
            dfs(adj, visited, i);
            cout<<endl;
            // when we come out of DFS, increment the count of connected components by 1
            connectedComponents++;
        }
    }
    return 0;
}
/*
Output:
Connected Component 1:
1 2 3 6 7
Connected Component 2:
4 5
*/
