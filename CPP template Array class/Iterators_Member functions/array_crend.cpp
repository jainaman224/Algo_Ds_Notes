/*
Return const_reverse_iterator to reverse end
Returns a const_reverse_iterator pointing to the theoretical element preceding the first element in the vector, which is considered its reverse end.

A const_reverse_iterator is an iterator that points to const content and iterates in reverse order. This iterator can be increased and decreased (unless it is itself also const), just like the iterator returned by array::rend, but it cannot be used to modify the contents it points to.
*/




// array::crbegin/crend
#include <iostream>
#include <array>

int main ()
{
  std::array<int,6> myarray = {10, 20, 30, 40, 50, 60} ;

  std::cout << "myarray backwards:";
  for ( auto rit=myarray.crbegin() ; rit < myarray.crend(); ++rit )
    std::cout << ' ' << *rit;   // cannot modify *rit

  std::cout << '\n';

  return 0;
}



/*
Output:
myarray backwards: 60 50 40 30 20 10
*/
