# Problem Statement- Given two sequences, find the length of longest subsequence present in both of them. A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

# Function to calculate length of longest common subsequence
def LongestCommonSubsequence(arr1, arr2, size1, size2):
   LCS = [[0 for x in range(size2+1)] for y in range(size1+1)] 
   for i in range(0,size1+1):
        for j in range(0,size2+1):
            if i == 0 or j == 0:
                LCS[i][j] = 0
	    # when the last character of both subsequences match, increase length of lcs by 1
	    # LCS( {10,15,20,25} ,{10,15,23,25} )=1+ LCS( {10,15,20} ,{10,15,23} )
            elif arr1[i-1] == arr2[j-1]:
                LCS[i][j] = LCS[i-1][j-1] + 1
	    # when the last character is not same, take maximum obtained by adding one character to one of the subsequences 
	    # LCS({10,15,20} ,{10,15,23})= max(LCS( {10,15,20} ,{10,15} ) ,LCS( {10,15} ,{10,15,23}) )
            else:
                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1])
   return LCS[size1][size2]
   
# Driver Code
arr1 = [10, 15, 20, 25, 30, 35, 40]
arr2 = [10, 12, 23, 25, 28, 30, 32, 40]
size1 = len(arr1)
size2 = len(arr2)
l= LongestCommonSubsequence(arr1, arr2, size1, size2)
print("Length of Longest Common Subsequence is: ",l)
#The longest common subsequence comprises of elements 10, 25, 30, 40 in the above arrays
#Output:
#Length of Longest Common Subsequence is: 4
