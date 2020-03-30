//Floyd Warshall Algorithm using C

#include<stdio.h>

//Vertices count in the Graph
#define A 4

//Defining INF(infinite) as a large value.
//It's used for non-connected vertices
#define INF 999999

//Declaring a function to print the solution matrix
void solution(int dist[][A]);          

//Function to solve ALL-PAIR SHORTEST PATH problem
//using Floyd Warshall Algorithm
void floyd_warshall(int graph[][A])
{
    //Final result will be held in dist[][]
    int dist[A][A], i, j, k;

    for (i = 0; i < A; i++)
        for (j = 0; j < A; j++)
            dist[i][j] = graph[i][j];

    for (k = 0; k < A; k++)
    {
        //Select the vertices as source one by one
        for (i = 0; i < A; i++)
        {
            //Select the vertices as destination for above picked source
            for (j = 0; j < A; j++)
            {
                //When the vertex k is on the shortest path from i to j,
                //then update the value of dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    solution(dist);   
}

//Function to print the solution
void solution(int dist[][A])
{
    printf ("The following matrix shows the shortest distances"
            " between every pair of vertices: \n");
    for (int i = 0; i < A; i++)
    {
        for (int j = 0; j < A; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int graph[A][A] = {{0, 9, INF, 8},
                       {INF, 0, 6, INF},
                       {INF, INF, 0, 5},
                       {INF, INF, INF, 0}
                      };

    //Calling function to execute Floyd Warshall Algorithm
    floyd_warshall(graph);
    return 0;
}
//Sample Input :

/*The following weighted graph is our input
            8
       (0)------->(3)
        |         /|\
      9 |          |
        |          | 5
       \|/         |
       (1)------->(2)
            6

OUTPUT :

The following matrix shows the shortest distance between
every pair of vertices:

          0     9    15    8
        INF     0     6   11
        INF   INF     0    5
        INF   INF   INF    0 
*/
