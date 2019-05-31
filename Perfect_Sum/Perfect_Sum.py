'''
Perfect Sum problem:
Given an array of elements and a sum, print all subsets
which adds upto the given sum.
Example: arr = [1, 7, 3, 5, 6] and sum = 8, the solutions possible 
are [1, 7], [3, 5].
'''

flag = 0

def isSubsetSum(arr, subset, N, subsetSize, subsetSum, index , sum):
    global flag
    if (subsetSum == sum):
        flag = 1
        for i in range(0, subsetSize):
            print(subset[i], end = " ")
        print("")
    else:
        for i in range(index, N):
            subset[subsetSize] = arr[i]
            isSubsetSum(arr, subset, N, subsetSize + 1, 
                        subsetSum + arr[i], i + 1, sum)

N = int(input("Enter size of array"))
print("Enter elements of array")
arr = [int(x) for x in input().split()]
print("Enter sum")
sum = int(input())
subset = []
for i in range(0, N):
    subset.append(0)
isSubsetSum(arr, subset, N, 0, 0, 0, sum)
if flag == 0:
    print("No such subset present")

'''
INPUT:
N = 5
arr = [1 2 3 4 5]
sum = 7

OUTPUT:
1  2  4
2  5
3  4
'''
