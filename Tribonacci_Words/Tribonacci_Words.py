'''
TRIBONACCI WORDS

It is a series of words where each word is formed by concatenation
of last three words.
where :
T(1) = 1
T(2) = 12
T(3) = 1213

T(n) = T(n-1) + T(n-2) + T(n-3)
'''

def tribonacci(n):
    if n == 1:
        return "1"
    if n == 2:
        return "12"
    if n == 3:
        return "1213"
    return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3)

n = int(input("Enter N: "))
print("The tribonacci word at position", n, "is:", tribonacci(n))

'''
INPUT : n = 5
OUTPUT: The tribonacci word at position 5 is: 1213121121312
'''
