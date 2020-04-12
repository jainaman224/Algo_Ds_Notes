import 'dart:math';

LongestCommonSub(String a, String b){
  int n = a.length;
  int m = b.length;

  var memo = new List<List<int>>.generate(n + 1,(_) => new List.filled(m+1, 0), growable: false);

  for (int i = 0; i < a.length; i++) {
    for (int j = 0; j < b.length; j++) {
      if (a[i] == b[j]) {
        memo[i+1][j+1] = memo[i][j] + 1;
      } else {
        memo[i+1][j+1] = max(memo[i+1][j], memo[i][j+1]);
      }
    }
  }

    return memo[n][m];
 
}
