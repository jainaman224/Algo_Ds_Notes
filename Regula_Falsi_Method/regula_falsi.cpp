// Regula Falsi in C++
#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate f(x) where f(x) = x^3 - 2x - 5
double f(float x) {
    return (x * x * x - 2 * x - 5);
}

// Function to find root of f(x)
void regulaFalsi(float x1, float x2) {
    if (f(x1) * f(x2) >= 0) {
        cout << "You have assumed incorrect x1 and x2";
        return;
    }
    float x3 = x1;
    do {
        x3 = float(x1 - (x2 - x1) / (f(x2) - f(x1)) * f(x1));
        if (f(x3) * f(x1) < 0)
            x2 = x3;
        else
            x1 = x3;
    } while (abs(f(x3)) > 0.001);
    cout << "Value of root is " << x3;
}

int main() {
    float x1, x2;
    cout << "Enter x1 = ";
    cin >> x1;
    cout << "Enter x2 = ";
    cin >> x2;
    regulaFalsi(x1, x2);
    return 0;
}

// Output -
// Enter x1 = 2
// Enter x2 = 3
// Value of root is 2.09452
