function insertionSort(arr,left,right)
{
  for(let i=left+1;i<=right;i++)
  {
    let temp = arr[i]; 
        let j = i - 1; 
        while (arr[j] > temp && j >= left) 
        { 
            arr[j+1] = arr[j]; 
            j--; 
        } 
        arr[j+1] = temp; 
    } 
}
// merge function merges the sorted runs 
function merge(arr, l, m, r) 
{ 
    // original array is broken in two parts 
    // left and right array 
    let len1 = m - l + 1, len2 = r - m;
    var left = new Array[len1];
    var right = new Array[len2];
    for (let i = 0; i < len1; i++) 
        left[i] = arr[l + i]; 
    for (let i = 0; i < len2; i++) 
        right[i] = arr[m + 1 + i]; 
  
    let i = 0; 
    let j = 0; 
    let k = l; 
  
    // after comparing, we merge those two array 
    // in larger sub array 
    while (i < len1 && j < len2) 
    { 
        if (left[i] <= right[j]) 
        { 
            arr[k] = left[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = right[j]; 
            j++; 
        } 
        k++; 
    }
    // copy remaining elements of left, if any 
    while (i < len1) 
    { 
        arr[k] = left[i]; 
        k++; 
        i++; 
    }
    // copy remaining element of right, if any 
    while (j < len2) 
    { 
        arr[k] = right[j]; 
        k++; 
        j++; 
    } 
}
// iterative Timsort function to sort the 
// array[0...n-1] (similar to merge sort) 
function timSort( arr, n) 
{ 
  var run=32;
    // Sort individual subarrays of size RUN 
    for (let i = 0; i < n; i+=run) 
        insertionSort(arr, i,Math.min((i+31), (n-1))); 
    // start merging from size RUN (or 32). It will merge 
    // to form size 64, then 128, 256 and so on .... 
    for (let size = run; size < n; size = 2*size) 
    { 
        // pick starting point of left sub array. We 
        // are going to merge arr[left..left+size-1] 
        // and arr[left+size, left+2*size-1] 
        // After every merge, we increase left by 2*size 
        for (let left = 0; left < n; left += 2*size) 
        { 
            // find ending point of left sub array 
            // mid+1 is starting point of right sub array 
            let mid = left + size - 1; 
            let right = min((left + 2*size - 1), (n-1)); 
  
            // merge sub array arr[left.....mid] & 
            // arr[mid+1....right] 
            merge(arr, left, mid, right); 
        } 
    } 
} 
  
//function to print the Array 
function printArray(arr, n) 
{ 
    for (let i = 0; i < n; i++) 
        console.log(" " , arr[i]); 
    console.log("\n"); 
} 

function main() 
{ 
    let arr = [5, 21, 7, 23, 19]; 
    let n = arr.length; 
    console.log("Given Array is\n"); 
    printArray(arr, n); 
    timSort(arr, n); 
    console.log("After Sorting Array is\n"); 
    printArray(arr, n); 
} 
main();

// OUTPUT =>
// ------------
// Given Array is
//   5
//   21
//   7
//   23
//   19
// After Sorting Array is
//   5
//   7
//   19
//   21
//   23
