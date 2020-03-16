"""ASCII SUBSEQUENCES PROBLEM
This problem is same as the "Subsequences" question just instead of two function calls, three function calls will be made :
- One with the same string.
- One with a letter added.
- One with the ASCII code of the letter added to the string."""

def subseq(s, i, string1):
    if (i == len(string1)):
        print(s)
        return
    #The 3 function calls in the same order as explained above.
    # First function call
    subseq(s, i + 1, string1) 
    # Second function call
    subseq(s + string1[i], i + 1, string1) 
    #Third function call in which ord(string1[i]) gives the ASCII value which is then converted to string for concatenation
    subseq(s + str(ord(string1[i])),i + 1, string1)  
        
string1 = input("Enter the string")
print("Number of Subsequences :", pow(3, len(string1)))
subseq("", 0, string1)
 
"""Sample Input: Enter the string
ab
Sample Output:
Number of Subsequences : 9

b
98
a
ab
a98
97
97b
9798
"""
