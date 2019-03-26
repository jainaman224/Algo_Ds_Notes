// Space Complexity: O(n)
// Time Complexity: O(m*n) 
  
public class Longest_Common_Substring { 
  
	static String LongestCommonSubstring(String str1, String str2) { 
		String temp;
		// longest string is str1 and the smallest string is str2
		if(str2.length() > str1.length()){
			temp = str1;
			str1 = str2;
			str2 = temp;
		}  
		int m = str1.length(); 
		int n = str2.length(); 
		int maxlength = 0; //length of longest common Substring 
		int end = 0; //ending point of longest common Substring

		int consqRow[][] = new int[2][n+1]; //store result of 2 consecutive rows
		int curr = 0; //current row in the matrix 

		// 1st row and 1st column (matrix) consqRow need to be 0
		// As the default value in java is 0 so we can ignore this

		//maintaing the array for consequtive two rows
		for (int i = 1; i <= m; i++) { 
			for (int j = 1; j <= n; j++) { 
				if (str1.charAt(i - 1) == str2.charAt(j - 1)) {                   
					consqRow[curr][j] = consqRow[1 - curr][j - 1] + 1; 
						if (consqRow[curr][j] > maxlength) { 
							maxlength = consqRow[curr][j]; 
							end = i - 1; 
						} 
				} 
				else { 
					consqRow[curr][j] = 0; 
				} 
			}   
			curr = 1 - curr; // changing the row alternatively
		} 

		if (maxlength == 0) { 
			return "-1"; 
		} 
		else {
			String s = "";
			// string is from end-maxlength+1 to end as maxlength is the length of
			// the common substring.
			for(int i=end-maxlength+1; i<=end; i++){
				s+= str1.charAt(i);
			}
			return s; 
		}
	} 

	public static void main(String args[]) { 
		String string1 = "DsAlgoNotes"; 
		String string2 = "gssocAlgoNote19"; 
		// function call  
		String temp = LongestCommonSubstring(string1, string2);
		System.out.println("String1: " + string1 + "\nString2: " + string2 );
		if(temp == "-1"){
			System.out.println("No common Substring");
		}
		else
			System.out.println("Longest Common Substring: "+temp + " (of length: " +temp.length()+")"); 
		} 
} 

/*
Sample Input:
    string1:  DsAlgonotes
    string2:  gssocAlgoNotes19

Sample Output:
   Longest Common Substring: Algo (of length: 4)

*/
