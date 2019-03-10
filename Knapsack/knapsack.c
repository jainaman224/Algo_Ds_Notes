// Girlscript Summer Of Code
// 0-1 Knapsack program in Python

/*
To know what Knapsack problem is, refer 0-1knapsack/knapsack.py of this repository.
What is Dynamic Programming?
Dynamic Programming is mainly an optimization over plain recursion. Wherever we see a recursive solution that has repeated calls for same inputs, we can optimize it using Dynamic Programming. The idea is to simply store the results of subproblems, so that we do not have to re-comupute them when needed later. This simple optimization reduces time complexities from exponential to polynomial. For example, if we write simple recursive solution for Fibonacci Numbers, we get exponential time complexity and if we optimize it by storing solutions of subproblems, time complexity reduces to linear.
[Refered from www.geeksforgeeks.com]
*/
#include<stdio.h> 

// Function to get maximum of two numbers: 
int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 

// Knapsack function based on Dynamic Programming 
int knapSack(int W, int wt[], int val[], int n) 
{ 
    int i, w; 
    int K[n+1][W+1]; 


    for (i = 0; i <= n; i++) 
    { 
	for (w = 0; w <= W; w++) 
	{ 
		if (i==0 || w==0) 
			K[i][w] = 0; 
		else if (wt[i-1] <= w) 
				K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]); 
		else
				K[i][w] = K[i-1][w]; 
	} 
    } 

    return K[n][W]; 
} 

// Main function
int main() 
{ 
        // Test case for the program :
	int val[] = {30, 20, 60, 80, 10}; 
	int wt[] = {10, 20, 30, 40, 50}; 
        // Maximum Weight
	int W = 80; 
	int n = sizeof(val)/sizeof(val[0]); 
        // Display Result
	printf("%d\n", knapSack(W, wt, val, n)); 
        // Result is 170 for the test case given initially.

	return 0; 
} 
//  Contributed by Jaseem CK
//  Happy Coding!
