#include <iostream>

using namespace std;

void search(string text, string pattern)
{
    int lengthText = text.length();
    int lengthPattern = pattern.length();

    for(int i = 0; i <= lengthText - lengthPattern; i++)
    {
        for(int j = 0; j < lengthPattern; j++)
            if(text[i + j] != pattern[j])
                break;

        if(j == lengthPattern)
           cout << "Pattern found at " << i + 1 << endl;
    }
}

int main()
{
    cout << "Enter text" << endl;
    cin >> text;
    cout << "Enter pattern" << endl;
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
