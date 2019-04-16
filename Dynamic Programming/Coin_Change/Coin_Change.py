# Function to calculate the number of ways of making the desired change using the given coins
def CoinChange(coins, m, value): 
    dp = [0]*(value+1)
  
    # Base case when value is 0
    dp[0] = 1

    for i in range(0,m): 
        for j in range(coins[i],value+1): 
            dp[j] += dp[j-coins[i]] 
  
    return dp[value] 
  
# Driver Program 
coins = [1, 2, 3] 
m = len(coins) 
value=5
print("Number of ways to make the required change:")
print(CoinChange(coins, m, value))
