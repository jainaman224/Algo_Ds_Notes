# gcd function
def egcd(a, b):
    while(b != 0):
        rem = a % b
        a = b
        b = rem
    return a

# m is message to be encrypted, 1 < m < n
m = int(input())

# p & q are two random prime numbers
p = 59
q = 53
n = p * q

# eulers toitent function
phi = (p -1) * (q-1)

# (n,e) forms our public key, 1 < e < phi
e = 2
while e < phi:
    if (egcd(e, phi) == 1):
        break
    e += 1

# (n,d) forms our private key, 1 < d < phi
d = 2
while d < phi:
    temp = ((e * d) - 1) % phi 
    if temp == 0:
        break
    d += 1

# printing cipher text 
c = pow(m, e) % n
print("Cipher = ",c)

# printing original message
message = pow(c, d) % n
print("Message = ",message)

'''
Input :
111
Output :
Cipher =  1132
Message =  111
'''
