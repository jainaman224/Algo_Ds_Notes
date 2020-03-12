# Rabin Karp Algorithm
The problem is to find a pattern P in a given string S. 
The Rabin-Karp string matching algorithm calculates a hash value for the pattern, as well as for each M-character subsequences of text to be compared. If the hash values are unequal, the algorithm will determine the hash value for next M-character sequence. If the hash values are equal, the algorithm will analyze the pattern and the M-character sequence. In this way, there is only one comparison per text subsequence, and character matching is only required when the hash values match.

## Algorithm

### Input:
Text T, pattern P, d and q are chosen depending on the text and pattern.

### Output:
Index at which the pattern occurs.

### Pseudocode:
```
RABIN-KARP-MATCHER (T, P, d, q)
 n ← length [T]
 m  ← length [P]
 h  ←  dm-1 mod q
 p ←  0
 t0 ←  0
 for i ← 1 to m
     do p ←  (dp + P[i]) mod q
         t0 ← (dt0+T [i]) mod q
 for s  ←  0 to n-m
     do if p = ts
         then if P [1.....m] = T [s+1.....s + m]
             then "Pattern occurs with shift" s
         If s < n-m
             then ts+1 ←  (d (ts-T [s+1]h)+T [s+m+1])mod q
 ```

## Example
![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/Pattern-Searching-2-1.png)

## Time Complexity
The running time of RABIN-KARP-MATCHER in the worst case scenario O((n-m+1) m but it has a good average case running time. If the expected number of strong shifts is small O (1) and prime q is chosen to be quite large, then the Rabin-Karp algorithm can be expected to run in time O (n+m) plus the time to require to process spurious hits.

## Implementation
- [C++ Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Rabin_Karp/Rabin_Karp.cpp)
> :rocket: [Compile Online](https://repl.it/repls/UntrueMediumLoop) :rocket:

- [JAVA Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Rabin_karp/Rabin_karp.java)
> :rocket: [Compile Online](https://repl.it/repls/AccomplishedLightpinkMapping) :rocket:

## References
* [GeeksforGeeks](https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/)
* Introduction to Algorithms 3rd Edition by Clifford Stein, Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest.
