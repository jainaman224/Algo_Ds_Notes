# Z ALGORITHM
This algorithm finds all occurrences of a pattern in a text in linear time. Let length of text be n and of pattern be m, then total time taken is O(m + n) with linear space complexity. Now we can see that both time and space complexity is same as KMP algorithm but this algorithm is Simpler to understand.
Z algorithm is a linear time string matching algorithm which runs in  complexity. It is used to find all occurrence of a pattern  in a string , which is common string searching problem.
In this algorithm, we construct a Z array.

### What is Z Array?
For a string str[0..n-1], Z array is of same length as string. An element Z[i] of Z array stores length of the longest substring starting from str[i] which is also a prefix of str[0..n-1]. The first entry of Z array is meaning less as complete string is always prefix of itself.

```
Example:

Index            0   1   2   3   4   5   6   7   8   9  10  11 
Text             a   a   b   c   a   a   b   x   a   a   a   z
Z values         X   1   0   0   3   1   0   0   2   2   1   0

str  = "aaaaaa"
Z[]  = {x, 5, 4, 3, 2, 1}

str = "aabaacd"
Z[] = {x, 1, 0, 2, 1, 0, 0}

str = "abababab"
Z[] = {x, 0, 6, 0, 4, 0, 2, 0}
```

### How is Z array helpful in Searching Pattern in Linear time?
The idea is to concatenate pattern and text, and create a string “P$T” where P is pattern, $ is a special character should not be present in pattern and text, and T is text. Build the Z array for concatenated string. In Z array, if Z value at any point is equal to pattern length, then pattern is present at that point.
```
Example:
Pattern P = "aab",  Text T = "baabaa"
The concatenated string is = "aab$baabaa"
Z array for above concatenated string is {x, 1, 0, 0, 0, 
                                          3, 1, 0, 2, 1}.
Since length of pattern is 3, the value 3 in Z array 
indicates presence of pattern. 
```

### How to construct Z array?
A Simple Solution is two run two nested loops, the outer loop goes to every index and the inner loop finds length of the longest prefix that matches substring starting at current index. 

## ALGORITHM
![algo](https://github.com/syedareehaquasar/reeha/blob/master/1.PNG)

## Pseudocode
Simple and short. Note that the optimization L = R = i is used when S[0] ≠ S[i] (it doesn't affect the algorithm since at the next iteration i > R regardless).

```
int L = 0, R = 0;
for (int i = 1; i < n; i++) {
    if (i > R) {
        L = R = i;
        while (R < n && s[R-L] == s[R]){
            R++;
            z[i] = R-L;
            R--;
        }
    }
    else {
    int k = i-L;
    if (z[k] < R-i+1) {
        z[i] = z[k];
        }
    else {
      L = i;
      while (R < n && s[R-L] == s[R]){
      R++;
      z[i] = R-L; R--;
    }
  }
}
```
## Example:
S = “abc”, T = “abcdabaabc”
L = “abc$abcdabaabc”
Compute Z values.
Z[1] = 0, Z[2] = 0, Z[3] = 0, Z[4] = 3, Z[5] = 0, Z[6] = 0, Z[7] = 0, Z[8] = 2, Z[9] = 0, Z[10] = 1, Z[11] = 3, Z[12] = 0, Z[13] = 0
Look at values of Z[4] and Z[11]
hence string S matches at index 4 (abc$abcdabaabc) and index 11 (abc$abcdabaabc)

## Time Complexity
O(n)
The algorithm runs in O(n) time. Characters are never compared at positions less than , and every time a match is found,  is increased by one, so there are at most n comparisons

## Implementation
 - [c code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Z_Algorithm/Z_Algorithm.c)
 - [coffee code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Z_Algorithm/Z_Algorithm.coffee)
 - [cpp code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Z_Algorithm/Z_Algorithm.cpp)
 - [c# code]
 - [go code]
 - [java code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Z_Algorithm/Z_Algorithm.java)
 - [javaScript code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Z_Algorithm/Z_Algorithm.js)
 - [kotlin code]
 - [python code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Z_Algorithm/Z_Algorithm.py)
 - [ruby code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Z_Algorithm/Z_Algorithm.rb)
 - [dart code]
