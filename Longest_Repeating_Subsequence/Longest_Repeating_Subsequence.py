
def LongestRepeatingSubsequence(string):
    length = len(string)
    
    # Initialize dp with zero
    dp = [[0]*(length+1) for i in range(length+1)]

    for i in range(1,length+1):
        for j in range(1,length+1):

            # If two characters are same(different position)
            # then dp of present state is dp of previous state plus 1
            if i != j and string[i-1] == string[j-1]:
                dp[i][j] = dp[i-1][j-1] + 1
            else:

                # Else maximum of just vertically above or horizontally left element
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])

    return dp[length][length]

def main():
    string = "AlgoDsNoteDs"
    length = LongestRepeatingSubsequence(string)
    print("String: ", string)
    print("Length of longest repeating subsequence: ", length)

if __name__ == '__main__':
    main()

'''

Sample Output:
    String: AlgoDsNotes
    Length of longest repeating subsequence: 3

Explanation:
    Longest Repeating Subsequence is "oDs"

'''
