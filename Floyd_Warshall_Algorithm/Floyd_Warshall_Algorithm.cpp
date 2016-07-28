#include <iostream>
#include <limits.h>
#include <iomanip>
#define INF INT_MAX
#define V 4
using namespace std;

void printSolution(int dist[V][V]);

void floydWarshall(int graph[V][V])
{ int dist[V][V],i,j,k;
  for(i = 0;i < V;i++)
    for(j = 0;j < V;j++)
      dist[i][j]=graph[i][j];
      
      
  for(k = 0;k < V;k++)
    for(i = 0;i < V;i++)
      for(j = 0;j < V;j++)
       { if(dist[i][k] != INF &&
            dist[k][j] != INF &&
            dist[i][k] + dist[k][j] < dist[i][j])
            dist[i][j] = dist[i][k] + dist[k][j];
       }
  printSolution(dist);
} 

void printSolution(int dist[V][V])
{   cout<<"Following matrix shows the shortest distances between each pair of vertices\n";
     for (int i = 0;i < V;i++)
      {for (int j = 0;j < V;j++)
        { if (dist[i][j] == INF)
           cout<<setw(7)<<"INF";
          else
           cout<<setw(7)<<dist[i][j];
        }
       cout<<"\n";
      } 
}

int main() {
  int graph[V][V]={     {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                  };
  floydWarshall(graph);                
  return 0;
}

/* OUTPUT

Following matrix shows the shortest distances between each pair of vertices
      0      5      8      9
    INF      0      3      4
    INF    INF      0      1
    INF    INF    INF      0

*/
