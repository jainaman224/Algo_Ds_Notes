'''
    For octal number with n digits:
    dn-1 ... d3 d2 d1 d0
    
    The decimal number is equal to the sum of octal digits (dn) times their power of 8 (8n):
    decimal = d0×8^0 + d1×8^1 + d2×8^2 + ...
'''

# Driver Code 
num = int(input())

dec = 0
base = 1 
 
while (num): 
    x = num % 10;
    num = int(num / 10)
    dec += x * base
    base = base * 8
    
print(dec)

'''
Input:
1000
Output:
512
'''

