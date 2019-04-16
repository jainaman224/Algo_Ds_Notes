
public class Sieve_of_Eratosthenes
{
	public static void output(int n)
	{
		boolean prime[] = new boolean[n+1]; // All the elements of array initialized as false by default

		// If i is non-prime, change prime[i] to true
		for(int p = 2; p*p <= n; p++)
		{
			if(!prime[p]) // If prime[p] is still false, then p is a prime
			{
				for(int i = p*2; i <= n; i += p) // Update all multiples of p as they are non-prime
				prime[i] = true;
			}
		}
		// Print all prime numbers
		for(int i = 2; i < prime.length; i++)
		{
			if(prime[i] == false) // Finally, elements which are still false are those whose location is prime
			System.out.print(i + "  "); // Printing these prime location
		}
	}

	// Driver function to test above function
	public static void main(String[] args)
	{
		int n = 30;
		System.out.println("Following are the prime numbers smaller than or equal to " + n);
		output(n);
	}

}

/*Output:

Following are the prime numbers smaller than or equal to 30
2 3 5 7 11 13 17 19 23 29

*/
