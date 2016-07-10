<?php

$list = array(3, 4, 25, 45, 78);
$element_to_be_found = 25;

function binary_search($element_to_be_found, $list, $left, $right)
{
    if ($left > $right)
        return -1;

    $mid = ($right + $left) / 2;

    if($list[$mid] == $element_to_be_found)
        return $mid + 1;
    else if($list[$mid] > $element_to_be_found)
        return binary_search($element_to_be_found,$list,$left,$mid-1);
    else if($list[$mid] < $element_to_be_found)
        return binary_search($element_to_be_found,$list,$mid+1,$right);
}

$ans = binary_search($element_to_be_found, $list, 0, count($list) - 1);

if($ans == -1)
    echo "Element not found";
else
    echo "Element found at position $ans";
    
/*

Output : Element found at position 3
    
*/

?>
    
