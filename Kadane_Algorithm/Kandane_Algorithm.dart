/* Dart implementation of Kadane's Algorithm to find the Maximum Subarray Sum
including the extra phase required when all the numbers in array are negative */

import 'dart:io';

int max(a, b) // Function that returns maximum between Two Numbers
{
    if(a > b) 
        return a;
    else 
        return b;
}

int kadane( input , n ) // Function implementing Kadane's Algorithm (array contains at least one positive number)
{
    int currentmax = 0, maxsofar = 0;

    for(int i = 0; i < n; i++)
    {
        currentmax = max( 0 , currentmax + input[i]);
        maxsofar = max( maxsofar, currentmax );
    }

    return maxsofar; // Maximum subarray sum
}

void main() {
    var maxsubarraysum;
    var input = [-2, 1, -6, 4, -1, 2, 1, -5, 4]; // Input array
    var n = input.length; // Size of array
    var flag = 0; // Flag variable to check if all the numbers in array are negative or not
    var largestinnegative = input[0]; // Smallest_negative variable will store the maximum subarray sum if all the numbers are negative in array

    for(int i = 0; i < n; i++) // Scanning each element in array
    {
        if(input[i] >= 0) // If any element is positive, kadane's algo can be applied
        {
            flag = 1;
            break;
        }
        else 
            if( input[i] > largestinnegative ) // If all the elements are negative, find the largest in them
                largestinnegative = input[i];
    }

    if(flag == 1) // Kadane's algo applicable
        maxsubarraysum = kadane( input , n );
    else
        maxsubarraysum = largestinnegative;// Kadane 's algo not applicable,
        // hence the max_subarray_sum will be the largest number in array itself

    print("Maximum Subarray Sum is: $maxsubarraysum");
}

/* Output
Maximum Subarray Sum is: 6
*/