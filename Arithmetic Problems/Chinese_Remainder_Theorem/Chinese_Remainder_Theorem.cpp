// A C++ program to demonstrate working of Chinese Remainder Theorem

// NAIVE IMPLEMENTATION

/*

  s is size of num[] and rem[].  Returns the smallest
  number a such that:
  a % num[0] = rem[0],
  a % num[1] = rem[1],
  ..................
  a % num[s-1] = rem[s-1]
  Assumption: Numbers in num[] are pairwise coprime
  (gcd for every pair is 1)

*/

#include <iostream>

using namespace std;

int min(int num[], int rem[], int s)
{
	int a = 1; // Initialize result
  	while(true)
  	{
		int i;
     	for (i = 0; i < s; i++)
		{
       		if(a%num[i] != rem[i])
        		break;
		}

        // If all remainders matched, we found a
       	if (i == s)
       		return a;
       	// Else try next number
       	a++;
  	}
  	return a;
}


// Driver function
int main()
{
	int num[] = {3, 4, 5};
	int rem[] = {2, 3, 1};
	int s = sizeof(num) / sizeof(num[0]);
	cout << "Number is " << min(num, rem, s);
	return 0;
}

/* Output

  Number is 11

*/
