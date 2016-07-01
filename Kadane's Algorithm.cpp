/* C++ implementation of Kadane's Algorithm to find the Maximum Subarray Sum
 including the extra phase required when all the numbers in array are negative*/


#include <iostream>

using namespace std;

int kadane(int input[], int n) // function implementing Kadane's Algorithm (array contains at least one positive number)
{
    int current_max = 0;
    int max_so_far = 0;

    for(int i = 0; i < n; i++)
    {
        current_max = max(0, current_max + input[i]);
         max_so_far = max(max_so_far, current_max);
    }

    return max_so_far;// maximum subarray sum
}



int main()
{
    int n, max_subarray_sum;

    int input[] = { -2, 1, -6, 4, -1, 2, 1, -5, 4 };//input array

    n = sizeof(input) / sizeof(input[0]);//size of array

    int flag = 0;//flag variable to check if all the numbers in array are negative or not

    int largest_in_negative = input[0];//smallest_negative variable will store the maximum subarray sum if all the numbers are negative in array

    for(int i = 0; i < n; i++) // scanning each element in array
    {

        if (input[i] >= 0)// if any element is positive, kadane's algo can be applied
        {
            flag = 1;
            break;
        }

        else if (input[i] > largest_in_negative) // if all the elements are negative, find the largest in them
            largest_in_negative = input[i];

    }

    if (flag == 1)// kadane's algo applicable
       max_subarray_sum = kadane(input, n);
    else
       max_subarray_sum = largest_in_negative;// kadane 's algo not applicable,
        //hence the max_subarray_sum will be the largest number in array itself

    cout<< "Maximum Subarray Sum is "<<max_subarray_sum<<endl;

    return 0;
}

/*

output : Maximum Subarray Sum is 6

*/
