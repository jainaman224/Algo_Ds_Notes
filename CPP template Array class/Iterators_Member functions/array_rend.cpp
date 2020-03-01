/*
Return reverse iterator to reverse end
Returns a reverse iterator pointing to the theoretical element preceding the first element in the array (which is considered its reverse end).

The range between array::rbegin and array::rend contains all the elements of the array (in reverse order).
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
14 80 26 4
Notice how the reverse iterator iterates through the array in a reverse way by increasing the iterator.
*/
