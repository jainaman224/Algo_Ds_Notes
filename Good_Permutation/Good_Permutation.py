'''
GOOD PERMUTATION

A good permutation of a natural number N, is an arrangement
of first N natural numbers such that,
No number is present at it's position ( A[i] != i)
and
The value of a position is the index where the position is 
present as a value. ( A[A[i]] = i )

When such a permutation is not present, we print -1.
When we look at the second requirement, we find that if we
swap the consecutive numbers, we are able to satisfy the 
requirements. When N is odd, the swaps can not be possible.
Hence, we print -1.
'''

def permute(n):
    if (n % 2):
        print(-1)
    else:
        for i in range(0, n):
            if (i % 2):
                print(i, end = ' ')
            else:
                print(i + 2, end = ' ')
            
n = int(input("Enter N: "))
permute(n)

'''
    INPUT : a = 5
            r = 0.5
    OUTPUT : The sum of infinite G.P. is 10.0
'''
