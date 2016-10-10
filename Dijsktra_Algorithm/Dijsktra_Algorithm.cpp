#include <iostream>
#include <climits>
#include <vector>
#include <set>

using namespace std;

const int numberVertex = 10;

void dijkstra(vector <pair<int, int> > Alist[numberVertex], int source)
{
    int distance[numberVertex], numVisitedVertex, node;
    set <pair <int, int> > heap;

    for(int i = 0; i < numberVertex; ++i)
        distance[i] = INT_MAX;
    
    distance[source] = 0;

    for(int i = 0; i < numberVertex; ++i)
        heap.insert(make_pair(distance[i], i));

    numVisitedVertex = 1;

    while (numVisitedVertex < numberVertex)
    {
        int u = heap.begin()->second;
        if (distance[u] == INT_MAX)
            break;

        int numNeighbours = Alist[u].size();
        for(int vertex = 0; vertex < numNeighbours; vertex++)
        {
            node = Alist[u][vertex].first;
            if (distance[node] > distance[u] + Alist[u][vertex].second)
            {
                heap.erase(make_pair(distance[node], node));
                distance[node] = distance[u] + Alist[u][vertex].second;
                heap.insert(make_pair(distance[node], node));
            }
        }
        heap.erase(heap.begin());
        ++ numVisitedVertex;

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

    vector <pair<int, int> > Alist[numberVertex];
    for (int i = 0; i < numberVertex; ++i)
        for (int j = 0; j < numberVertex; ++j)
            if (graph[i][j])
                Alist[i].push_back(make_pair(j, graph[i][j]));

    dijkstra(Alist, 0);

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
