/*This method discovers a prime factor p of an integer n
whenever p - 1 has only small prime factors
*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll modular_pow(ll base, ll exponent, ll modulus)
{
    ll result = 1;
    while(exponent > 0)
    {
        if(exponent&1)
            result = (result*base)%modulus;
        exponent = exponent >> 1;
        base = (base*base)%modulus;
    }
    return result;
}

ll pollard_p1(ll n, ll B)
{
    ll a = 2;
    ll e = 2;
    while(e<=B)
    {
        a = (modular_pow(a,e,n));
        e++;
    }
    ll p = __gcd(a-1,n);
    if(p > 1 && p < n)
        return p;
    return -1;
}


int main()
{
    ll n,B;
    cout<<"Enter n (to factor) and limit B\n";
    cin>>n>>B;
    cout<<"One of the factors of "<<n<<" is "<<pollard_p1(n,B);
    return 0;	
}

/*
Sample Input
n = 57247159
B = 8

Output:
One of the factors of 57247159 is 421
*/
