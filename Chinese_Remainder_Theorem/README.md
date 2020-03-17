# Chinese Remainder Theorem

**Problem Statement :** We are given two arrays num[0..n-1] and rem[0..n-1]. In num[0..n-1], every pair is coprime (gcd for every pair is 1). We need to find minimum positive number x such that:

          x % num[0]  =  rem[0],
          x % num[1]  =  rem[1],
          x % num[2]  =  rem[2],
          .......................
          x % num[n-1]  =  rem[n-1]

## Example

Consider the following given example for understanding *Chinese Remainder Theorem*.

        Input : num[] = {5, 7}, rem[] = {1, 3}
        output : x = 31

        Explanation: 31 is the smallest number such that:
        (1) When we divide it by 5, we get remainder 1.
        (2) When we divide it by 7, we get remainder 3.


## Solution

The solution is based on the below given formula :

        x =  sum of { (rem[i]* pp[i]* inv[i]) % prod } where 0 <= i <= n-1

        rem[i] is given array of remainders

        prod is product of all given numbers
        prod = num[0] * num[1] * ... * num[k-1]

        pp[i] is product of all divided by num[i]
        pp[i] = prod / num[i]

        inv[i] = Modular Multiplicative Inverse of pp[i] with respect to num[i]

Let us consider an example for a better understanding of *above given formula*.

        Input:  num[] = {3, 4, 5}, rem[] = {2, 3, 1}
        Output: x = 11

        Explanation: num[] = {3, 4, 5}, rem[] = {2, 3, 1}
        prod  = 60
        pp[]  = {20, 15, 12}
        inv[] = {2,  3,  3}  // (20*2)%3 = 1, (15*3)%4 = 1, // (12*3)%5 = 1

         x = (rem[0]* pp[0]* inv[0] + rem[1]* pp[1]* inv[1] + rem[2]* pp[2]* inv[2]) % prod
           = (2*20*2 + 3*15*3 + 1*12*3) % 60
           = (40 + 135 + 36) % 60
           = 11

## Pseudo Code           

The code is a simple 4-step process followed to find the solution :

        STEP 1 : Find the Product of all the numbers given in num[].
        STEP 2 : Find the number which is equal to Product divided by num[i] and store it in pp[i].
        STEP 3 : Find the Modular Multiplicative Inverse of pp[i] with respect to num[i] and store it
                 in inv[i].
        STEP 4 : Multiply rem[i] with the product of pp[i] and inv[i] for all 0 <= i <= n-1 and
                 add them. This is our required Output.


## Complexity

 Time complexity :

       O(n*log(max(a,b)) , where

       n is the total number of elements in the array.
       a is the maximum value in num[]
       b is the minimum value in rem[]


## Implementation

- [CoffeeScript code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Chinese_Remainder_Theorem/Chinese_Remainder_Theorem.coffee)

- [C++ Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Chinese_Remainder_Theorem/Chinese_Remainder_Theorem.cpp)

- [C# Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Chinese_Remainder_Theorem/Chinese_Remainder_Theorem.cs)

- [Java Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Chinese_Remainder_Theorem/Chinese_Remainder_Theorem.java)

- [JavaScript Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Chinese_Remainder_Theorem/Chinese_Remainder_Theorem.js)

- [Python Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Chinese_Remainder_Theorem/Chinese_Remainder_Theorem.py)
