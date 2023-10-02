// This Code is used to find factorial.

#include <iostream>

/// @brief give the factorial of a number
/// @param val that number
/// @return Ty
[[nodiscard]] constexpr auto factorial(std::size_t val) -> std::size_t {
    if (val <= 1) {
        return 1;
    }
    return val * factorial(val - 1);
}

int main() { std::cout << factorial(5) << '\n'; }

/*ENTER THE NUMBER
5
Answer is : 120*/
