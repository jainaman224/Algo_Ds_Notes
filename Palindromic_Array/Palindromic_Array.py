''' A Palindromic Sequence is a sequence of numbers which is 
the same when read both forward and backward.
Example: 1, 2, 3, 2, 1 '''

def isPalindromic(arr, N):
    for i in range(0, int(N / 2) - 1):
        if arr[i] != arr[N - i -1]:
            return False 
    return True

print("Enter number of elements in array")
N = int(input())
print("Enter elements of array")
arr = [int(x) for x in input().split(' ')]
if isPalindromic(arr, N):
    print("The array is palindromic")
else:
    print("The array is not palindromic")

'''
Input:
N = 5
arr = {0, 1, 2, 3, 4}

Output:
The array is not palindromic

Input:
N = 6
arr = {0, 2, 4, 4, 2, 0}

Output:
The array is palindromic
'''
