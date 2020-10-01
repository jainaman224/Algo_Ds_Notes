'''
A majority element in an array arr of size n is an
element that appears more than n/2 times.
Example: 
N = 9, arr = {1, 2, 2, 2, 4, 2, 2, 1, 5}
Majority Element = 2 as count[2] = 5 which is greater
than n/2 i.e 4
'''

def checkMajorityElement(arr, N):
    mp = {}
    # Computing frequency of each element using Map
    for i in range(0, N):
        if arr[i] in mp.keys(): 
            mp[arr[i]] += 1
        else: 
            mp[arr[i]] = 1

    # iterating over map
    for key in mp:
        if mp[key] > (N / 2):
            return key
    return -1

print("Enter size of array:")
N = int(input())
print("Enter elements of array:")
arr = [int(x) for x in input().split(' ')]
ans = checkMajorityElement(arr, N)
if ans != -1:
    print("Majority Element is: %d" % ans)
else:
    print("No majority element in array")

'''
Input:
N = 9
arr = {1, 2, 2, 2, 4, 2, 2, 1, 5}

Output:
Majority Element is: 2

Input:
N = 5
arr = {1, 2, 3, 4, 5}

Output:
No majority element in array
'''
