/*
    LONGEST PALINDROMIC SUBSEQUENCE
    The task is to find the length of the longest possible subsequence
    of a given word which is a palindrome.
    A palindrome is a string that is same when read from any side.
*/
import java.util.*;

public class LongestPalindromicSubsequence {
    
    /*
        Printing Longest Palindromic Subsequence
    */

    public static String printLps(int[][] lpsDp, int len, String str, String rev) {
        int row = len, col = len;
        String ans = "";
        for ( ; row > 0 && col > 0; ) {
            if (str.charAt(row - 1) == rev.charAt(col - 1)) {
                ans = str.charAt(row - 1) + ans;
                row--;
                col--;
            } 
            else {
                if (lpsDp[row - 1][col] > lpsDp[row][col - 1]) {
                    row--;
                } 
                else {
                    col--;
                }
            }
        }
        return ans;
    }

/*
    We use Dynamic Programming approach to solve this problem.
    A 2D matrix M of size n*n is created where n is the length of the given
    string. Here the row i denotes the char S[i] of the string while column j
    denotes char R[j], where R is the reverse of the string S. Thus, M[i][j]
    denotes the max length of longest common subsequence between the string
    S[0...i] and R[0..j]. Hence M[n][n] will compute the longest common
    subsequence of S[0..n] and R[0..n], which is the required answer.
*/
    public static void lps(String str) {
        String rev = "";
        int len = str.length();
        // Stroring the reverse of the string.
        for (int i = len - 1; i >= 0; i--){
            rev = rev + str.charAt(i);
        }
        int lpsDp[][] = new int[len + 1][len + 1];
        for (int i = 0; i <= len; i++) {
            for (int j = 0; j <= len; j++) {
                if (i == 0 || j == 0) {
                    lpsDp[i][j] = 0;  
                }
                else{
                    if (str.charAt(i - 1) == rev.charAt(j - 1)) {
                        /*
                            When we find a match between s[i] and r[j], the lps count would be
                            one more than the lps between s[0...i-1] and r[0...j-1].
                        */
                        lpsDp[i][j] = (lpsDp[i - 1][j - 1] + 1);
                    } else {
                        int ans = 0;
                        /*
                            If no match found between s[i] and r[j], the lps count would be 
                            maximum of lps found between (s[0....i-1] and r[0....j]) and 
                            (s[0...i] and r[0...j-1]).
                        */
                        if(lpsDp[i][j - 1] >= lpsDp[i - 1][j]){
                            ans = lpsDp[i][j - 1];
                        }
                        else{
                            ans = lpsDp[i - 1][j];
                        }
                        lpsDp[i][j] = ans;
                    }
                }
            }
        }
        System.out.println("The longest palindromic subsequence is of length: " + lpsDp[len][len]);
        System.out.println("The longest palindromic subsequence is: " + printLps(lpsDp, len, str, rev));

    }

    public static void main(String[] args) {
        String str;
        Scanner sc = new Scanner(System.in);
        str = sc.nextLine();
        lps(str);
    }
}

/*
Input: DATASTRUCTURES
Output: The longest palindromic subsequence is of length: 7
         The longest palindromic subsequence is SRUTURS
Verification:
The concerned 2D matrix formed is:
    S E R U T C U R T S A T A D
  0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
D 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
A 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1
T 0 0 0 0 0 1 1 1 1 1 1 1 2 2 2
A 0 0 0 0 0 1 1 1 1 1 1 2 2 3 3
S 0 1 1 1 1 1 1 1 1 1 2 2 2 3 3
T 0 1 1 1 1 2 2 2 2 2 2 2 3 3 3
R 0 1 1 2 2 2 2 2 3 3 3 3 3 3 3
U 0 1 1 2 3 3 3 3 3 3 3 3 3 3 3
C 0 1 1 2 3 3 4 4 4 4 4 4 4 4 4
T 0 1 1 2 3 4 4 4 4 5 5 5 5 5 5
U 0 1 1 2 3 4 4 5 5 5 5 5 5 5 5
R 0 1 1 2 3 4 4 5 6 6 6 6 6 6 6
E 0 1 2 2 3 4 4 5 6 6 6 6 6 6 6
S 0 1 2 2 3 4 4 5 6 6 7 7 7 7 7
    And the longest palindromic subsequence of the string is: SRUTURS (length = 7)
*/
