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

import java.io.*;
import java.util.Scanner;

class CoinChangeProblem
{
// Function to calculate the number of ways of making the desired change using the given coins
    public static int CoinChange(int coins[], int m, int value) 
    { 
        int dp[] = new int[value + 1];

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
    public static void main(String[] args) 
    { 
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of coins");
        int m = sc.nextInt(); 
        System.out.println("Enter denominations of coins");
        int coins[] = new int[m + 1];
        for(int i = 0; i < m; i++)
            coins[i] = sc.nextInt();
        System.out.println("Enter value");
        int value = sc.nextInt();
        System.out.println("Number of ways to make the required change:");
        System.out.println(CoinChange(coins, m, value));  
    }
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
