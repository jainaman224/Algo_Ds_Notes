#include<bits/stdc++.h>

using namespace std;

int LongestRepeatingSubsequence(string str) { 
    int length;
    length = str.length();

    // Initialize all dp elements with 0
    vector<vector<int>> dp(length+1, vector<int>(length+1, 0));

    for (int i=1; i<=length; i++) {
        for (int j=1; j<=length; j++) {

            // If two characters are same(different position)  
            // then dp of present state is dp of previous state plus 1
            if(i != j && str[i-1] == str[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else {

                // else maximum of just vertically above or horizontally left element
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);              
            }
        }
    }

    // returing value of result
    return dp[length][length];
}

int main()
{     
    string str = "AlgoDsNoteDs";
    int length = LongestRepeatingSubsequence(str);
    cout << "String: " << str << "\n";
    cout << "Length of the longest repeating subsequence is: " << length << "\n";
}

/*
Sample Output:
    String: AlgoDsNotesDs
    Length of longest repeating subsequence is: 3

Explanation:
    The longest repeating subsequence is "oDs"
*/
