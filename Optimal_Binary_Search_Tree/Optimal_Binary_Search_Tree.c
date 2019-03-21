#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 

// EXAMPLE
//Input:  keys[] = {10, 12, 34}, freq[] = {54, 10, 4}
//There can be following possible BSTs
//    10                12                 34         10              34
//      \             /    \              /             \            /
//      12          10     34           12               34         10  
//        \                            /                 /           \
//         34                        10                12             12  
//     I               II             III             IV             V
//  
//Cost of the optimal BST (1 BST) is  = 86

int sum(int freq[], int i, int j) 
{ 
    int count= 0; 
    for (int k = i; k <=j; k++) 
       count += freq[k]; 
    return count; 
} 

int minCostBST(int keys[], int freq[], int size)
{
   int cost[size][size];
   for (int i = 0; i < size; i++)    
      cost[i][i] = freq[i]; // freq is assigned to the diagonal elements of 2-D array cost.

   for (int leng=2; leng<=size; leng++) 
    {
        for (int i=0; i<=size-leng+1; i++) 
          {   
             int j = i+leng-1;
             cost[i][j] = INT_MAX;    
             // One by one consider all elements as root
             for (int r=i; r<=j; r++) 
             {
               //comparing with the cost and update cost if needed
               int c = ((r > i)?cost[i][r-1]:0)+((r < j)?cost[r+1][j]:0)+sum(freq, i, j);
               if (c < cost[i][j])
                  cost[i][j] = c;
             }
          }
     }
   return cost[0][size-1];
}

int main() 
{   
    int size,i;
    printf("Enter the numbers of keys ");
    scanf("%d",&size);
    int keys[size]; 
    int freq[size];
    printf("Enter the data elements ");
    for ( i=0;i<size;i++)
       scanf("%d",&keys[i]);
    printf("Enter the frequencies ");
    for (i=0;i<size;i++)
       scanf("%d",&freq[i]);
    
    printf("Cost of Optimal Binary search tree is  %d ",minCostBST(keys, freq, size));  
               
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
