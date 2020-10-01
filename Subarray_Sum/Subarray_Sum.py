'''
    SUBARRAY SUM 

    The task is to find sum of all possible subarrays of an array.
    This can be done by finding all subarray by a brute force solution
    and then finding combined sum of them.
    An efficient solution gets us to the theory that every element 
    contributes (i+1)*(n-1) times in the required sum. We use this
    formula for the computation of sum.
'''
    
print("Enter the size of array : ")
num = int(input())
a = []
print("Enter array elements")
for i in range(0, num):
    a.append(int(input()))
ans = 0
for i in range(0, num):
    ans = ans + (a[i] * (i + 1) * (num - i))
print("The sum of all subarrays is :", ans)

'''
Input : num = 4
        Array = [-1, -4, -5, 20]
Output :
        The sum of all subarrays is : 22
'''
