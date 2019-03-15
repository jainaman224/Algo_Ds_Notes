# Unbounded Knapsack Problem

def UnboundedKnapsack(W,n,wt,val):
    dp=[]
    for i in range(W+1):
        dp.append(0)
    for i in range(0,W+1):
        for j in range(0,n):
            if wt[j] <= i:
                dp[i] = max(dp[i] , dp[i-wt[j]]+val[j])
    return dp[W]

# No. of items
n = 4
# Weights of all items
wt = [5,10,8,15]
# Values of all items
val = [40,30,50,25]
# Capacity of Knapsack
W = 120

print("The maximum value possible is ",UnboundedKnapsack(W,n,wt,val))
