"""Extended Euclidean Algorithm 
  ==============================
  GCD of two numbers is the largest number that divides both of them.
  A simple way to find GCD is to factorize both numbers and multiply
  common factors.
  
     GCD(a,b) = ax + by

  If we can find the value of  x and y then we can easily find the 
  value of GCD(a,b) by replacing (x,y) with their respective values.
"""

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


''' Output

GCD of numbers 98 and 21 is 7

'''
