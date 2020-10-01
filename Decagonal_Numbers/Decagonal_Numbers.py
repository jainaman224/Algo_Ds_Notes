'''
    A decagonal number is a figurate number that extends the concept of 
    triangular and square numbers to the decagon (a ten-sided polygon).
    
    The n-th decagonal number is given by the formula:
    Dn = 4n^2 - 3n.
'''

# To calculate decagonal number
def decagonalnumber (num):
    # Using formula
    return 4 * num * num - 3 * num 
   
# Driver code 
num = int(input())
print(num, "decagonal number :", decagonalnumber(num)) 

'''
Input:
6
output:
6 decagonal number : 126
'''
