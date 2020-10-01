# Taylor Series Using Horner's Rule

Horner's rule for polynomial division is an algorithm used to simplify the process of evaluating a polynomial f(x) at a certain value x = x0 by dividing the polynomial into monomials (polynomials of the 1st degree). Each monomial involves a maximum of one multiplication and one addition processes. The result obtained from one monomial is added to the result obtained from the next monomial and so forth in an accumulative addition fashion. This division process is also known as synthetic division.
To explain the above, let is re-write the polynomial in its expanded form;
f(x0) = a0 + a1x0 + a2x02 + ... + anx0n
This can, also, be written as:
f(x0) = a0 + x0(a1 + x0(a2 + x0(a3 + ... + (an-1 + anx0)....)
The algorithm proposed by this rule is based on evaluating the monomials formed above starting from the one in the inner-most parenthesis and move out to evaluate the monomials in the outer parenthesis.

## Algorithm

The algorithm is executed following the below steps:
1.Creating a exponential function
2.Declare static variable s
3.Take base case:-if(num==0)then return s
4.Else creating a formula of expansion using Horner's method like s=1+x*(s/num)
5.return recursive case

## Time Complexity

- O(n)

## Illustration for above algorithim

![GIF](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQ75s7IAgoTnSpbsACLb-dolOUtJZ7MaykTtIsYuNIZgir6joYZ)

## Implementation

- [C Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Taylor_series_Repo/Taylor_series_Horner_rule.c)