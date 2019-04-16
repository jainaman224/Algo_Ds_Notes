#include <iostream>

using namespace std;

void search(string text, string pattern)
{
    int lengthText = text.length();
    int lengthPattern = pattern.length();

    for(int i = 0; i <= lengthText - lengthPattern; i++)
    {
        int j;

        for(j = 0; j < lengthPattern; j++)
            if(text[i + j] != pattern[j])
                break;

        if(j == lengthPattern)
           cout << "Pattern found at " << i + 1 << endl;
    }
}

int main()
{
   string text = "namanchamanbomanamansanam";
   string pattern = "aman";
   search(text, pattern);
   return 0;
}

/* Output

Pattern found at 2
Pattern found at 8
Pattern found at 17

*/
