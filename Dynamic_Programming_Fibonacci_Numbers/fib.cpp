#include <iostream>

using namespace std;


/*
   DYNAMIC PROGRAMMING STEPS:

   Step 1: You spot a recursive solution to a problem. When you program that solution, it will be correct, but you'll find that it's incredibly slow, because it makes many duplicate procedure calls.

   Step 2: You cache the answers to recursive calls so that when they are repeated, you can return from them instantly. This is called memoization.

   Step 3: If you want to, you can typically figure out how to eliminate the recursive calls, and instead populate the cache with one or more for loops. This is faster than memoization, but usually not by much.

   Step 4: Sometimes, you can eliminate the cache completely. This makes the program even faster and more memory efficient. 
 */

int find_fib(int n)
{
	int v[3];
	int i;

	if (n == 0 || n == 1) return 1;

	v[0] = 1;
	v[1] = 1;
	for (i = 2; i <= n; i++) {
		v[2] = v[0] + v[1];
		v[0] = v[1];
		v[1] = v[2];
	}

	return v[2];
}

int main(){

	int anum;
	cout << "Enter a number you want to see the Fibonacci number for: ";
	cin >> anum;
	cout << endl;

	cout << "Fibonacci number is: " << find_fib(anum) << endl;

	return(0);
}
