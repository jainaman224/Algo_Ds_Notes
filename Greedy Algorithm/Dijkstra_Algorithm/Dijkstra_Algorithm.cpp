#include <iostream>
#include <climits>

using namespace std;

const int numberVertex = 10;

int minDistance(int distance[], bool ShortestPathTree[])
{
    int min = INT_MAX, min_index;

    for(int vertex = 0; vertex < numberVertex; vertex++)
    {
        if(ShortestPathTree[vertex] == false && distance[vertex] <= min)
        {
            min = distance[vertex];
            min_index = vertex;
        }
    }

    return min_index;
}

void dijkstra(int graph[numberVertex][numberVertex], int source)
{
    int distance[numberVertex];
    bool ShortestPathTree[numberVertex];

    for(int i = 0; i < numberVertex; i++)
    {
        distance[i] = INT_MAX;
        ShortestPathTree[i] = false;
    }

    distance[source] = 0;

    for(int count = 0; count < numberVertex - 1; count++)
    {
        int u = minDistance(distance, ShortestPathTree);

        ShortestPathTree[u] = true;

        for(int vertex = 0; vertex < numberVertex; vertex++)
            if(ShortestPathTree[vertex] == 0 && graph[u][vertex] != 0 &&
                distance[u] != INT_MAX && distance[u] + graph[u][vertex] < distance[vertex])
                distance[vertex] = distance[u] + graph[u][vertex];
    }

    cout << "Distance from Source:" << endl;
    cout << "Vertex\t\tDistance" << endl;
    for(int i = 0; i < numberVertex; i++)
        cout << i << "\t\t" << distance[i] << endl;
}

int main()
{
    int graph[numberVertex][numberVertex] = {{0, 14, 0, 7, 0, 0, 0, 8, 0, 10},
                                             {14, 0, 8, 0, 0, 0, 0, 11, 0, 0},
                                             {0, 8, 0, 7, 0, 4, 0, 0, 2, 0},
                                             {7, 0, 7, 0, 9, 12, 0, 0, 0, 5},
                                             {0, 0, 0, 9, 0, 0, 0, 0, 0, 0},
                                             {0, 0, 4, 0, 0, 0, 2, 0, 0, 11},
                                             {0, 0, 0, 12, 0, 2, 0, 1, 6, 15},
                                             {8, 11, 0, 0, 0, 0, 1, 0, 7, 0},
                                             {0, 0, 2, 0, 0, 0, 6, 7, 0, 0},
                                             {10, 0, 0, 5, 0, 11, 15, 0, 0, 0}};

    dijkstra(graph, 0);

    return 0;
}


/* Output

Distance from Source:
Vertex		Distance
0		0
1		14
2		14
3		7
4		16
5		11
6		9
7		8
8		15
9		10

*/
