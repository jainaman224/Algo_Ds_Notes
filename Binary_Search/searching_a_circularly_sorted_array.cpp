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
    int num;
    cin >> num;
    int arr[num]; // array must contain distinct elements for this to work
    for (int i = 0; i < num; i++) {
        cin >> arr[i];
    } 
    int desired;
    cin >> desired;
    cout << searchCircular(arr, num, desired); // Returns the index of element
    return 0;
}

/*
Input: 
num = 4
array = {1, 4, 5, 6}

Output:
1

Input:
num = 5
array = {1, 3, 5, 7, 9}
desired = 2

Output:
-1
*/
