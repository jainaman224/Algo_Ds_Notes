//Subsequence of a String using bitmasking
#include<iostream>
#include<string>
using namespace std;
void subsequence_bitmasking(string s)
{
    //Calculate length of string
    int len = s.length();

    //Number of subsequence are always 1>>length
    int no_of_subseq = 1 << len;
    for (int i = 0 ; i < no_of_subseq ; i++)
    {
        int m = 0;
        string ans = "";
        int j = i;
        while (j)
        {
            if (j & 1)
            {
                ans += s[m];
            }
            m++;
            j = j >> 1;
        }
        cout << ans << " ";
    }
}
int main()
{
    string str;
    cout << "Enter string" << endl;
    cin >> str;
    subsequence_bitmasking(str);
    cout << endl;
    return 0;
}

/*
Sample Input

Enter string
abc

Sample Output

 a b ab c ac bc abc
*/
