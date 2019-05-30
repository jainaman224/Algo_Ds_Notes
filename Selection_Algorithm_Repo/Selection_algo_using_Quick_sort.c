#include<stdio.h>

// This uses partition function of QuickSort to find kth smallest element in an unsorted array in nlogk time (avg case)
// O(n square ) in the worst case

int partition(int * a, int low, int high);
int selectKth(int * a, int low, int high, int k) {

    if (low == high)
        return a[low];
    else {

        // Call the partition to place the first pivot.
        int p = partition(a, low, high);
        if (p == k) {
            return a[p];
        } else if (k < p) {
            return selectKth(a, low, p - 1, k);
        } else {
            return selectKth(a, p + 1, high, k);
        }

    }
}

int partition(int * a, int low, int high) {
    int i, j, pivot;
    j = low - 1;
    pivot = a[high];
    for (i = low; i < high; i++) {
        if (a[i] < pivot) {
            j++;
            int temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }

    }
    int temp = a[j + 1];
    a[j + 1] = a[high];
    a[high] = temp;

    return j + 1;
}

int main() {

    int a[] = {
        9,
        5,
        1,
        3,
        4,
        -2
    };
    int n = sizeof(a) / sizeof(int);
    int i;

    // This should give Sorted output . Selecting elements one by one .
    for (i = 0; i < 6; i++) {
        int ans = selectKth(a, 0, n - 1, i);
        printf("%d\n", ans);
    }
    return 0;
}

/* sample input:-9,5,1,3,4,-2
   sample output:-
                -2,1,3,4,5,9
*/
