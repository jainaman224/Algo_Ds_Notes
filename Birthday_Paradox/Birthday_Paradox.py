#Python3 program to approximate the number of people in Birthday Paradox problem
import math

def find(p):
    return math.ceil(math.sqrt(2*365*math.log(1/(1-p))))

print(find(0.70))

"""
Output
30
"""