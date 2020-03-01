/*
std::array::at

Access element
Returns a reference to the element at position n in the array.

The function automatically checks whether n is within the bounds of valid elements in the container, throwing an out_of_range exception if it is not (i.e., if n is greater than, or equal to, its size). This is in contrast with member operator[], that does not check against bounds.
*/



// array::at
#include <iostream>
#include <array>

int main ()
{
  std::array<int,10> myarray;

  // assign some values:
  for (int i=0; i<10; i++) myarray.at(i) = i+1;

  // print content:
  std::cout << "myarray contains:";
  for (int i=0; i<10; i++)
    std::cout << ' ' << myarray.at(i);
  std::cout << '\n';

  return 0;
}



/*
Output:
myarray contains: 1 2 3 4 5 6 7 8 9 10
*/




