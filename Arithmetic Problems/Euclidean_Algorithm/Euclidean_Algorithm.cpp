#include <iostream>

using namespace std;

int gcdFunction(int x, int y)  // recursive function
{
    if(x == 0)
        return y;
    else
        return gcdFunction(y % x, x);
}

int gcdFunction2(int x, int y)
{
  // Since at the end of the algorithm, the two numbers should be the GCD and 0
  // so we can simply return x+y without comparing x and y
  while( (x %= y) && (y %= x) );
  return x + y;
}

int main()
{
	int x, y;   // 2 nos. whose gcd we've to find
	x = 462, y = 780;
	cout << "GCD of numbers " << x << " and " << y << " is " << gcdFunction(x, y) << endl;

  cout << "Another amazing implementation of GCD : " << gcdFunction2(x, y) << endl;

	return 0;
}

/* Output

GCD of numbers 462 and 780 is 6
Another amazing implementation of GCD : 6

*/
