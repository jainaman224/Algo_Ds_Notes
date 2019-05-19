#include <iostream>

using namespace std;

void search(string text, string pattern)
{
    int lengthText = text.length();
    int lengthPattern = pattern.length();
    int j;

    for(int i = 0; i <= lengthText - lengthPattern; i++)
    {
        for(j = 0; j < lengthPattern; j++)
            if(text[i + j] != pattern[j])
                break;

        if(j == lengthPattern)
           cout << "Pattern found at " << i + 1 << endl;
    }
}

int main()
{
    string text, pattern;
    cout << "Enter text" << endl;
    cin >> text;
    cout << "Enter pattern" << endl;
    cin >> pattern;
    search(text, pattern);
    return 0;
}

/* 
Input:
text = "namanchamanbomanamansanam"
pattern = "aman"

Output:
Pattern found at 2
Pattern found at 8
Pattern found at 17
*/
