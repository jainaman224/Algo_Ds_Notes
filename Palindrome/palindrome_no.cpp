/*
This program checks whether the entered number is palindrome or not and
generates output according to input provided.
*/

#include <iostream>
#include <string>


auto is_palindrome(const std::string &x) -> bool {
  return (x == std::string(x.rbegin(), x.rend()));
}

constexpr auto is_palindrome(int x) noexcept -> bool {
  if (x < 0) {
    return false;
  }
  if (!x) {
    return true;
  }
  long res{};
  const int org{x};
  while (x) {
    res = res * 10 + (x % 10);
    x /= 10;
  }
  return res == org;
}

auto main() -> int {
  std::cout << is_palindrome(12456);
  std::cout << is_palindrome("121");
}
/*
  INPUT:
        n=12456
  OUTPUT:
        Entered no. is not palindrome.

  INPUT:
        n=12821
  OUTPUT:
        Entered no. is palindrome.
*/
