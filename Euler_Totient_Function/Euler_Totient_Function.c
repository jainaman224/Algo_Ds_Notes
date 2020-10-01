#include<stdio.h>
#define ll long long

// Greatest Common Divisor Function
ll gcd(ll a, ll b)
{
    if(a == 0)
        return 0;
    return gcd(b % a, a);
}

// Euler totient Function by using Brute force method, checking GCD of every number with n, if equals 1.
ll EulerTotient_Brute(ll num)
{
    ll answer = 1;
    for(ll i = 2; i < num; i++)
    {
        if(gcd(i, num) == 1)
            answer++;
        return answer;
    }
}

// Euler Totient Function using Euler product Formula E(n) = (1- 1/p1)*(1 - 1/p2).. where p1, p2 are prime factors of n.
ll EulerTotient_ProductForm(ll num)
{
    ll answer = num;
    // Finding the prime factors and applying the Euler Product Formula
    for (ll i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            while (num % i == 0)
                num /= i;
            answer = answer - (answer / i);
        }
    }
    // For the prime factor greater than square root of num
    if (num > 1)
        answer = answer-(answer / num);
    return answer;
}

// Main method
int main()
{
    ll num;
    printf("Enter the number: \n");
    scanf("%lld", &num);
    printf("Euler totient function value is: %lld", EulerTotient_ProductForm(num));
    return 0;
}

/*
  Input:
  10

  Output:
  Enter the number:
  Euler totient function value is: 4
*/
