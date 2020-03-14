//C++ Program to find last digit of nth fibonacci numbers
#include<iostream>
using namespace std;

int main() {
    int a[60], n, i;
    a[0] = 0;
    a[1] = 1;
    //Using the concept that after 60 numbers in a fibonacci numbers the last digit repeats itself again and again
    for(i = 2 ; i < 60 ; i++ ){        //for storing the last digits of first 60 fibonacci numbers
        a[i] = (a[i-1] + a[i-2]) % 10;//Now we will store last digits in array and their index as position in first 60 numbers fibonacci numbers 
    } 
    cin >> n ;  

    cout << "\nThe Position of Fibonacci Number: " << n ; //getting the required number

    cout << "\nThe Last Digit of this Number : " << a[n % 60] ;//print the last digit given in that position
    return 0;
}
/*
Sample Input 1:
2344
Sample Output 1:
The Position of Fibonacci Number: 2344
The Last Digit of this Number : 3
Sample Input 2:
267
Sample Output 2:
The Position of Fibonacci Number : 267
The Last Digit of this Number : 8
*/
