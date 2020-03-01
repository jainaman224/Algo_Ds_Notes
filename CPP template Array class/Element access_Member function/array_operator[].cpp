/*
std::array::operator[]

Access element
Returns a reference to the element at position n in the array container.

A similar member function, array::at, has the same behavior as this operator function, except that array::at checks the array bounds and signals whether n is out of range by throwing an exception.
*/





// array::operator[]
#include <iostream>
#include <array>

int main ()
{
  std::array<int,10> myarray;
  unsigned int i;

  // assign some values:
  for (i=0; i<10; i++) myarray[i]=i;

  // print content
  std::cout << "myarray contains:";
  for (i=0; i<10; i++)
    std::cout << ' ' << myarray[i];
  std::cout << '\n';

  return 0;
}


/*
Output:
myarray contains: 0 1 2 3 4 5 6 7 8 9
*/

