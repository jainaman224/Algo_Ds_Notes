Miller Rabin Primality Test

It tells if the give no. N is probable prime or composite.
It can confirm that the no. is  composite but it cannot confirm 100% that the no. is prime.

The probability that a composite no. N is returned as possible prime after k-iterations with different values of a is 4<sup>-k</sup> .

Input : N
Output : If N is prime or not
Algorithm :

	Express N as N = 2<sup>r</sup>*s+1

	Iterate the following k times : 
		a= random no between 1 and n-1 (inclusive)
		calculate x= (a^((2^r)*s))%n	such that 1<= 2^r < n-1
		if r=0
				if x==1 or x==n-1
					n is probable prime.
				Else continue with next values of r and calculate x
		else
				if x==1
					not prime
				if x==n-1
					prime
				else
					r++
					if !(2^r < n-1 )
						break (the number is not prime)
