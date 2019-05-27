'''
SPECIAL PERMUTATION

A Special Permutation is a permutation of n numbers such that there 
are at-least (n - k) indices where the value is equal to the index
of that number.
'''

def count(number):
    dearrangement = []
    dearrangement.append(1)
    dearrangement.append(0)
    dearrangement.append(1)

    for i in range(3, number + 1):
        dearrangement.append((i - 1) * 
        (dearrangement[i - 1] + dearrangement[i - 2]))
    return dearrangement[number]

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

def special_permutation(n, k):
    ans = 0
    for i in range(n - k, n + 1):
        ans = ans + (nCr(n, i, mod) * count(n - i))
    return ans

number = int(input())
k = int(input())
special = special_permutation(number, k)
print("The number of special permutations is", special)

'''
INPUT :
n = 7
k = 3
OUTPUT :
The number of special permutations is 92
'''
