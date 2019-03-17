// C++ Code for Comb Sort Algorithm
#include <bits/stdc++.h>
using namespace std;

// function for updation of gap value
int updateGap(int gap)
{ 
    // Shrink gap by the shrink factor 1.3
    gap = (gap * 10) / 13;
    if (gap < 1)
        return 1;
    return gap;
}

// Function to sort arr[] using Comb Sort 
void combSort(int arr[], int n) 
{
  // initialize gap with array length
  int gap = n;
  bool swapped = true;
  while (gap > 1 || swapped == true)
  {
    // call to function updateGap to shrink gap value
    gap = updateGap(gap);
    swapped = false;
    // Compare all elements with the obtained gap value
    for (int i = 0; i < (n - gap); i++)
    {
      int temp;
      if (arr[i] > arr[i + gap])
      {
        // Swap arr[i] and arr[i+gap] 
        temp = arr[i];
        arr[i] = arr[i + gap];
        arr[i + gap] = temp;
        swapped = true;
      }
    }
  }
}

// Driver function
int main()
{
  int arr[] = {3, -6, 20, 66, 25, -52, 0, 11, 42};
  int n = sizeof(arr)/sizeof(arr[0]);
  // Call to combSort function
  combSort(arr, n);
  // Printing sorted array
  cout << "Sorted array" << endl;
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
}     
