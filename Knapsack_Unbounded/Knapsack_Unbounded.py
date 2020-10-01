# Unbounded Knapsack Problem

def UnboundedKnapsack(Capacity,n,weight,value):
    maxProfit=[]
    for i in range(Capacity+1):
        maxProfit.append(0)
    for i in range(0,Capacity+1):
        for j in range(0,n):
            if weight[j] <= i:
                maxProfit[i] = max(maxProfit[i] , maxProfit[i-weight[j]]+value[j])
    return maxProfit[Capacity]

# No. of items
n = 4
# Weights of all items
weight = [5,10,8,15]
# Values of all items
value = [40,30,50,25]
# Capacity of Knapsack
Capacity = 120

print("The maximum value possible is ",UnboundedKnapsack(Capacity,n,weight,value))
