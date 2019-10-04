# Longest Common SubString

## DP based approach
The normal DP approach is of ``O(m*n)`` Space Complexity. But we can keep only two consequitive rows i.e., ``O(2*n)``.

A variable ``end``: ending point of the longest common substring in string String1.<br />
variable ``maxlength``: the length of the longest common substring.

Suppose we are at DP state when the length of String1 is i and length of String2 is j, the result of which is stored in ``currentRow[i][j]``.

Now if ``string1[i-1] == string2[j-1]``: <br />
    &nbsp;&nbsp;&nbsp;&nbsp;then ``currentRow[i][j] = 1 + currentRow[i-1][j-1]``
  
Result of current row in matrix ``currentRow[][]`` depends on values from previous row. Hence the required length of longest common substring can be obtained by maintaining values of two consecutive rows only.

The longest common substring then is from index ``end – maxlength + 1`` to index ``end`` in string1.
### Time Complexity: ``O(m*n)``
### Space Complexity:   ``O(n)``
