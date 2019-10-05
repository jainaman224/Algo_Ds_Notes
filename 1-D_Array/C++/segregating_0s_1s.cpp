
#include <iostream>
using namespace std;

// FUNCTION TO SEGREGATE ZEROES AND ONES
void segregate_01(int *arr, int n) {
    
    int i = 0, j = n-1;

    // CONTINUE THIS LOOP WHILE I<J
    while(i < j) {
        if(arr[i] == 0) {
            i++;
        }
        else if(arr[j] == 1) {
            j--;
        }
        else {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

}

// FUNCTION TO PRINT AN ARRAY
void printArray(int *arr, int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// MAIN DRIVER FUNCTION
int main() {

    int n;
    cout << "Enter the number of elements in array: ";
    cin >> n;

    // CREATE A NEW ARRAY DYNAMICALLY
    int *arr = new int[n];
    cout << "Enter the elements of the array: " << endl;

    // TAKING AS INPUT, N NUMBERS
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    // PRINT ORIGINAL INPUT ARRAY
    cout << "Original array is: ";
    printArray(arr, n);

    // FUNCTION TO SEGREGATE THE ZEROES AND ONES
    segregate_01(arr, n);

    // PRINT THE NEW ARRAY AFTER MODIFICATION
    cout << "Final array is: ";
    printArray(arr, n);

}