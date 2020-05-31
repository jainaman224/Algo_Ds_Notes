// Importing required libraries
import 'dart:io';

// Function to fill the coefficients array
void coef(int number, List c){
    c[0] = 1;
    for (int i = 0; i < number; c[0] = -c[0], i ++){
        c[i + 1] = 1;
        for (int j = i; j > 0; j --){
            c[j] = c[j - 1] - c[j];
        }
    }
}

// Function to find the primality of a given number using AKS primality test
bool aks_primality(int number){
    List c = List(100);
    coef(number, c);
    c[0] ++;
    c[number] --;
    int i = number;
    while ((i --) > 0 && c[i] % number == 0);
    return i < 0;
}

// Driver method of the program
void main(){
    // Input of the number
    print("Enter a number for primality test:");
    var input = stdin.readLineSync();
    int number = int.parse(input);
    
    // Respective output
    if (number > 64){
        print("This number is out of scope of this algorithm. This works only till 64");
        return;
    }
    if (aks_primality(number)){
        print("It is a prime number");
    }
    else {
        print("It is not a prime number");
    }
}

/**
 *  Sample Input and Output
 * ---------------------------------
 * Enter a number for primality test:
 * 37
 * It is a prime number
 * Enter a number for primality test:
 * 24
 * It is not a prime number
 */
