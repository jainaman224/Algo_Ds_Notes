#include <iostream>

using namespace std;

const int vertices = 5;

void bellmanford(int adjacency_matrix[vertices][vertices], int source)
{
    int distance[vertices];
    int predecessor[vertices];
    for (int i = 0; i < vertices; i++)
    {
        distance[i] = 9999;
        predecessor[i] = -1;
    }

    distance[source] = 0;

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            for (int k = 0; k < vertices; k++)
            {
                if (adjacency_matrix[j][k] != 0 && distance[j] + adjacency_matrix[j][k] < distance[k])
                {
                    distance[k] = distance[j] + adjacency_matrix[j][k];
                    predecessor[k] = j;
                }
            }
        }
    }

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 1; j < vertices; j++)
        {
            if (adjacency_matrix[i][j] != 0 && distance[i] + adjacency_matrix[i][j] < distance[j])
            {
                cout << "The Graph contains negative weight cycle";
                return;
            }
        }
    }

    cout << "Distance of all the vertices from source " << source << endl;
    cout << "Vertex\tDistance\tpredecessor\n";

    for (int i = 0; i < vertices; i++)
        cout << i << "\t" << distance[i] << "\t\t" << predecessor[i] << endl;
}

int main()
{
    int adjacency_matrix[vertices][vertices] = {
                                                {0, 0, 6, 3, 0},
                                                {3, 0, 0, 0, 0},
                                                {0, 0, 0, 2, 0},
                                                {0, 1, 1, 0, 0},
                                                {0, 4, 0, 2, 0}
                                            };

    bellmanford(adjacency_matrix, 4);
    return 0;
}


/* output
 * Distance of all the vertices from source 4
 * Vertex Distance  predecessor
 * 0  6   1
 * 1  3   3
 * 2  3   3
 * 3  2   4
 * 4  0   -1
 */
