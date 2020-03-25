//Count Inversion in java

import java.util.*;
class CountInversion
 {
    static int sortfn( int arr[], int n )
    {
      int temp[] = new int[n];
      return mergeSort(arr, temp, 0, n - 1);
    }

    /*This function returns  the number of inversions in the array*/
    
   static int mergeSort( int arr[], int temp[], int left, int right)
    {
      int mid, invcount = 0;
      if(right > left)
      {
       /*Divide the array into two parts*/
       mid = (right + left) / 2;

       /*inversions in the left subarray*/
       invcount = mergeSort( arr, temp, left, mid);

       /*inversions in the right subarray */
       invcount += mergeSort( arr, temp, mid + 1, right);

       /*merge counts the number of cross inversions*/
       invcount += mergefn( arr, temp, left, mid + 1, right);
     }
       return invcount;
   }

    /*This method merges two sorted arrays and returns inversion count in
    the arrays.*/
    
  static int mergefn( int arr[], int temp[], int left, int mid, int right )
   {
       int i, j, k;
       int invcount = 0;
       /* i is index for left subarray*/
       i = left;
       /* j is index for right subarray*/
       j = mid;
       /* k is index for resultant merged subarray*/
       k = left;
       while ( ( i <= mid - 1 ) && ( j <= right ) )
        {
          if ( arr[i] <= arr[j] )
            {
             temp[k++] = arr[i++];
            }
           else
            {
             temp[k++] = arr[j++];
             inv_count = inv_count + (mid - i);
            }
       }

       /*Copy the remaining elements of left subarray to temp*/
       while ( i <= mid - 1 )
       temp[k++] = arr[i++];

       /*Copy the remaining elements of right subarray to temp*/
       while ( j <= right )
       temp[k++] = arr[j++];

       /*Copy back the merged elements to original array*/
       for ( i = left; i <= right; i++ )
       arr[i] = temp[i];

       return invcount;
    }


  public static void main( String[] args )
     {
       int n;
       Scanner in = new Scanner( System.in );
       n = in.nextInt();
       int a[] = new int[n];
       for(int i=0; i < n; i++)
       a[i] = in.nextInt();
       System.out.println( sortfn(a, n) );
     }
   }

/* Sample input
5
1 20 6 4 5

Sample output
5
 */

