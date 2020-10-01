/*ASCII SUBSEQUENCES PROBLEM

This problem is same as the "Subsequences" question just instead of two function calls, three function calls will be made :

- One with the same string.
- One with a letter added.
- One with the ascii code of the letter added to the string.

- For example:-
Take as input str, a string. We are concerned with all the possible ascii-subsequences of str. E.g. “ab” has following ascii-subsequences “”, “b”, “98”, “a”, “ab”, “a98”, “97”, “97b”, “9798”

a. Write a recursive function which returns the count of ascii-subsequences for a given string. Print the value returned.

b. Write a recursive function which prints all possible ascii-subsequences for a given string (void is the return type for function).
*/
//*********************//
/*Time Complexity: 
O(3^N) where N = String Length.*/
//*******************//

#include<iostream>
#include<string>
#include<cmath>
using namespace std;

string str;

void subseq(string s, int i)
{
    if( ! str[i])
    {
        cout << s << " ";
        return;
    }
    // The 3 function calls in the same order as explained above.
    subseq(s, i + 1);
    subseq(s + str[i], i + 1);
    subseq(s + to_string((int)str[i]), i + 1); // str[i] is type casted to integer which gives the ASCII value which is then converted to string for concatenation.
}
    
int main()
{
    cin >> str;
    cout << pow(3, str.size()) << "\n";
    subseq("", 0);
    return 0;
}

/*Sample Input:
ab
Sample Output:
 b 98 a ab a98 97 97b 9798 
9
*/
