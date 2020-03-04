/*

Hamiltonian Cycle - Hamiltonian Path in an undirected adjmat is a path
that visits each vertex exactly once.

A Hamiltonian cycle (or Hamiltonian circuit) is a Hamiltonian Path
such that there is an edge (in the adjmat) from the last vertex to the
first vertex of the Hamiltonian Path.

For more information
Watch "https://www.youtube.com/watch?v=dQr4wZCiJJ4"
This gives a clear explanation regarding the solution

*/

#include<iostream>

#define NODE 5
using namespace std;

int path[NODE];

void printcycle() {

    //Prints the first Hamiltonian cycle found
    cout<<"Hamiltonian Cycle: ";

    for (int i = 0; i < NODE; i++)
        cout << path[i] << " ";

}

bool isValid(int adjmat[NODE][NODE], int v, int k) {

    if (adjmat [path[k-1]][v] == 0)
        return false;

    for (int i = 0; i < k; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool cyclepresent(int adjmat[NODE][NODE], int k) {

    if (k == NODE) {
        if (adjmat[path[k-1]][ path[0] ] == 1 )
            return true;

        else
            return false;
   }

    for (int v = 1; v < NODE; v++) {
        if (isValid(adjmat, v, k)) {
            path[k] = v;

            if (cyclepresent (adjmat, k+1) == true)
                return true;

            path[k] = -1;
        }
   }
    return false;
}

bool hamilcycle(int adjmat[NODE][NODE]) {

    for (int i = 0; i < NODE; i++)
        path[i] = -1;

    path[0] = 0;

    if ( cyclepresent(adjmat, 1) == false ) {
        cout << "Solution does not exist"<<endl;
        return false;
    }

    printcycle();
    return true;
}

int main() {

    int adjmat[NODE][NODE] = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 1, 1},
    {0, 1, 0, 0, 1},
    {1, 1, 0, 0, 1},
    {0, 1, 1, 1, 0},
    };

   hamilcycle(adjmat);
}

/*

Change the adjmat value by below value

int adjmat[NODE][NODE] = {
   {0, 1, 0, 1, 0},
   {1, 0, 1, 1, 1},
   {0, 1, 0, 0, 1},
   {1, 1, 0, 0, 0},
   {0, 1, 1, 0, 0},
};

*/
