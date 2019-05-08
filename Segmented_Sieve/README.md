# Segmented Sieve

In the classical sieve of Eratosthenes one starts with the numbers 2, 3, 4, ..., N, and successively discard those that are multiples of the primes up to sqrt(N); these primes will be called sieving primes. On a computer, the character of each integer (either prime or composite), or better yet, the character of each integer that is not a multiple of the very first primes (say, 2, 3 and 5), can be represented by one bit of information. Because each computer has a finite amount of physical memory, if N is too large one is forced to subdivide the interval [2,N] in manageable subintervals. This subdivision gives rise to the so-called segmented sieve of Eratosthenes.



## Algorithm
To find all the prime numbers in a given interval by Segmented Sieve method:
- Use Simple Sieve to find all primes upto square root of ‘n’ and store these primes in an array “prime[]”. Store the found primes in an array ‘prime[]’.
- We need all primes in range [0..n-1]. We divide this range in different segments such that size of every segment is at-most √n
- Do following for every segment [low..high]
    - Create an array mark[high-low+1]. Here we need only O(x) space where x is number of elements in given range.
    - Iterate through all primes found in step 1. For every prime, mark its multiples in given range [low..high].


## Pseudocode
```
Simple sieve()
Let A be an array of Boolean values, indexed by integers 2 to n and B be an array of all primes till n,
 initially all set to true.
 
 for i = 2, 3, 4, ..., not exceeding vn:
   if A[i] is true:
     for j = i2, i2+i, i2+2i, i2+3i, ..., not exceeding n:
       A[j] := false.
 
 Store all i such that A[i] is true in Array B.
 return B
 
 Segmented sieve()
 Input: Lower bound and upper bound greater than 1, and returned array of Sieve function (Primes)
 
 Let A be an array of Boolean values, of size upper bound - lower bound + 1.
 Initially all set to true.
 
 for i = 0, 1, 2 ..., not exceeding squareroot(upper bound):
   currPrime = primes[i]
   firstPrime = (lower / (currPrime)) * (currPrime)
   
   if firstPrime is greater than lower
     firstPrime = firstPrime + currPrime
     
        for j = firstPrime, firstPrime + currPrime, firstPrime + 2*currPrime.. till j <= upper bound
           A[j - lower bound] = false
           
        if firstPrime is equal to currPrime        
           isPrime[firstPrime - lower bound] = true
           
 for i = 0, 1, 2... till i is greater than or equal to upper bound - lower bound
    if A[i] is true
      print i + lower bound     

```


## Implementation

*  [Code](https://www.geeksforgeeks.org/segmented-sieve/)
