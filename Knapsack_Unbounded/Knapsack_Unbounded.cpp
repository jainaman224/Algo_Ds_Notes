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

lint UnboundedKnapsack(lint Capacity,lint n, lint weight[],lint value[]){
    lint maxProfit[Capacity+1];
    for(lint i=0;i<Capacity+1;i++){
        maxProfit[i]=0;                            // Initialzing our dp array with 0
    }
    for(lint i=0;i<W+1;i++){
        for(lint j=0;j<n;j++){
            if(weight[j]<=i){
                maxProfit[i] = max(maxProfit[i], maxProfit[i-weight[j]] + value[j]);   // Dp formula : maxProfit[i] = max value we can achieve with available items and knapsack capacity being i.
            }
        }
    }
    return maxProfit[Capacity];
}

int main(){
    //  The no. of items : 
    lint n = 4;
    //  Weights of all the items : 
    lint weight[4] = {5 , 10, 8, 15};
    //  Enter values of all the items : 
    lint value[4] = {40, 30, 50, 25};
    // Enter the knapsack capacity : 
    lint Capacity = 120;
    cout<<"The maximum value you can achieve in Unbounded Knapsack is: "<<UnboundedKnapsack(Capacity,n,weight,value);

    return 0;
}

