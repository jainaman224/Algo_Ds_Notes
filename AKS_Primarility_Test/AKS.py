def expandX1(m):
    c = [1]
    for i in range(m):
        c.append(c[-1] * -(m-i) / (i+1))
    return c[::-1]

def isPrime(m):
    if m < 2: return False
    c = expandX1(m)
    c[0] += 1
    return not any(mul % m for mul in c[0:-1])


#----DRIVER PROGRAM----
print('\n# [for small primes]AKS TEST GAVE THE FOLLOWING AS PRIMES')
print([m for m in range(1000) if isPrime(m)])


