'''
ROOT MEAN SQUARE

Root Mean Square or RMS is known as quadratic mean of a given array.
It holds a lot of importance in mathematical calculations in various
domains like Physics and geometry.
'''

def RMS(a, n, index, ans):
    if (index == n):
        ans = ans // n
        print("RMS of array is :", ans)
        return
    ans = ans + a[index] * a[index]
    RMS(a, n, index + 1, ans)

n = int(input())
a = [int(x) for x in input().split(' ')]
RMS(a, n, 0, 0)

'''
INPUT : n = 3
        a = [3, 15, 32]
OUTPUT :
RMS of array is : 419
'''
