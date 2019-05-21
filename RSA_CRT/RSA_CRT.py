# gcd function
def egcd(a, b):
    while (b != 0):
        rem = a % b
        a = b
        b = rem
    return a

# modular inversion function
def findInv(x, y, n):
    d = 2
    while d < n:
        temp = ((d * x) - 1) % y
        if temp == 0:
            break
        d += 1
    return d

# m is message to be encrypted, 1 < m < n
m = int(input("Enter the message \n"))

# p & q are two random prime numbers
print("Enter two prime numbers")
p = int(input())
q = int(input())
n = p * q

# eulers toitent function
phi = (p - 1) * (q - 1)

# (n,e) forms our public key, 1 < e < phi
e = 2
while e < phi:
    if (egcd(e, phi) == 1):
        break
    e += 1

# calculating CRT exponents dP, dQ and qInv to make calculations shorter and faster
dP = findInv(e, p - 1, n)
dQ = findInv(e, q - 1, n)
qInv = findInv(q, p, n)

# printing cipher text 
c = pow(m, e) % n
print("Cipher = ", c)

# printing original message
m1 = pow(c, dP) % p
m2 = pow(c, dQ) % q
h = (qInv * (m1 + p - m2)) % p
message = m2 + (h * q)
print("Original message = ", message)

'''
Input :
Enter the message
1331
Enter two prime numbers
131
137
Output :
Cipher =  16990
Message =  1331
'''
