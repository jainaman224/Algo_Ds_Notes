# Calculating inverse using extended Euclidean algorithm iterative method
def inverse(a, m):
    m0 = m; x0 = 0; x1 = 1

    if m == 1:
        return 0

    while a > 1:
        q = int(a / m); t = m
        m = a % m; a = t
        t = x0
        x0 = x1 - q * x0; x1 = t

    if x1 < 0:
        x1 += m0

    return x1

def findMinimumDividend(divisor, remainder):
    product = 1

    for i in range(len(divisor)):
        product *= divisor[i]

    result = 0

    for i in range(len(divisor)):
        partialProduct = int(product / divisor[i])
        result += remainder[i] * inverse(partialProduct, divisor[i]) * partialProduct;

    return result % product

divisor = [3, 4, 5, 7, 11]
remainder = [2, 3, 1, 4, 5]

print("Minimum value of dividend is " + str(findMinimumDividend(divisor, remainder)))

''' Output

Minimum value of dividend is 4235

'''
