<?php 

function countSort(&$arr, $n, $exp) 
{ 
    // output array 
    $output = array_fill(0, $n, 0); 
    $count = array_fill(0, 10, 0); 

    // Store count of occurrences in count[] 
    for ($i = 0; $i < $n; $i++) 
	    $count[ ($arr[$i] / $exp) % 10 ]++; 

    // contains actual position of this digit in output[] 
    for ($i = 1; $i < 10; $i++) 
        $count[$i] += $count[$i - 1]; 

    // Build the output array 
    for ($i = $n - 1; $i >= 0; $i--) 
    { 
	    $output[$count[ ($arr[$i] / $exp) % 10 ] - 1] = $arr[$i]; 
	    $count[ ($arr[$i] / $exp) % 10 ]--; 
    } 

    // Copy the output array to arr[]
    for ($i = 0; $i < $n; $i++) 
	    $arr[$i] = $output[$i]; 
} 

// The main function that sorts arr[]  
function radixsort(&$arr, $n) 
{ 
    // Find the maximum number to know number of digits
    $m = max($arr); 
    // Do counting sort for every digit
    for ($exp = 1; $m / $exp > 0; $exp *= 10) 
	    countSort($arr, $n, $exp); 
} 

// A utility function to print an array 
function PrintArray(&$arr,$n) 
{ 
    echo "sorted Array : ";
    for ($i = 0; $i < $n; $i++) 
	    echo $arr[$i] . " "; 
} 

// Driver Code 
$n = readline ("Enter size of an array : ");
readline ("Enter the elements : ");
for ($i = 0; $i < $n; $i++) 
{
    $arr[$i] = readline(); 
}

radixsort($arr, $n); 
PrintArray($arr, $n); 

/*
OUTPUT:
Enter size of an array : 7
Enter the elements : 
12
45
9
85
700
2
4
Sorted Array : 2 4 9 12 45 85 700
*/

?>
