#include<bits/stdc++.h>
#define A 4
int Infinity=1000000;

using namespace std;

void output(int graph[A][A])
{
    cout<<"The matrix below shows the shortest distances between each pair of vertices\n";
    for(int i=0; i<A; i++, cout<<endl)
      for(int j=0; j<A; j++, cout<<"\t")
        (graph[i][j]==Infinity)?cout<<"INFINITY":cout<<graph[i][j];
}

void FloydWarshall(int graph[A][A])
{
  for(int k=0; k<A; k++)
    for(int i=0; i<A; i++)
      for(int j=0; j<A; j++)
        graph[i][j]=min(graph[i][j], graph[i][k]+graph[k][j]);
    output(graph);
}

int main() {
  int graph[A][A] = {     {0,        8,        Infinity, 15},
                          {Infinity, 0,        7,        Infinity},
                          {Infinity, Infinity, 0,        7},
                          {Infinity, Infinity, Infinity, 0}
                    };
  FloydWarshall(graph);
  return 0;
}

/* OUTPUT
The matrix below shows the shortest distances between each pair of vertices
           0           8          15          15
    INFINITY           0           7          14
    INFINITY    INFINITY           0           7
    INFINITY    INFINITY    INFINITY           0
*/