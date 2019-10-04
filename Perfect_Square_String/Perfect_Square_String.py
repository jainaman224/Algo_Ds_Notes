'''
Perfect Square String is a string in which sum of ASCII value of all characters is a perfect square.
'''

import math

def perfectSquareString(string): 
    sum = 0
      
    # Length of the string
    length = len(string) 
      
    # Calculating sum of the string by converting it in its ASCII value
    for i in range(length): 
        sum = sum + ord(string[i])
      
    # Calculating square root 
    squareRoot = math.sqrt(sum) 
      
    # Checking if square root is an integer 
    return squareRoot - math.floor(squareRoot))
  
# Driver code 
string = input()
  
if (perfectSquareString(string) == 0): 
    print("YES")
else: 
    print("NO")
    
'''
INPUT :
Q
OUTPUT :
YES
Becasue ASCII value of Q is 81 which is a perfect square
'''
