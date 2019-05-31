''' A Bitonic Sequence is a sequence of numbers which is first
strictly increasing then after a point strictly decreasing.
Example: -10, 0, 3, 5, 15, 13, 7, 2 '''

def isBitonic(arr, N):
    if arr[0] > arr[1]:
        return -1

    for i in range(2, N):
        if arr[i - 1] >= arr[i]:
            break

    if i == N - 1:
        return 1
 
    for j in range(i + 1, N):
        if arr[j - 1] <= arr[j]:
            break
    
    if j != N:
        return -1
  
    return 1

print("Enter number of elements in array")
N = int(input())
print("Enter elements of array")
arr = [int(x) for x in input().split(' ')]
ans = isBitonic(arr, N)
if ans == -1:
    print("The array is not bitonic")
else:
    print("The array is bitonic")

'''
Input:
N = 5
arr = {0, 1, 2, 3, 4}

Output:
The array is not bitonic

Input:
N = 5
arr = {0, 2, 4, 3, 1}

Output:
The array is bitonic

Input:
N = 5
arr = {4, 3, 2, 1, 0}

Output:
The array is not bitonic
'''
