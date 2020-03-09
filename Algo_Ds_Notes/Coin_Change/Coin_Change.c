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

#include <stdio.h>
#include <string.h>

// Function to calculate the number of ways of making the desired change using
// the given coins
int coinChange(int coins[], int m, int value) 
{
    int dp[value + 1];
    memset(dp, 0, sizeof(dp));

    // Base case when value is 0
    dp[0] = 1;
    int i, j;
 
    for (i = 0; i < m; i++) {
       for (j = coins[i]; j <= value; j++)
           dp[j] += dp[j - coins[i]];
    }
    return dp[value];
}

// Driver Function
int main() 
{
    int m;
    printf("Enter number of coins\n");
    scanf("%d", &m);
    int coins[m], i, value;
    printf("Enter denominations of coins");
    for (i = 0; i < m; i++)
        scanf("%d", &coins[i]);
    printf("Enter value\n");
    scanf("%d", &value);
    printf("Number of ways to make the required change:\n");
    printf("%d", coinChange(coins, m, value));
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
