#include<bits/stdc++.h>
using namespace std;
	
// Function to find longest common substring. 
string LCS(string str1, string str2) 
{ 
  	
  	string temp;

  	// longest string is str1 and the smallest string is str2
    if(str2.size() > str1.size()){
    	temp = str1;
    	str1= str2;
    	str2 = temp;
    }
    int m, n; 
    m = str1.size();
    n = str2.size();

    int maxlength = 0; //length of longest common Substring
  	int end; //ending point of longest common Substring
  
    
    int consqRow[2][n+1]; //store result of 2 consecutive rows
    int curr = 0; //current row in the matrix  
  	
  	//maintaing the array for consequtive two rows
  	for(int i=0;i<2; i++){
  		for(int j=0;j<=n; j++){
  				consqRow[i][j] = 0;
  		}
  	}

    for (int i = 1; i <= m; i++) { 

        for (int j = 1; j <= n; j++) { 

            if (str1[i - 1] == str2[j - 1]) { 
              
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
   
        curr = 1 - curr; // changing the row
    } 
  	

    
    if (maxlength == 0) { 
        return "-1"; 
    } 
  	else{
  		string s = "";

  		for(int i=end-maxlength+1; i<=end; i++){
  			s+=str1[i];
  		}
  		
    	return s; 
  	}
}

int main(){

	string string1 = "DsAlgoNotes"; 
	string string2 = "gssocAlgoNote19";
		
	string lcsStr = LCS(string1, string2);

	cout << "String1: " << string1 << "\nString2: " << string2 << "\n";
	if(lcsStr == "-1"){
		cout << "No common substring\n"; 
	}
	else{
		cout << "Longest Common Substring: " << lcsStr << " (of length: " << lcsStr.size() << ")\n";
	}
	return 0;
}