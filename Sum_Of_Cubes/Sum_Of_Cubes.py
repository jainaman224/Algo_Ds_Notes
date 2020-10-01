'''
    The sum of cubes of first N natural numbers is given
    by the equation (((N) * (N + 1)) / 2 ) ^ 2 i.e.
    1^3 + 2^3 + 3^3 + 4^3 + 5^3.........N^3 sums upto
    (((N) * (N + 1)) / 2 ) ^ 2 
'''

print("Enter the value of N: ")
N = int(input())
ans = pow(((N * (N + 1)) / 2 ), 2)
print(ans)

'''
Input:
N = 5

Output:
ans = 225

Verification:
1^3 + 2^3 + 3^3 + 4^3 + 5^3
= 1 + 8 + 27 + 64 + 125
= 225
'''
