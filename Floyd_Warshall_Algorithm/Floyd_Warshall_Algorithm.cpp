#include <iostream>
#include <limits.h>
#include <iomanip>

#define Infinity INT_MAX
#define A 4

using namespace std;

void FloydWarshall(int graph[A][A]);

void output(int length[A][A]);

void FloydWarshall(int graph[A][A])
{
  int length[A][A],x,y,z;
  for(x = 0; x < A; x++)
    for(y = 0; y < A; y++)
      length[x][y] = graph[x][y];

  for(z = 0; z < A; z++)
    for(x = 0; x < A; x++)
      for(y = 0; y < A; y++)
       { if(length[x][z] != Infinity &&
            length[z][y] != Infinity &&
            length[x][z] + length[z][y] < length[x][y])
            length[x][y] = length[x][z] + length[z][y];
       }
  output(length);
}

void output(int length[A][A])
{
     cout << "The matrix below shows the shortest distances between each pair of vertices\n";
     for (int x = 0; x < A; x++)
      {
        for (int y = 0; y < A; y++)
        {
          if (length[x][y] == Infinity)
           cout << setw(12) << "INFINITY";
          else
           cout << setw(12) << length[x][y];
        }
       cout << endl;
      }
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
