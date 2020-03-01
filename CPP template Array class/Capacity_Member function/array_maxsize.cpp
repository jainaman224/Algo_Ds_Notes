/*
std::array::max_size
Return maximum size
Returns the maximum number of elements that the array container can hold.

The max_size of an array object, just like its size, is always equal to the second template parameter used to instantiate the array template class.
*/



// array::max_size
#include <iostream>
#include <array>

int main ()
{
  std::array<int,10> myints;
  std::cout << "size of myints: " << myints.size() << '\n';
  std::cout << "max_size of myints: " << myints.max_size() << '\n';

  return 0;
}


/*
Output:
size of myints: 10
max_size of myints: 10
size and max_size of an array object always match.
*/
