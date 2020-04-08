/*
Question- Given n numbers (both +ve and -ve), arranged in a circle, find the maximum sum of consecutive number. 
Solution- There are two cases for this problem.
Case-1 The elements that contribute to the maximum sum are arranged such that no wrapping is there.Kadane will simply work.
Case-2 The elements which contribute to the maximum sum are arranged such that wrapping is there.
*/

#include<iostream>
using namespace std;

/* Function to find contiguous sub-array with the largest sum
in given set of integers*/
int kadaneAlgo(int a[], int n)
{ 
    int max_so_far=0, max_ending_here = 0;

    for(int i = 0; i < n; i++)
    { 
        max_ending_here += a[i];
        if(max_ending_here < 0)
        {
            max_ending_here = 0;
        }

        max_so_far = max(max_ending_here, max_so_far);
    }
    return max_so_far;
}

int circular_subarray_sum(int a[], int n)
{  
    //answer for case 1.
    int kadane_max = kadaneAlgo(a, n);
    
    //Find total sum and negate all elements of the array.
    int total_sum = 0;
    for(int i = 0; i < n; i++)
    { 
        total_sum += a[i];
        a[i] = -a[i];

    }
    /*Ans for test case 2.
    Find out the sum of non contributing elements and subtract this sum from the Total sum.*/
    total_sum = total_sum + kadaneAlgo(a, n); 
    return max(kadane_max, total_sum); 
}

int main()
{
    int n;
    cin >> n;
    int a[n];

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "The sum of subarray with the largest sum is: " << circular_subarray_sum(a, n) << endl;
    return 0;
}

/*
Input-
9
2 1 -8 4 -5 1 -7 4 -1
Output-
The sum of subarray with the largest sum is 6
*/