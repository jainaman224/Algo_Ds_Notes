// Importing required libraries
import 'dart:io';

// Function to sort the input list using cocktail sort
void cocktail_sort(List array, int n){
    bool swapped = true;
    int start = 0;
    int end = n;
    while (swapped == true){
        swapped = false;
        // Forward swapping
        for (int i = start; i < end - 1; i ++){
            if (array[i] > array[i + 1]){
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = true;
            }
        }
        if (swapped == false){
            break;
        }
        swapped = false;
        end = end - 1;
        // Reverse swapping
        for (int i = end - 1; i >= start; i --){
            if (array[i] > array[i + 1]){
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = true;
            }
        }
        start = start + 1;
    }

}

// Driver method of the program
void main(){
    // Input of size of the array
    print("Enter number of elements in the array:");
    var input = stdin.readLineSync();
    int n = int.parse(input);
    // Input of the array elements
    print("Enter array elements:");
    input = stdin.readLineSync();
    var lis = input.split(" ");
    List array = lis.map(int.parse).toList();
    // Cocktail sorting
    cocktail_sort(array, n);
    // Printing the output to stdout
    print(array.join(" "));
}

/**
 *   Sample Input and Output
 * ------------------------------------
 * Enter number of elements in the array:
 * 10
 * Enter array elements:
 * 10 9 8 7 6 5 4 3 2 1
 * 1 2 3 4 5 6 7 8 9 10
 */
