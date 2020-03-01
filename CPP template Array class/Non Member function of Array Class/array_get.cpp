/*
std::get (array)
template <size_t I, class T, size_t N> T& get (array<T,N>& arr) noexcept;
template <size_t I, class T, size_t N> T&& get (array<T,N>&& arr) noexcept;
template <size_t I, class T, size_t N> const T& get (const array<T,N>& arr) noexcept;
Get element (tuple interface)
Returns a reference to the Ith element of array arr.

This overload of tuple's homonym function get is provided so that array objects can be treated as tuples. For that purpose, header <array> also overloads tuple_size and tuple_element types with the appropriate members defined.
*/




// arrays as tuples
#include <iostream>
#include <array>
#include <tuple>

int main ()
{
  std::array<int,3> myarray = {10, 20, 30};
  std::tuple<int,int,int> mytuple (10, 20, 30);

  std::tuple_element<0,decltype(myarray)>::type myelement;  // int myelement

  myelement = std::get<2>(myarray);
  std::get<2>(myarray) = std::get<0>(myarray);
  std::get<0>(myarray) = myelement;

  std::cout << "first element in myarray: " << std::get<0>(myarray) << "\n";
  std::cout << "first element in mytuple: " << std::get<0>(mytuple) << "\n";

  return 0;
}



/*
Output:
first element in myarray: 30
first element in mytuple: 10
*/


