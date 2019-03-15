#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ulint unsigned long long int
#define lint long long int
#define mp make_pair
#define pb push_back
#define f(x) for(lint i=0;i<x;i++)
#define fj(x) for(lint j=0;j<x;j++)
#define mod 1000000007
#define F first
#define S second
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

lint modex(lint x,lint y,lint p){
    if(x == 0){
        return 0;		
    }
    if(y == 0){
        return 1;
    }
    if(y%2 == 0){
        lint ans = modex(x,y/2,p);
		return (ans*ans)%p;
    }
    return ((x%p)*(modex(x,y-1,p)))%p;
}

int main(){
    lint x = 12;
    lint y = 7;
    lint p = 17;
    cout<<"("<<x<<"^"<<y<<")%"<<p<<" = "<<modex(x,y,p);

    return 0;
}

