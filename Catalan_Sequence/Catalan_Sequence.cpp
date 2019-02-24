#include <bits/stdc++.h>
using namespace std;

const long long MOD=1000000007;
const long long MAX=10000;
vector<long long> catalan(MAX+1, 0);

void init()
{
    catalan[1]=1;
    for(long long i=2; i<=MAX; i++)
        for(long long j=0; j<i; j++)
            catalan[i]+=(catalan[j]*catalan[i-j-1])%MOD, catalan[i]%=MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    cout<<"The first few numbers(mod 1e9+7) of catalan sequence are:\n";
    for(long long i=0; i<=MAX; i++)
        if(i&1)
            cout<<catalan[i]<<" ";
#include <bits/stdc++.h>
using namespace std;

const long long MOD=1000000007;
const long long MAX=10000;
vector<long long> catalan(MAX+1, 0);

void init()
{
    catalan[1]=1;
    for(long long i=2; i<=MAX; i++)
        for(long long j=0; j<i; j++)
            catalan[i]+=(catalan[j]*catalan[i-j-1])%MOD, catalan[i]%=MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    cout<<"The first few numbers(mod 1e9+7) of catalan sequence are:\n";
    for(long long i=0; i<=MAX; i++)
        if(i&1)
            cout<<catalan[i]<<" ";
}