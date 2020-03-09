'''
TOTAL SET BITS FROM 1 to N

Total set bits in a number n is defined as number of 1s in 
binary representation of the number. The task is to calculate
total number of set bits in all numbers till N.
'''

def setBits(n):
    bit = 0
    for i in range(0, n):
        bit = bit + count(i)
    return bit

def count(n):
    bit = 0
    while (n): 
        bit += n & 1
        n >>= 1
    return bit

n = int(input())
print("The total set bits are", setBits(n))

'''
INPUT :
n = 12
OUTPUT :
The total set bits are 20
'''
