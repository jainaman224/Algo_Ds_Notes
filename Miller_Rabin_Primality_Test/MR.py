# It requires Python3.6 or above to run this implementation of Miller Rabin Primality Test.

import random  

def power(x, y, p): 
    res = 1;  
    x = x % p;  
    while (y > 0):       
        if (y & 1): 
            res = (res * x) % p; 
        y = y>>1; # y = y/2 
        x = (x * x) % p; 
    return res; 
  

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
    return False; 
  
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
  
k = 4;  
  
#-----DRIVER PROGRAM-----
m=int(input("Enter range: "))
for n in range(1,m): 
    if (isPrime(n, k)): 
        print(n , end=" "); 
  
