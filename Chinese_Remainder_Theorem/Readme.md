# Chinese Remainder Theorem

If m<sub>1</sub>, m<sub>2</sub>, .., m<sub>k</sub> are pairwise relatively prime positive integers, and if a<sub>1</sub>, a<sub>2</sub>, .., a<sub>k</sub> are any integers, then the simultaneous congruences x ≡ a<sub>1</sub> (mod m<sub>1</sub>), x ≡ a<sub>2</sub> (mod m<sub>2</sub>), ..., x ≡ a<sub>k</sub> (mod m<sub>k</sub>) have a solution, and the solution is unique modulo m, where m = m<sub>1</sub>m<sub>2</sub>⋅⋅⋅m<sub>k</sub> .

**Problem Statement :** 

We are given two arrays num[0..n-1] and rem[0..n-1]. In num[0..n-1], every pair is coprime (gcd for every pair is 1). We need to find minimum positive number x such that:

          x % num[0]  =  rem[0],
          x % num[1]  =  rem[1],
          x % num[2]  =  rem[2],
          .......................
          x % num[n-1]  =  rem[n-1]
          
## Algorithm

The solution is based on the below given formula :

        x =  sum of { (rem[i]* pp[i]* inv[i]) % prod } where 0 <= i <= n-1

        where,
        
        rem[i] is given array of remainders

        prod is product of all given numbers
        prod = num[0] * num[1] * ... * num[k-1]

        pp[i] is product of all divided by num[i]
        pp[i] = prod / num[i]

        inv[i] = Modular Multiplicative Inverse of pp[i] with respect to num[i] 


## Example

![Pic01](https://i.pinimg.com/474x/f4/62/23/f46223a470eb8f967b3be60f8a255c6e--chinese-remainder-theorem-the-chinese.jpg)

Consider the above given example for understanding **Chinese Remainder Theorem**.

        Input : num[] = {3, 5, 7}, rem[] = {1, 2, 3}
        output : x = 52

        Explanation: 52 is the smallest number such that:
        (1) When we divide it by 3, we get remainder 1.
        (2) When we divide it by 5, we get remainder 2
        (3) When we divide it by 7, we get remainder 3.


Let us consider an example for a better understanding of **above given formula**.

        Input:  num[] = {3, 5, 7}, rem[] = {1, 2, 3}
        Output: x = 52

        Explanation: num[] = {3, 5, 7}, rem[] = {1, 2, 3}
        prod  = 3*5*7 = 105
        pp[]  = {35, 21, 15}
        inv[] = {2,  1,  1}  // (35*2)%3 = 1, (21*1)%5 = 1, // (15*1)%7 = 1

         x = (rem[0]* pp[0]* inv[0] + rem[1]* pp[1]* inv[1] + rem[2]* pp[2]* inv[2]) % prod
           = (1*35*2 + 2*21*1 + 3*15*1) % 105
           = (70 + 42 + 45) % 105
           = 52

## Pseudo Code           

The code is a simple 4-step process followed to find the solution :

        STEP 1 : Find the Product of all the numbers given in num[].
        STEP 2 : Find the number which is equal to Product divided by num[i] and store it in pp[i].
        STEP 3 : Find the Modular Multiplicative Inverse of pp[i] with respect to num[i] and store it
                 in inv[i].
        STEP 4 : Multiply rem[i] with the product of pp[i] and inv[i] for all 0 <= i <= n-1 and
                 add them. This is our required Output.


## Complexity

 Time complexity : __O(n*log(max(a,b))__ , where

* __n__ is the total number of elements in the array. 
* __a__ is the maximum value in __num[ ]__ 
* __b__ is the minimum value in __rem[ ]__


## Implementation

- [C Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Chinese_Remainder_Theorem/Chinese_remainder_theorem.c)

- [CoffeeScript code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Chinese_Remainder_Theorem/Chinese_Remainder_Theorem.coffee)

- [C++ Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Chinese_Remainder_Theorem/Chinese_Remainder_Theorem.cpp)

- [C# Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Chinese_Remainder_Theorem/Chinese_Remainder_Theorem.cs)

- [Dart Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Chinese_Remainder_Theorem/Chinese_Remainder_Theorem.dart)

- [Go Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Chinese_Remainder_Theorem/Chinese_Remainder_Theorem.go)

- [Java Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Chinese_Remainder_Theorem/Chinese_Remainder_Theorem.java)

- [JavaScript Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Chinese_Remainder_Theorem/Chinese_Remainder_Theorem.js)

- [PHP Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Chinese_Remainder_Theorem/Chinese_Remainder_Theorem.php)

- [Python Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Chinese_Remainder_Theorem/Chinese_Remainder_Theorem.py)

### Refer this [link](https://www.youtube.com/watch?v=ru7mWZJlRQg) to know more!

## References

Image source: [https://www.storyofmathematics.com/chinese.html](https://www.storyofmathematics.com/chinese.html)    

#### Websites: 
1. [http://homepages.math.uic.edu/~leon/mcs425-s08/handouts/chinese_remainder.pdf](http://homepages.math.uic.edu/~leon/mcs425-s08/handouts/chinese_remainder.pdf)   
2. [https://www.geeksforgeeks.org/chinese-remainder-theorem-set-2-implementation/](https://www.geeksforgeeks.org/chinese-remainder-theorem-set-2-implementation/)
3. [https://medium.com/free-code-camp/how-to-implement-the-chinese-remainder-theorem-in-java-db88a3f1ffe0](https://medium.com/free-code-camp/how-to-implement-the-chinese-remainder-theorem-in-java-db88a3f1ffe0)
