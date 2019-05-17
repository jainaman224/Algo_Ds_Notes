/*
    The Coin Change problem states that given an amount N, how
    many possible ways are there to make the desired change using
    unlimited supply of coins of given denominations. Example:
    if N = 5 and coins = {1, 2, 3} then
    5 = 1 + 1 + 1 + 1 + 1
    5 = 1 + 1 + 1 + 2
    5 = 1 + 1 + 3
    5 = 1 + 2 + 2
    5 = 2 + 3
*/

#include<bits/stdc++.h>

using namespace std;

// Function to calculate the number of ways of making the desired change using the given coins
int coinChange(int coins[], int m, int value) 
{ 
    int dp[value + 1];
    memset(dp, 0, sizeof(dp)); 

    // Base case when value is 0
    dp[0] = 1; 
  
    for(int i = 0; i < m; i++)
    {
        for(int j = coins[i]; j <= value; j++) 
            dp[j] += dp[j - coins[i]];
    }
    return dp[value]; 
} 

// Driver Function
int main() 
{ 
    int m;
    cout << "Enter number of coins" << endl;
    cin >> m;
    int coins[m], value;
    cout << "Enter denominations of coins" << endl;
    for (int i = 0; i < m; i++)
        cin >> coins[i];
    cout << "Enter value" << endl;
    cin >> value;   
    cout << "Number of ways to make the required change:" << endl;
    cout << coinChange(coins, m, value) << endl; 
    return 0; 
}

/*
Input:
m = 3
coins = {1, 2, 3}
value = 5

Output:
Number of ways to make the required change:
5
*/
