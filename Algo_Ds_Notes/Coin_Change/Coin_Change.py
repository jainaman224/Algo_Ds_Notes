'''
    The Coin Change problem states that given an amount N, how
    many possible ways are there to make the desired change using
    unlimited supply of coins of given denominations. Example:
    if N = 5 and coins = {1, 2, 3} then
    5 = 1 + 1 + 1 + 1 + 1
    5 = 1 + 1 + 1 + 2
    5 = 1 + 1 + 3
    5 = 1 + 2 + 2
    5 = 2 + 3
'''

# Function to calculate the number of ways of making the desired change using the given coins
def CoinChange(coins, m, value): 
    dp = [0]*(value + 1)
  
    # Base case when value is 0
    dp[0] = 1

    for i in range(0, m): 
        for j in range(coins[i], value + 1): 
            dp[j] += dp[j - coins[i]] 
  
    return dp[value] 
  
# Driver Program
print("Enter number of coins")
m = int(input()) 
print("Enter denominations of coins")
coins = [int(x) for x in input().split(' ')]
print("Enter value") 
value = int(input())
print("Number of ways to make the required change:")
print(CoinChange(coins, m, value))

'''
Input:
m = 3
coins = {1, 2, 3}
value = 5
Output:
Number of ways to make the required change:
5
'''
