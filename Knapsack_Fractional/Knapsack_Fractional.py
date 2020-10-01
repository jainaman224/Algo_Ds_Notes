#Fractional Knapsack problem is a variation of Knapsack problem where we can choose items by breaking them in fractions.
# The objective is to fill the knapsack with items to get maximum benefit without crossing the weight capacity of the knapsack.

# Function to compute maximum profit obtainable
def fractionalKnapsackProblem(arr, nItems, Capacity):
    # We sort the vector v on the basis of ratio value/weight, so v becomes:
    #[(2, (12, 6)), (3, (30,10)), (4, (20,5)),(5, (15,3)), (5, (5,1)), (6, (12,2)) ] 
    arr.sort()
    # variable weight to keep track of current weight added to Knapsack
    # variable value to keep track of current value obtained from Knapsack
    # variable remain to keep track of additional weight that can still be added to Knapsack
    weight = 0.0
    value = 0.0
    # Items with greater value/weight are selected first
    for i in range(nItems-1,-1,-1):
        # if current weight plus weight of the item to be added doesn't exceed Knapsack capacity select it
        if ((weight + wt[i]) <= Capacity):
            weight += (arr[i][1][1])
            value += (arr[i][1][0])
        else:
        # if current weight plus weight of the item to be added exceeds Knapsack capacity, break the item into fractional part, and select the portion out of it which doesn't exceed the Knapsack capacity
            remain = (Capacity - weight)
            value += ((arr[i][1][0]) * (remain / arr[i][1][1]))
            break
    # (12+ 5+ 15+ 20 + 30*(12-11)/10)
    return value

#Driver Code
wt = [6, 10, 3, 5, 1, 2]
val = [12, 30, 15, 20, 5, 12]
nItems = len(wt)
arr=[]
# storing values in a pair of pair so arr will hold: 
#[(2, (12, 6)), (3, (30,10)), (5, (15,3)), (4, (20,5)), (5, (5,1)), (6, (12,2))] 
for i in range(nItems):
    pair1 = (val[i], wt[i])
    pair2 = (float(val[i])/wt[i], pair1)
    arr.append(pair2)
# Knapsack Capacity
Capacity = 12
# Call to Knapsack function
value = fractionalKnapsackProblem(arr, nItems, Capacity)
print("The maximum profit that can be obtained is :",value)
#Output:
#The maximum profit that can be obtained is :55
