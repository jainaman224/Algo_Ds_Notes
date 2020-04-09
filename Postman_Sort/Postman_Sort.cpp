/*
* C++ Implementation for Postman Sort Algorithm.
* This is the algorithm used by letter-sorting machines in the post office: 
* first states, then post offices, then routes, etc. 
* Since keys are not compared against each other, sorting time is O(cn), 
* where c depends on the size of the key and number of buckets.
*/

#include <bits/stdc++.h>
using namespace std;

void arrange(int p, int s);
int temp, maxdigits = 0, c = 0;
int t1, t2, k, t, n = 1, i, j;
int arr[100], arr1[100];
int main(){
    int count, max;
    cout << "The size of the Array : " ;
    cin >> count;
    int arr[count];
    for(i = 0; i < count; i++)
        cin >> arr[i];
    
    cout << "\nThe Unsorted Array is : \n" ;
    for(i = 0; i < count; i++) 
        cout << arr[i] << " ";
    
    for(i = 0; i < count; i++) {
        // first element in t
        t = arr[i];
        // Calculating the Number of digits using logarithmic
        c = log10(arr[i]);
        // number of digits in a each number
        if(maxdigits < c)
            maxdigits = c;
    }

    while(--maxdigits)
        n = n * 10;
    
    for(i = 0; i < count; i++) {
        // MSB - Dividing by particular base
        max = arr[i] / n;
        t = i;
        for(j = i + 1; j < count; j++) {
            if(max > arr[j] / n) {
                max = arr[j] / n;
                t = j;
            }
        }
        swap(arr1[t], arr1[i]);
        swap(arr[t], arr[i]);
    }

    while (n >= 1) {
        for(i = 0; i < count;) {
            t1 = arr[i] / n;
            for(j = i + 1; t1 == (arr[j] / n); j++);
            arrange(i, j);
            i = j;
        }
        n = n / 10;
    }

    cout << "\nThe Sorted Array is : \n";
    for(int i = 0; i < count; i++) 
        cout << arr[i] << " ";
    cout << "\n";
    return 0;
}

// Function to arrange the of sequence having same base 
void arrange(int p, int s) {
    for(int i = p; i < s - 1; i++) {
        for(int j = i + 1; j < s; j++) {
            if(arr1[i] > arr1[j]) {
                // swap arr1[i] and arr1[j]
                swap(arr1[i], arr1[j]);

                temp = arr[i] % 10;
                arr[i] = arr[j] % 10;
                arr[j] = temp;
            }
        }
    }
}

/*
INPUT :
The size of the Array : 10
70, 80, 20, 50, 10, 60, 40, 100, 90, 30

OUTPUT : 
The Unsorted Array is : 
70 80 20 50 10 60 40 100 90 30
The Sorted Array is : 
10 20 30 40 50 60 70 80 90 100
*/
