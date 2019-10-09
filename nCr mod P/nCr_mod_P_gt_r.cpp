/*
    nCr % p.

    The task is to find the binomial coefficient nCr under modulo p when p > r.
    Here, we compute nCr using the rules of number theory, binary exponentiation and the direct formula for nCr.
    Time complexity is O(r + log p).
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll p;

ll binExpMod(ll n, ll m){
    if(m==0) return 1;
    if(m%2==1)  return (n*(binExpMod(n,m-1)))%p;
    else return ((binExpMod(n,m/2))*(binExpMod(n,m/2)))%p;
}
//Binary exponentiation modulo p: Works in O(log m) time.

ll c(ll n, ll r){
    if(n<r) return 0;
    //It is a common extension for nCr to be 0 when n<r. It can be seen from the combinatorial definition.
    //nCr = (n-r+1)(n-r+2)...(n)/(r!)
    if(2*r>n) return c(n,n-r); //As shown later, time complexity is O(r + log p), so keeping r smaller is better.
    ll x=1;    //x stores the value of (n-r+1)(n-r+2)...(n) modulo p
    for(ll i=n-r+1;i<=n;i++) x=(x*i)%p;
    ll y=1;    //y stores the value of r! modulo p
    for(ll i=1;i<=r;i++) y=(y*i)%p;
    /*
    Now we can multiply x with the multiplicative inverse of y w.r.t p
    to get (x/y) modulo p.
    */
    ll ans=(x*binExpMod(y,p-2))%p;
    /*
    By Fermat's little theorem, a^(p-1) ≡ 1 (mod p) when p doesn't divide a.
    Thus, a * a^(p-2) ≡ 1 (mod p),
    i.e. when p doesn't divide a, a^(p-2) % p is the multiplicative inverse of a w.r.t p.
    Note that p not dividing r!, as in our case is the same as saying that p > r.
    To calculate a^(p-2), we have used binary exponentiation which works in O(log p) time.
    Thus, the total time complexity is O(r + log p).
    */
    return ans;
}

int main(){
    ll n, r;
    cout<<"Enter n, r and p respectively: ";
    cin>>n>>r>>p;
    cout<<"The value of "<<n<<"C"<<r<<" modulo "<<p<<" is: "<<c(n,r);
    return 0;
}
