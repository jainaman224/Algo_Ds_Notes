/*
std::array::front

Access first element
Returns a reference to the first element in the array container.

Unlike member array::begin, which returns an iterator to this same element, this function returns a direct reference.

Calling this function on an empty container causes undefined behavior.
*/



// array::front
#include <iostream>
#include <array>

int main ()
{
  std::array<int,3> myarray = {2, 16, 77};

  std::cout << "front is: " << myarray.front() << std::endl;   // 2
  std::cout << "back is: " << myarray.back() << std::endl;     // 77

  myarray.front() = 100;

  std::cout << "myarray now contains:";
  for ( int& x : myarray ) std::cout << ' ' << x;

  std::cout << '\n';

  return 0;
}




/*
Output:
front is: 2
back is: 77
myarray now contains: 100 16 77
*/
