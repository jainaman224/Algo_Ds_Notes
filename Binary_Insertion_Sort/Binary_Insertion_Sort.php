<?php 
/*Binary Insertion sort is a variant of Insertion sorting in which proper location to insert the key element is found using the binary search.*/

function binarySearch ($a, $item, $start, $end) {

    if ($end <= $start)  
        return ($item > $a[$start]) ? ($start + 1) : $start;  
    $mid = (int)(($start + $end) / 2);  
    if($item == $a[$mid])  
        return $mid + 1;  
    if($item > $a[$mid])  
        return binarySearch($a, $item, $mid + 1, $end);    
    return binarySearch($a, $item, $start, $mid - 1);  
}  
  
// Function to sort an array a of size 'n'  
function insertionSort(&$a, $n) {  
    $i; $loc; $j; $k; $key;  
    for ($i = 1; $i < $n; ++$i) {  
        $j = $i - 1;  
        $key = $a[$i];  
        $loc = binarySearch($a, $key, 0, $j);  
        while ($j >= $loc) {  
            $a[$j + 1] = $a[$j];  
            $j--;  
        }  
        $a[$j + 1] = $key;  
    }  
}  
  
// Driver Code 
$a = array(37, 23, 0, 17, 12, 72, 31, 46, 100, 88, 54);  
$n = sizeof($a);  
insertionSort($a, $n);  
echo "Sorted array:\n";  
for ($i = 0; $i < $n; $i++)  
    echo "$a[$i] ";  

/* 
OUTPUT :

Sorted array:
0 12 17 23 31 37 46 54 72 88 100

*/
?> 

