# function to find factorial of a number - recursive approach
def factorial(num):
    if(num==0 or num==1):
        return 1
    return num*factorial(num-1)

#Driver Program
number = int(input())
print(factorial(number))


# Input: 5
# Output: 120
