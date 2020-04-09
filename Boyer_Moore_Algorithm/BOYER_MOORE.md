# BOYER-MOORE ALGORITHM

1. It was developed by Robert S. Boyer and J Strother Moore in 1977.
2. Boyer-Moore Algorithm is the most efficient string matching algorithm in usual application such as in text editors and commands substitutions.
3. In this procedure, the substring or pattern is searched from the last character of the pattern.
4. The B-M algorithm takes a 'backward' approach: the pattern string (P) is aligned with the start of the text string (T), and then compares the characters of a pattern from right to left, beginning with rightmost character.


**Components of Boyer-moore algorithm**

+ A preprocessing table is created as suffix table.


## Two strategies 

The two strategies are called heuristics of B - M as they are used to reduce the search. They are:

1. **Bad Character Heuristics occurrence shift:**
This Heuristics has two implications:

+ Suppose there is a character in a text in which does not occur in a pattern at all. When a mismatch happens at this character (called as bad character), the whole pattern can be changed, begin matching form substring next to this 'bad character.
+ On the other hand, it might be that a bad character is present in the pattern, in this case, align the nature of the pattern with a bad character in the text.

2. **Good Suffix Heuristics or matching shift:**
A good suffix is a suffix that has matched successfully. After a mismatch which has a negative shift in bad character heuristics, look if a substring of pattern matched till bad character has a good suffix in it, if it is so then we have an onward jump equal to the length of suffix found.

### Algorithm of Boyer-moore


searchPattern(text, pattern)

**Input:** The main text and the pattern, that will be searched
**Output:** The indexes where the pattern is found

```
Begin

   patLen := pattern length
   
   strLen := text size

   for all entries of shiftArray, do 
   
      set all entries to 0
      
   done
    
   call fullSuffixMatch(shiftArray, borderArray, pattern)
   
   call partialSuffixMatch(shiftArray, borderArray, pattern)
   
   shift := 0

   while shift <= (strLen - patLen), do 
   
      j := patLen -1 
      
      while j >= 0 and pattern[j] = text[shift + j], do
      
         decrease j by 1
         
      done

      if j < 0, then 
      
         print the shift as, there is a match
         
         shift := shift + shiftArray[0]
         
      else
      
         shift := shift + shiftArray[j+1]
         
       done
   
End
```

 

#### Time Complexity

1.Searching phase in O ( mn ) time complexity.
2.3n text character comparisons in the worst case.
3.O(n / m) best performance.

##### See Also

1. https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_string-search_algorithm
2. https://www.geeksforgeeks.org/boyer-moore-algorithm-for-pattern-searching/
3. https://www.tutorialspoint.com/Boyer-Moore-Algorithm
 

 

