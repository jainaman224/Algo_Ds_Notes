/*
Return iterator to end
Returns an iterator pointing to the past-the-end element in the array container.

The past-the-end element is the theoretical element that would follow the last element in the array. It does not point to any element, and thus shall not be dereferenced.

Because the ranges used by functions of the standard library do not include the element pointed by their closing iterator, this function is often used in combination with array::begin to specify a range including all the elements in the container.

In zero-sized arrays, this function returns the same as array::begin.
*/


// array::end example
#include <iostream>
#include <array>

int main ()
{
  std::array<int,5> myarray = { 5, 19, 77, 34, 99 };

  std::cout << "myarray contains:";
  for ( auto it = myarray.begin(); it != myarray.end(); ++it )
    std::cout << ' ' << *it;

  std::cout << '\n';

  return 0;
}


/*
Output:
myarray contains: 5 19 77 34 99
*/
