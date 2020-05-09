//Program to rotate array Arr[] of size n by d Elements
#include<iostream>
using namespace std;

void swap(int *input,int i,int j){

    int temp=input[i];
    input[i]=input[j];
    input[j]=temp;
}
void Reverse(int * input,int start,int end){

    int i=start,j=end;
    while(i<j){
        swap(input,i,j);
        i++;
        j--;
    }
}
void Rotate(int * input,int d ,int n){
    if(d>=n)
        d=d%n;
    Reverse(input,0,n-1);   // reverse the whole array
    Reverse(input,0,n-d-1);  //reverse array from starting index till n-d-1
    Reverse(input,n-d,n-1);  //reverse array from n-d to last element

}
int main()
{
    int n, r;
    cout << "Enter number of elements in your array: ";
    cin >> n;
    int *arr=new int [n+1];

    cout << "Enter your array: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter the value for rotation cycle: ";
	cin >> r;

    Rotate(arr, r, n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
     delete []arr;	
    return 0;
}



/*
INPUT:
Enter number of elements in your array: 5
Enter your array: 1
2
3
4
5
Enter the value for rotation cycle: 2
OUTPUT:
3 4 5 1 2
*/
