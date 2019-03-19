/* Problem Statement- Given two sequences, find the length of longest subsequence present in both of them. A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.*/
import java.lang.Math;

class LCS
{
    // Function to calculate length of longest common subsequence
    public static int LongestCommonSubsequence(int arr1[], int arr2[], int n, int m) 
    { 
        int lcs[][] = new int[n+1][m+1];
        for (int i=0; i<=n; i++) 
        { 
                for (int j=0; j<=m; j++) 
                { 
                    if (i == 0 || j == 0) 
                        lcs[i][j] = 0; 
                    else if (arr1[i-1] == arr2[j-1]) 
                        lcs[i][j] = lcs[i-1][j-1] + 1; 
                    else
                        lcs[i][j] = Math.max(lcs[i-1][j], lcs[i][j-1]); 
                } 
        } 
        return lcs[n][m]; 
    } 
   
    // Driver Function
    public static void main(String args[]) 
    { 
        int arr1[] = {10, 15, 20, 25, 30, 35, 40};
        int arr2[] = {10, 12, 23, 25, 28, 30, 32, 40};
        int n = arr1.length ;
        int m = arr2.length;
        LCS obj=new LCS();
        int l= obj.LongestCommonSubsequence(arr1, arr2, n, m);
        System.out.println("Length of Longest Common Subsequence is: "+l);
    }
}
/*The longest common subsequence comprises of elements 10, 25, 30, 40 in the above arrays
Output:
Length of Longest Common Subsequence is: 4
*/
