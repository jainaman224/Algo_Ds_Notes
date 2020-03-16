#!/usr/bin/python3
from math import ceil, floor

def karatsuba(x,y):
    # base case
    if x < 10 and y < 10: # in other words, if x and y are single digits
        return x*y

    n = max(len(str(x)), len(str(y)))
    m = ceil(n/2)   # Cast n into a float because n might lie outside the representable range of integers.

    a = floor(x / 10**m)
    b = x % (10**m)

    c = floor(y / 10**m)
    d = y % (10**m)

    # recursive steps
    ac = karatsuba(a,c)
    bd = karatsuba(b,d)
    ad_plus_bc = karatsuba(a + b, c + d) - ac - bd

    return int(ac*(10**(m*2)) + ad_plus_bc*(10**m) + bd)

# INPUT 123456789, 987654321
a,b = map(int, input().split(' '))

# OUTPUT 121932631112635269 
print(karatsuba(a, b))
