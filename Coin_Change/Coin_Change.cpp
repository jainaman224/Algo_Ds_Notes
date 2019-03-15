#include<bits/stdc++.h>

using namespace std;

// Function to calculate the number of ways of making the desired change using the given coins
int CoinChange(int coins[], int m, int value ) 
{ 
    int dp[value+1];
    memset(dp, 0, sizeof(dp)); 

    // Base case when value is 0
    dp[0] = 1; 
  
    for(int i=0; i<m; i++)
    {
        for(int j=coins[i]; j<=value; j++) 
            dp[j] += dp[j-coins[i]];
    }
    return dp[value]; 
} 

// Driver Function
int main() 
{ 
    int coins[] = {1, 2, 3}; 
    int m = sizeof(coins)/sizeof(coins[0]);
    int value=5;
    cout<<"Number of ways to make the required change:"<<endl;
    cout<<CoinChange(coins, m, value)<<endl; 
    return 0; 
} 
