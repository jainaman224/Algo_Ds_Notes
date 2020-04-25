<?php
// PHP Implementation of LIS using Dynamic Programming

// fumction to return the length of LIS
function lisLen($arr, $n){
    
    // length of LIS ending at index 0 is 1
    $dp[0] = 1;
    
    // compute the length of LIS ending at each index 
    for ($i = 1; $i < $n; $i++){ 
        $dp[$i] = 1; 
        for ($j = 0; $j < $i; $j++)   
            if ($arr[$i] > $arr[$j] && $dp[$i] < $dp[$j] + 1)  
                $dp[$i] = $dp[$j] + 1;  
    } 
    
    // find the max out of computed lengths of LIS 
    // ending at different indices
    $max = PHP_INT_MIN;
    for($i = 0; $i < $n; $i++){
        if($max < $dp[$i])
            $max = $dp[$i];
    }
    
    return $max;
}

// Sample test case
$arr = array(3, 10, 2, 1, 20, 40, 60, 7);
$n = sizeof($arr);

echo "Length of LIS is " , lisLen($arr, $n);

/*
Sample Input as specified in the code:
3, 10, 2, 1, 20, 40, 60, 7

Sample Output:
Length of LIS is 5
*/

?>
