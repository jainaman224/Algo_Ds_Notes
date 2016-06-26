In mathematics, the Euclidean algorithm, or Euclid's algorithm, is an efficient method for computing the greatest common divisor (GCD) of two numbers, the largest number that divides both of them without leaving a remainder. It is named after the ancient Greek mathematician Euclid, who first described it in Euclid's Elements . It is an example of an algorithm, a step-by-step procedure for performing a calculation according to well-defined rules, and is one of the oldest algorithms in common use. It can be used to reduce fractions to their simplest form, and is a part of many other number-theoretic and cryptographic calculations.

The Euclidean algorithm is based on the principle that the greatest common divisor of two numbers does not change if the larger number is replaced by its difference with the smaller number. For example, 21 is the GCD of 252 and 105 (252 = 21 × 12 and 105 = 21 × 5), and the same number 21 is also the GCD of 105 and 147 = 252 − 105. Since this replacement reduces the larger of the two numbers, repeating this process gives successively smaller pairs of numbers until the two numbers become equal. When that occurs, they are the GCD of the original two numbers. By reversing the steps, the GCD can be expressed as a sum of the two original numbers each multiplied by a positive or negative integer, e.g., 21 = 5 × 105 + (−2) × 252. 



C++ PROGRAM TO DEMONSTRATE BASIC EUCLIDEAN ALGORITHM

//Basic Euclidean Algorithm
#include <iostream>
using namespace std;

int gcdfunction(int x,int y)  //recursive function
{  if(x==0)
    return y;
    else
    return gcdfunction(y%x, x);
}
   

int main() {
	int x,y;   //2 nos. whose gcd we've to find
	cin>>x>>y;
	cout<<"GCD of numbers "<<x<<" and "<<y<<" is \n"<<gcdfunction(x,y);
	return 0;
}

The Time Complexity is O(log min(a, b)).