# Sieve of Eratosthenes

Sieve of Eratosthenes, systematic procedure for finding prime numbers that begins by arranging all of the natural numbers (1, 2, 3, …) in numerical order. After striking out the number 1, simply strike out every second number following the number 2, every third number following the number 3, and continue in this manner to strike out every nth number following the number n. The numbers that remain are prime. The procedure is named for the Greek astronomer Eratosthenes of Cyrene (c. 276–194 BC).

One of a number of prime number sieves, it is one of the most efficient ways to find all of the smaller primes. It may be used to find primes in arithmetic progressions.


## Algorithm
To find all the prime numbers less than or equal to a given integer n by Eratosthenes' method:

- Initially, we take all numbers between 2 and n. Then, We mark all proper multiples of 2 (as 2 is the smallest prime number) as composite. 
- Then we find the next number that hasn't been marked as composite, in our case it is 3 (as 3 is the next prime number), and we mark all proper multiples of 3 as composite. 
- The next unmarked number is 5, which is the next prime number, and we mark all proper multiples of it.
- And we continue this procedure until we processed all numbers in the row.
- Since we iterate over the prime numbers in order, we already marked all numbers, who are divisible by at least one of the prime numbers, as divisible. Hence if we reach a number and it is not marked, then it isn't divisible by any smaller prime number and therefore has to be prime.

## Illustration for above algorithim
![GIF](https://camo.githubusercontent.com/7fc5b65934c2498fd50d20d8d8873f38802647c5/687474703a2f2f692e67697068792e636f6d2f336f3757544467625a50465847754d5151552e676966)


## Pseudocode
```
Input: an integer n > 1.
 
 Let A be an array of Boolean values, indexed by integers 2 to n,
 initially all set to true.
 
 for i = 2, 3, 4, ..., not exceeding vn:
   if A[i] is true:
     for j = i2, i2+i, i2+2i, i2+3i, ..., not exceeding n:
       A[j] := false.
 
 Output: all i such that A[i] is true.
```


## Implementation

*  [C++ Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Sieve_Of_Eratosthenes/Sieve_Of_Eratosthenes.cpp)

 
*  [Java Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Sieve_Of_Eratosthenes/Sieve_Of_Eratosthenes.java)

  
*  [Python Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Sieve_Of_Eratosthenes/Sieve_Of_Eratosthenes.py)

