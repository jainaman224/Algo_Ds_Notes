'''
DEARRANGEMENTS

It is a permutation of N elements such that no element appears in 
its original position.
We have to find the number of such permutations possible.

If count(n) = no of dearrangements for n numbers,
we use the generic formula 
count(n) = (n - 1) * [count(n - 1) + count(n - 2)]
'''

def count(number):
    if (number <= 2):
        return (number + 1) % 2
    last = count(number - 1)
    secondLast = count(number - 2)
    return (number - 1) * (last + secondLast)

number = int(input())
dearrangements = count(number)
print("The number of dearrangements is", dearrangements)

'''
INPUT : n = 6
OUTPUT: The number of dearrangements is 265
'''
