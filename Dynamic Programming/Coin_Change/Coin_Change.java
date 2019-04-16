import java.io.*;

class CoinChangeProblem
{
// Function to calculate the number of ways of making the desired change using the given coins
    public static int CoinChange( int coins[], int m, int value) 
    { 
        int dp[]=new int[value+1];

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
    public static void main(String[] args) 
        { 
            int coins[] = {1, 2, 3}; 
            int m = coins.length; 
            int value=5;
            System.out.println("Number of ways to make the required change:");
            System.out.println(CoinChange(coins, m, value));  
        }
}
