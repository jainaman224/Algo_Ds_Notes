/*
DIGIT COUNT OF A NUMBER

The task is to count the number of digits present in the given
number.
*/

#include <iostream>

constexpr int getDigits(int n) {
    int ans{};
    while (n) {
        ++ans;
        n /= 10;
    }
    return ans;
}

int main() {
    std::cout << "Enter N: ";
    int n{};
    std::cin >> n;
    std::cout << "Number of digits is : " << getDigits(n);
}

/*
INPUT : n = 6534
OUTPUT: Number of digits is : 4
*/
