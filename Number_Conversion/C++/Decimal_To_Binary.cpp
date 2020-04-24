// C++ program to convert numbers from decimal to binary form

#include <iostream>
#include <math.h>
using namespace std;

// Function to convert the number from decimal to binary form

void printBinary(int n){

    int size = log2(n) + 1; // command to find out number of bits in the given number which decides the size of the array

    int b[size], j = 0; // Array to store the binary number

    while(n! = 0){
        b[j] = n % 2;
        n = n / 2;
        j++;
    }

    cout<<"\nThe binary form is : ";
    for(j = size - 1; j >= 0; j--)
        cout << b[j];
}

int main()
{
    cout << "Enter the number you wish to convert:"<<endl;
    int n;
    cin >> n;
    printBinary(n);
    cout << "\n"; // Calling function printBinary to convert the number to binary form
    return 0;
}
/*
Input : 25
Output : 11001
*/
