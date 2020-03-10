# AKS Primality Test

The AKS primality test (also known as Agrawal–Kayal–Saxena primality test and cyclotomic AKS test) is a deterministic primality-proving algorithm. It was the first algorithm that can provably determine whether any given number is prime or composite within polynomial time, without relying on the generalized Riemann hypothesis, or any mathematical conjecture. 

## Features of AKS Primality Test

1. The AKS algorithm can be used to verify the primality of any general number given.
2. The maximum running time of the algorithm can be expressed as a polynomial over the number of digits in the target number.
3. The algorithm is guaranteed to distinguish deterministically whether the target number is prime or composite.
4. The correctness of AKS is not conditional on any subsidiary unproven hypothesis.

## How to Evaluate

The AKS primality test is based upon the following theorem: 

An integer n greater than 2 is prime if and only if the polynomial congruence relation :


**(x+a)^{n} ≡ (x^{n}+a) (mod n)**

holds for some a coprime to n. Here x is just a formal symbol .


The AKS test evaluates the equality by making complexity dependent on the size of r . This is expressed as

**(x+a)^{n} ≡ (x^{n}+a) (mod x^{r}-1, n)**


which can be expressed in simpler term as

**(x+a)^{n} - (x^{n}+a) = (x^{r}-1)g + nf**

for some polynomials f and g .

This congruence can be checked in polynomial time when r is polynomial to the digits of n. The AKS algorithm evaluates this congruence for a large set of a values, whose size is polynomial to the digits of n. The proof of validity of the AKS algorithm shows that one can find r and a set of a values with the above properties such that if the congruences hold then n is a power of a prime. The brute force approach would require the expansion of the (x – a)^n polynomial and a reduction (mod n) of the resulting n + 1 coefficients .

As a should be co-prime to n. So, to implement this algorithm we can check by taking a = 1, but for large values of n we should take large values of a.
The algorithm is based on the condition that if n is any number, then it is prime if,

( x – 1 )^n – ( x^n – 1) is divisible by n.

## Example

Checking for n = 3 :

(x-1)^3 – (x^3 – 1)

= (x^3 – 3x^2 + 3x – 1) – (x^3 – 1)

= -3x^2 + 3x

As all the coefficients are divisible by n i.e. 3, so 3 (n) is prime. As the number increases, size increases.

## Implementation

- [C code]
(https://github.com/jainaman224/Algo_Ds_Notes/blob/master/AKS_Primarility_Test/AKS.c)

- [C++ Code]
(https://github.com/jainaman224/Algo_Ds_Notes/blob/master/AKS_Primarility_Test/AKS.cpp) 

- [Python Code]
(https://github.com/jainaman224/Algo_Ds_Notes/blob/master/AKS_Primarility_Test/AKS.py)

- [Java Code]
(https://github.com/jainaman224/Algo_Ds_Notes/blob/master/AKS_Primarility_Test/AKS.java)

- [JavaScript Code]
(https://github.com/jainaman224/Algo_Ds_Notes/blob/master/AKS_Primarility_Test/AKS.js)
 
## See also
[AKS Primality Test on Wikipedia](https://en.wikipedia.org/wiki/AKS_primality_test)
