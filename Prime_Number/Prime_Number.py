import math  

def Prime(num, i): 
    if (num == 1):
        return False
    
    # Base cases 
    if (i <= 1): 
        return True 
        
    # Checking if i is a divisor or not        
    if (num % i == 0): 
        return False

    # Check for next divisor 
    return Prime(num, i - 2) 

# Driver Program 
num = int(input())
if (num == 2):
    print("It is a prime number")
if (num % 2 == 0):
    print("It is not a prime number")
if (Prime(num, math.sqrt(num))): 
    print("It is a prime number") 
else: 
    print("It is not a prime number")
    
# Input: 29
# Output: It is a prime number    
