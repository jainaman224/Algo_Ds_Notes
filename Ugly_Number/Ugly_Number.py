# Ugly numbers are numbers whose only prime factors are 2, 3 or 5.

x = False
num = int(input("Input an integer number: "))
while (num != 1) :
    if (num % 5 == 0) : # To check if number is divisible by 5 or not
        num /= 5
    elif (num % 3 == 0) : # To check if number is divisible by 3 or not
        num /= 3
    elif (num % 2 == 0) : # To check if number is divisible by 2 or not
        num /= 2  
    else :
        print("It is not an ugly number")
        x = True
        break
if x == False :
    print("It is an ugly number")

'''
Input an integer number: 8
It is an ugly number.
'''
