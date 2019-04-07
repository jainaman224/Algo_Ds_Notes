'''
    LONGEST PALINDROMIC SUBSTRING

    The task is to find the longest substring of a given string that is palindromic.
    A palindromic string is a string which is same when read from front or back.

    eg. radar is same when read frontwards or backwards.

'''
import math
'''
    The idea is to iterate over all the characters of the string and checking in 
    every iteration, the longest palindrome that can be made by setting the current 
    character as a center of both odd length and even length palindromes.
    The counter for max length palindrome is maintained.
'''
def longest_palindromic_substr(st):
    ans = "";    # To store the answer.
    if(len(st) == 1):
        return st; # When length of string is 1, it is itself the longest palindromic substring.
    max_length = 0;    # Stores the max length of palindrome found.
    for i in range(1,len(st)):
        len_ans = 0;
        temp_ans = "";       
        ''' When we check for odd-length palindromes, the current character is at definite 
        center of the palindrome. Thus, length is already 1, as a single character is 
        a palindrome in itself. We iterate two pointers, both on either side of the current
        character until a different character is found at both the pointers or an end is reached
        on either side. '''
        temp_ans = temp_ans + st[i];
        len_ans = 1;
        j = i-1
        k = i+1
        while(j >= 0 and k < len(st) and st[j] == st[k]):
            len_ans = len_ans + 2
            temp_ans = temp_ans + st[k]
            temp_ans = st[j] + temp_ans
            j = j-1
            k = k+1
        if (len_ans > max_length):
            max_length = len_ans;
            ans = temp_ans;
        temp_ans = "";
        len_ans = 0;
        ''' For odd length palindromes, we have two centers. So, we keep two pointers, one
        on the current character and the other on the character left to it and check for 
        their similarity. The left pointer will move left and the other one right in each
        iteration.
        '''
        j = i-1
        k = i
        while(j >= 0 and k < len(st) and st[j] == st[k]):
            len_ans = len_ans+2
            temp_ans = temp_ans + st[k]
            temp_ans = st[j] + temp_ans
            j = j-1
            k = k+1
        if (len_ans > max_length):
            max_length = len_ans;
            ans = temp_ans;
    return ans;


st = "algorithmhtirrithm";
ans = longest_palindromic_substr(st);
print("The longest palindromic substring is:",ans)

'''
    Input : st = "algorithmhtirrithm"
    Output: The longest palindromic substring is: mhtirrithm
    Verification : algorith[mhtirrithm] this is a substring with length 10 and also a palindrome.
'''
