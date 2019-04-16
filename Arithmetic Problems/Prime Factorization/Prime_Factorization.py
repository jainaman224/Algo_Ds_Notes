'''
    Prime Factorization of a number

    The task is to prime factorize a number using efficient techniques.
    i.e. denote a number as a product of different prime factors.

'''
import math 
'''
    Since, 2 is the only even prime number, we compute it's frequence in the
    prime factorization of num separately, and then run the loop from 3, and 
    increment it by 2, so that we only check the odd numbers.
    In the loop, we keep decrementing the value of num by a factor of the number,
    which divides it.
    After the loop, if the value of num still tends to be greater than 2, it means,
    it is a prime factor in itself. Thus, we add to it's prime factors.
'''
def prime_factorize(num):
    prime_factors = []  # To maintain the prime factors of the given number.
    while(not (num%2)):
        prime_factors.append(2)
        num/=2
    for i in range(3,int(math.sqrt(num))+1):
        while(not (num%i)):
            prime_factors.append(i)
            num/=i
    if num>2:
        prime_factors.append(num)
    # Printing the prime factors.
    for i in range(0,len(prime_factors)):
        print(prime_factors[i],end='')
        if not (i == len(prime_factors)-1):
            print(" * ",end='')
num = 100
print(num," = ",end='')
prime_factorize(num)


'''
Input : num = 100.
Output: 100 = 2 * 2 * 5 * 5

'''

