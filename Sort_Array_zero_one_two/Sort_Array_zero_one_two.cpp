/*Given an array A[] consisting 0s, 1s and 2s. The task is to write a function that sorts the given array. 
The function puts all 0s first, then all 1s and all 2s in last.*/

#include<stdlib.h>
#include<iostream>
using namespace std;

void sort_zero_one_two(int a[],int n)
{
    int zero = 0; //counter to store number of 0's
    int one = 0;  //counter to store number of 1's
    for(int i = 0 ;i < n; i++)
    {
        if(a[i] == 0)
            zero++;
        else if(a[i] == 1)
            one++;
    }
    for(int i = 0;i < zero;i++)
        a[i] = 0;
    for(int i = zero;i< zero+one;i++)
        a[i] = 1;
    for(int i = one+zero;i < n;i++) //filling rest of the array with 2
        a[i] = 2;
}

int main()
{
    int n;
    cout<<"Enter the number of elements of array: ";
    cin>>n;
    int a[n];
    cout<<"Enter the array elements: ";
    for(int i = 0;i < n;i++)
        cin>>a[i];
    cout<<"Original array : ";
    for(int i = 0;i < n;i++)
        cout<<a[i]<<" ";
    sort_zero_one_two(a,n); //calling the sort function
    cout<<"\nSorted array   : ";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}

/* Sample Input - Output
Enter the number of elements of array: 7                                                                                                                                                                                                                  
Enter the array elements: 1 0 2 1 1 0 2                                                                                                                                                                                                             
Original array : 1 0 2 1 1 0 2 
Sorted array   : 0 0 1 1 1 2 2  */

