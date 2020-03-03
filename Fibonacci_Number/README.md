# Fibonacci Sequence

> The Fibonacci Sequence turns out to be the key to understanding how nature designs and is a part of the same ubiquitous music of the spheres that builds harmony into atoms, molecules, crystals, shells, suns and galaxies and makes the Universe sing.
<br>*~Guy Murchie, The Seven Mysteries of Life: An Exploration of Science and Philosophy*

<img src="https://cdn.britannica.com/95/130895-050-F4DEFE46/numbers-diagonal-Fibonacci-sequence-triangle-Pascal.jpg" width=270 height=300>

<img src="https://media0.giphy.com/media/IdkQbKfSg1Gi4/giphy.gif">

## Introduction

The Fibonacci sequence is a set of numbers that starts with a one or a zero, followed by a one, and then proceeds based on the rule that each successive number (called a Fibonacci number) is equal to the sum of the two preceding numbers.

In mathematical terms, the Fibonacci numbers, commonly denoted by F<sub>n</sub>, form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1.

It is one of the most famous formulas in mathematics defined by the linear recurrence equation

```
F(n) = F(n - 1) + F(n - 2)
```

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
           a ← b,
           b ← fib
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

IF n is greater than or equal to 2
   a = 1,
   b = 1,

   DISPLAY a, b
   REPEAT LOOP from 2 to n
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

Explanation: As per the algorithm, we know that F(0) returns 0, and F(1) is equal to 1.

Hence, the addition of F(1) & F(0) will evaluate to F(2).
```

```
Input (N): 3
Output: 2
Reason: F(3) = F(2) + F(1) = 1 + 1 = 2.

Explanation: From the above patch, we evaluated F(2) as 1 and we already know F(1) = 1.

Therefore, F(3) will evaluate to 1 + 1 = 2

```

```
Input (N): 4
Output: 3
Reason: F(4) = F(3) + F(2) = 2 + 1 = 3.

Explanation: From above, it is clear that F(3) & F(2) evaluate to 2 and 1 respectively.

Hence, their sum will be equal to the value of F(4), that is 3.
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

## Different Approaches To Solve Fibonacci Sequence

### Approach 1: Recursion

**Algorithm**

- First of all, check if the input value N is less than or equal to 1. If the condition satisfies to True, return N.

- Otherwise, the function F(int n) calls itself, with the result of the 2 previous numbers being added to each other, passed in as the argument. This is derived directly from the Recurrence Relation:
```
F(n) = F(n - 1) + F(n - 2)
```
- Repeat this until all numbers have been calculated, then return the resulting answer.

<img src="https://i.stack.imgur.com/QVSdv.png">

### Approach 2: Bottom-Up Approach Using Memorization

**Algorithm**

- Check if N is less than or equal to 1; If so, return N
- Otherwise, iterate through N, storing each computed answer in an array along the way.
- Use this array as a reference to the 2 previous numbers to calculate the current Fibonacci number.
- Once we reach the last number, return it's Fibonacci number.

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

## Complexity Analysis

**Approach 1: Recursion**
- Time Complexity: O(2<sup>N</sup>)

**Approach 2: Bottom-Up Approach Using Memorization**
- Time complexity : O(N)

**Approach 3: Iterative Approach**
- Time complexity: O(N)

### Concluding Results

The Iteration method would be the prefer and faster approach to solving our problem because we are storing the first two of our Fibonacci numbers in two variables (n - 1, n - 2) and using "Fib" to store our Fibonacci number. Storing these values prevent us from constantly using memory space in the Stack. Thus giving us a time complexity of O(N).

## Fibonacci Sequence And Golden Ratio

Golden Ratio is a number that’s equal to approximately 1.618. This number is now often known as **phi** and is expressed in writing using the symbol for the letter phi from the Greek alphabet.

The Fibonacci sequence is related to the golden ratio, a proportion (roughly 1:1.6) that occurs frequently throughout the natural world and is applied across many areas of human endeavors.

Both the Fibonacci sequence and the golden ratio are used to guide design for architecture, websites and user interfaces, among other things.

