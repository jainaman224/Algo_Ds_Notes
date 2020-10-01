# Euler's Totient Function

In number theory, Euler's totient function counts the positive integers up to a given integer n that are relatively prime to n. It is written using the Greek letter phi as f(n) or ?(n), and may also be called Euler's phi function. It can be defined more formally as the number of integers k in the range 1 = k = n for which the greatest common divisor gcd(n, k) is equal to 1. The integers k of this form are sometimes referred to as totatives of n.


## Euler's product formula
It states E(n) = (1- 1/p1)*(1 - 1/p2)..
where the product is over the distinct prime numbers dividing n.
Moreover, The function is multiplicative.
This means that if gcd(m, n) = 1, then f(mn) = f(m) f(n). (Outline of proof: let A, B, C be the sets of nonnegative integers, which are, respectively, coprime to and less than m, n, and mn; then there is a bijection between A × B and C, by the Chinese remainder theorem.)