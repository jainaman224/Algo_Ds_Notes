#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// Function to print nth fibonacci number
constexpr auto FibonacciNumber(const int n) -> size_t {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    //
    const double sqrt_5 = std::sqrt(5);
    return static_cast<size_t>(
        (std::pow(1 + sqrt_5, n) - std::pow(1 - sqrt_5, n)) /
        ((std::pow(2, n)) * sqrt_5));
}

// Function to print fibonacci series
auto FibonacciSeries(int n) {
    std::vector<int> ret;
    // 1 1 2 3 5 8 13 22
    for (int i{n}; i >= 0; --i) {
        std::cout << FibonacciNumber(i) << " ";
    }
}

int main() {
    int num;
    cin >> num;
    cout << "The fibonacci number at position " << num << " is "
         << FibonacciNumber(num);
    cout << "\nFibonacci series:\n";
    FibonacciSeries(num);
}

/*
Input :
6
Output :
The fibonacci number at position 6 is 8
Fibonacci series:
1 1 2 3 5 8
*/
