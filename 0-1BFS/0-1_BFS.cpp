/* Given a graph where every edge has weight as either 0 or 1. 
 A source vertex is also given in the graph. 
 Find the shortest path from source vertex to every other vertex.
 Complexity O(V+E) */

#include<bits/stdc++.h> 
#define V 1000

using namespace std; 

int dist[V];  // array to store the shortest distances
// the graph stores vectors of int pairs such that graph[node].first = destination node & graph[node].second = edge weight
vector < pair <int , int> > graph[V];
deque <int> Q; // keeps track of edges during BFS

//FUNCTIONS: 

int distbfs(int i, int v) // returns the new distance to the destination node
{
    return dist[v] + graph[v][i].second;
}

/* To print shortest distance from given source (here, 0) to 
 every other node */
void zeroOneBFS(int source, int n) 
{ 
    // Marking distances of all nodes from the source except itself as infinity  
    int i = 0;
    while (i < n) 
    {
        if (i == source)
        {
            dist[i] = 0; // distance of source from itself is 0
            Q.push_back(i); 
        }
        else
            dist[i] = INT_MAX; // other vertices
        i++;
    }

    while (!Q.empty()) 
    { 
        int v = Q.front(); 
        Q.pop_front(); 

        for (int i = 0; i < graph[v].size(); i++) 
        { 
        // checks for the shortest distance to the nodes
            if (dist[graph[v][i].first] > distbfs(i, v)) 
            { 
                dist[graph[v][i].first] = distbfs(i, v); 

                /* Put destination vertex connected by 0 edge to front and vertex connected by 1 
                edge to back so that vertices are processed 
                in ascending order of weights. */
                if (graph[v][i].second == 0) 
                    Q.push_front(graph[v][i].first); 
                else
                    Q.push_back(graph[v][i].first); 
            } 
        } 
    } 

    // printing the dist array that stores the shortest distances 
    for (int i = 0; i < n; i++) 
        cout << dist[i] << endl; 
} 

// function to add edges to the graph
void addEdge(int u, int v, int wt) 
{
    graph[u].push_back( make_pair(v, wt)); 
    graph[v].push_back( make_pair(u, wt)); 
}

// to initialise the graph
void create_graph()
{
    addEdge(0, 1, 0); 
    addEdge(0, 7, 1); 
    addEdge(1, 7, 1); 
    addEdge(1, 2, 1); 
    addEdge(2, 3, 0); 
    addEdge(2, 5, 0); 
    addEdge(2, 8, 1); 
    addEdge(3, 4, 1); 
    addEdge(3, 5, 1); 
    addEdge(4, 5, 1); 
    addEdge(5, 6, 1); 
    addEdge(6, 7, 1); 
    addEdge(7, 8, 1); 
}

int main() 
{ 
    int n = 9; // no of vertices
    int e = 13; // no of edges
    create_graph();
    int source = 0; // start BFS from 0 
    zeroOneBFS(source, n); 
} 
/*OUTPUT:
0
0
1
1
2
1
2
1
2
*/
