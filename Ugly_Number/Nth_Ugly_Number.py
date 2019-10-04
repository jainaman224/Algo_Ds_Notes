# Ugly numbers are numbers whose only prime factors are 2, 3 or 5.

# Function to check if a number is ugly or not 
def isUgly(num) : 
    x = True
    while (num != 1) : 
        # To check if number is divisible by 5 or not
        if (num % 5 == 0) :  
            num /= 5  
        # To check if number is divisible by 3 or not
        elif (num % 3 == 0) :  
            num /= 3  
        # To check if number is divisible by 2 or not
        elif (num % 2 == 0) :  
            num /= 2  
        else :
            x = False  
            break
    return x

# Function to get the nth ugly number
def NthUglyNumber(n) :
    i = 1 
    count = 1   # ugly number count  
    # Check for all integers untill ugly count  becomes n 
    while (n > count) :
        i = i + 1
        if ( isUgly(i) ) :
            count = count + 1 
    return i

number = 100
no = NthUglyNumber(number) 
print("The Ugly no. at position " + str(number) + " is " + str(no) , end = '')

'''
Input: number : 100
Output : The Ugly no. at position 100 is 1536
'''
