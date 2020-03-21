//Implementation of the Knuth Morris Pratt algorithm for pattern searching in C language
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>

char *parent = "acabacdabac";
char *pattern = "abacdab";

int* makeTable(char* pattern) {

	int patternSize = strlen(pattern);
	int *table = (int*)malloc(patternSize*sizeof(int));
	int j = 0; int i = 1 ;
	memset(table, 0, sizeof(table));
	for (i = 1; i <= patternSize; i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = table[j - 1];    // If there is a mismatch, move j one by one until the last match. At this time, j = table [j-1].
		}
		if (pattern[i] == pattern[j]) {
			table[i] = ++j; 
		}
	}
	return table;
}

void KMP_ALGORITHM(char* originaltext, char*pattern) {

	int patternlen = strlen(pattern);
	int textlen = strlen(originaltext);
	int* table = makeTable(pattern);
	int j = 0; int i = 1;
	for (i = 0; i < textlen; i++) {
		while (j > 0 && pattern[j] != originaltext[i]) {
			j = table[j - 1];
		}
		if (originaltext[i] == pattern[j]) {
			if (j == patternlen - 1) {
				printf("The given pattern matches with the text from index %d to %d.\n", i - patternlen + 1,i);
			}
			else {
				j++;
			}
		}
	}
}

int main() {
    int m, n;
    
    printf("Enter the length of text : ");
    scanf("%d", &n);
    char text[n];
    printf("\nEnter the text : ");
    scanf("%s", text);

    printf("\nEnter length of pattern : ");
    scanf("%d", &m);
    char pat[m];
    printf("\nEnter the pattern : ");
    scanf("%s", pat);
    printf("\n");
	
    KMP_ALGORITHM(text, pat);
    printf("\n");
    return 0;
}

/*SAMPLE INPUT AND OUTPUT
SAMPLE 1
Enter the length of text : 6                                                                                                                 
Enter the text : banana                                                                                                                         
                                                                                                                                              
Enter length of pattern : 2                                                                                                                   
Enter the pattern : an                                                                                                                        
                                                                                                                                              
The given pattern matches with the text from index 0 to 1.                                                                                    
The given pattern matches with the text from index 2 to 3. 
SAMPLE 2
Enter the length of text : 4                                                                                                                  
Enter the text : anan                                                                                                                         
                                                                                                                                              
Enter length of pattern : 2                                                                                                                   
Enter the pattern : an                                                                                                                        
                                                                                                                                              
The given pattern matches with the text from index 0 to 1.                                                                                    
The given pattern matches with the text from index 2 to 3.   
The given pattern matches with the text from index 4 to 5.                                                                                    
The given pattern matches with the text from index 7 to 8.  
*/
