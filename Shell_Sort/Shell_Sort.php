<?php
function shell_Sort($new_arr)
{   
    $a = round(count($new_arr) / 2);    //Gap Value
    while($a > 0)
    {
        for($b = $a; $b < count($new_arr); $b++)    //Comparing and Sorting the elements of array
        {
            $d = $new_arr[$b];
            $c = $b;
            while($c >= $a && $new_arr[$c - $a] > $d)
            {
                $new_arr[$c] = $new_arr[$c - $a];
                $c -= $a;
            }
            $new_arr[$c] = $d;
        }   
        $a = round($a / 2.2);
   }   
    return $new_arr;    //Array is returned after sorting
}   
 
//Driver Code :
$sample_arr = array(4, 9, 11, -5, 8, 1, 0, 6, -3);
echo "Array before sorting :<br/>";
echo implode(', ', $sample_arr);
echo "<br/>";
echo "<br/>Array after sorting :<br/>";
echo implode(', ', shell_Sort($sample_arr)). PHP_EOL;

/*
Implementing Shell Sort Algorithm :

Array before sorting :
4, 9, 11, -5, 8, 1, 0, 6, -3

Array after sorting :
-5, -3, 0, 1, 4, 6, 8, 9, 11
*/

?>
