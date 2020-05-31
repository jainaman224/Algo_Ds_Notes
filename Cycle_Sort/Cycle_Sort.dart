// Importing required libraries
import 'dart:io';

// Function to sort the list using cycle sort
void cycle_sort(List array, int n){
    for(int cycle_start = 0; cycle_start <= n - 2; cycle_start ++){
        // Selecting an element
        int value = array[cycle_start];
        int position = cycle_start;
        // Finding its position where it should be when the list is sorted
        for(int i = cycle_start; i < n; i ++){
            if(array[i] < value){
                position ++;
            }
        }
        // If its in the right position already, ignore
        if(position == cycle_start){
            continue;
        }
        // If not, and there are repititive values, insert after them
        while(value == array[position]){
            position += 1;
        }
        if(position != cycle_start){
            int temp = value;
            value = array[position];
            array[position] = temp;
        }
        // Continue the same process till the cycle ends.
        while(position != cycle_start){
            position = cycle_start;
            for(int i = cycle_start; i < n; i ++){
                if(array[i] < value){
                    position += 1;
                }
            }
            while(value == array[position]){
                position += 1;
            }
            if(value != array[position]){
                int temp = value;
                value = array[position];
                array[position] = temp;
            }
        }
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
    // Cycle sorting
    cycle_sort(array, n);
    // Printing the output to stdout
    print(array.join(" "));
}
/**
 *  Sample Input and Output
 * -------------------------------
 * Enter number of elements in the array:
 * 7
 * Enter array elements:
 * 78 7 8 89 8 8 8
 * 7 8 8 8 8 78 89
 */
