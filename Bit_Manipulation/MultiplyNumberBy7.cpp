#include <iostream>
using namespace std;

int multiply(int n){
    return n*(1<<3)-n;
}

int main() {
    int n;
    cout << "Enter the number to be multiplied by 7: ";
    cin >> n;
    cout << multiply(n) << endl;
    return 0;
}
