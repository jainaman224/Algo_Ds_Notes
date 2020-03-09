// A Dynamic programming solution for Rod Cutting problem
#include <iostream>
#include <limits.h>

using namespace std;

// A function for calculating max of two nos.
int max(int a, int b)
{
	return (a > b) ? a : b;
}

// Returns the max obtainable cost
int CutRod(int cost[], int n)
{
	int val[n + 1], i, j;
    val[0] = 0;

	for (i = 1; i <= n; i++)
    {
		int max_value = INT_MIN;
       	for (j = 0; j < i; j++)
        	max_value = max(max_value, cost[j] + val[i - j - 1]);
        val[i] = max_value;
    }
    return val[n];
}

// Driver function
int main() {
	int size;
	cin >> size;
	int arr[size];
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}
	cout << "Maximum value is " << CutRod(arr, size) << endl;
	return 0;
}


/* 
INPUT: 
size = 8
arr = {3, 5, 8, 9, 10, 17, 17, 20}
OUTPUT:
Maximum value is 24
*/
