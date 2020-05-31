# Taking input
a = int(input("Enter a number : "))

# Calculating factorial
def fact(n):
    if n == 1 or n == 0 :
        return 1
    else :
        return n * fact(n-1)

# Printing the output
print("The factorial of", a ,"is :",(fact(a)))

# Calculating factorial using recursion

# Enter a number : 6
# The factorial of 6 is : 720
