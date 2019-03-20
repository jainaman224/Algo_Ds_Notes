
def LCS(string1, string2):

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
	
	curr, maxlength, end = 0, 0, 0
	for i in range(1,m+1):
		for j in range(1,n+1):
			
			if string1[i-1] == string2[j-1]:
				
				consqRow[curr][j] = consqRow[1 - curr][j - 1] + 1
				if (consqRow[curr][j] > maxlength):
					maxlength = consqRow[curr][j]
					end = i - 1
			else:
					consqRow[curr][j] = 0

		curr = 1 - curr
	if maxlength == 0:
		return "-1"
	else:
		return string1[end-maxlength+1:end+1]
                
def main():
	string1 = "DsAlgoNotes"
	string2 = "gssocAlgoNote19"
	common = LCS(string1,string2)
	print("String1:",string1)
	print("String2:",string2)
	if common == "-1":
		print("No common SubString")
	else:
		print("Longest Common Substring:",common,"( of length:",len(common),")")
if __name__ == '__main__':
	main()
