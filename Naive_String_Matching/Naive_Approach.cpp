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
           cout << "Pattern found at " << i << endl;
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

Pattern found at 1
Pattern found at 7
Pattern found at 16

*/
