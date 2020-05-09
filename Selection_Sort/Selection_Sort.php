/*
 * Selection sort is used for sorting arrays.
 * It is based on identifying minimum element from the array 
 * and placing it in beginning. 
 * This is repeated until we reach the end of array.
 */
<?php
    // Selection Sort function 
    function selection_sort($ar, $size)
    {
        for ($i = 0; $i < $size - 1; $i = $i + 1)  
        {  
            // Find the minimum element in unsorted array  
            $min_idx = $i;  
            for ($j = $i + 1; $j < $size; $j = $j + 1)  
            if ($ar[$j] < $ar[$min_idx])  
                $min_idx = $j;  
 
            // Swap the minimum element with the first element of unsorted array 
            $temp = $ar[$min_idx];
            $ar[$min_idx] = $ar[$i];
            $ar[$i] = $temp;  
        }  

        // Print the sorted array
        for($i = 0; $i < $size; $i = $i + 1)
            echo "$ar[$i] ";
    }

    // Sample Input 
    $ar = array(10, 5, 4, 3, 1);

    // count() function returns the number of elements in an array
    $size = count($ar);

    // function call 
    selection_sort($ar, $size);

?>
/*
 * Sample Output
 * 1 3 4 5 10
 */
