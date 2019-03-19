#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 
#include<bits/stdc++.h>
using namespace std; 
// EXAMPLE
//Input:  keys[] = {10, 12, 20}, freq[] = {34, 8, 50}
//There can be following possible BSTs
//    10                12                 20         10              20
//      \             /    \              /             \            /
//      12          10     20           12               20         10  
//        \                            /                 /           \
//         20                        10                12             12  
//     I               II             III             IV             V
//Among all possible BSTs, cost of the fifth BST is minimum.  
//Cost of the fifth BST is 1*50 + 2*34 + 3*8 = 142


int sum(int freq[], int i, int j) 
{ 
    int s = 0; 
    for (int k = i; k <=j; k++) 
       s += freq[k]; 
    return s; 
} 
  
  

int minCostBST(int keys[], int freq[], int n)
{
   int cost[n][n];
   for (int i = 0; i < n; i++)    
      cost[i][i] = freq[i]; // freq is assigned to the diagonal elements of 2-D array cost.

   for (int leng=2; leng<=n; leng++) 
    {
        for (int i=0; i<=n-leng+1; i++) 
          {   
             int j = i+leng-1;
             cost[i][j] = INT_MAX;    
             // One by one consider all elements as root
             for (int r=i; r<=j; r++) {
             //comparing with the cost and update cost if needed
             int c = ((r > i)?cost[i][r-1]:0)+((r < j)?cost[r+1][j]:0)+sum(freq, i, j);
             if (c < cost[i][j])
                cost[i][j] = c;
          }
      }
  }
   return cost[0][n-1];
}


  


int main() 
{   
    int n,i;
    cout <<"Enter the numbers of keys ";
    cin>>n;
    int keys[n]; 
    int freq[n];
    cout<<"Enter the data elements ";
    for ( i=0;i<n;i++)
       cin>>keys[i];
    cout<<"Enter the frequencies ";
    for (i=0;i<n;i++)
       cin>>freq[i];
    
    cout<<"Cost of Optimal Binary search tree is  ",  
              cout<< minCostBST(keys, freq, n); 
    return 0; 
}
//INPUT:Enter the numbers of keys 3    
//Enter the data elements 10
//12
//34
//Enter the frequencies 54
//10
//4
//OUTPUT:Cost of Optimal Binary search tree is  86 