<img src="https://miro.medium.com/max/694/1*CyFEy7GFPwxysCDaX_jm-Q.png" width=300>

<img src="https://www.quickanddirtytips.com/sites/default/files/images/1649/golden-ratio-shell.png" width=300>

**There is a special relationship between Golden Ratio and Fibonacci Numbers**

When we take any two successive Fibonacci Numbers, their ratio is very close to the Golden Ratio.

| A  | B | Ratio (B / A) |
| :-------------: | :-------------: | :-------------: |
| 2  | 3  | 1.5  |
| 3  | 5  | 1.666666666...  |
| 5  | 8  | 1.6  |
| 8  | 13  | 1.625  |
| 13  | 21  | 1.615384615...  |
| ...  | ...  | ...  |
| 144  | 233  | 1.618055556...  |
| 233  | 377  | 1.618025751...  |
| ...  | ...  | ...  |

## Magic Of Fibonacci Numbers

Let us look at the final digit in each Fibonacci number - the units digit:

**0**, **1**, **1**, **2**, **3**, **5**, **8**, 1**3**, 2**1**, 3**4**, 5**5**, 8**9**, 14**4**, 23**3**, 37**7**, 61**0**, 98**7**, ...

There is a pattern in the final digits
```
0, 1, 1, 2, 3, 5, 8, 3, 1, 4, 5, 9, 4, 3, 7, 0, 7, ...
```
Yes! It takes a while before it is noticeable.

In fact, the series is just 60 numbers long and then it repeats the same sequence again and again all the way through the Fibonacci series - for ever. Hence, we can say that the series of final digits repeats with a cycle length of 60.

Similar analysis can be done for last digits as well.

## Amazing Facts About Fibonacci Sequence And Nature

- In music, a scale dominant note is the 5th note of major scale which is also the 8th note of all 13 notes that comprise octave. This provides an added instance of Fibonacci numbers in key musical relationship. Interestingly, 8/13 is .61538 which approximates Phi.

- Fibonacci sequences appear in biological setting in two consecutive Fibonacci numbers, such as branching of trees, arrangement of leaves on stem, the fruitlets of pineapple ,the flowering of artichoke & arrangement of pine cone & family tree of honeybees.

<img src="https://i.ya-webdesign.com/images/fibonacci-drawing-rose-3.png" width=400>

<img src="https://i.pinimg.com/originals/ea/f1/73/eaf1738ff446ea088a4c7bf84a4b88fe.jpg" width=290>

- A one dimensional optimization technique method called the **Fibonacci Search** techniques uses Fibonacci Numbers.

- The Fibonacci numbers are also an example of a complete sequence.

  + This means that every positive integer can be written as a sum of Fibonacci numbers, where any one number is used once at most. Specifically, every positive integer can be written in a unique way as the sum of one or more distinct Fibonacci numbers in such a way that the sum does not include any two consecutive Fibonacci numbers.

- With the exceptions of 1, 8 and 144, every Fibonacci number has a prime factor that is not a factor of any smaller Fibonacci number.

- No Fibonacci number greater than 8 is one greater or one less than any prime number.

- Any three consecutive Fibonacci numbers, taken two at a time, are relatively prime.

---

The Pineapple scales are roughly hexagonal in shape. And because of this 3 distinct Fibonacci numbers 5,8 and 13 scales can be observed.

<img src="https://i.ya-webdesign.com/images/fibonacci-drawing-pineapple.png">

---

The pattern and the way in which the seeds are packed on the flower heads seem to always follow a Fibonacci pattern. The reason is because this arrangement form an optimal packaging, so that no matter how large the head, the seeds are almost always uniformly spaced. This is usually seen in Sunflowers.

<img src="https://i.pinimg.com/originals/2a/78/90/2a7890cbfb13ef42578155f79de55665.gif">

## Conclusion

### Fibonacci Sequence At A Glance

<img src="https://encrypted-tbn0.gstatic.com/images?q=tbn%3AANd9GcRtKMuS-fG5QYquaDo9Zk-wpLb7azf_dRiyTWABxegy9HH2KAPQ">