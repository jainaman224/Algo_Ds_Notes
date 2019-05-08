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

package main

import "fmt"

// Function to calculate the number of ways of making
// the desired change using the given coins
func CoinChange(coins[] int, m int, value int) int {
    dp := make([]int , value + 1) 

    // Base case when value is 0
    dp[0] = 1
    
    /*
        The outer loop runs over the coins array. It selects
        a coin and checks whether a given value can be made 
        using that denomination or not. The inner loop runs
        upto the value we want to obtain.
    */
    for i := 0; i < m; i++ {
        for j := coins[i]; j <= value; j++ { 
            dp[j] += dp[j - coins[i]]
        }
    }

    // this gives the number of ways value can be formed using
    // the given coins
    return dp[value]
} 

// Driver Function
func main() { 
    // Array contaning coins available
    coins := []int{1, 2, 3}
    m := len(coins)
    value := 5
    // Call to CoinChange function
    fmt.Println("Number of ways to make the required change: ")
    fmt.Println(CoinChange(coins, m, value))
} 

/*
    Input:
    N = 5
    coins = {1, 2, 3}

    Output:
    Number of ways to make the required change: 
    5
*/
