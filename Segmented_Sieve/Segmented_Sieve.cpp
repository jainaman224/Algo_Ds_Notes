// Segmented Sieve

#include<bits/stdc++.h>
using namespace std;
#define MAX 100001

// Creating Simple sieve of eratosthenes
vector<int>* sieve()
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
    vector <int>* primes = new vector <int>();
    primes -> push_back(2);
    for(int i = 3; i < MAX; i += 2)
    {
        if(isPrime[i])
        {
            primes -> push_back(i);
        }
    }
    return primes;
}

// Segmented sieve function
void printPrimesSegmented(long long lower, long long upper, vector<int>* & primes)
{
    int isPrime[upper - lower + 1];

    for(int i = 0; i <= upper - lower; i++)
    {
        isPrime[i] = 1;
    }

    for(int i = 0; primes -> at(i)*(long long)primes -> at(i) <= upper; i++)
    {
        int currPrime = primes -> at(i);
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
            cout << i + lower << " ";
        }
    }
}

// Main method
int main()
{
    vector<int>* primes = sieve();
    long long lower, upper;
    cout << "Enter the lower and upper bound for Prime numbers: ";
    cin >> lower >> upper;
    cout << "\nThe primes in the given range is: " << endl;
    printPrimesSegmented(lower, upper, primes);
    cout << endl;
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
