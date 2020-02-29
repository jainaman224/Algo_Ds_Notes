#include <stdio.h>

// Function that computes the longest commmon subsequence between two arrays of numbers
// Input: First Array, Second Array, Size of First Array, Size of Second Array
// Output: Longest Common Subsequnce
int LongestCommonSubsequence(int arr1[], int arr2[], int size1, int size2) {
    // Declaring a 2-D array LCS where LCS[i][j] denotes the longest common subsequence of 
    // the two arrays until the ith element of the first array and the jth element of the second array
    int LCS[size1 + 1][size2 + 1];
    for (int i = 0; i <= size1; i++) {
        for (int j= 0; j <= size2; j++) {
            // Scenario 1: putting a 0 if either of the index is 0
            if (i == 0 || j == 0) {
                LCS[i][j] = 0;
            }             
            // Scenario 2: ith element of the first array is equal to jth element of array of second array
            else if (arr1[i - 1] == arr2[j - 1]) {
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            }             
            // Scenario 3: ith element of the first array is not equal to jth element of array of second array.
            // In this case we chose the max between LCS[i - 1][j] and LCS[i][j - 1]
            else {
                LCS[i][j] = LCS[i - 1][j] > LCS[i][j - 1] ? LCS[i - 1][j] : LCS[i][j - 1];
            }
        }
    }
    return LCS[size1][size2];
}

int main() 
{ 
    int arr1[]= {10, 15, 20, 25, 30, 35, 40};
    int arr2[] = {10, 12, 23, 25, 28, 30, 32, 40};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int l = LongestCommonSubsequence(arr1, arr2, size1, size2);
    printf("Length of Longest Common Subsequence is: %d\n", l);
    return 0; 
}