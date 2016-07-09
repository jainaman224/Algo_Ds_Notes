<?php

// Function implementing Interpolation Search
function Interpolation_Search($list, $search_item)
{
	$low = 0;
	$high = count($list) - 1;
	$pos;
	
	while($low <= $high && $search_item >= $list[$low] && $search_item <= $list[$high])
	{
		$rise = $high - $low;
		$run = $list[$high] - $list[$low];
		$x = $search_item - $list[$low];
		
		$pos = $low + ($rise / $run) * $x;
		
		if($list[$pos] == $search_item)
			return $pos;
		else if($search_item < $list[$pos])
			$high = $pos - 1;
		else if($search_item > $list[$pos])
			$low = $pos + 1;
	}
	return -1;
}

$list = array(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

$search_item = 18;

$index = Interpolation_Search($list, $search_item);

if($index == -1)
	echo "Element not found";
else
	echo "Element found at index $index";

/*

Output: Element found at index 7

*/

?>
