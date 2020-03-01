/*
Return reverse iterator to reverse beginning
Returns a reverse iterator pointing to the last element in the array container.

rbegin points to the element right before the one that would be pointed to by member end.

Notice that unlike member array::back, which returns a reference to this same element, this function returns a reverse random access iterator.
*/




// array::rbegin/rend
#include <iostream>
#include <array>

int main ()
{
  std::array<int,4> myarray = {4, 26, 80, 14} ;

  std::cout << "myarray contains:";
  for ( auto rit=myarray.rbegin() ; rit < myarray.rend(); ++rit )
    std::cout << ' ' << *rit;

  std::cout << '\n';

  return 0;
}




/*
Output:
myarray contains: 14 80 26 4
Notice how the reverse iterator iterates through the vector in a reverse way by increasing the iterator.

*/
