'''
LUCAS NUMBERS

These numbers are similar to Fibonacci Numbers. The only difference
is that the first two terms are 2 and 1.
'''

def lucas(n):
    a = []
    a.append(2)
    a.append(1)
    for i in range(2, n):
        a.append(a[i - 1] + a[i - 2])
    return a[n - 1]

def lucas_recursive(n):
    if (n == 1):
        return 2
    if (n == 2):
        return 1
    return lucas_recursive(n - 1) + lucas_recursive(n - 2)

number = int(input())
print("The Lucas number at position", number, "is", lucas(number))

'''
INPUT :
n = 8
OUTPUT :
The Lucas number at position 8 is 29
'''
