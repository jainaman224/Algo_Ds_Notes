def gcdFunction(x, y):
    if x == 0:
        return y
    else:
        return gcdFunction(y % x, x)

x = 462
y = 780

print("GCD of numbers " + str(x) + " and " + str(y) + " is " + str(gcdFunction(x, y)))


''' Output

GCD of numbers 462 and 780 is 6

'''
