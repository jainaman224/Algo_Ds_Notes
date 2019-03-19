/* Problem Statement- Given two sequences, find the length of longest subsequence present in both of them. A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.*/
package main

import "fmt"

// Function to calculate max of two elements
func max(a int, b int) int {
    if a>=b {
        return a
    } else {
        return b
    }
}

// Function to calculate length of longest common subsequence
func LongestCommonSubsequence(arr1[] int, arr2[] int, n int, m int) int { 
    // initialising 2D array in Go
    LCS := make([][]int, n+1)
    for i := range LCS {
        LCS[i] = make([]int, m+1)
    }
    // Computing lcs
    for i := 0; i<=n; i++ {
        for j := 0; j<=m; j++ { 
            if i == 0 || j == 0 {
                LCS[i][j] = 0
            } else if arr1[i-1] == arr2[j-1] {
                LCS[i][j] = LCS[i-1][j-1] + 1
            } else {
                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1])
            }
        } 
    } 
   return LCS[n][m]; 
} 
   
// Driver Function
func main() { 
    arr1 := []int{10, 15, 20, 25, 30, 35, 40}
    arr2 := []int{10, 12, 23, 25, 28, 30, 32, 40}
    n := len(arr1)
    m := len(arr2)
    l := LongestCommonSubsequence(arr1, arr2, n, m)
    fmt.Printf("Length of Longest Common Subsequence is: %d", l)
}
/*The longest common subsequence comprises of elements 10, 25, 30, 40 in the above arrays
Output:
Length of Longest Common Subsequence is: 4
*/
