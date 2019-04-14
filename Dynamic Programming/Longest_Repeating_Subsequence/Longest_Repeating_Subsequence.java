public class Longest_Repeating_Subsequence {
    
    static int LongestRepeatingSubsequence(String str) { 
        int length;
        length = str.length();

        // Intialize dp (default value is zero)
        int dp[][] = new int[length+1][length+1];

        for (int i=1; i<=length; i++) {
            for (int j=1; j<=length; j++) {

                // If two characters are same(different position) 
                // then dp of present state is dp of previous state plus 1
                if(i != j && str.charAt(i-1) == str.charAt(j-1))
                    dp[i][j] = dp[i-1][j-1] + 1;
                else {

                    // Else maximum of just vertically above or horizontally left element
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        // returning value of result
        return dp[length][length];
    }

    public static void main(String args[]) { 
        String str = "AlgoDsNoteDs";
        int length = LongestRepeatingSubsequence(str);
        System.out.println("String: " + str);
        System.out.println("Length of longest repeating subsequence: " + length);
    }

}

/*
Sample Output:
    String: AlgoDsNotes
    Length of repeating subsequence: 3

Explanation:
    The longest repeating subsequence is: "oDs"
*/
