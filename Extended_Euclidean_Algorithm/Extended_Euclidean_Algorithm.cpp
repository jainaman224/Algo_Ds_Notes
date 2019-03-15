/* Extended Euclidean Algorithm 
  ==============================
  GCD of two numbers is the largest number that divides both of them.
  A simple way to find GCD is to factorize both numbers and multiply
  common factors.
  
     GCD(a,b) = ax + by

  If we can find the value of  x and y then we can easily find the 
  value of GCD(a,b) by replacing (x,y) with their respective values.
*/

#include <iostream>
#include <tuple>	
using namespace std;

// Function for Extended Euclidean algorithm
// It returns multiple values using tuple in C++

tuple<int, int, int> extended_gcd(int a, int b)
{
  
	if (a == 0)
		return make_tuple(b, 0, 1);

	int gcd, x, y;

	// unpack tuple  returned by function into variables
	tie(gcd, x, y) = extended_gcd(b % a, a);

	return make_tuple(gcd, (y - (b/a) * x), x);
}

// main function
int main()
{ 
 /* 
    Input 
    30 50
 */
 
	int a = 30;
	int b = 50;

	tuple<int, int, int> t = extended_gcd(a, b);
	
	int gcd = get<0>(t);
	int x = get<1>(t);
	int y = get<2>(t);
	
  /* 
   Output
    10
  */
	cout << "GCD is " << gcd << endl;
	cout << "x = " << x << " y = " << y << endl;

	cout << a << "*" << x << " + " << b << "*" << y << " = " << gcd;

	return 0;
}
