// CPP program to count inversion sort in an array
// inversion count is in an array such that arr[i] > arr[j]  where  i < j 
#include<iostream>
using namespace std;
int mergefn(int arr[] ,int temp[], int left, int mid, int right)
{
    int i = left;
    int j = mid;
    int  k = left;
    int inv_cnt = 0;
  while( ( i <= mid-1 ) && ( j <= right ) )
    {
        if( arr[i] <= arr[j] )
            temp[k++] = arr[i++];
        else
        {
             /* if arr[i] is greater than arr[j], then there are (mid – i) inversions.
                because left and right subarrays are sorted,
                so all the remaining elements in left-subarray
                (arr[i+1], arr[i+2] … arr[mid]) will be greater than arr[j] */
                temp[k++] = arr[j++];
                inv_cnt += (mid-i);
        }
    }
     /* Copy the remaining elements of left subarray
         (if there are any) to temp*/
    while( i <= mid-1 )
        temp[k++] = arr[i++];
     /* Copy the remaining elements of right subarray
        (if there are any) to temp*/
    while( j <= right )
        temp[k++] = arr[j++];
         /*Copy back the merged elements to original array*/
  for( i = left ; i <= right ; i++ )
        arr[i] = temp[i];
    return inv_cnt;
}
int mergesort ( int arr[], int temp[], int left, int right )
{

  // inv_cnt stores the total number of inversion count in arr[]
  int inv_cnt = 0;
 if( right > left )
    {
        int mid = ( left + right ) / 2;
        // merge sort counts inversion in the first half array
        inv_cnt += mergesort( arr, temp, left, mid );
        // merge sort counts inversion in second half array
        inv_cnt += mergesort( arr, temp, mid+1, right );
        // mergefn counts the cross inversions in the left and right array
        inv_cnt += mergefn( arr, temp, left, mid+1, right );
    
    }
    
    return inv_cnt;
}
int main()
{
    // test cases t
	int t;
	cin>>t;
	while(t--){
    // size of array n
    int n;
    cin>>n;
    // input array arr[]
    int arr[n];
    for( int i=0 ; i<n ; i++ )
        cin>>arr[i];
        // auxillary array temp[] to store sorted elements
    int temp[n];
    cout<<mergesort( arr, temp, 0, n-1)<<endl;
    }
    return 0;
}

/* Sample Input
2
4
1 2 4 3
3
3 2 1
Sample Output
1
3 */
