#include <bits/stdc++.h> 
using namespace std; 
 
int max(int a, int b) { 
  return (a > b)? a : b; 
}  

int knapSack(int W, int wt[], int val[], int n)  
{   
if (n == 0 || W == 0)     //base case
    return 0;  
  
if (wt[n-1] > W)   //If weight of the nth item is more than Knapsack capacity W, then this item cannot be included in the optimal solution 
    return knapSack(W, wt, val, n-1);  
   
else return max( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1),  
                    knapSack(W, wt, val, n-1) );  
}  
   
int main()  
{  
    int val[] = {60, 100, 120};  
    int wt[] = {10, 20, 30};  
    int W = 50;  
    int n = sizeof(val)/sizeof(val[0]);  
    cout<<knapSack(W, wt, val, n);      //output: 220
    return 0;  
}  
