#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
    int numberVertex;
    vector <int> *adjacency;

  public:
    // Constructor to initialise graph
    Graph(int numberVertex)
    {
        this->numberVertex = numberVertex;
        adjacency = new vector <int> [numberVertex];
    }

    // Function to add edge between source and destination
    void addEdge(int source, int destination)
    {
        adjacency[source].push_back(destination);
    }

    // Function to perform Breadth First Search
    void bfs(int starting);
};

void Graph::bfs(int starting)
{
    bool visited[numberVertex];

    for (int i = 0; i < numberVertex; i++)
        visited[i] = false;

    queue <int> queue_vertex;

    visited[starting] = true;
    queue_vertex.push(starting);

    while (!queue_vertex.empty())
    {
        starting = queue_vertex.front();
        cout << starting << " ";
        queue_vertex.pop();

        for (vector <int> :: iterator it = adjacency[starting].begin(); it != adjacency[starting].end(); ++it)
        {
            if(!visited[*it])
            {
                visited[*it] = true;
                queue_vertex.push(*it);
            }
        }
    }
}

int main()
{
    // Number of vertices
    int n;
    cin >> n;
    Graph graph(n);

    int edges;
    cin >> edges;
    // Create edges between vertices
    int u, v;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    cout << "Breadth First Traversal is: ";
    graph.bfs(0);

    return 0;
}


/* 
Input:
8
14
0 1
0 2
1 2
1 4
2 0
2 3
3 3
3 6
4 0
4 5
5 6
5 7
6 2
7 3

Output:

Breadth First Traversal is: 0 1 2 4 3 5 6 7

*/
