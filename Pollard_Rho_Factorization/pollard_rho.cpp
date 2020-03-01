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

ll pollard_rho(ll n)
{
	ll x = 2;
	ll y = 2;
	ll c = 3;
	ll d = 1;
	while(d == 1)
	{
		x = (modular_pow(x,2,n) + c + n)%n;
		y = (modular_pow(y,2,n) + c + n)%n;
		y = (modular_pow(y,2,n) + c + n)%n;
		d = __gcd(abs(x-y),n);
		if(d == n) return -1;
	}
	return d;
}


int main()
{
	ll n = 10967535067;
	cout<<"One of the factors of "<<n<<" is "<<pollard_rho(n);
       	return 0;	
}
