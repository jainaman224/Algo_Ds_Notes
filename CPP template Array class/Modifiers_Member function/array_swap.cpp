/*
std::array::swap

Swap content
Exchanges the content of the array by the content of x, which is another array object of the same type (including the same size).

After the call to this member function, the elements in this container are those which were in x before the call, and the elements of x are those which were in this.

Unlike with the swap member functions of the other containers, this member function operates in linear time by performing as many individual swap operations between the individual elements as their size (see swap).
*/




// swap arrays
#include <iostream>
#include <array>

int main ()
{
  std::array<int,5> first = {10, 20, 30, 40, 50};
  std::array<int,5> second = {11, 22, 33, 44, 55};

  first.swap (second);

  std::cout << "first:";
  for (int& x : first) std::cout << ' ' << x;
  std::cout << '\n';

  std::cout << "second:";
  for (int& x : second) std::cout << ' ' << x;
  std::cout << '\n';

  return 0;
}




/*
Output:
first: 11 22 33 44 55
second: 10 20 30 40 50
*/


