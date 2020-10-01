# Finding greatest common divisor using Euclidean Algorithm
def gcdFunction(a, b):
    if a == 0:
        return b

    return gcdFunction(b % a, a)

def power(x, y, m):
    if y == 0:
        return 1

    p = power(x, int(y / 2), m) % m
    p = (p * p) % m

    if y % 2 == 0:
        return p
    else:
        return (x * p) % m

def modInverse(a, m):
    gcd = gcdFunction(a, m)

    if gcd != 1:
        return -1
    else:
        return power(a, m - 2, m)


a = 3
m = 11

ans = modInverse(a, m)

if ans == -1:
    print("Inverse doesn't exist")
else:
    print("Modular multiplicative inverse is " + str(ans))


''' Output

Modular multiplicative inverse is 4

'''
