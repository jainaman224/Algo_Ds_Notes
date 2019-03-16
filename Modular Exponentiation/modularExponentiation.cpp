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
    if(base == 0){
        return 0;		
    }
    if(exponent == 0){
        return 1;
    }
    if(exponent%2 == 0){
        lint ans = modex(base,exponent/2,mod);
        return (ans*ans)%mod;
    }
    return ((base%mod)*(modex(base,exponent-1,mod)))%mod;
}

int main(){
    lint base = 12;
    lint exponent = 7;
    lint mod = 17;
    cout<<"("<<base<<"^"<<exponent<<")%"<<mod<<" = "<<modex(base,exponent,mod);
    return 0;
}

