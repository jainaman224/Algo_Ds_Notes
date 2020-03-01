/*
std::array::data

Get pointer to data
Returns a pointer to the first element in the array object.

Because elements in the array are stored in contiguous storage locations, the pointer retrieved can be offset to access any element in the array.
*/




// array::data
#include <iostream>
#include <cstring>
#include <array>

int main ()
{
  const char* cstr = "Test string";
  std::array<char,12> charray;

  std::memcpy (charray.data(),cstr,12);

  std::cout << charray.data() << '\n';

  return 0;
}



/*
Output:
Test string
*/
