<?php

//Circle sort algorithm can be visualized by drawing concentric circles on an array of integers. 
//The elements of the array lying on the same circle diametrically opposite to each other are compared and if found in the wrong order they are swapped.
// This goes on in a recursive fashion in which the array is divided into sub-arrays on which the above process is repeated until we get pairs of sorted elements which when put together form a sorted array.

//function to perform circular swaps recursively.
//this function returns true if there was a swap.
//operation performed.

function circleSortRec($a, $low, $high)
{
    $swapped = false;
    
    //base case

    if($low == $high)
    {
        return false;
    }

    //storing upper and lower bounds of list to be used in the recursive case.

    $lo = $low;
    $hi = $high;

    while($lo < $hi)
    {
        //swaps the pair of elements if true.

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

    //special case arises only for list of odd size.
      
    if($lo == $hi)
    if($a[$lo] > $a[$hi+1])
    {
        $t = $a[$low];
        $a[$low] = $a[$hi+1];
        $a[$hi+1] = $t;
        $swapped = true;
    }

    //recursive case to check the traverse lists as sub lists.

    $mid = ($high - $low)/2;
    $firstHalf = circleSortRec($a , $low , $low+$mid);
    $secondHalf = circleSortRec($a , $low+$mid+1 , $high);
    return $swapped || $firstHalf || $secondHalf;
}

//this function mainly calls circleSortRec

function circleSort($a , $n)
{
    //keep calling circleSortRec while there is a swap operation.

    while(circleSortRec($a , 0 , $n-1))
    {
        ;
    }
}

//Driver Program

$a = array(7, 5, 3, 1, 2, 4, 6, 8);
$n = sizeof($a)/sizeof($a[0]);

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

?>