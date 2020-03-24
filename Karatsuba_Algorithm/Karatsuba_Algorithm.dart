import 'dart:io';
import 'dart:math';

// function to find minimun of two integers
int minof(a, b){
    if(a < b) 
        return a;
    else return b;
}

int karatSuba(num1, num2){

    // for single digit number multiply directly
    if (num1 < 10 || num2 < 10) {
        return num1 * num2;
    }

    String num1Str = num1.toString();
    String num2Str = num2.toString();
    int n = minof(num1Str.length, num2Str.length);
    int half = (n / 2).round();

    // divide num1 into two halves
    int num1_H = int.parse(num1Str.substring(0, num1Str.length - half));
    int num1_L = int.parse(num1Str.substring(num1Str.length - half, num1Str.length));

    // divide num2 into two halves
    int num2_H = int.parse(num2Str.substring(0, num2Str.length - half));
    int num2_L = int.parse(num2Str.substring(num2Str.length - half, num2Str.length));

    // using the KaratSuba Definition
    int s1 = karatSuba(num1_L, num2_L);
    int s2 = karatSuba(num1_L + num1_H, num2_L + num2_H);
    int s3 = karatSuba(num1_H, num2_H);
    int s4 = s2 - s3 - s1;

    // karatsuba formula for finding product
    int result = s3 * pow(10, 2 * half) + s4 * pow(10, half) + s1;

    return result;
}


void main(){
    String a, b;
    a = stdin.readLineSync(); 
    b = stdin.readLineSync();
    print(karatSuba(int.parse(a), int.parse(b)));
}
/*
Sample input:
12345
6789

Sample Output:
83810205
*/
