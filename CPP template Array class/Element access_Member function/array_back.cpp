/*
std::array::back

Access last element
Returns a reference to the last element in the array container.

Unlike member array::end, which returns an iterator just past this element, this function returns a direct reference.

Calling this function on an empty container causes undefined behavior.
*/







// array::back
#include <iostream>
#include <array>

int main ()
{
  std::array<int,3> myarray = {5, 19, 77};

  std::cout << "front is: " << myarray.front() << std::endl;   // 5
  std::cout << "back is: " << myarray.back() << std::endl;     // 77

  myarray.back() = 50;

  std::cout << "myarray now contains:";
  for ( int& x : myarray ) std::cout << ' ' << x;
  std::cout << '\n';

  return 0;
}





/*
Output:
front is: 5
back is: 77
myarray now contains: 5 19 50
*/
