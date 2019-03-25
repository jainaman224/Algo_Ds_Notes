# It requires Python3.6 or above to run this implementation of Miller Rabin Primality Test.

import random  

# Performing Modular exponentiation. It will return (x^y)%p.
def power(x, y, p): 
    res = 1;  

    #updating x if is more than or equal to p.
    x = x % p;  
    while (y > 0):       

        #if y is odd, multiply x with result.
        if (y & 1): 
            res = (res * x) % p; 

        #y must be even now.    
        y = y>>1; # y = y/2 
        x = (x * x) % p; 
    return res; 
  


# Performing Miller-Rabin Test. It returns false if n is composite andreturns false if n is prime. d is an odd number such that d*2<sup>r</sup> = n-1 for some r >= 1 
def millerRabinTest(d, n): 

    a = 2 + random.randint(1, n - 4); 
    x = power(a, d, n); 
    if (x == 1 or x == n - 1): 
        return True; 

    while (d != n - 1): 
        x = (x * x) % n; 
        d *= 2; 
        if (x == 1): 
            return False; 
        if (x == n - 1): 
            return True; 

    #Return composite.    
    return False; 


# It returns false if n is composite and returns true if n is prime. k is an input parameter that determines accuracy level. Higher value of k indicates more accuracy. 
def isPrime( n, k): 
    if (n <= 1 or n == 4): 
        return False; 
    if (n <= 3): 
        return True; 
    d = n - 1; 
    while (d % 2 == 0): 
        d //= 2; 
    for i in range(k): 
        if (millerRabinTest(d, n) == False): 
            return False; 
    return True; 
  
#Driver Code for Number of iterations=4 and primes smaller than 100
k = 4;  
for n in range(1,100): 
    if (isPrime(n, k)): 
        print(n , end=" "); 

#sample output
#2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 
