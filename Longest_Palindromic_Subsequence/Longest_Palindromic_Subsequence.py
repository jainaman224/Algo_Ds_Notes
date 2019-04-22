'''
    LONGEST PALINDROMIC SUBSEQUENCE
    The task is to find the length of the longest possible subsequence
    of a given word which is a palindrome.
    A palindrome is a string that is same when read from any side.
'''

'''
    Printing Longest Palindromic Subsequence
'''
def print_lps(lps_dp, length, st, rev):
    row = length
    col = length
    ans = ""
    while (row > 0 and col > 0):
        if (st[row-1] == rev[col-1]):
            ans = st[row-1] + ans
            row = row-1
            col = col-1
        else:
            if (lps_dp[row - 1][col] > lps_dp[row][col - 1]):
                row = row-1
            else:
                col = col-1
    return ans
    
'''
    We use Dynamic Programming approach to solve this problem.
    A 2D matrix M of size n*n is created where n is the length of the given
    string. Here the row i denotes the char S[i] of the string while column j
    denotes char R[j], where R is the reverse of the string S. Thus, M[i][j]
    denotes the max length of longest common subsequence between the string
    S[0...i] and R[0..j]. Hence M[n][n] will compute the longest common
    subsequence of S[0..n] and R[0..n], which is the required answer.
'''    
def lps(st): 
    rev = st
    length = len(st)
    # Stroring the reverse of the string.
    rev = rev[::-1]
    lps_dp = []
    for i in range(0, length+1):
        temp = []
        for j in range(0, length+1):
            if ( i == 0 or j == 0 ):
                temp.append(0)  
            else :
                if ( st[i - 1] == rev[j - 1] ):
                    '''
                        When we find a match between s[i] and r[j], the lps count would be
                        one more than the lps between s[0...i-1] and r[0...j-1].
                    '''
                    temp.append(lps_dp[i - 1][j - 1] + 1)
                else:
                    ans = 0
                    '''
                        If no match found between s[i] and r[j], the lps count would be 
                        maximum of lps found between (s[0....i-1] and r[0....j]) and 
                        (s[0...i] and r[0...j-1]).
                    '''
                    if ( temp[j-1] >= lps_dp[i-1][j] ):
                        ans = temp[j-1]
                    else:
                        ans = lps_dp[i-1][j]
                    temp.append(ans)
        lps_dp.append(temp)
    print("The longest palindromic subsequence is of length : ",lps_dp[length][length])
    print("The longest palindromic subsequence is : ",print_lps(lps_dp,length,st,rev))

st = "DATASTRUCTURES"
lps(st)

'''
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
'''
