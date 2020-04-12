/*
Problem Statement - Given two sequences, find the length of longest subsequence present in 
both of them.A subsequence is a sequence that can be derived from another sequence by 
deleting some or no elements without changing the order of the remaining elements.
*/
import 'dart:math';

// I/P and O/P Examples
void main() {
    var inputSet1 = [10, 15, 20, 25, 30, 35, 40];
    var inputSet2 = [10, 12, 23, 25, 28, 30, 32, 40];
    var result = LongestCommonSub(inputSet1, inputSet2);
    // The length of longest subsequence is: 4
    print('The length of longest subsequence is: ${result}');
}

LongestCommonSub(List  a, List  b){
    int n = a.length;
    int m = b.length;

    var memo = new List<List<int>>.generate(n + 1,(_) => new List.filled(m+1, 0), growable: false);

    for (int i = 0; i < a.length; i++) {
        for (int j = 0; j < b.length; j++) {
            // when the last character of both match, increase length of lcs by 1
            if (a[i] == b[j]) {
                memo[i+1][j+1] = memo[i][j] + 1;
      } 
            /* 
            when the last character is not same, take maximum obtained by adding 
            one character to one of the subsequences.
            */
            else {
                memo[i+1][j+1] = max(memo[i+1][j], memo[i][j+1]);
      }
    }
  }

    return memo[n][m];
 
}
