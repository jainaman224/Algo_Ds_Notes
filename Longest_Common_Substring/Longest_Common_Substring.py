# Space Complexity: O(n)
# Time Complexity: O(m*n) 

def LongestCommonSubstring(string1, string2):
	# longest string is string1 and the smallest string is string2
	if len(string2) > len(string1):
		temp = string2 
		string2 = string1
		string1 = temp
	m = len(string1)
	n = len(string2)
	consqRow = []

	for i in range(2):
		temp = []
		for j in range(n+1):
			temp.append(0)
		consqRow.append(temp)
	
	#  1st row and 1st column matrix consqRow need to be 0
	#  As the default value initialized is 0 so we can ignore this condition here
	#	0 0 0 0 0 0
	#	0 x x x x x
	
	curr, maxlength, end = 0, 0, 0 #length of longest common Substring in maxlength
	#ending point of longest common Substring

	#maintaing the array for consequtive two rows
	for i in range(1,m+1):
		for j in range(1,n+1):
			if string1[i-1] == string2[j-1]:
				consqRow[curr][j] = consqRow[1 - curr][j - 1] + 1
				if (consqRow[curr][j] > maxlength):
					maxlength = consqRow[curr][j]
					end = i - 1
			else:
				consqRow[curr][j] = 0
		curr = 1 - curr #changing the row alternatively

	if maxlength == 0:
		return "-1"
	else:
		# string is from end-maxlength+1 to end as maxlength is the length of
        #  the common substring.
		return string1[end-maxlength+1:end+1]
                
def main():
	string1 = "DsAlgonotes"
	string2 = "gssocAlgoNotes19"
	common = LongestCommonSubstring(string1,string2)
	print("String1:",string1)
	print("String2:",string2)
	if common == "-1":
		print("No common SubString")
	else:
		print("Longest Common Substring:",common,"( of length:",len(common),")")

if __name__ == '__main__':
	main()

'''

Sample Input:
    string1:  DsAlgonotes
    string2:  gssocAlgoNotes19

Sample Output:
   Longest Common Substring: Algo (of length: 4)

'''