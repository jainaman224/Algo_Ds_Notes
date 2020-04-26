#include<bits/stdc++.h>
using namespace std;
void show(int *array, int size) {
   for(int i = 1; i<=size; i++)
      cout<<array[i] << " ";
   cout<<"\n";
}
int maxElement(int array[], int size) {
   int maximum = array[1];
   for(int i = 2; i<=size; i++) {
      if(array[i] > maximum)
         maximum = array[i];
   }
   return maximum;
}
void countingSort(int *array, int size) {
   int output[size+1];
   int max = maxElement(array, size);
   int count[max+1];
   for(int i = 0; i<=max; i++)
      count[i] = 0; 
   for(int i = 1; i <=size; i++)
      count[array[i]]++;  
   for(int i = 1; i<=max; i++)
      count[i] += count[i-1];
   for(int i = size; i>=1; i--) {
      output[count[array[i]]] = array[i];
      count[array[i]] -= 1; 
   }
   for(int i = 1; i<=size; i++) {
      array[i] = output[i];
   }
}
int main() {
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr[n+1];
   cout << "Enter the elements of array :\n" ;
   for(int i = 1; i<=n; i++)
      cin >> arr[i];
   cout << "Array before Sorting: ";
   show(arr, n);
   countingSort(arr, n);
   cout << "Array after Sorting: ";
   show(arr, n);
}
