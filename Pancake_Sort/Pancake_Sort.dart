/**
 *   Pancake Sort
 * --------------------------
 * It is a sorting algorithm of O(n^2) algorithm which sorts like selection sort
 * by moving the minimum to the front by reversing the array till its index.
 */

// Importing required libraries
import 'dart:io';

// Utility function to find maximum of the array
int findMax(List array, int n){
    int max_value = array[0];
    int max_index = 0;
    for (int i = 0; i < n; i ++){
        if (max_value < array[i]){
            max_value = array[i];
            max_index = i;
        }
    }
    return max_index;
}

// Utility function to flip an array from an index
void flip(List array, int i){
    int start = 0, temp;
    while (start < i){
        temp = array[start];
        array[start] = array[i];
        array[i] = temp;
        start ++;
        i --;
    }
}

// Function to sort a list using pancake sort
void pancakeSort(List array, int n){
    for (int i = n; i > 1; i --){
        int max_index = findMax(array, i);
        if (max_index != i - 1){
            flip(array, max_index);
            flip(array, i - 1);
        }
    }
}
// Driver method of the program
void main(){
    print("Enter number of elements of the array:");
    var input = stdin.readLineSync();
    int n = int.parse(input);

    print("Enter array elements:");
    input = stdin.readLineSync();
    var lis = input.split(" ");
    List array = lis.map(int.parse).toList();

    pancakeSort(array, n);

    print(array.join(" "));
}

/**
 *   Sample Input and Output
 * ------------------------------------
 * Enter number of elements of the array:
 * 10
 * Enter array elements:
 * 10 9 8 7 6 5 4 3 2 1
 * 1 2 3 4 5 6 7 8 9 10
 */
