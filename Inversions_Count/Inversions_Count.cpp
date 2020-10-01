#include<bits/stdc++.h>
using namespace std;

//merge two sorted arrays such that resultant array is also sorted
int merge(int input_arr[], int *aux, int low, int mid, int high) {
    int x = low, y = mid, z = low, count = 0;
    while( (x <= mid-1) && (y <= high) ) {
        if( input_arr[x] <= input_arr[y] ) {
            aux[z++] = input_arr[x++];
        }
        else {
            aux[z++] = input_arr[y++];
            count += mid-x;
        }
    }

    while(x <= mid-1) {
        aux[z++] = input_arr[x++];
    }
    while(y <= high) {
        aux[z++] = input_arr[y++];
    }

    for(int i = low; i <= high; i++) {
        input_arr[i] = aux[i];
    }
    return count;
}

//merge sort to find inversion count
int mergeSort(int input_arr[], int *aux, int low, int high) {
    int count = 0;
    if(high > low) {
        int mid = (low + high) / 2;
        count = mergeSort(input_arr, aux, low, mid);
        count += mergeSort(input_arr, aux, mid + 1, high);
        count += merge(input_arr, aux, low, mid + 1, high);
    }
    return count;
}

//wrapper function that returns number of inversions
int inversions_count(int input_arr[], int n) {
    int *aux = new int[n];
    return mergeSort(input_arr, aux, 0, n-1);
}

int main() {
    
    //Count number of inversions for the input_arr [1, 10, 3, 4, 5, 8, 7, 9, 2]

    int input_arr[] = {1, 10, 3, 4, 5, 8, 7, 9, 2};
    int n = sizeof(input_arr) / sizeof(input_arr[0]);
    cout<<inversions_count(input_arr, n)<<endl;
    return 0;
}
/*
Expected output:
14
*/
