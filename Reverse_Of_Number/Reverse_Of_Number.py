''' Reverse of a number is the number obtained when we read 
the original number backwards. 
Example: number = 12345, reverse = 54321
number = 1005, reverse = 5001 '''

# function to reverse a number
def reverse(N):
    rev = 0
    while N > 0: 
        a = N % 10
        rev = rev * 10 + a
        N = int(N / 10)
    return rev

print("Enter number to reverse:")
N = int(input())
ans = reverse(N)
print("The reverse of %d is %d" % (N, ans))

'''
Input:
12345

Output:
The reverse of 12345 is 54321

Input:
1000

Output:
The reverse of 1000 is 1
'''
