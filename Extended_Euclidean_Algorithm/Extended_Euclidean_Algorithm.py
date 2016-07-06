def gcdFunction(a, b, x, y):
    if a == 0:
        x = 0
        y = 1
        return b

    x1 = 0; y1 = 0
    gcd = gcdFunction(b % a, a, x1, y1)

    x = y1 - int(b / a) * x1
    y = x1

    return gcd

a = 98; b = 21
x = 0; y = 0

print("GCD of numbers " + str(a) + " and " + str(b) + " is " + str(gcdFunction(a, b, x, y)))
