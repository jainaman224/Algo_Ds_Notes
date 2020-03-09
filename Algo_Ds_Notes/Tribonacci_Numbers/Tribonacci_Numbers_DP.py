'''
TRIBONACCI NUMBERS

It is a series of numbers where each term is the sum of preceeding 3
numbers of the sequence.

T(n) = T(n-1) + T(n-2) + T(n-3)
'''

trib = []

def tribonacci(n):
    x = n - 3
    if x < 0:
        trib[n] = 0
        return trib[n]
    if not x:
        trib[n] = 1
        return trib[n]
    if trib[n] != -1:
        return trib[n]        
    trib[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3)
    return trib[n]

def init():
    for i in range(0, 10000):
        trib.append(-1)

init()
n = int(input("Enter N: "))
print("The tribonacci number at position", n, "is:", tribonacci(n))

'''
INPUT : n = 6
OUTPUT: The tribonacci number at position 6 is: 4
VERIFICATION: The tribonacci series : 0 0 1 1 2 4
'''
