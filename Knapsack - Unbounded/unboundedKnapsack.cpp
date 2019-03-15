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

lint UnboundedKnapsack(lint W,lint n, lint wt[],lint val[]){
    lint dp[W+1];
    f(W+1){
        dp[i]=0;                            // Initialzing our dp array with 0
    }
    f(W+1){
        fj(n){
            if(wt[j]<=i){
                dp[i] = max(dp[i], dp[i-wt[j]] + val[j]);   // Dp formula : dp[i] = max value we can achieve with available items and knapsack capacity being i.
            }
        }
    }
    return dp[W];
}

int main(){
    //  The no. of items : 
    lint n = 4;
    //  Weights of all the items : 
    lint wt[4] = {5 , 10, 8, 15};
    //  Enter values of all the items : 
    lint val[4] = {40, 30, 50, 25};
    // Enter the knapsack capacity : 
    lint W = 120;
    cout<<"The maximum value you can achieve in Unbounded Knapsack is: "<<UnboundedKnapsack(W,n,wt,val);

    return 0;
}

