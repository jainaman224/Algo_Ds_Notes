'''
JOLLY JUMPER SEQUENCE

If the set of differences of consecutive elements of the sequence
varies from 1 to n - 1, the sequence formed is said to be Jolly Jumper
Sequence.
'''

def Jolly(a, n):
    check = []
    for i in range(0, n):
        check.append(0)
    for i in range(1, n):
        x = abs(a[i] - a[i - 1])
        if (x == 0 or x > n - 1 or check[x] == 1):
            return 0
        check[x] = 1
    return 1

n = int(input())
a = [int(x) for x in input().split()]
if (Jolly(a, n) == 1):
    print("It is a jolly jumper sequence") 
else:
    print("It is not a jolly jumper sequence")

'''
INPUT :
n = 6
a = [14 9 13 12 10 7]
OUTPUT :
It is a jolly jumper sequence
'''
