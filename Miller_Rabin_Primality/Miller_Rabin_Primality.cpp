#include <iostream>
#include <cmath>
using namespace std;

#define ITERATION 10
//modular exponentiation
long long bigmod(long long base, long long exp, long long m);

bool miller_rabin_test(long long n)
{
    if(n == 2)	return 1;
    
    if(n < 2 || (n & 1 == 0))
        return 0;
    int i, s, r ;
    //convert the no in (2^t)*s+1 form;
    s = n-1 , r = 0;
    while(s % 2==0)
    {
        s = s>>1; //dividing by 2
        r++;
    }
    //now s = required s factor;
    for(i = 1; i <= ITERATION; i++)
    {
        long long a, x, temp;
        temp = s;
        a= (rand() % (n-3)) + 2;//gives random no in between 2 and N-2 inclusive
        // evaluating   (a^(2^r)*s)%n   for different values of r, such that 1<= 2^r <n-1

        x = bigmod(a,s,n);
        if(x == 1 || x == n-1)
        	continue; //probable prime
        else
        {
        	for(int j = 0; j < r && x != 1 && x != n-1; j++)
        	{
        		x = bigmod(x, 2, n);
        	}
        	if(x != n-1) return 0;
        }
        //after testing all values of x ie. a^s, a^2s, a^4s,... a^(n-2)s  %N
    }
    return 1;
}

int main()
{
	long long t = 73;
	cout<<(miller_rabin_test(t)?"Yes, its a prime.":"No, isn't a prime");
	return 0;
}

long long bigmod(long long base, long long exp, long long m)
{
	long long ans, temp;
	ans = 1; temp = base;
	while(exp > 0)
	{
		if(exp & 1)
		{
			ans = (ans * temp) % m;
		}
		temp = (temp * temp) % m;
		exp >>= 1;
	}
	return ans;
}