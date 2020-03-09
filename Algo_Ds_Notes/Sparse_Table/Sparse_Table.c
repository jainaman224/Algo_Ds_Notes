
/***********************************************************************
* A C Program that implements a Data Structure called Sparse Table.    *
* After preprocessing of Sparse Table,                                 *
* one can answer Range Min/Max Query in O(1) Time                      *
*                                                                      *
* Memory Complexity - O(N*log(N))                                      *
* Total Time Complexity - O(N*log(N))                                  *
* Time Complexity for each Query - O(1)                                *
************************************************************************/

#include <stdio.h>
#include <math.h>
#define min(a, b) (a>b)?b:a

const int N = 100005; // Set this as the Max size of Input Array
const int M = 25; // Set this as log2(Max size of Input Array)

int pre[N][M]; // Array that we are precomputing in Precompute() function
int arr[] = {1, 4, 6, 2, 7, 3, 1, 6}; // Input Array
int n; // Size of Input Array

void Precompute()
{
	/* Pre[i][j] denotes the minimum of Index of the minimum element
	*  in the range of (i) to (i + 2^j - 1)
	*/

	for(int i = 0; i<n; i++)
	{
		pre[i][0] = i;
	}

	/* Compute minimum value for all intervals with size 2^j
	*  For that we can take minimum of 2 blocks of size 2^(j-1)
	*/

	for(int j = 1; (1<<j)<=n; j++)
	{
		for(int i = 0; (i+(1<<j))<=n; i++)
		{
			pre[i][j] = pre[i][j-1];
			if(arr[pre[i][j]]>arr[pre[i+(1<<(j-1))][j-1]])
			{
				pre[i][j] = pre[i+(1<<(j-1))][j-1];
			}
		}
	}

	return;
}

void Query(int l, int r)
{
	int temp = log2(r-l+1), ans;

	ans = min(arr[pre[l][temp]], arr[pre[r-(1<<temp)+1][temp]]);

	printf("Minimum in %d and %d is %d\n", l, r, ans);

	return;
}


int main()
{
	n = sizeof(arr)/sizeof(arr[0]); // Size of Input Array

	/*Precompute the pre Array in O(n*log(n))*/
	Precompute();

	/* Answer any Range Minimum Query in O(1)*/
	Query(1, 3);
	Query(2, 6);

	return 0;
}
