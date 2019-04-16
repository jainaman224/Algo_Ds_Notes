#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ulint unsigned long long int
#define lint long long int
#define mp make_pair
#define pb push_back
#define f(x) for(lint i=0;i<x;i++)
#define fj(x) for(lint j=0;j<x;j++)
#define F first
#define S second
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

lint modex(lint base,lint exponent,lint mod){
    if(base == 0){                                  // 0^x = 0.
        return 0;		
    }
    if(exponent == 0){
        return 1;                                   // x^0 = 1.
    }
    if(exponent%2 == 0){
        lint ans = modex(base,exponent/2,mod);      // as, a^b = (a^(b/2))*(a^(b/2)), we use recursion to effectively reduce the no.
        return (ans*ans)%mod;                       // of operations required for computing.
    }
    return ((base%mod)*(modex(base,exponent-1,mod)))%mod;   // when exponent is odd, we reduce it by 1 to make it even, which again uses
}                                                           // recursion for computation.

int main(){
    lint base = 12;
    lint exponent = 7;
    lint mod = 17;
    cout<<"("<<base<<"^"<<exponent<<")%"<<mod<<" = "<<modex(base,exponent,mod);
    return 0;
}

