'''
DIGIT COUNT OF A NUMBER

The task is to count the number of digits present in the given
number.
'''

def getDigits(n):
    ans = 0
    while (n):
        ans = ans + 1
        n = n // 10
    return ans

n = int(input("Enter N: "))
print("Number of digits is :", getDigits(n))

'''
INPUT : n = 6534
OUTPUT: Number of digits is : 4
'''
