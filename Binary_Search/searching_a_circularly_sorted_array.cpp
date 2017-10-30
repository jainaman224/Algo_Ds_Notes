#include <iostream>

using namespace std;

int searchCircular(int a[],int len,int num)
{
    int low = 0;
    int high = len-1;
    while(low <= high){
        int mid = (low + (high-low)/2);
        if(a[mid] == num) return mid;
        else if(a[mid] <= a[high]){
            if(num > a[mid] && num <= a[high]){
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        else if(a[mid] > a[low]){
            if(num < a[mid] && num >= a[low])
                high = mid - 1;
            else
                low = mid+1;
        }
    }
    return -1;
}

int main()
{
    int a[] = {8,9,10,11,12,2,3,4,5,6,7}; //array must contain distinct elements for this to work
    cout << endl << searchCircular(a,11,9);
    return 0;
}
