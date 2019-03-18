// C++ Code for Comb Sort Algorithm
#include <bits/stdc++.h>
using namespace std;

// Function to sort arr[] using Comb Sort
void combSort(int arr[], int n)
 {
  // initialize gap with array length
  int gap = n;
  int flag= 1;
  while (gap > 1 || flag == 1) 
  {
    // updating gap value by using shrink factor as 1.3
    gap = (gap * 10) / 13;
    // if Gap is less than 1, take gap as 1
    gap= max(1,gap);
    flag= 0;
    // Compare all elements with the obtained gap value
    for (int i = 0; i < (n - gap); i++) 
    {
      // Swap arr[i] and arr[i+gap] if arr[i] is greater
      if (arr[i] > arr[i + gap]) 
      {
        swap(arr[i], arr[i+gap]);
        flag= 1;
      }
    }
  }
}

// Driver function
int main() 
{
  int arr[] = {-10, 50, 20, 0, 15, -25, 30};
  int n = sizeof(arr) / sizeof(arr[0]);
  // Call to combSort function
  combSort(arr, n);
  // Printing sorted array
  cout << "Array after sorting:" << endl;
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
}

/* Output
Array after sorting:
-25 -10 0 15 20 30 50
*/
