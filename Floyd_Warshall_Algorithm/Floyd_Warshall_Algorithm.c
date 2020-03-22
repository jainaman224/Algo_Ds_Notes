//C Program for Floyd Warshall Algorithm

#include<stdio.h>

//Number of vertices in the graph
#define A 4

//Define INF(infinite) as a large value. This will be used for
//the vertices that are not connected with each other
#define INF 1000000

//A function to print the solution matrix
void printSolution(int dist[][A]);          

//Function to solve ALL-PAIR SHORTEST PATH problem
//using Floyd Warshall Algorithm
void floydWarshall (int graph[][A])
{

    //dist[][] will hold the final shortest distance between
    //every pair of vertices
    int dist[A][A], i, j, k;

    for (i = 0; i < A; i++)
        for (j = 0; j < A; j++)
            dist[i][j] = graph[i][j];

    /* Add all vertices one by one to the set of intermediate vertices
    ---> Before start of an iteration, we have shortest distances
    between all pairs of vertices such that the shortest distances
    consider only the vertices in set {0, 1,..k-1} as intermediate vertices
    ----> After the end of an iteration, vertex no. k is added to
    the set of intermediate vertices and the set becomes {0, 1, 2,..k} */

    for (k = 0; k < A; k++)
    {
        //Pick all vertices as source one by one
        for (i = 0; i < A; i++)
        {
            //Pick all vertices as destination for the above picked source
            for (j = 0; j < A; j++)
            {
                //If vertex k is on the shortest path from i to j,
                //then update the value of dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    //Print the shortest distance matrix
    printSolution(dist);   
}

//Function to print the solution
void printSolution(int dist[][A])
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

    int graph[A][A] = { {0,   9,  INF, 8},
                        {INF, 0,   6, INF},
                        {INF, INF, 0,   5},
                        {INF, INF, INF, 0}
                      };

    //Calling function to execute Floyd Warshall Algorithm
    floydWarshall(graph);
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
        INF   INF   INF    0 */
