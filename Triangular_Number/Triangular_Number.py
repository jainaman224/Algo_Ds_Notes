'''The nth triangular number is the number of dots in the triangular arrangement 
with n dots on a side, and is equal to the sum of the n natural numbers from 1 to n.
We can check if a number is triangular number or not by solving a quadratic equation :
n^2 + n + (-2 * num) = 0 
where n is sum of first ‘n’ natural numbers
and num is the input number.'''

import math

def Triangular(num): 
    a, b = 1, 1
    c = (num * (-2)) 
    
    # Calculating discriminant
    d = (b * b) - (4 * a * c) 

    if (d < 0): 
        return False

    # Calculating roots of equation 
    root1 = ( -b + math.sqrt(d)) / (2 * a) 
    root2 = ( -b - math.sqrt(d)) / (2 * a) 

    # if root1 is natural and integer number than it is a triangular number
    if (root1 > 0 and math.floor(root1) == root1): 
        return True

    # if root2 is natural and integer number than it is a triangular number 
    if (root2 > 0 and math.floor(root2) == root2): 
        return True

    return False

# Driver code 
num = 10
if (Triangular(num)): 
    print("The number is a triangular number") 
else: 
    print("The number is Not a triangular number") 

# OUTPUT: The number is a triangular number
