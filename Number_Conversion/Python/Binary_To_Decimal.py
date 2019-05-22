'''
    For binary number with n digits:
    dn-1 ... d3 d2 d1 d0
    The decimal number is equal to the sum of binary digits (dn) times their power of 2 (2n):
    decimal = d0×2^0 + d1×2^1 + d2×2^2 + ...
'''

def binaryToDecimal(num): 
    decimal = 0 
       
    base = 1
   
    while(num): 
        x = num % 10 
        num = int(num / 10) 
          
        decimal += x * base
        base = base * 2
    return decimal
  
# Driver Code 
num = int(input()) 
print(binaryToDecimal(num))

'''
Input:
100
Output:
4
'''
