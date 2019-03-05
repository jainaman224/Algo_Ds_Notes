/* Extended Euclidean Algorithm 
  ==============================
  GCD of two numbers is the largest number that divides both of them.
  A simple way to find GCD is to factorize both numbers and multiply
  common factors.
  
     GCD(a,b) = ax + by
     
  If we can find the value of  x and y then we can easily find the 
  value of GCD(a,b) by replacing (x,y) with their respective values.
*/

#include <stdio.h> 

// C function for extended Euclidean Algorithm 
int gcdExtended(int a, int b, int *x, int *y) 
{ 
	// Base Case 
	if (a == 0) 
	{ 
		*x = 0; 
		*y = 1; 
		return b; 
	} 
  // To store results of recursive call 
	int x1, y1; 

  // Recursion
	int gcd = gcdExtended(b%a, a, &x1, &y1); 

	/* Update x and y using results of recursive call */
	*x = y1 - (b/a) * x1; 
	*y = x1; 

	return gcd; 
} 

// Driver Program 
/* Input 
   50 20
*/
int main() 
{ 
	int x, y; 
	int a = 50, b = 20; 
	int g = gcdExtended(a, b, &x, &y);

  /* Output
      10

     GCD of 50 and 20 is 10 
  */ 
	printf("gcdExtended(%d, %d) = %d", a, b, g); 
	return 0; 
} 
