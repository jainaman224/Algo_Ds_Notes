//Sieve of Eratosthenes

#include <stdio.h>
#include <stdlib.h>
#define ll long long

void Sieve(ll n)
{
    // Creating an array for storing prime factors.
    // and if the i is not prime, mark it as 0 else 1
    ll primefac[n + 1];

    // Initialising all elements as 1
    for(ll i = 2; i <= n; i++)
        primefac[i] = 1;

    for(ll i = 2; i * i <= n; i++)
    {
        // If prime[i] is marked 1, then it is a prime.
        if(primefac[i] == 1)
        {
            // Marking all multiples of i as 0
            for(int j = i * i; j <= n; j += i)
                primefac[j] = 0;
        }
    }

    // Printing all the prime numbers
    for(ll i = 2; i <= n; i++)
       if(primefac[i])
       {
           printf("%lld ", i);
       }
}

// Main method
int main()
{
    ll num;
    printf("Enter the number: ");
    scanf("%lld", &num);
    printf("Below are the prime numbers smaller than or equal to %lld \n", num);
    Sieve(num);
    return 0;
}

/*
  Input:
  25

  Output:
  Enter the number:
  Below are the prime numbers smaller than or equal to 25
  2 3 5 7 11 13 17 19 23
*/
