<?php
function insertionSort(&$arr,$left,$right)
{
  for($i=$left+1;$i<=$right;$i++)
  {
        $temp = $arr[$i]; 
        $j = $i-1; 
        while ($j>=$left && $arr[$j] > $temp) 
        { 
            $arr[$j+1] = $arr[$j]; 
            $j--; 
        } 
        $arr[$j+1] = $temp; 
    } 
}
// merge function merges the sorted runs 
function merge(&$arr, $l, $m, $r) 
{ 
    // original array is broken in two parts 
    // left and right array 
    $len1 = $m - $l + 1;
    $len2 = $r - $m;
    $left = new SplFixedArray($len1);
    $right = new SplFixedArray($len2);
    for ($i = 0; $i < $len1; $i++) 
        $left[$i] = $arr[$l + $i]; 
    for ($i = 0; $i < $len2; $i++) 
        $right[$i] = $arr[$m + 1 + $i]; 
  
    $i = 0; 
    $j = 0; 
    $k = $l; 
  
    // after comparing, we merge those two array 
    // in larger sub array 
    while ($i < $len1 && $j <$len2) 
    { 
        if ($left[$i] <= $right[$j]) 
        { 
            $arr[$k] = $left[$i]; 
            $i++; 
        } 
        else
        { 
            $arr[$k] = $right[$j]; 
            $j++; 
        } 
        $k++; 
    }
    // copy remaining elements of left, if any 
    while ($i < $len1) 
    { 
        $arr[$k] = $left[$i]; 
        $k++; 
        $i++; 
    }
    // copy remaining element of right, if any 
    while ($j < $len2) 
    { 
        $arr[$k] = $right[$j]; 
        $k++; 
        $j++; 
    } 
}
// iterative Timsort function to sort the 
// array[0...n-1] (similar to merge sort) 
function timSort(&$arr) 
{ 
  $run=32;
    // Sort individual subarrays of size RUN 
    for ($i = 0; $i < count($arr); $i+=$run) 
        insertionSort($arr, $i,min(($i+31), (count($arr)-1))); 
    // start merging from size RUN (or 32). It will merge 
    // to form size 64, then 128, 256 and so on .... 
    for ($size = $run; $size < count($arr); $size = 2*$size) 
    { 
        // pick starting point of left sub array. We 
        // are going to merge arr[left..left+size-1] 
        // and arr[left+size, left+2*size-1] 
        // After every merge, we increase left by 2*size 
        for ($left = 0; $left < count($arr); $left += 2*$size) 
        { 
            // find ending point of left sub array 
            // mid+1 is starting point of right sub array 
            $mid = $left + $size - 1; 
            $right = min(($left + 2*$size - 1), (count($arr)-1)); 
  
            // merge sub array arr[left.....mid] & 
            // arr[mid+1....right] 
            merge($arr, $left, $mid, $right); 
        } 
    } 
} 
  
//function to print the Array 
function printArray($arr) 
{ 
    $output = "[";
    for ($i = 0; $i < count($arr); $i++){
        $output .= " ".$arr[$i]." "; 
        if ($i<count($arr)-1) {
            $output .=",";
        }
    }
    $output .= "]";
    echo $output;
} 


$arr = array(9,65,0,2,-4,12,-18); 
print("\nGiven Array is\n"); 
printArray($arr); 
timSort($arr); 
print("\nAfter Sorting Array is\n"); 
printArray($arr); 

// OUTPUT =>
// ------------
// Given Array is
//[ 9 , 65 , 0 , 2 , -4 , 12 , -18 ]
//After sorting Array is
//[ -18 , -4 , 0 , 2 , 9 , 12 , 65 ]
?>