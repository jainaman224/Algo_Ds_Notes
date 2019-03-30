/*
    LONGEST PALINDROMIC SUBSTRING

    The task is to find the longest substring of a given string that is palindromic.
    A palindromic string is a string which is same when read from front or back.

    eg. radar is same when read frontwards or backwards.

*/
#include <bits/stdc++.h>
using namespace std;
#define lint long long int
/*
    The idea is to iterate over all the characters of the string and checking in 
    every iteration, the longest palindrome that can be made by setting the current 
    character as a center of both odd length and even length palindromes.
    The counter for max length palindrome is maintained.
*/
string longest_palindromic_substr(string str){
    string ans = "";    // To store the answer.
    if(str.length() == 1){
        return str; // When length of string is 1, it is itself the longest palindromic substring.
    }
    lint max_length = 0;    // Stores the max length of palindrome found.
    for(int i = 1; i < str.length(); i++){
        lint len_ans = 0;
        string temp_ans = "";       
        /* When we check for odd-length palindromes, the current character is at definite 
        center of the palindrome. Thus, length is already 1, as a single character is 
        a palindrome in itself. We iterate two pointers, both on either side of the current
        character until a different character is found at both the pointers or an end is reached
        on either side. */
        temp_ans += str[i];
        len_ans = 1;
        for(int j = i-1, k = i+1; j >= 0 && k < str.length() && str[j] == str[k]; j--, k++){
            len_ans += 2;
            temp_ans = temp_ans + str[k];
            temp_ans = str[j] + temp_ans;
        }
        if (len_ans > max_length) {
            max_length = len_ans;
            ans = temp_ans;
        }
        temp_ans = "";
        len_ans = 0;
        /* For odd length palindromes, we have two centers. So, we keep two pointers, one
        on the current character and the other on the character left to it and check for 
        their similarity. The left pointer will move left and the other one right in each
        iteration.
        */
        for(int j = i-1, k = i; j >= 0 && k < str.length() && str[j] == str[k]; j--, k++){
            len_ans += 2;
            temp_ans = temp_ans + str[k];
            temp_ans = str[j] + temp_ans;
        }
        if (len_ans > max_length) {
            max_length = len_ans;
            ans = temp_ans;
        }
    }
    return ans;
}

int main()
{
    string str = "algorithmhtirrithm";
    string ans = longest_palindromic_substr(str);
    cout<<"The longest palindromic substring is: "<<ans;
}
/*
    Input : str = "algorithmhtirrithm"
    Output: The longest palindromic substring is: mhtirrithm
    Verification : algorith[mhtirrithm] this is a substring with length 10 and also a palindrome.
*/
