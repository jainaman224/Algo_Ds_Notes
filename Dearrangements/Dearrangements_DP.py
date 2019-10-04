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
    dearrangement = []
    dearrangement.append(1)
    dearrangement.append(0)
    dearrangement.append(1)

    for i in range(3, number + 1):
        dearrangement.append((i - 1) * 
        (dearrangement[i - 1] + dearrangement[i - 2]))
    return dearrangement[number]

number = int(input())
dearrangements = count(number)
print("The number of dearrangements is", dearrangements)

'''
INPUT : n = 6
OUTPUT: The number of dearrangements is 265
'''
