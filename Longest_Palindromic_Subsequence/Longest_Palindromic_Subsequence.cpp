/*
    LONGEST PALINDROMIC SUBSEQUENCE
    The task is to find the length of the longest possible subsequence
    of a given word which is a palindrome.
    A palindrome is a string that is same when read from any side.
*/
#include <bits/stdc++.h>
using namespace std;
#define lint long long int

/*
    Printing Longest Palindromic Subsequence
*/
string print_lps(vector<vector<lint> > lps_dp, lint len, string str, string rev) {
    lint row = len, col = len;
    string ans = "";
    for (;row > 0 && col > 0;) {
        if (str[row-1] == rev[col-1]) {
            ans = str[row-1] + ans;
            row--;
            col--;
        } 
        else {
            if (lps_dp[row - 1][col] > lps_dp[row][col - 1]) {
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

void lps(string str) {
	string rev = str;
	int len = str.length();
  // Stroring the reverse of the string.
	reverse(rev.begin(), rev.end());
	vector<vector<int> > lps_dp;
	for (int i = 0; i <= len; i++) {
		vector<int> temp;
		for (int j = 0; j <= len; j++) {
			if (i == 0 || j == 0) {
			        temp.push_back(0);    
			}
			else {
				if (str[i - 1] == rev[j - 1]) {
					/*
						When we find a match between s[i] and r[j], the lps count would be
						one more than the lps between s[0...i-1] and r[0...j-1].
					*/
					temp.push_back( (lps_dp[i - 1][j - 1] + 1) );
				} 
				else {
					int ans = 0;
					/*
						If no match found between s[i] and r[j], the lps count would be 
						maximum of lps found between (s[0....i-1] and r[0....j]) and 
						(s[0...i] and r[0...j-1]).
					*/
					if (temp[j-1] >= lps_dp[i-1][j]) {
						ans = temp[j-1];
					}
					else {
						ans = lps_dp[i-1][j];
					}
					temp.push_back(ans);
				}
			}
		}
		lps_dp.push_back(temp);
	}
	cout << "The longest palindromic subsequence is of length : " << lps_dp[len][len];
}



int main() {
    string str = "DATASTRUCTURES";
    lps(str);
    return 0;
}
/*
Input : DATASTRUCTURES
Output : The longest palindromic subsequence is of length : 7
         The longest palindromic subsequence is SRUTURS
Verification :
The concerned 2D matrix formed is :
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
    And the longest palindromic subsequence of the string is : SRUTURS (length =
7)
*/
