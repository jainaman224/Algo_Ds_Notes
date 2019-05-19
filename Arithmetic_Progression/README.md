# Arithmetic Progression (A.P)

Arithmetic Progression(AP) is very important topic in Mathematics which can be used in programming to solve many problems.

_An arithmetic progression or arithmetic sequence is a sequence of numbers such that the difference between the consecutive terms is constant. Difference here means the second term minus the first term.In simple terms, it means that the next number in the series is calculated by adding a fixed number to the previous number in the series._

For instance, the sequence _1,4,7,10,13,16....._ is an arithmetic progression with _common difference_ of _3_.

( 16-13 = 13-10 = 10-7 = 7-4 = 4-1 = 3 )

![Illustration: Arithmetic Progression](<https://cdncontribute.geeksforgeeks.org/wp-content/uploads/4-min-1.png>)

***Illustration of Arithmetic Progression. [Image Courtesy: GeeksforGeeks]***

### Terms related to Arithmetic Progression

**Initial Term**:  The first term of the A.P is called the initial term. It is denoted by **a<sub>n</sub>**.
**Common Difference**: The value by which the consecutive terms increase or decrease is called the common difference.  It is denoted by **d**.

NOTE: The behavior of the arithmetic progression depends on the common difference **d**. If the common difference is: 
* positive, then the members (terms) will grow towards positive infinity.
* negative, then the members (terms) will grow towards negative infinity.

## Formula of n<sup>th</sup> term of the A.P

If **a** is the initial term and **d** is the common difference.Then, the explicit formula for the n<sup>th</sup> term of the A.P   is **a<sub>n</sub> = a + (n-1)d**

## Formula of the sum of n<sup>th</sup> term of A.P

If **a** is the initial term and **d** is the common difference.Then, the explicit formula for the sum of **n** terms of the A.P is **S<sub>n</sub> = n/2 [2a + (n-1)d]**

## Properties of Arithmetic Progressions

**Increasing/Decreasing Sequence:**

- If the common difference is positive, i.e. *d>0*  then the arithmetic progression is an *increasing* sequence and satisfies the condition *a<sub>n-1</sub> > a<sub>n</sub>* :  *a<sub>1</sub> < a<sub>2</sub> < a<sub>3</sub> < ...* 
 For example, the arithmetic progression with initial term *2* and common difference *3* i.e. *2,5,8,11,14,....,*  is an increasing sequence.
- If the common difference is negative, i.e.  *d<0* then the arithmetic progression is a *decreasing* sequence and satisfies the condition *a<sub>n-1</sub> > a<sub>n</sub>* : *a<sub>1</sub> > a<sub>2</sub> > a<sub>3</sub> > ...*
 As an example, the arithmetic progression with initial term *1* and common difference *-3*  i.e.*1,-2,-5,-11,...,*  is a decreasing sequence.

**Other properties:**

- If *a,b,c* are in AP, then *2b = a + c*. 
- If each term of an AP is increased, decreased, multiplied, or divided by a constant non-zero number, then the resulting sequence is also in AP.
- If the *n<sup>th</sup>* term of any sequence is of the form *an + b* , then the sequence is in AP where the common difference is a.

## Implementation

- [C Code](<https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Arithmetic_Progression/Arithmetic_Progression.c>)

> 🚀 [Compile Online](https://repl.it/@gauravburjwal/Arithmetic-Progression-in-C) 🚀

- [C++ Code](<https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Arithmetic_Progression/Arithmetic_Progression.cpp>)

> 🚀 [Compile Online](https://repl.it/@gauravburjwal/Arithmetic-Progression-in-Cpp) 🚀

- [Java Code](<https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Arithmetic_Progression/Arithmetic_Progression.java>)

> 🚀 [Compile Online](https://repl.it/@gauravburjwal/Arithmetic-Progression-in-Java) 🚀

- [Python Code](<https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Arithmetic_Progression/Arithmetic_Progression.py>)

> 🚀 [Compile Online](https://repl.it/@gauravburjwal/Arithmetic-Progression-in-Python) 🚀

* [Go Code](<https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Arithmetic_Progression/Arithmetic_Progression.go>)

> 🚀 [Compile Online](https://repl.it/@gauravburjwal/Arithmetic-Progression-in-Go) 🚀
