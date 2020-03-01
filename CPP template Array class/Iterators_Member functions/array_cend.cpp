/*
Returns a const_iterator pointing to the past-the-end element in the array container.

A const_iterator is an iterator that points to const content. This iterator can be increased and decreased (unless it is itself also const), just like the iterator returned by array::end, but it cannot be used to modify the contents it points to, even if the array object is not itself const.
*/


// array::cend example
#include <iostream>
#include <array>

int main ()
{
  std::array<int,5> myarray = { 15, 720, 801, 1002, 3502 };

  std::cout << "myarray contains:";
  for ( auto it = myarray.cbegin(); it != myarray.cend(); ++it )
    std::cout << ' ' << *it;   // cannot modify *it

  std::cout << '\n';

  return 0;
}



/*
Output:
myarray contains: 15 720 801 1002 3502
*/
