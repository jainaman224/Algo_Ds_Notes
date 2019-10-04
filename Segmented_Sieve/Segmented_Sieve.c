// Segmented Sieve

#include<stdio.h>
#include<stdlib.h>
#define MAX 100001

int primes[MAX];

// Creating Simple sieve of eratothenes
void sieve()
{
    int isPrime[MAX];
    for(int i = 0; i < MAX; i++)
    {
        isPrime[i] = 1;
    }

    // Marking all the multiples of prime as 0
    for(int i = 2; i * i < MAX; i++)
    {
        if(isPrime[i])
        {
            for(int j = i * i; j < MAX; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }

    primes[0] = 2;
    int k = 1;
    for(int i = 3; i < MAX; i += 2)
    {
        if(isPrime[i])
        {
            primes[k] = i;
            k++;
        }
    }
}

// Segmented sieve function
void printPrimesSegmented(long long int lower, long long int upper, int* primes)
{
    int isPrime[upper - lower + 1];

    for(int i = 0; i <= upper - lower; i++)
    {
        isPrime[i] = 1;
    }

    for(long long int i = 0; ((long long) primes[i]) * (primes[i]) <= upper; i++)
    {

        int currPrime = primes[i];
        // We are finding the first prime just smaller or equal to lower bound
        long long firstPrime = (lower / (currPrime)) * (currPrime);
        if(firstPrime < lower)
        {
            firstPrime = firstPrime + currPrime;
        }

        // We are marking all multiples within lower bound to upper bound as 0
        for(long long j = firstPrime; j <= upper; j += currPrime)
        {
            isPrime[j - lower] = 0;
        }

        // Considering the case where lower bound is itself a prime number.
        if(firstPrime == currPrime)
        {
            isPrime[firstPrime - lower] = 1;
        }
    }

    for(int i = 0; i <= upper - lower; i++)
    {
        if(isPrime[i] == 1)
        {
            printf("%d ", i + lower);
        }
    }
}

// Main method
int main()
{
    sieve();
    long long int lower, upper;
    printf("Enter the lower and upper bound for Prime numbers: ");
    scanf("%lld %lld", &lower, &upper);
    printf("\nThe primes in the given range is: \n");
    printPrimesSegmented(lower, upper, primes);
    printf("\n");
    return 0;
}

/*
  Input:
  10 20

  Output:
  Enter the lower and upper bound for Prime numbers:
  The primes in the given range is:
  11 13 17 19
*/
