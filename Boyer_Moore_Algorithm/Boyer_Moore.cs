// C# Program for Boyer Moore String Matching Algorithm 

using System;

public class Algorithm
{ 
    static int CHARACTERS = 256; 
    
    // Getting maximum of two integers 
    static int max (int a, int b) { return (a > b)? a: b; } 
    
    // Bad Character Pre-Processing Function
    static void badChar( char []str, int size,int []badCharacter) 
    { 
        int i; 

        // Initializing all occurences to -1 
        for (i = 0; i < CHARACTERS; i++)
            badCharacter[i] = -1; 

        // Filling the Actual Value
        for (i = 0; i < size; i++) 
            badCharacter[(int) str[i]] = i;
    } 

    // Pattern Searching Function
    static void search( char []txt, char []pat) 
    {
        int m = pat.Length; 
        int n = txt.Length;

        int []Character = new int[CHARACTERS];
        badChar(pat, m, Character); 

        /* 
            s is used to keep track of 
            pattern shifting with respect to text
        */

        int s = 0; 

        while(s <= (n - m))
        {
            int j = m - 1; 

            while(j >= 0 && pat[j] == txt[s+j])
                j--; 

            /* 
                If the pattern is present at current 
                shift, then index j will become -1 after 
                the above loop 
            */

            if (j < 0) 
            { 
                Console.WriteLine("Pattern occurs at index: " + s); 
                s += (s+m < n)? m-Character[txt[s+m]] : 1; 
            } 

            else 
                s += max(1, j - Character[txt[s+j]]); 

        } 
    } 

    public static void Main() 
    { 
        Console.WriteLine("Enter The String Value: ");
        String valueEntered = Console.ReadLine(); 
        Console.WriteLine("Enter The Pattern To Search: ");
        String pattern = Console.ReadLine();
        Console.WriteLine(); 

        char []txt = valueEntered.ToCharArray(); 
        char []pat = pattern.ToCharArray(); 
        search(txt, pat); 
    } 
} 

/**

Enter The String Value: 
ABAAABCD
Enter The Pattern To Search: 
ABC

Pattern occurs at index: 4

--------------------------------------------------

Enter The String Value: 
AABAACAADAABAABA
Enter The Pattern To Search: 
AABA

Pattern occurs at index: 0
Pattern occurs at index: 9
Pattern occurs at index: 12

--------------------------------------------------

Enter The String Value: 
THIS IS A TEST TEXT
Enter The Pattern To Search: 
TEST

Pattern occurs at index: 10

*/
