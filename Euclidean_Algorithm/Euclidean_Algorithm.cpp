#include <iostream>

using namespace std;

int gcdFunction(int x, int y)  // recursive function
{
    if(x == 0)
        return y;
    else
        return gcdFunction(y % x, x);
}

int main()
{
	int x, y;   // 2 nos. whose gcd we've to find
	x = 462, y = 780;
	cout << "GCD of numbers " << x << " and " << y << " is " << gcdFunction(x, y);
	return 0;
}

/* Output

GCD of numbers 462 and 780 is 6

*/
