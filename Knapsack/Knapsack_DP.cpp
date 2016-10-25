                                                                      /*DESCRIPTION*/

                                            /*Reusing precalculated results is nothing but Dynamic Programming*/
/*In 0-1 Knapsack problem, WE are given a Knapsack (a kind of bag) and several items with their weight and profit. The bag has a maximum capacity of weight it can hold.
Now your task is to maximise the profit by choosing several items. It is called 0-1 because of the decision values, either an item will be taken or it will be discarded.
The right approach to solve it is using DP (dynamic programming). Let the capacity of Knapsack be K, and there be N items, wt[]  be the array of weights and
wt[i] be the weight of ith item; P[] be the array of profits and P[i] be the profit gained by ith item.
Now you need to maximise Sigma (P[i]), take the sum as SUM. and constraint is Sigma (wt[i]) We can solve it using DP.*/

                                                                  /*SOURCE CODE*/

#include <iostream>

using namespace std;

int max(int a, int b)              // A utility function that returns maximum of two integers
{
    return (a > b) ? a : b;
}

int knapSack(int K, int wt[], int P[], int n)               // Returns the maximum value that can be put in a knapsack of capacity W
{
    int i, w;
    int DP[n + 1][K + 1];

    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= K; w++)
        {
            if(i == 0 || w == 0)
               DP[i][w] = 0;
            else if(wt[i - 1] <= w)
              DP[i][w] = max(P[i - 1] + DP[i - 1][w - wt[i - 1]], DP[i - 1][w]);
            else
              DP[i][w] = DP[i - 1][w];
        }
    }

    return DP[n][K];
}

int knapSack_large(int K, int wt[], int P[], int n)
{
    int i, w;
    int DP[2][K + 1];

    for(i = 1; i <= K; i++)
        DP[0][i] = 0;
    DP[0][0] = 0;
    DP[1][0] = 0;

    for(i = 1; i <= n; i++)
    {
        for(w = 1; w <= K; w++)
        {
            if(wt[i - 1] <= w)
                DP[i & 1][w] = max(P[i - 1] + DP[!(i & 1)][w - wt[i - 1]], DP[!(i & 1)][w]);
            else
                DP[i & 1][w] = DP[!(i & 1)][w];
        }
    }

    return DP[n & 1][K];
}

int main()
{
    int P[] = {11, 22, 33, 44, 55};
    int wt[] = {111, 121, 131, 141, 151};
    int K = 300;
    int n = sizeof(wt) / sizeof(wt[0]);

	cout << knapSack(K, wt, P, n);

        cout << endl << "Memory Optimised KnapSack " << knapSack_large(K, wt, P, n);
    return 0;
}


/* Output

99

*/
