'''
CYCLIC PERMUTATIONS

Cyclic permutations of a number are defined as a number that
can be obtained by rotating the concerned number any number 
of times between it's digits.
'''

def getDigits(n):
    ans = 0
    while (n):
        ans = ans + 1
        n = n // 10
    return ans

def cyclic(n):
    length = getDigits(n)
    res = n
    while (1) :
        print(res)
        remainder = int(res % 10)
        quotient = int(res / 10)
        res = remainder * pow(10, length - 1) + quotient
        if (res == n):
            break
            
n = int(input("Enter N: "))
cyclic(n)

'''
INPUT : n = 6534
OUTPUT: 6534
        4653
        3465
        5346
'''
