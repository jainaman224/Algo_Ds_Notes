<?php

    /* Ternary search is a searching technique much like binary search 
     *  but instead of dividing the given array in two parts, it divides it in 3 parts.
     *  It order to search, it needs the array to be sorted.
     */

    // Ternary Search function 
    function ternary_search($ar ,$l , $r , $x)
    {
        // r >= l means there is some space to search x in ar
        if( $r >= $l )
       {
            /* Dividing the array into three parts 
             * namely ar[0]..ar[mid1], ar[mid1]...ar[mid2], ar[mid2]...ar[length - 1]
             */
            $mid1 = (int)($l + ($r - $l) / 3);
            $mid2 = (int)($mid1 + ($r - $l) / 3);
       
            // if x is present at mid1
            if($ar[$mid1] == $x)
                return $mid1;

            // if x is present at mid2
            if($ar[$mid2] == $x)
                return $mid2;
        
            // if x is present in left one-third part
            if($ar[$mid1] > $x)
                return ternary_search($ar, $l, $mid - 1, $x);

           // if x is present in right one third part
            if($ar[$mid2] < $x)
                return ternary_search($ar, $mid2 + 1, $r,  $x);
        
            // if x is present in middle one third part
            return ternary_search($ar, $mid1 + 1, $mid2 - 1, $x);
       }
       else   
            return -1;
            // if x is not present in ar
    }

    // Sample Input (make sure to use sorted array)
    $ar = array(1, 2, 3, 4, 5, 6, 7, 8);

    // x will contain the value which is to be searched in given array
    $x = 4;

    /* to search x in ar, we firstly pass whole of array to the ternary_search() function
     * i.e., (l == 0, r == count(ar) - 1), where count(ar) returns the number of elements in ar
     */

    $index_x = ternary_search($ar, 0, count($ar) - 1, $x);
    // index_x holds the "index" where x is found in ar or -1 if not found 
 
    echo "$index_x";

    /* Sample Output 
     * 3
     * Note that the 3 is the index of "4" in ar (ar[3] = 4)
     */
?>
