#include <stdio.h>
#include <string.h>

void Rabin_Karp (char *text, char *pattern)
{
    int text_len = strlen (text);
    int pattern_len = strlen (pattern);
    int hash = 1;
    
    for (int i = 0; i < pattern_len - 1; i++)
    {
        hash = (hash * 256) % 149;
        // there are 256 total characters in Ascii table & 149 is a prime number chosen randomly
    }
    int hash_txt = 0, hash_pat = 0;
    
    for (int i = 0; i < pattern_len; i++)
    {
        hash_txt = (hash_txt * 256 + text [i]) % 149; // hash value for text
        hash_pat = (hash_pat * 256 + pattern [i]) % 149; // hash value for pattern
    }
    
    for(int i = 0; i < = text_len - pattern_len; i++)
    {
        int j;
        
        if (hash_txt == hash_pat) 
        {
            // checking if all the chars are equal in text portion & pattern
            for (j = 0; j < pattern_len; j++)
            {
                if (text [i+j] != pattern [j])
                    break;
            }
            if (j == pattern_len)
            {
                printf ("\n\nPattern searched is found at position %d\n\n", i+1);
            }
        }
        // finding the pattern in remaining portion of the text
        if (i < text_len-pattern_len)
        {
            hash_txt = ((hash_txt - text [i] * hash) * 256 + text [i + pattern_len]) % 149;
            if (hash_txt < 0)
            {
                hash_txt = hash_txt + 149;
            }        
        }    
    }
}

int main()
{
    char text [30];
    char pattern [15];
    printf ("Enter Text:\n");
    scanf ("%s", text);
    printf ("Enter Pattern to be searched:\n");
    scanf ("%s", pattern);
    Rabin_Karp (text, pattern);
    return 0;
}

/* Input/Output Demo:
Enter Text:
bbaavcaavaavifjkdfkfaav
Enter Pattern to be searched:
aav
Pattern searched is found at position 3
Pattern searched is found at position 7
Pattern searched is found at position 10
Pattern searched is found at position 21 */
