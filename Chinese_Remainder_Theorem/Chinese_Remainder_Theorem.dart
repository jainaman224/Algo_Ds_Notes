/*
          Dart program to implement Chinese Remainder Theorem (CRT)
    ---------------------------------------------------------------------

                        Chinese Remainder Theorem
    ---------------------------------------------------------------------

    The Chinese Remainder Theorem ( based on Extended Euclid's algorithm ) states that a set of 'k' congruency equations with a single variable 
    as follows 

                  x % num[0] = rem[0]
                  x % num[1] = rem[1]
                  .
                  .
                  .
                  x % num[k] = rem[k]

    can be solved by using the formula, x = ( sum(rem[i]*pd[i]*inv[i]) for all i ) % product where

    product is the product of all numbers in num array
    rem[i] is the i'th remainder in the given input,
    pd[i] is the value of product divided by num[i],
    inv[i] is the modulo inverse of pd[i] and num[i],
    sum() is a function that sums up the values.

    Here, the obtained solution is minimum possible x.

*/ 

// Importing required libraries.
import 'dart:io';

// Function to calculate modulo inverse.
int modular_inverse(int a, int m){

    // Temporary variable to store m to use later.
    int temp = m;

    if (m == 1){
        return 0;
    }

    int y = 0, x = 1, temp2, quotient, remainder;

    // Calculating x and y based on Euclid's algorithm
    while (a > 1){
        quotient = (a / m).floor();
        remainder = a % m;
        a = m;
        m = remainder;
        temp2 = y;
        y = x - quotient * y;
        x = temp2;
    }

    // Making x positive if found negative
    if (x < 0){
        x += temp;
    }

    return x;
}

// Driver function of the program
void main(){

    // Taking input of the number array (num[i]).
    print("Enter array of pairwise co-prime numbers:");

    var input = stdin.readLineSync();
    var lis = input.split(' ');
    List numbers = lis.map(int.parse).toList();

    // Taking input of remainder array (rem[i]).
    print("Enter remainders:");

    input = stdin.readLineSync();
    lis = input.split(' ');
    List remainders = lis.map(int.parse).toList();
    
    int product = 1;

    // Length of the 'numbers' list.
    int length = numbers.length;
    
    // Finding product of all the numbers.
    for (int i = 0; i < length; i ++){
        product *= numbers[i];
    }
    
    int temp, result = 0;

    // Summing the required values for all i according to the formula.
    for (int i = 0; i < length; i ++){
        temp = (product / numbers[i]).floor();
        result += temp * (remainders[i]) * modular_inverse(temp,numbers[i]);
    }
    
    result = result % product;

    // Printing result
    print("The value of 'x' by Chinese Remainder Theorem is $result.");

}

/*
    Sample Input

    Enter array of pairwise co-prime numbers:
    9 8 5 7 1
    Enter remainders:
    1 2 3 4 5

    Sample Output
        
    The value of 'x' by Chinese Remainder Theorem is 298.

*/

