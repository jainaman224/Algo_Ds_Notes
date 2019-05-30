'''
Centered Square Number is a centered figurate number that gives the number
of dots in a square with a dot in the center and all other dots surrounding 
the center dot in successive square layers.
    
Nth Centered square number can be calculated by using formula n^2 + (n-1)^2.
'''

def centeredSquare (num):
    # Using formula
    return num * num + ((num - 1) * (num - 1))
   
# Driver code 
num = int(input())
print(centeredSquare(num))

'''
Input:
6
output:
61
'''
