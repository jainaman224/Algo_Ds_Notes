/**
 *    3 way Quick sort
 * ---------------------------------
 * In three way quick sort, we partition the list into three divisions where
 * division1 is less than pivot, division2 is equal to pivot and division3 is greater than
 * pivot. The sorting is implemented using Dutch National Flag algorithm.
 */

// Importing required libraries
import 'dart:io';

// Method to swap two integers in a list
void swap(List array, int i, int j){
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

// Method to partition the array based on 3 way partition
List partition(List array, int low, int high){
    int i, j;
    if(high - low <= 1){
        if(array[high] < array[low]){
            swap(array, high, low);
        }
        i = low;
        j = high;
        // Returning the partitioning indices as list.
        return [i, j];
    }

    int mid = low;
    int pivot = array[high];
    while(mid <= high){
        if(array[mid] < pivot){
            swap(array, low++, mid++);
        }
        else if(array[mid] == pivot){
            mid++;
        }
        else if(array[mid] > pivot){
            swap(array, mid, high--);
        }
    }
    i = low - 1;
    j = mid;

    // Returning the partitioning indices as list
    return [i, j];
}

// Method to sort a list using 3 way partition quick sort.
void quicksort_3_way(List array, int low, int high){

    // Base case
    if(low >= high){
        return;
    }

    // Partitioning indices
    List indices = partition(array, low, high);

    // Recursion
    quicksort_3_way(array, low, indices[0]);
    quicksort_3_way(array, indices[1], high);

}

// Driver method of the program
void main(){

    // Input of number of elements of the array
    print("Enter number of elements of the array:");
    var input = stdin.readLineSync();
    int n = int.parse(input);

    // Input of array elements
    print("Enter array elements:");
    input = stdin.readLineSync();
    var lis = input.split(" ");
    List array = lis.map(int.parse).toList();

    // Finding the sorted array using quick sort 3 way partition
    quicksort_3_way(array, 0, n - 1);

    // Printing the output to stdout.
    print(array.join(" "));
}
/**
 *  Sample Input and Output
 * -------------------------------
 * Enter number of elements of the array:
 * 13
 * Enter array elements:
 * 4 9 4 4 1 9 4 4 9 4 4 1 4
 * 1 1 4 4 4 4 4 4 4 4 9 9 9
 */
