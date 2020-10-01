# include <stdio.h>
# include <iostream>
using namespace std; 

// To get maximum of two integers 
#define max(a, b) ((a > b)? a : b)

int eggDrop(int eggs, int floors)
{
    /* A 2D table where entery eggFloor[i][j] will represent minimum 
       number of trials needed for e eggs and f floors. */
    int eggfloor[eggs][floors]; 
    for (int e = 1; e <= eggs; e++)
    {
        for (int f = 0; f <= floors; f++) 
        {
            if(f == 0)
            {
                eggfloor[e][f] = 0;
            }
            else if(e == 1)
            {
                eggfloor[e][f] = f;
            }
            else
            {
                // Fill rest of the entries in table using optimal substructure 
                // property 
                int min = INT_MAX;
                for (int i = 1; i <= f; i++)
                {
                    int sol = max(eggfloor[e-1][i-1], eggfloor[e][f-i]) + 1;
                    if(sol < min)
                    {
                        min = sol;
                    }
                }
                eggfloor[e][f] = min;
            }
        }
    }
    return eggfloor[eggs][floors];
}

int main() 
{ 
    int eggs ,floors; 
    cout << "Enter the number of eggs: ";
    cin >> eggs;
    cout << "Enter the number of floors: ";
    cin >> floors;

    cout << "Minimum number of trials: " << eggDrop(eggs, floors) << endl; 
    return 0; 
}

/*Enter the number of eggs: 2
Enter the number of floors: 10
Minimum number of trials: 4*/
