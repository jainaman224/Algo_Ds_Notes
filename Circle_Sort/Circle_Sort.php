<?php
 
//In circle sort The elements of the array lying on the same circle diametrically opposite to each other are compared.

function circleSortRec($a, $low, $high)
{
    $swapped = false;
    
    if($low == $high)
    {
        return false;
    }

    $lo = $low;
    $hi = $high;

    while($lo < $hi)
    {

        if($a[$lo] > $a[$hi])
        {
            $temp = $a[$lo];
            $a[$lo] = $a[$hi];
            $a[$hi] = $temp;
            $swapped = true;
        }
        $lo++;
        $hi--;
    }
      
    if($lo == $hi)
    if($a[$lo] > $a[$hi + 1])
    {
        $t = $a[$low];
        $a[$low] = $a[$hi + 1];
        $a[$hi + 1] = $t;
        $swapped = true;
    }

    $mid = ($high - $low) / 2;
    $firstHalf = circleSortRec($a , $low , $low + $mid);
    $secondHalf = circleSortRec($a , $low + $mid + 1 , $high);
    return $swapped || $firstHalf || $secondHalf;
}

function circleSort($a , $n)
{

    while(circleSortRec($a,0,$n - 1))
    {
        ;
    }
}

$a = explode(' ',readline());
$n = sizeof($a) / sizeof($a[0]);

echo "Unsorted: ";

for($i = 0; $i < $n; $i++)
{
    echo "$a[$i] ";
}

circleSort($a , $n);

echo "\n Sorted: ";

for($i = 0; $i < $n; $i++)
{
    echo "$a[$i] ";
}

return 0;

/*
Input:
7 5 3 1 2 4 6 8

Output: 
Unsorted: [6, 5, 3, 1, 8, 7, 2, 4]
Sorted: [1, 2, 3, 4, 5, 6, 7, 8]
*/

?>
