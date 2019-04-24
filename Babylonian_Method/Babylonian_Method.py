#    1. Start with an arbitrary positive start value num (the closer to the 
#       root, the better).
#    2. Initializing guess=1;
#    3. Gives the accuracy of decimal places
#    4. Do following until desired approximation is achieved.
#       a) Get the next approximation for root using average of num and guess
#       b) Set guess = number/guess */

#Function for square_root
def square_root(number):
    num = number
    guess = 1
    accuracy = 0.000001
    while(num - guess > accuracy):
        num = (num + guess) / 2
        guess = number / num

    return num

#To check if function is working
n = 3
print("Square root of", n, "is", round(square_root(n), 6)) 

#Output :- Square root of 3 is 1.732051
