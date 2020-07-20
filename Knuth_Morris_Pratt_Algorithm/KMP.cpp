#include <iostream>

using namespace std;

void calculateLps(string pattern, int lps[])
{
    int length = 0;  // Length of the previous longest prefix suffix
    unsigned int i;

    lps[0] = 0;
    i = 1;

    // The loop calculates lps[i] for i = 1 to size - 1
    while(i < pattern.size())
    {
        if(pattern[i] == pattern[length])
        {
            length++;
            lps[i] = length;
            i++;
        }
        else // If (pattern[i] != pattern[len])
        {
            if(length != 0)
                length = lps[length - 1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(string pattern, string text)
{
    int sizePattern = pattern.size();
    int sizeText = text.size();

    int *lps = new int[sizePattern];
    int j  = 0;

    calculateLps(pattern, lps);

    int i = 0;

    while(i < sizeText)
    {
        if (pattern[j] == text[i])
        {
            j++;
            i++;
        }

        if(j == sizePattern)
        {
            cout << "Pattern found at " <<  i - j  << endl;
            j = lps[j - 1];
        }
        else if (i < sizeText && pattern[j] != text[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }

    delete[] lps;
}

int main()
{
    string text = "namanchamanbomanamansanam";
    string pattern = "aman";
    KMPSearch(pattern, text);
    return 0;
}

/* Output

Pattern found at 1
Pattern found at 7
Pattern found at 16

*/
