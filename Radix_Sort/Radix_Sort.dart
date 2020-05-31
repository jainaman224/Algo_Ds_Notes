// Importing required libraries
import 'dart:io';

// Function to sort based on bits of integers using count sort
void countSort(List array, int n, int exp){
    List output = List(n);
    List count = List(10);
    for(int i = 0; i < 10; i ++){
        count[i] = 0;
    }
    for(int i = 0; i < n; i ++){
        count[((array[i] / exp).floor()) % 10] ++;
    }
    for(int i = 1; i < 10; i ++){
        count[i] += count[i - 1];
    }
    for(int i = n - 1; i >= 0; i --){
        output[count[((array[i] / exp).floor()) % 10] - 1] = array[i];
        count[((array[i] / exp).floor()) % 10] --;
    }
    for(int i = 0; i < n; i ++){
        array[i] = output[i];
    }
}
// Function to find max of the array
int getMax(List array, int n){
    int max_value = array[0];
    for(int i = 0; i < n; i ++){
        if(max_value < array[i]){
            max_value = array[i];
        }
    }
    return max_value;
}
// Function to sort an array using radix sort
void radix_sort(List array, int n){
    int max_value = getMax(array, n);
    for(int exp = 1; max_value / exp > 0; exp *= 10){
        countSort(array, n, exp);
    }
}
// Driver method of the program.
void main(){
    print("Enter number of elements in the array:");
    var input = stdin.readLineSync();
    int n = int.parse(input);

    print("Enter array elements:");
    input = stdin.readLineSync();
    var lis = input.split(" ");
    List array = lis.map(int.parse).toList();

    radix_sort(array, n);

    print(array.join(" "));
}
/**
 *   Sample Input and Output
 * ---------------------------------
 * Enter number of elements in the array:
 * 10
 * Enter array elements:
 * 10 9 8 7 6 5 4 3 2 1
 * 1 2 3 4 5 6 7 8 9 10
 */
