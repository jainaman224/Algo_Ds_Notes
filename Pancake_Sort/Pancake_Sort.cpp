# include <iostream>
# include <conio.h>
using namespace std;
  
// Reverses the array 
void reverseArray(int array[], int i) 
{ 
    int temp, start = 0; 
    for (start = 0; start < i; start++)
    { 
        temp = array[start]; 
        array[start] = array[i]; 
        array[i] = temp; 
        i--; 
    } 
} 
  
// Returns index of the maximum element  
int Max(int array[], int n) 
{ 
    int max = 0, i; 
    for (i = 0; i < n; i++) 
        if (array[i] > array[max]) 
            max = i; 
    return max; 
}  

int pancakeSort(int array[], int n) 
{ 
    for (int end = n; end > 1; end--) 
    { 
        int max = Max(array, end);  
        
        if (max != end-1) 
        { 
            //reverse the array from index 0 till the max index
            reverseArray(array, max);  
            //reverse the array from index 0 till the length of the array
            reverseArray(array, end-1); 
        } 
    } 
} 
   
int main() 
{ 
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;
    int array[n];
    cout << "Enter the elements : \n";
    for (int i = 0; i < n; i++)
        cin >> array[i];
  
    pancakeSort(array, n); 
  
    cout << "Sorted Array \n"; 
    for (int i = 0; i < n; ++i) 
        cout << array[i] << " ";  
  
    return 0; 
}

/*
Enter the number of elements : 5
Enter the elements :
9
2
7
4
8
Sorted Array
2 4 7 8 9
*/
