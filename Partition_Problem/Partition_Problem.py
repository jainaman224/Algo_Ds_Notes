'''
PARTITION PROBLEM

The problem is to identify if a given set of n elements can be divided
into two separate subsets such that sum of elements of both the subsets
is equal.
'''

def check(a, total, ind):
    if total == 0:
        return True
    if ind == -1 or total < 0:
        return False
    if a[ind] > total:
        return check(a, total, ind - 1)
    return check(a, total - a[ind], ind - 1) or \
    check(a, total, ind - 1)

n = int(input())
a = []
total = 0
for i in range(0, n):
    a.append(int(input()))
    total = total + a[i]

if total % 2 == 1:
    print("Not Possible") 
else:
    if check(a, total / 2, n - 1):
        print("Possible")
    else:
        print("Not Possible")

'''
INPUT :
n = 4
a = [1, 4, 3, 2]
OUTPUT :
Possible
VERIFICATION :
Set can be divided into two sets :
[1, 4] and [3, 2], both of whose sum is 5.
'''
