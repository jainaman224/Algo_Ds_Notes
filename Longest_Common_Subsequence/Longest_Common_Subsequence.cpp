/* Problem Statement- Given two sequences, find the length of longest subsequence present in both of them. A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.*/
#include<bits/stdc++.h> 
using namespace std;

// Function to calculate length of longest common subsequence
int LongestCommonSubsequence(int arr1[], int arr2[], int n, int m) 
{ 
   int LCS[n+1][m+1];
   for (int i=0; i<=n; i++) 
   { 
        for (int j=0; j<=m; j++) 
        { 
            if (i == 0 || j == 0) 
                LCS[i][j] = 0; 
            else if (arr1[i-1] == arr2[j-1]) 
                LCS[i][j] = LCS[i-1][j-1] + 1; 
            else
                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]); 
        } 
   } 
   return LCS[n][m]; 
} 
   
// Driver Function
int main() 
{ 
    int arr1[]= {10, 15, 20, 25, 30, 35, 40};
    int arr2[] = {10, 12, 23, 25, 28, 30, 32, 40};
    int n= sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    int l= LongestCommonSubsequence(arr1, arr2, n, m);
    cout<<"Length of Longest Common Subsequence is: "<<l<<endl;
    return 0; 
}
/*The longest common subsequence comprises of elements 10, 25, 30, 40 in the above arrays
Output:
Length of Longest Common Subsequence is: 4
*/
