/* Dart implementation of Kadane's Algorithm to find the Maximum Subarray Sum
including the extra phase required when all the numbers in array are negative */

import 'dart:io';

// Function that returns maximum between Two Numbers
int max(a, b){
    if(a > b) 
          return a;
    else 
          return b;
}


// Function implementing Kadane's Algorithm (array contains at least one positive number)
int kadane( input , n ){
    int currentmax = 0, maxsofar = 0;

    for( int i = 0; i < n; i++ )
    {
        currentmax = max( 0 , currentmax + input[i] );
        maxsofar = max( maxsofar, currentmax );
    }
    return maxsofar;
}

void main() {

    int maxsubarraysum, size;

    // Input array
    stdout.write("Enter the number of elements in the array:");
    String input = stdin.readLineSync();
    size = int.parse(input);
    List array = [];
    for( int i = 0; i < size; i++ )
    {
        String x1 = stdin.readLineSync();
        int x2 = int.parse(x1);
        array.add(x2);
    }

    // Size of array
    int n = array.length;

    // Flag variable to check if all the numbers in array are negative or not
    int flag = 0;

    // Smallest_negative variable will store the maximum subarray sum if all the numbers are negative in array
    int largestinnegative = array[0];

    // Scanning each element in array
    for( int i = 0; i < n; i++ )
    {
        // If any element is positive, kadane's algo can be applied
        if(array[i] >= 0)
        {
            flag = 1;
            break;
        }
        else 
        {   // If all the elements are negative, find the largest in them
            if( array[i] > largestinnegative )
            {
                largestinnegative = array[i];
            }
        }
    }

    // Kadane's algo applicable
    if(flag == 1)
    {
        maxsubarraysum = kadane( array , n );
    }
    else
    {   // Kadane 's algo not applicable,
        maxsubarraysum = largestinnegative;
    }

    // hence the max_subarray_sum will be the largest number in array itself
    print("Maximum Subarray Sum is: $maxsubarraysum");
}
