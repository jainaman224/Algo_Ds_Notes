/*
Return iterator to beginning
Returns an iterator pointing to the first element in the array container.

Notice that, unlike member array::front, which returns a reference to the first element, this function returns a random access iterator pointing to it.

In zero-sized arrays, this function returns the same as array::end, but the returned iterator should not be dereferenced.
*/

// array::begin example
#include <iostream>
#include <array>

int main ()
{
  std::array<int,5> myarray = { 2, 16, 77, 34, 50 };

  std::cout << "myarray contains:";
  for ( auto it = myarray.begin(); it != myarray.end(); ++it )
  std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}


/*
Output:
myarray contains: 2 16 77 34 50
*/
