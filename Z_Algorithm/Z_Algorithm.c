//Z-algorithm implementation in C
#include<stdio.h> 
#include<string.h>

/*
Z-Array:
An element Z[i] of Z array stores length of the longest substring starting from str[i] which is also a prefix of str[0..n-1].
The idea is to concatenate pattern and text, and create a string “P$T” where P is pattern, $ is a special character should not be present in pattern and text, and T is text. Build the Z array for concatenated string. In Z array, if Z value at any point is equal to pattern length, then pattern is present at that point. 
*/

void main() {
	// The given string is 'namanchamanbomanamansanam'
   	char mainString[50] = "namanchamanbomanamansanam";
	// The given pattern is 'aman'
   	char pattern[50] = "aman";
   	//Apart from other languages operations on strings are bit complex
   	//Make sure to include string.h header and use operations strcpy and strcat to copy and concatenate 		respectively
   	//You have to consider both since the first parameter of strcat itself becomes the result and 		becomes mutated
   	//so we will have to copy it into another variable to use later
   	char mainStringcpy[50];
   	char patterncpy[50];
   	int TempArray[strlen(mainString)];
   	int index = -1;
   	strcpy(patterncpy, pattern);
   	strcpy(mainStringcpy, mainString);
   	strcat(pattern,"$");
   	strcat(pattern,mainString);
   	char combinedString[100]="";
   	strcat(combinedString,pattern);
   	int patternLength = strlen(patterncpy);
   	int combinedStringLength = strlen(combinedString);
   	int Zarray[combinedStringLength];
   	int n = strlen(combinedString);
   	//The z-section is from zleft to zright
   	int zleft=0, zright=0, current;

	//Creating the Z-array
	for(int i = 1; i < n; i++) {
      		if(i > zright) {
         		zleft = zright = i;    
         		while(zright < n && combinedString[zright-zleft] == combinedString[zright]) {
            			zright++;     
         		}
         		Zarray[i] = zright-zleft;
         		zright--;
      		}
		else {
         		current = i-zleft;
         		if(Zarray[current] < zright-i+1){
            			Zarray[i] = Zarray[current];
			}    
         		else {
            			zleft = i;
            			while(zright < n && combinedString[zright - zleft] == combinedString[zright]) {
               				zright++;
            			}
            			Zarray[i] = zright - zleft;
            			zright--;
         		}
      		}
   	}


	for(int i = 0; i<combinedStringLength; i++) {
      		if(Zarray[i] == patternLength) {
         		(index)++;
         		TempArray[(index)] = i - patternLength ;
      		}
   	}
   	for(int i = 0; i <= index; i++) {
      		printf("The pattern %s is found at index : %d\n",patterncpy,TempArray[i]);
   	}
}
/*
Output
-------------------
Pattern found at 2
Pattern found at 8
Pattern found at 17
-------------------
*/
//Happy Coding
