# Suffix Array

Suffix array is a useful data structure which stores suffix of a string in alphabetical order. (https://en.wikipedia.org/wiki/Suffix_array)

For example:
```
raw = abaab
Suffix: abaab, baab, aab, ab, b
Sorted suffix: aab, ab, abaab, b, baab
```
Null character is considered less than any other character.

Suffix array of raw:
```
[2, 3, 0, 4, 1]
```

because suffix starting from position 2(`aab`) is the smallest, then comes suffix starting from position 3(`ab`), ..., and suffix starting from position 1 (`baab`) is the largest.

## Doubling algorithm

This algorithm builds suffix array in `O(nlogn)` time complexity and `O(CHAR_MAX + n)` space complexity, based on sorting segments with length 1, 2, 4, 8, ..., until all segments are different, which is called "doubling algorithm".

(Paper: http://www.cas.mcmaster.ca/~bill/best/algorithms/07Taxonomy.pdf)

### Example

Still take `abaab` as an example:

(Visualized version: https://web.stanford.edu/~mjkay/NewSuffixArrays.pdf)

#### Iteration 1

We sort all segments with length 1 in 'raw'(i.e. a b a a b), and relabel the original string.

```
x = 01001  // 'a' => 0, 'b' => 1. two different segments. Still have repeated segments, continue iteration.
sa = 02314  // because letter 'a' appears at 0, 2, 3, then letter 'b' at 1, 4
```

Here, `x[i]` stands for the order of `raw[i]`.

#### Iteration 2 [Step = 1]

We sort all segments with length 2 in `raw`(i.e. `01 10 00 01 1$` in `old_x`, since each element in `old_x` represents exact one character in `raw`), and relabel it

```
x = 13012  // '00' => 0, 01 => 1, 1$ => 2, 10 => 3. 4 different segments. still have repeated segments, continue iteration.
sa = 20341  // 00 at position 2, 01 at position 0 and 3, 1$ at position 4, 10 at position 1
```

Here, `x[i]` stands for the order of `raw[i...i+1]`

#### Iteration 3 [Step = 2]

We sort all segments with length 4 in `x`(i.e. `10 31 02 1$ 2$` in `old_x`, since each element in `old_x` represents 2 characters in `raw`. If we want `x[i]` stands for `raw[i...i+3]`, then we need to let the concatenation of `old_x[i]`(which stands for `raw[i...i+1]`) and `old_x[i+2]` (which stands for `raw[i+2...i+3]`) become the key of length-4 segment)

```
/----------------new_x[0]-----------------\
/-----old_x[0]------\/-----old_x[2]---------\
.........................................................
|raw[0]  |   raw[1]  |   raw[2]  |   raw[3]  |   raw[4] |
.........................................................

x = 24013  // 02 => 0, 1$ => 1, 10 => 2, 2$ => 3, 31 => 4. All different, done!
sa = 23041  // 02 at position 2, 1$ at position 3, 10 at position 0, 2$ at position 4, 31 at position 1
```

Here, `x[i]` stands for the order of `raw[i...i+3]` of all length-4 substrings of `raw`.

### How to sort key pairs

In each iteration, we need sort key pairs `(x[i], x[i + step])`  `(0 <= i < n)`. The naive method is to use quicksort, thus we need to use `O(nlogn)` for each iteration, and `O(nlognlogn)` for the whole algorithm.

A better way is to look into the range of `x[i]/raw[i]`: the maximum is bounded by both the length of `raw` (`n`) [since our goal is to make each elements of `x` different] and the character set size `CHAR_MAX` [for `raw[i]`]. Therefore, we can use bucket sort.

For 2-keyword bucket sort, the basic idea is(just like radix sort):
1. Sort elements based on the 2nd keyword
2. Sort elements based on the 1st keyword (must be stable)

#### Stable bucket sort
How can we perform a stable bucket sort?

```
// Assume origin is [1, 2, 2, 0, 0]
for (int item : origin)
  bucket[item]++;
// bucket: [2, 1, 2]
for (size_t i=1; i<bucket_size; ++i)
  bucket[i] += bucket[i-1];
// bucket: [2, 3, 5]
for  (int i = origin.size() - 1; i >= 0; --i)
  result[ --bucket[ origin[i] ] ] = i
// result: [3, 4, 0, 1, 2]
```

#### Sort array by 2nd keyword, using existing array of previous iteration

So how can we get the 2nd keyword? Remember that the 2nd keyword for position `i` is `x[i+step]` (if i + step < N) or `$` (if i + step >= N).

Take a look at the result of the 2nd iteration:
```
x   =   13012
```
and the key pairs to sort of the 3rd iteration:
```
  10 31 02 1$ 2$,
```
2nd keyword:
```
  0  1  2  $  $
```

But the sorted array by the 2nd keyword is already there!
Sa of iteration 2:
```
sa  =   23041
new_sa == { N - step, N - step + 1, ..., N - 1, sa[origin1] - step, sa[origin2] - step, ... }
```
The smallest `step` elements must be the last `step` elements, because the second keyword of them is always `$`.
Sort result of 2nd keyword in iteration 3:
```
new_sa= 3 4 0 1 2.
```

Explanation:
Step = 2, thus 3 4 are the smallest elements. position 0, 1 are impossible for a second keyword:
ignore them from sa, the remaining items in sa (2 3 4) is the order of 2nd keywords of position (0 1 2)
