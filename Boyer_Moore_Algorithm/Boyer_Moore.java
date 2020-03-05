/* Author : Sonali Patel*/
/* Java Program for Boyer Moore String Matching Algorithm */
import java.util.*;

class Main{ 
	
    static int NO_OF_CHARACTERS = 256; 
    static int max_of_a_and_b (int a, int b){ 
        return (a > b)? a: b; 
    } 
    
    static void badCharacterHeuristic( char []str, int size,int badcharacter[]){ 
        int i; 

        // Initialize all elements of badcharacter as -1 
        for (i = 0; i < NO_OF_CHARACTERS; i++){ 
            badcharacter[i] = -1; 
        }
        // Fill the actual value of last occurrence of a character 
        for (i = 0; i < size; i++){ 
            badcharacter[(int) str[i]] = i;
        }   
    } 

    // A pattern searching function 
    static void search( char text[], char pattern[]){ 
        int m = pattern.length; 
        int n = text.length; 

        int badCharacterHeuristic[] = new int[NO_OF_CHARACTERS]; 

        /* Fill the bad character array by calling the preprocessing function badCharHeuristic() for given pattern */
        badCharacterHeuristic(pattern, m, badcharacter); 

        int s = 0; // s is shift of the pattern with respect to text 

        while(s <= (n - m)){ 
            int j = m-1; 

            /* Keep reducing index j of pattern while characters of pattern and text are matching at this shift s */
            while(j >= 0 && pattern[j] == text[s+j]) 
                j--; 

            /* If the pattern is present at current shift, then index j will become -1 after the above loop */
            if (j < 0){ 
                System.out.println("Patterns occur at shift = " + s); 

                // Shift the pattern so that the next character in text aligns with the last occurrence of it in pattern. 
                // The condition s+m < n is necessary for the case when pattern occurs at the end of text 
                s += (s+m < n)? m-badcharacter[text[s+m]] : 1; 

            } else
                s += max_of_a_and_b(1, j - badcharacter[text[s+j]]); 
        } 
    } 

    /* Driver program*/
    public static void main(String []args) { 

        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        char text[] = s.toCharArray();
        s = sc.nextLine();
        char pattern[] = s.toCharArray();
        search(text, pattern); 
    } 
} 

/* Samle input and output
Input: AABAACAADAABAABA AABA
Output:
pattern occurs at shift = 0
pattern occurs at shift = 9
pattern occurs at shift = 12 */


