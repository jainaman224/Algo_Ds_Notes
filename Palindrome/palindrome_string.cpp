/*
This program checks whether the enterd string is palindrome or not and generates output according to input provided.
*/

#include<iostream>
#include<string.h> // to use swap()
using namespace std;

void string_palindrome(string s)
{
    string reverse = s;
    int n = s.length();
    for(int i=0;i<n/2;i++)
    {
        swap(reverse[i], reverse[n-i-1]);
    }
    if(reverse == s)
    {
        cout << s <<" is Plindrome." << endl;
    }
    else
    {
        cout << s << " is not Palindrome." << endl;
    }
}
int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;
    string_palindrome(str);
    return 0;
}



/*
INPUT:
	Enter a string: abhnch

OUTPUT:
	abhnch is not Palindrome.
	
_______________________________________

INPUT:
	Enter a string: adbcbda

OUTPUT:
	adbcbda is Palindrome.
*/
