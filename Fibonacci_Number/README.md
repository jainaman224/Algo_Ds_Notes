# Fibonacci Sequence

> The Fibonacci Sequence turns out to be the key to understanding how nature designs and is a part of the same ubiquitous music of the spheres that builds harmony into atoms, molecules, crystals, shells, suns and galaxies and makes the Universe sing.
<br>*~Guy Murchie, The Seven Mysteries of Life: An Exploration of Science and Philosophy*

## Introduction

The Fibonacci sequence is a set of numbers that starts with a one or a zero, followed by a one, and then proceeds based on the rule that each successive number (called a Fibonacci number) is equal to the sum of the two preceding numbers.

In mathematical terms, the Fibonacci numbers, commonly denoted by F<sub>n</sub>, form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1.

It is one of the most famous formulas in mathematics defined by the linear recurrence equation

```
F(n) = F(n - 1) + F(n - 2)
```

So, the Fibonacci Sequence becomes
```
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
```
and so on!

## Algorithm
```
Step 1: START
Step 2: Let variables a, b, fib, n, i
Step 3: Initialize variables
          a ← 1,
          b ← 1,
          i ← 2
Step 4: Read n from user
Step 5: Print a and b
Step 6: Repeat until i < n
           fib ← a + b
           print fib
           a ← b, b ← fib
           i ← i + 1
Stop 7: STOP
```

## Pseudocode

```
START

READ n from USER

IF n is less than 1
   DISPLAY 0

IF n is equal to 1
   DISPLAY 1

IF n is equal to 2
   DISPLAY 1, 1

IF n is greater than 2
   a = 1,
   b = 1,

   DISPLAY a, b
   REPEAT FOR 0 to n
      Fib = a + b
      DISPLAY Fib
      a = b
      b = Fib
   END FOR
END IF

END
```

## Examples

```
Input (N): 2
Output: 1
Reason: F(2) = F(1) + F(0) = 1 + 0 = 1.

```

```
Input (N): 3
Output: 2
Reason: F(3) = F(2) + F(1) = 1 + 1 = 2.

```

```
Input (N): 4
Output: 3
Reason: F(4) = F(3) + F(2) = 2 + 1 = 3.

```

```
One More Example...

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...

The next number is the result of addition up the two immediate previous numbers.
- 2 is the result of  (1 + 1),
- 3 is the result of (1 + 2),
- And 5 is (2 + 3), and so on!

In other words, each new number in the series is addition of previous two numbers.
Hence the next number in the sequence above will be 21 + 34 = 55

```

## Complexity Analysis

### Approach 1: Recursion

**Algorithm**

- First of all, check if the input value N is less than or equal to 1. If the condition satisfies to True, return N.

- Otherwise, the function F(int n) calls itself, with the result of the 2 previous numbers being added to each other, passed in as the argument. This is derived directly from the Recurrence Relation:
```
F(n) = F(n - 1) + F(n - 2)
```
- Repeat this until all numbers have been calculated, then return the resulting answer.

**Time Complexity: O(2<sup>N</sup>)**

This is probably the slowest way to solve the Fibonacci Sequence Problem since it takes exponential time. The amount of operations needed, for each level of recursion, grows exponentially as the depth approaches N.

### Approach 2: Bottom-Up Approach Using Memorization

**Algorithm**

- Check if N is less than or equal to 1; If so, return N
- Otherwise, iterate through N, storing each computed answer in an array along the way.
- Use this array as a reference to the 2 previous numbers to calculate the current Fibonacci number.
- Once we reach the last number, return it's Fibonacci number.

**Time complexity : O(N)**

Each number, starting at 2, up to and including N, is traversed, computed and then stored for O(1) access later on.

### Approach 3: Iterative Approach

**Algorithm**

- If N is equal to 0, return 0
- Set a ← 0, b ← 1
- DISPLAY a,
- REPEAT until N
  - Compute the sum of a and b & store the sum in Fib {Fib ← a + b}
  - a ← b
  - b ← Fib
  - DISPLAY Fib
- End Loop
- END

**Time complexity: O(N)**

Each value from 2 to N will be visited at least once. The time it takes to do this is directly proportionate to N where N is the Fibonacci Number we are looking to compute.

### Concluding Thoughts

The Iteration method would be the prefer and faster approach to solving our problem because we are storing the first two of our Fibonacci numbers in two variables (n - 1, n - 2) and using "Fib" to store our Fibonacci number. Storing these values prevent us from constantly using memory space in the Stack. Thus giving us a time complexity of O(N).

## Fibonacci Sequence And Golden Ratio

Golden Ratio is a number that’s equal to approximately 1.618. This number is now often known as **phi** and is expressed in writing using the symbol for the letter phi from the Greek alphabet.

The Fibonacci sequence is related to the golden ratio, a proportion (roughly 1:1.6) that occurs frequently throughout the natural world and is applied across many areas of human endeavors.

Both the Fibonacci sequence and the golden ratio are used to guide design for architecture, websites and user interfaces, among other things.
