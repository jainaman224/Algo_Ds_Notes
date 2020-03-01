/*
Return const_iterator to beginning
Returns a const_iterator pointing to the first element in the array container.

A const_iterator is an iterator that points to const content. This iterator can be increased and decreased (unless it is itself also const), just like the iterator returned by array::begin, but it cannot be used to modify the contents it points to, even if the array object is not itself const.

*/



// array::cbegin example
#include <iostream>
#include <array>

int main ()
{
  std::array<int,5> myarray = { 2, 16, 77, 34, 50 };

  std::cout << "myarray contains:";

  for ( auto it = myarray.cbegin(); it != myarray.cend(); ++it )
    std::cout << ' ' << *it;   // cannot modify *it

  std::cout << '\n';

  return 0;
}



/*
Output:
myarray contains: 2 16 77 34 50
*/
