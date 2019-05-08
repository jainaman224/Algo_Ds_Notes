# ASCII SUBSEQUENCES PROBLEM

This problem is same as the "Subsequences" question just instead of two function calls, three function calls will be made :

- One with the same string.
- One with a letter added.
- One with the ascii code of the letter added to the string.

- For example:-
Take as input str, a string. We are concerned with all the possible ascii-subsequences of str. E.g. “ab” has following ascii-subsequences “”, “b”, “98”, “a”, “ab”, “a98”, “97”, “97b”, “9798”

a. Write a recursive function which returns the count of ascii-subsequences for a given string. Print the value returned.

b. Write a recursive function which prints all possible ascii-subsequences for a given string (void is the return type for function).

### Input Format:
   Enter the string

### Constraints:
   None

### Output Format:
  Display the number of ASCII-subsequences and display all the ASCII- subsequences

### Sample Input:
ab

### Sample Output:
 b 98 a ab a98 97 97b 9798 
9

### Time Limit:
4 sec

### Time Complexity: 
O(3^N) where N = String Length.
