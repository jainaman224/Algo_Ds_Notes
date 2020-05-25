<?php 
// Exponential search in PHP

function Binary_Search($input_arr, $left, $right, $x)
{
    if ($right > $left) 
    {
        $mid = $left + ($right - $left) / 2; 
        if ($input_arr[$mid] == $x) 
            return $mid; 
        if ($x < $input_arr[$mid] ) 
            return Binary_Search($input_arr, $left, $mid - 1, $x); 
		
        return Binary_Search($input_arr, $mid + 1, $right, $x); 
    }
    return -1; 
}

function Exponential_Search($input_arr,$size,$x)
{
	if ($input_arr[0] == $x)
        return 0;
    $i = 1;
	while ($i < $size and $input_arr[$i] <= $x)
    {
	    $i = $i * 2;
	}
	
	return Binary_Search($input_arr, $i / 2, min($i, $size), $x);
	
}

//Driver Code

$input_arr = array(1, 2, 3, 4, 5, 6);
$size = count($input_arr); 
$x = 4;
$result = exponential_search($input_arr, $size, $x);
if ($result != -1)
    echo "The index at which the element " , $x,  " is present is " , $result;
    
else
    echo "The element is not present in array";

/*
OUTPUT:
The index at which the element 4 is present is 3
*/

?>
