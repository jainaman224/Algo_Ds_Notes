// Importing required libraries
import 'dart:io';
import 'dart:math';

// Declaring required variables
int temp, max, count, maxdigits = 0, c = 0;
int t1, t, i, j;
List array, array1;
int n = 1;
  
// Method to arrange numbers that have same base
void arrange(int k, int n){
    for(int i = k; i < n - 1; i ++){
        for(int j = i + 1; j < n; j ++){
            if(array1[i] > array1[j]){
                temp = array1[i];
                array1[i] = array1[j];
                array1[j] = temp;
                temp = array[i]%10;
                array[i] = array[j]%10;
                array[j] = temp;
            }
        }
    }
}


void main(){

    // Input of the size of the array
    print("Enter the number of elements in the array:");
    var input = stdin.readLineSync();
    count = int.parse(input);

    // Input of array elements
    print("Enter the array elements:");
    input = stdin.readLineSync();
    var lis = input.split(' ');
    array = lis.map(int.parse).toList();
    array1 = lis.map(int.parse).toList();

    // Finding the maximum possible length of the numbers in the array
    for(i = 0; i < count; i ++){
        t = array[i];
        c = (log(array[i])/log(10)).floor();
        if(c > maxdigits){
            maxdigits = c;
        }
    }

    for(i = 0; i < maxdigits - 1; i ++){
        n = n * 10;
    }

    for(i = 0; i < count; i ++){
        max = (array[i]/n).floor();
        t = i;
        for(j = i + 1; j < count; j ++){
            if(max > (array[j]/n).floor()){
                max = (array[j]/n).floor();
                t = j;
            }
        }

        // Swapping
        temp = array1[t];
        array1[t] = array1[i];
        array1[i] = temp;
        temp = array[t];
        array[t] = array[i];
        array[i] = temp;
    }

    while(n >= 1){
        for(i = 0; i < count;){
            t1 = (array[i]/n).floor();
            for(j = i + 1; j < count && t1 == (array[j]/n).floor(); j ++){
                arrange(i, j);
            }
            i = j;
        }
        n = (n / 10).floor();
    }

    print("The sorted array is:");
    print(array.join(" "));
}

/**
 *  Sample Input and Output
 * ----------------------------
 * Enter the number of elements in the array:
 * 10
 * Enter the array elements:
 * 10 9 8 7 6 5 4 3 2 1
 * The sorted array is:
 * 1 2 3 4 5 6 7 8 9 10
 * 
 */
