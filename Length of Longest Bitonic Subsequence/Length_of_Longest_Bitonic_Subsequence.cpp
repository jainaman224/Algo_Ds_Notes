#include<iostream>
using namespace std;

int longBitonicSub( int arr[], int size ) {
   int *increasingSubSeq = new int[size];          //create increasing sub sequence array
   for (int i = 0; i < size; i++)
      increasingSubSeq[i] = 1;              //set all values to 1

   for (int i = 1; i < size; i++)           //compute values from left ot right
      for (int j = 0; j < i; j++)
         if (arr[i] > arr[j] && increasingSubSeq[i] < increasingSubSeq[j] + 1)
            increasingSubSeq[i] = increasingSubSeq[j] + 1;

   int *decreasingSubSeq = new int [size];       //create decreasing sub sequence array
   for (int i = 0; i < size; i++)
      decreasingSubSeq[i] = 1;              //set all values to 1

   for (int i = size-2; i >= 0; i--)          //compute values from left ot right
      for (int j = size-1; j > i; j--)
         if (arr[i] > arr[j] && decreasingSubSeq[i] < decreasingSubSeq[j] + 1)
            decreasingSubSeq[i] = decreasingSubSeq[j] + 1;

   int max = increasingSubSeq[0] + decreasingSubSeq[0] - 1;
   for (int i = 1; i < size; i++) //find max length
      if (increasingSubSeq[i] + decreasingSubSeq[i] - 1 > max)
         max = increasingSubSeq[i] + decreasingSubSeq[i] - 1;
   return max;
}

int main() {
   int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
   int n = 16;
   cout << "Length of longest bitonic subsequence is " << longBitonicSub(arr, n);
}
/*  Output-
    Length of longest bitonic subsequence is 7  */
    
