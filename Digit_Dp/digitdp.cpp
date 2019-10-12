/*
There are many types of problems that ask to count the number of integers ‘x‘ between two integers say ‘a‘ and ‘b‘ such that x satisfies a specific property that can be related to its digits.
So, if we say G(x) tells the number of such integers between 1 to x (inclusively), then the number of such integers between a and b can be given by G(b) – G(a-1). This is when Digit DP (Dynamic Programming) comes into action. All such integer counting problems that satisfy the above property can be solved by digit DP approach.
Key Concept
Let given number x has n digits. The main idea of digit DP is to first represent the digits as an array of digits t[]. Let’s say a we have tntn-1tn-2 … t2t1 as the decimal representation where ti (0 < i <= n) tells the i-th digit from the right. The leftmost digit tn is the most significant digit.
Now, after representing the given number this way we generate the numbers less than the given number and simultaneously calculate using DP, if the number satisfy the given property. We start generating integers having number of digits = 1 and then till number of digits = n. Integers having less number of digits than n can be analyzed by setting the leftmost digits to be zero.
*/

// Example Problem
// Given two integers a and b. The task is to print 
// sum of all the digits appearing in the 
// integers between a and b 
#include "bits/stdc++.h" 
using namespace std; 

// Memoization for the state results 
long long dp[20][180][2]; 

// Stores the digits in x in a vector digit 
long long getDigits(long long x, vector <int> &digit) 
{ 
	while (x) 
	{ 
		digit.push_back(x%10); 
		x /= 10; 
	} 
} 

// Return sum of digits from 1 to integer in 
// digit vector 
long long digitSum(int idx, int sum, int tight, 
						vector <int> &digit) 
{ 
	// base case 
	if (idx == -1) 
	return sum; 

	// checking if already calculated this state 
	if (dp[idx][sum][tight] != -1 and tight != 1) 
		return dp[idx][sum][tight]; 

	long long ret = 0; 

	// calculating range value 
	int k = (tight)? digit[idx] : 9; 

	for (int i = 0; i <= k ; i++) 
	{ 
		// caclulating newTight value for next state 
		int newTight = (digit[idx] == i)? tight : 0; 

		// fetching answer from next state 
		ret += digitSum(idx-1, sum+i, newTight, digit); 
	} 

	if (!tight) 
	dp[idx][sum][tight] = ret; 

	return ret; 
} 

// Returns sum of digits in numbers from a to b. 
int rangeDigitSum(int a, int b) 
{ 
	// initializing dp with -1 
	memset(dp, -1, sizeof(dp)); 

	// storing digits of a-1 in digit vector 
	vector<int> digitA; 
	getDigits(a-1, digitA); 

	// Finding sum of digits from 1 to "a-1" which is passed 
	// as digitA. 
	long long ans1 = digitSum(digitA.size()-1, 0, 1, digitA); 

	// Storing digits of b in digit vector 
	vector<int> digitB; 
	getDigits(b, digitB); 

	// Finding sum of digits from 1 to "b" which is passed 
	// as digitB. 
	long long ans2 = digitSum(digitB.size()-1, 0, 1, digitB); 

	return (ans2 - ans1); 
} 

// driver function to call above function 
int main() 
{ 
	long long a = 123, b = 1024; 
	cout << "digit sum for given range : "
		<< rangeDigitSum(a, b) << endl; 
	return 0; 
} 