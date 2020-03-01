/*
Relational operators for array
Performs the appropriate comparison operation between the array containers lhs and rhs.

The equality comparison (operator==) is performed by comparing the elements sequentially using operator==, stopping at the first mismatch (as if using algorithm equal).

The less-than comparison (operator<) behaves as if using algorithm lexicographical_compare, which compares the elements sequentially using operator< in a reciprocal manner (i.e., checking both a<b and b<a) and stopping at the first occurrence.



The other operations also use the operators == and < internally to compare the elements, behaving as if the following equivalent operations were performed:

 operation	  equivalent operation
 1. a!=b	     !(a==b)
 2. a>b	          b<a
 3. a<=b	     !(b<a)
 4. a>=b	     !(a<b)

These operators are overloaded in header <array>.
*/





// array comparisons
#include <iostream>
#include <array>

int main ()
{
  std::array<int,5> a = {10, 20, 30, 40, 50};
  std::array<int,5> b = {10, 20, 30, 40, 50};
  std::array<int,5> c = {50, 40, 30, 20, 10};

  if (a==b) std::cout << "a and b are equal\n";
  if (b!=c) std::cout << "b and c are not equal\n";
  if (b<c) std::cout << "b is less than c\n";
  if (c>b) std::cout << "c is greater than b\n";
  if (a<=b) std::cout << "a is less than or equal to b\n";
  if (a>=b) std::cout << "a is greater than or equal to b\n";

  return 0;
}





/*
Output:
a and b are equal
b and c are not equal
b is less than c
c is greater than b
a is less than or equal to b
a is greater than or equal to b
*/
