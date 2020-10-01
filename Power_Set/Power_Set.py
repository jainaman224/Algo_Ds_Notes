'''
POWER SET

A power set of a set is the set of all possible subsets of 
a given set S. 
example - {a, b, c} :
Power Set = {}, {a}, {b}, {c}, {a, b}, {a, c},  {a, b}, {b, c}, 
            {a, b, c}

Total elements in a power set of a set with n elements = 2^n
'''

def PowerSet(a, b, n, index):
    if (index == n):
        print("{", end = '')
        for i in range(0, n):
            if (b[i] == 1):
                print(a[i], end = " ")
        print("}")
        return
    PowerSet(a, b, n, index + 1)
    b[index] = 1
    PowerSet(a, b, n, index + 1)
    b[index] = 0

n = int(input())
a = [int(x) for x in input().split(' ')]
b = []
for i in range(0, n):
    b.append(0)
PowerSet(a, b, n, 0)

'''
INPUT : n = 3
        a = [3, 15, 32]
OUTPUT :
{}
{32 }
{15 }
{15 32 }
{3 }
{3 32 }
{3 15 }
{3 15 32 }
'''
