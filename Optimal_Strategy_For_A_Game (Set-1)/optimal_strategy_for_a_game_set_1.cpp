/*
OPTIMAL STRATEGY FOR A GAME SET - 1
Given Problem Statement : Problem statement: Consider a row of n coins of values v1 . . . vn, where n is even.
We play a game against an opponent by alternating turns. In each turn,
a player selects either the first or last coin from the row,
removes it from the row permanently and receives the value of the coin.
Determine the maximum possible amount of money we can definitely win if we move first.
Note - Note: The opponent is as clever as the user.
*/
// C++ program to find out maximum value from a given sequence of coins

#include <bits/stdc++.h>
using namespace std;

/*Returns optimal value possible that a player can
collect from an array of coins of size n. Note
than n must be even*/
int optimalStrategyOfGame(int* arr, int n)
{
    // Create a table to store solutions of subproblems
    int table[n][n];

    /*Fill table using above recursive formula.
    Note that the table is filled in diagonal fashion from
    diagonal elements to table[0][n-1] which is the result.*/
    for (int gap = 0; gap < n; ++gap){
        for (int i = 0, j = gap; j < n; ++i, ++j){

            /*Here x is value of F(i+2, j), y is F(i+1, j-1) and
            z is F(i, j-2) in above recursive formula*/
            int x = ((i + 2) <= j) ? table[i + 2][j] : 0;
            int y = ((i + 1) <= (j - 1)) ? table[i + 1][j - 1] : 0;
            int z = (i <= (j - 2)) ? table[i][j - 2] : 0;
            table[i][j] = max(arr[i] + min(x, y), arr[j] + min(y, z));
        }
    }

    return table[0][n - 1];
}

// Driver Code to test above function
int main()
{
     int arr1[1005], n;

    //Number of values in array you want to store
     cin >> n;

    //Input taken in array
     for(int i = 0 ; i < n ; i ++ )
          cin >> arr1[i];

    //function call for calculating it's optimal strategy
    printf("%d\n", optimalStrategyOfGame(arr1, n));

return 0;
}

/*
Input for test case 1:
4     // n = 4
8     //input taken in array
15
3
7
Output for test case 1:
22
*/
/*
Input for test case 2:
4     // n = 4
2     //input taken in array
2
2
2
Output for test case 2:
4
*/
/*
Input for test case 3:
6     // n = 6
20    //input taken in array
30
2
2
2
10
Output for test case 3:
42
*/
