/*
std::array::fill
      void fill (const value_type& val);

Fill array with value
Sets val as the value for all the elements in the array object.
*/





// array::fill example
#include <iostream>
#include <array>

int main () {
  std::array<int,6> myarray;

  myarray.fill(5);

  std::cout << "myarray contains:";
  for ( int& x : myarray) { std::cout << ' ' << x; }

  std::cout << '\n';

  return 0;
}



/*
Output:
myarray contains: 5 5 5 5 5 5
*/

