# Perfect number is a positive integer that is equal to the sum of its proper divisors.

num = int(input())
sum1 = 0

# Calculating the sum of divisors
for i in range(1, num):
    if (num % i == 0):
        sum1 = sum1 + i
        
if (sum1 == num):
    print("It is a perfect number")
else:
    print("It is not a perfect number")
    
# INPUT: 28
# OUTPUT: It is a perfect number
