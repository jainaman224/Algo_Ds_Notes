# Knuth-Morris Pratt Algorithm

1. It was invented by Donald Knuth and Vaughan Pratt.
2. It was the first linear time complexity algorithm for string matching which is used to find a pattern in a text.
3. This algorithm compares character by character from left to right.

## Components of Knuth-Morris Pratt algorithm

Prefix Table : In this algorithm whenever a mismatch occurs,it uses a preprocessed table known as Prefix Table to skip characters comparison while matching.

LPS Table : It stands for Longest proper Prefix which is also suffix. Sometimes prefix table is also known as LPS Table.

## Steps for Creating LPS Table

1. Define a one dimensional array with the size equal to the length of the Pattern. (LPS[size])
2. Define variables i & j. Set i = 0, j = 1 and LPS[0] = 0.
3. Compare the characters at Pattern[i] and Pattern[j].
4. If both are matched then set LPS[j] = i + 1 and increment both i & j values by one. Go to Step 3.
5. If both are not matched then check the value of variable 'i'. If it is '0' then set LPS[j] = 0 and increment 'j' value by one, if it is not '0' then set i = LPS[i - 1].  Step 3.
6. Repeat above steps until all the values of LPS[] are filled. 

## ALGORITHM

**Input** the main text, and the pattern, which will be searched.

```
Begin
   n := size of text
   m := size of pattern
   
   call findPrefix(pattern, m, prefArray)
   while i < n, do
      if text[i] = pattern[j], then
         increase i and j by 1
         
      if j = m, then
         print the location (i-j) as there is the pattern
         j := prefArray[j-1]
      else if i < n AND pattern[j] ≠ text[i] then
         if j ≠ 0 then
            j := prefArray[j - 1]
         else
            increase i by 1
   done
   End
```

**Output**: The location where patterns are found.

##  How The Knuth-Morris Pratt Algorithm Work?

Let us see an example

Consider the following Text and Pattern

Text : ABC ABCDAB ABCDABCDABDE

Pattern : ABCDABD

LPS[] table for the above pattern is as follows

LPS[] is {0,1,2,3,4,5,6}

**Step 1:** Start comparing first character of pattern with first character of Text from left to right

Text: ABC ABCDAB ABCDABCDABDE

Pattern: ABCDABD

0123456

Here mismatch occurred at Pattern[3],so we need to consider LPS[2] value. Since LPS[2] value is '0' we must compare first character in pattern with next character in Text.

**Step 2:** Start comparing first character of pattern with next character of Text.

Text : ABC ABCDAB ABCDABCDABDE

Pattern : ABCDABD

0123456

Here mismatch occurred at Pattern[6], so we need to consider LPS[5] value. Since LPS[5] value is '2' we compare Pattern[2] character with mismatched character in Text.

**Step 3:** Since LPS value is '2' no need to compare the Pattern[0] and Pattern[1] values

Text : ABC ABCDAB ABCDABCDABDE

Pattern : ABCDABD

0123456

Here mismatch occurred at pattern[2],so we need to consider LPS[1] value. Since LPS[1] value is  '0' we must compare first character in Pattern with next character in Text. 

**Step 4** Compare Pattern[0] with next character in Text

Text : ABC ABCDAB ABCDABCDABDE

Pattern : ABCDABD

0123456

Here mismatch occurred at Pattern[6], so we need to consider LPS[5] value. Since LPS[5] value is '2' we compare Pattern[2] character with mismatched character in Text.

**Step 5:** Compare Pattern[2] with mismatched character in Text.

Text : ABC ABCDAB ABCDABCDABDE

Pattern : ABCDABD

0123456

Here all the characters of Patterns matched with a substring in Text which is starting from index value 15.

So, we conclude that given Pattern found at index 15 in Text.

**TIME COMPLEXITY**

The time complexity of Knuth-Morris Pratt Algorithm is O(n).

**SPACE COMPLEXITY**

It also has a space complexity of O (m) because there’s some pre-processing involved.

**SEE ALSO**

1. https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Knuth_Morris_Pratt_Algorithm/KMP.cpp
2. https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Knuth_Morris_Pratt_Algorithm/KMP.java
3. https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Knuth_Morris_Pratt_Algorithm/KMP.py
4. https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Knuth_Morris_Pratt_Algorithm/KMP.cs

**REFERENCES**

1. https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
2. [https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm](https://en.wikipedia.org/wiki/Knuth–Morris–Pratt_algorithm)