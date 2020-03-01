/*
std::array::size
Return size
Returns the number of elements in the array container.

The size of an array object is always equal to the second template parameter used to instantiate the array template class (N).

Unlike the language operator sizeof, which returns the size in bytes, this member function returns the size of the array in terms of number of elements.
*/


// array::size
#include <iostream>
#include <array>

int main ()
{
  std::array<int,5> myints;
  std::cout << "size of myints: " << myints.size() << std::endl;
  std::cout << "sizeof(myints): " << sizeof(myints) << std::endl;

  return 0;
}



/*
Possible output:
size of myints: 5
sizeof(myints): 20
*/
