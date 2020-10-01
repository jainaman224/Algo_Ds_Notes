'''
PARTIAL DEARRANGEMENTS

A partial dearrangement is a dearrangement where some points are
fixed. That is, given a number n and a number k, we need to find
count of all such dearrangements of n numbers, where k numbers are
fixed in their position.
'''

mod = 1000000007

def nCr(n, r, mod):
    if n < r:
        return -1
    # We create a pascal triangle.
    Pascal = []
    Pascal.append(1)
    for i in range(0, r):
        Pascal.append(0)
    # We use the known formula nCr = (n-1)C(r) + (n-1)C(r-1) 
    # for computing the values.
    for i in range(0, n + 1):
        k = ((i) if (i < r) else (r)) 
        # We know, nCr = nC(n-r). Thus, at any point we only need min
        # of the two, so as to improve our computation time.
        for j in range(k, 0, -1):     
            Pascal[j] = (Pascal[j] + Pascal[j - 1]) % mod
    return Pascal[r]

def count(n, k):
    if k == 0:
        if n == 0:
            return 1
        if n == 1:
            return 0
        return (n - 1) * (count(n - 1, 0) + count(n - 2, 0))
    return nCr(n, k, mod) * count(n - k, 0)

number = int(input())
k = int(input())
dearrangements = count(number, k)
print("The number of partial dearrangements is", dearrangements)

'''
INPUT : n = 6
        k = 3
OUTPUT: The number of partial dearrangements is 40
'''
