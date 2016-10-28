##Miller Rabin Primality Test

This test tells if the given number N is probable prime or composite.
It can confirm that the number is composite but it cannot guarantee with 100%, that N is prime.

The probability that a composite number N is returned as possible prime after k-iterations with different values of a is 4<sup>-k</sup>.


###Input : N
###Output : If N is prime or not
###Algorithm :
	Define k (number of iterations) sufficiently high.

	Express N as N = (2^r)*s + 1

	Iterate the following k times : 
		a = random no between 2 and n - 2 (inclusive)
		calculate x = (a^((2^r)*s))%n	such that 1 <= 2^r < n-1
		if r == 0
				if x == 1 or x == n-1
					n is probable prime, continue for next iteration
				Else continue with next values of r and calculate x
		else
				if x == 1
					not prime, return False
				if x == n-1
					n is probable prime, continue for next iteration
				else
					r++
					if !(2^r < n - 1 )
						not prime, return False

###Reference : <a href="https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test">Wikipedia - Miller Rabin</a> 