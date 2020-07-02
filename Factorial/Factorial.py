#Code to obtain factorial of any given number

from itertools import accumulate as acc
from operator import mul
def factorial(n):
    if n<0:
         return "Factorial of negative number cannot be calculated"
    return list(acc(list(range(1,n+1)),mul))[-1]


if __name__=="__main__":
    n=int(input("Enter a number to calculate its factorial\n"))
    print("Output = ",factorial(n))

#Sample input and output:
#Enter a number to calculate its factorial
#12
# Output = 479001600
