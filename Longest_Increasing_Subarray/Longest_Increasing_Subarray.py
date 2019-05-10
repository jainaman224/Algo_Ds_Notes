'''
    LONGEST INCREASING SUBARRAY

    The task is to find a subarray from a given array having the maximum length
    such that the elements of the subarray are in ascending order.
'''

'''
    Approach : If the current element is greater than the last element, we 
               update the length variable, so as to keep a counter of the 
               maximum numbers in the current longest increasing subarray.
               The mx variable keeps the track of the maximum length across
               all increasing subarrays found.
               The max_index denotes the starting index of the longest 
               increasing subarray found.
               We reset the length to 1 whenever the current element is found
               to be lesser than the previous element.
'''

mx = 0
ln = 1
max_index = 0

def solve(a, n):
    global ln, mx, max_index
    for i in range(1, n):
        if (a[i] > a[i - 1]):
            ln = ln + 1
            continue
        if (mx < ln):
            mx = ln
            max_index = i - mx
        ln = 1
    if (mx < ln):
        mx = ln
        max_index = n - mx
    for i in range(max_index, mx + max_index):
        print(a[i], end = " ")

num = int(input())
arr = []
for i in range(0, num):
    arr = arr.append(int(input))
solve(arr, num)

'''
    Input: array : {1,14,2,1,7,11,16,18,4,6}
    Output: 1 7 11 16 18 
    Verification: 1 7 11 16 18 is the longest increasing subarray of the 
                  given array with length 5.
'''
