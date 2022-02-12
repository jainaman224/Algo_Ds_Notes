<?php
function RMQ($segArr, $segStart, $segEnd, $start, $end, $index)
{

    if ($start <= $segStart && $end >= $segEnd) return $segArr[$index];

    if ($segEnd < $start || $segStart > $end) return PHP_INT_MAX;

    $mid = floor($segStart + ($segEnd - $segStart) / 2);

    $left = RMQ($segArr, $segStart, $mid, $start, $end, 2 * $index + 1);
    $right = RMQ($segArr, $mid + 1, $segEnd, $start, $end, 2 * $index + 2);
    return ($left <= $right ? $left : $right);
}

function buildSegmentTree(&$arr, $start, $end, &$segArray, $index)
{
    if ($start == $end)
    {
        $segArray[$index] = $arr[$start];
        return $arr[$start];
    }

    $mid = floor($start + ($end - $start) / 2);
    $left = buildSegmentTree($arr, $start, $mid, $segArray, $index * 2 + 1);
    $right = buildSegmentTree($arr, $mid + 1, $end, $segArray, $index * 2 + 2);

    $segArray[$index] = ($left <= $right ? $left : $right);

    return $segArray[$index];
}

$arr = array(1,3,2,7,9,11,8,4,20,15);
$size = count($arr);

$height = ceil(log($size, 2));
$segtree_size = 2 * (pow(2, $height) - 1);
$segArray = new SplFixedArray($segtree_size);

buildSegmentTree($arr, 0, $size - 1, $segArray, 0);

$start = 1;
$end = 5;

echo "Minimum value in index range $start to $end is " . RMQ($segArray, 0, $size - 1, $start, $end, 0);
?>
