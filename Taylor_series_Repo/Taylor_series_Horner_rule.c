/*Description of Algorithm:-

Horner's rule for polynomial division is an algorithm used to simplify the process of evaluating a polynomial f(x) at a certain value x = x0 by dividing the polynomial into monomials (polynomials of the 1st degree). Each monomial involves a maximum of one multiplication and one addition processes. The result obtained from one monomial is added to the result obtained from the next monomial and so forth in an accumulative addition fashion. This division process is also known as synthetic division.

To explain the above, let is re-write the polynomial in its expanded form;

f(x0) = a0 + a1x0 + a2x02 + ... + anx0n
This can, also, be written as:

f(x0) = a0 + x0(a1 + x0(a2 + x0(a3 + ... + (an-1 + anx0)....)
The algorithm proposed by this rule is based on evaluating the monomials formed above starting from the one in the inner-most parenthesis and move out to evaluate the monomials in the outer parenthesis.

The algorithm is executed following the below steps:

1. Set k = n
2. Let bk = ak
3. Let bk - 1 = ak - 1 + bkx0
4. Let k = k - 1
5. If k ≥ 0 then go to step 3
Else End
*/
/*Example:-
This algorithm can, also, be graphically visualized by considering the 5th degree polynomial given by:

f(x) = a0 + a1x + a2x2 + a3x3 + a4x4 + a5x5
which can be evaluated at x = x0 by re-arranging it as:

f(x0) = a0 + x0(a1 + x0(a2 + x0(a3 + x0(a4 + a5x0))))*/

//=====*****=====*****=====*****======******//


/*Time-Complexity:O(n)*/


//****************************************//


#include<stdio.h>
double exponential(int x, int n)
{
    static double s; //declare static variable
    if(n == 0)   //Base case
    {
        return s;
    }
    s = 1 + x * (s / n); //formula of horner's rule
    return exponential(x, n-1); //recursive case
}
int main()
{
    int x, n;
    scanf("%d%d", &x, &n);
    printf("%lf \n", exponential(x, n)); //x^n
}
/*Input:-2 10
  Output:-
7.388713
*/
