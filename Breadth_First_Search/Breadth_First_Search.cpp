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
    // Number of vertices is 8
    Graph graph(8);

    // Create edges between vertices
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(1, 4);
    graph.addEdge(2, 0);
    graph.addEdge(2, 3);
    graph.addEdge(3, 3);
    graph.addEdge(3, 6);
    graph.addEdge(4, 0);
    graph.addEdge(4, 5);
    graph.addEdge(5, 6);
    graph.addEdge(5, 7);
    graph.addEdge(6, 2);
    graph.addEdge(7, 3);

    cout << "Breadth First Traversal is : ";
    graph.bfs(0);

    return 0;
}


/* Output

Breadth First Traversal is : 0 1 2 4 3 5 6 7

*/
