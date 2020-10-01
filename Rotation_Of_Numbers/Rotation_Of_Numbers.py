      
# Function to rotations of a number 
def rotation (num):
    # Finding the number of digits
    digit = 0
    temp = num
    while temp > 0: 
        digit += 1
        temp //= 10

    power = pow(10, digit - 1) 

    for i in range(digit - 1): 
        lastDigit = num % 10
        x = num // 10
        num = lastDigit * power + x
        print(num, end = " ") 
        
# Driver code 
num = int(input())
rotation(num)

'''
Input:
1234
Output:
4123 3412 2341 
'''
