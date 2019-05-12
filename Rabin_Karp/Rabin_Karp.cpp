// Rabin Karp Algorithm
/*
AN : range or No of alphabets
val : AN ^ patlen-1
patlen : pattern length
PN: any prime no given input from main
*/

/* Time-Complexity:-
The average case running time of the Rabin-Karp algorithm = O(n+m).
The best case running time of the Rabin-Karp algorithm = O(n+m).
The worst-case running time of the Rabin-Karp algorithm = O(nm).
*/

#include<iostream>
#include<cstring>
#define AN 256    // no. of character in alphabet
using namespace std;

void search(char *pattern, char *text, int PN)
{
    int patlen = strlen(pattern);   // pattern length
    int txtlen = strlen(text);      // text length
    int val = 1;
    int hpat = 0;      // pattern hash value
    int htxt = 0;      // text hash value
    int i, j;
    for (i = 0; i < patlen - 1; i++)
         val = (val * AN) % PN;       // PN is a prime number
    for (i = 0; i < patlen; i++)
    {
         hpat = (AN * hpat + pattern[i]) % PN;
         htxt = (AN * htxt + text[i]) % PN;
    }
    for (i = 0; i <= txtlen - patlen; i++)
    {
         if ( hpat == htxt )
         {
            // Check for patterns
             for (j = 0; j < patlen; j++)
             {
                 if (text[i + j] != pattern[j])
                 {
                    break;
                 }
            }
            if (j == patlen)
            {
                cout << "Found at index starting from " << i << endl;
            }
        }
        // Calculate the new pattern including i+m
        htxt = (AN * (htxt - val * text[i]) + text[i + patlen]) % PN;
        if (htxt < 0)
        {
            htxt = htxt + PN;
        }
    }
}

int main() {
    char *text = "XWINGO XOR WINGO";
    char *pattern = "WINGO";
    int PN = 101;  // A prime number
    search(pattern, text, PN);
    return 0;
}

/* Input:-XWINGO XOR WINGO
         WINGO
         101
 OUTPUT:-Found at index starting from 1
         Found at index starting from 11
*/
