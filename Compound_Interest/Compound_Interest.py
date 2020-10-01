'''
    Compound Interest = P(1 + R/100)^T
    
    P is principle amount
    R is the rate and
    T is the time span
'''

import math

p = int(input("Enter Principal: "))
r = int(input("Enter Rate: "))
t = int(input("Enter Time: "))
print(p * (math.pow((1 + r / 100), t)))

'''
INPUT : p = 1000, r = 8, t = 2
OUTPUT : 1166.40
'''
