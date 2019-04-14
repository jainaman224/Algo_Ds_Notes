#include <iostream>

using namespace std;

int searchCircular(int arr[], int len, int num)
{
    int low = 0;
    int high = len - 1;
    while(low <= high){
        int mid = (low + (high - low) / 2);
        if(arr[mid] == num) return mid;
        else if(arr[mid] <= arr[high]){
            if(num > arr[mid] && num <= arr[high]){
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        else if(arr[mid] > arr[low]){
            if(num < arr[mid] && num >= arr[low])
                high = mid - 1;
            else
                low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {8, 9, 10, 11, 12, 2, 3, 4, 5, 6, 7}; // array must contain distinct elements for this to work
    cout << endl << searchCircular(arr, 11, 9);
    return 0;
}
